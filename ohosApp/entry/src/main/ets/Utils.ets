import { hilog } from "@kit.PerformanceAnalysisKit";

export function logInfo(content: string) {
  hilog.info(0x0000, '[KWLM]', '%{public}s', content);
}

export function measureBlockRun(tag: string, block: (arg: number)=>void, arg: number) {
  let t0 = Date.now()
  block(arg)
  let t1 = Date.now()
  logInfo(`${tag}: costs ${t1-t0}ms`)
}