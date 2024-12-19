import groovy.util.Node

plugins {
    alias(libs.plugins.kotlinMultiplatform)
    alias(libs.plugins.kotlinCocoapods)
    alias(libs.plugins.androidLibrary)
    id("maven-publish")
}

val settingsFile = "/home/admin/software/apache-maven-3.2.1/conf/settings.xml"
val mtlVersion = System.getenv("MUPP_VERSION_NAME")
var groupValue : String = "com.taobao.kmp"
var publishVersion: String = "0.0.1-SNAPSHOT"
if (null != mtlVersion) {
    publishVersion = mtlVersion
}

fun getAccount() : HashMap<String, String> {
    val accountMap = HashMap<String, String>()

    val defaultSettingsFile = System.getProperty("user.home") + "/.m2/settings.xml"
    if (file(settingsFile).exists() || file(defaultSettingsFile).exists()) {
        val parsedSettingsXml =
            if (file(settingsFile).exists()) {
                (groovy.xml.XmlParser()).parse(settingsFile);
            } else {
                (groovy.xml.XmlParser()).parse(defaultSettingsFile)
            }
        val servers0 = (parsedSettingsXml.get("servers") as List<Node>).first()
        val serverList = servers0.get("server") as List<Node>
        serverList.forEach {
            val idText = (it.get("id") as List<Node>).first().text()
            if (idText == "releases") {
                val userNameText = (it.get("username") as List<Node>).first().text()
                val passwordText = (it.get("password") as List<Node>).first().text()
                accountMap["id"] = idText
                accountMap["username"] = userNameText
                accountMap["password"] = passwordText
            }
        }
    } else {
        accountMap["id"] = "releases"
        accountMap["username"] = "admin"
        accountMap["password"] = "screct"
    }
    return accountMap
}

publishing {
    repositories {
        if (publishVersion.endsWith("-SNAPSHOT")) {
            maven {
                group = groupValue
                version = publishVersion
                isAllowInsecureProtocol = true
                setUrl("http://mvnrepo.alibaba-inc.com/nexus/content/repositories/snapshots")
                credentials {
                    username = "snapshotsAdmin"
                    password = "123456"
                }
            }
        } else {
            val accountMap = getAccount();
            maven {
                group = groupValue
                version = publishVersion
                isAllowInsecureProtocol = true
                setUrl("http://mvnrepo.alibaba-inc.com/nexus/content/repositories/releases")
                credentials {
                    username = accountMap["username"]
                    password = accountMap["password"]
                }
            }
        }
    }
}

kotlin {
    androidTarget {
        compilations.all {
            kotlinOptions {
                jvmTarget = "1.8"
            }
        }
        publishLibraryVariants("release")
    }
    iosArm64()
    iosX64()
    iosSimulatorArm64()
    ohosArm64 {
        binaries.sharedLib {
            baseName = "TBKMP"
        }
    }

    cocoapods {
        summary = "Some description for the Shared Module"
        homepage = "Link to the Shared Module homepage"
        version = "1.0"
        ios.deploymentTarget = "16.0"
        framework {
            baseName = "shared"
            isStatic = true
        }
    }
    
    sourceSets {
        val commonMain by getting
        commonMain.dependencies {
            //put your multiplatform dependencies here
        }
        val ohosArm64Main by getting
        val ohosMain by creating {
            dependsOn(commonMain)
            ohosArm64Main.dependsOn(this)
        }
        val iosArm64Main by getting
        val iosX64Main by getting
        val iosSimulatorArm64Main by getting
        val iosMain by creating {
            dependsOn(commonMain)
            iosArm64Main.dependsOn(this)
            iosX64Main.dependsOn(this)
            iosSimulatorArm64Main.dependsOn(this)
        }
    }
}

android {
    namespace = "com.taobao.kmp"
    compileSdk = 33
    defaultConfig {
        minSdk = 21
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
}