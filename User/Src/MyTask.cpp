#include "MyTask.h"
#include "LED.h"
#include "cmsis_os.h"

void initialTestTaskFun(void const *argument) {
    for (;;) {
        LED::ledOn();
        osDelay(1000);
        LED::ledOff();
        osDelay(1000);
    }
}
