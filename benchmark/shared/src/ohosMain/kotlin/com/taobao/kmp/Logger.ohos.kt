package com.taobao.kmp

import platform.native_api.*

actual fun logInfo(tag: String?, content: String?) {
    OH_LOG_Print(LOG_APP, LOG_INFO, LOG_DOMAIN.toUInt(), tag, "%{public}s", content)
}