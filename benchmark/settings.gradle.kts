enableFeaturePreview("TYPESAFE_PROJECT_ACCESSORS")
pluginManagement {
    repositories {
        google()
        gradlePluginPortal()
        mavenCentral()
        maven("https://kmm-external-deps.oss-cn-hangzhou.aliyuncs.com")
    }
}

dependencyResolutionManagement {
    repositories {
        google()
        mavenCentral()
        maven("https://kmm-external-deps.oss-cn-hangzhou.aliyuncs.com")
    }
}

rootProject.name = "kmp_library_scaffold"
include(":shared")