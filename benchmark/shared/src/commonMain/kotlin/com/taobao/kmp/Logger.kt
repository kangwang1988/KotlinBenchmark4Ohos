package com.taobao.kmp

expect fun logInfo(tag: String?, content: String?)

class Logger {
    companion object {
        fun info(tag: String?, content: String?) {
            logInfo(tag, content)
        }
    }
}