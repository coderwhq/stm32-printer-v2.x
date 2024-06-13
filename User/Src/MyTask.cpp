#include "MyTask.h"

void initialTestTaskFun(void const *argument) {
    auto serial = Serial(&huart2);
    osEvent event;
    serial.serialPrintf((char *) "initialTestTaskFun,  %d \r\n", 123);
    for (;;) {
        //        LED::ledOn();
        //        osDelay(1000);
        //        LED::ledOff();
        //        osDelay(1000);
        serial.serialPrintf((char *) " one loop begin \r\n");
        event = osMessageGet(rxDataQueueHandle, osWaitForever);
        if (event.status == osEventMessage) {
            serial.serialPrintf((char *) event.value.p);
        } else if (event.status == osEventTimeout) {
            // overtime
        } else {
            // error
        }
        serial.serialPrintf((char *) " one loop end \r\n");
    }
}
