package com.taobao.kmp

import platform.Foundation.NSLog
import platform.Foundation.NSString
import platform.Foundation.create

actual fun logInfo(tag: String?, content: String?) {
    NSLog("[Info]%@:%@", NSString.create(string = tag?:""), NSString.create(string = content?:""))
}
