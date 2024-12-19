package com.taobao.kmp

import android.util.Log

actual fun logInfo(tag: String?, content: String?) {
    Log.i(tag, content?:"")
}