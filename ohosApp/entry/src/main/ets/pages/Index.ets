import { hilog } from '@kit.PerformanceAnalysisKit';
import testNapi from 'libentry.so';
import { nbodyImpl } from '../nbody';
import { measureBlockRun } from '../Utils';

@Entry
@Component
struct Index {
  @State knMessage: string = '[Kotlin/Native][n-body]';
  @State arkTSMessage: string = '[ArkTS][n-body]';
  @State nBodyNum: number = 1000000

  build() {
    Row() {
      Column() {
        Text(this.arkTSMessage)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            measureBlockRun(`${this.arkTSMessage}(${this.nBodyNum})`,nbodyImpl, this.nBodyNum)
          })
        Row().height(100)
        Text(this.knMessage)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            measureBlockRun(`${this.knMessage}(${this.nBodyNum})`,testNapi.runNBodyInKN, this.nBodyNum)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
