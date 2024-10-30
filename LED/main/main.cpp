//***********ไฟวิ่งทีละสองดวง***********/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(16); 
LED led2(17); 
LED led3(5); 
LED led4(18); 
LED led5(19); 
LED led6(21); 
LED led7(22); 
LED led8(23); 

LED leds[] = {led1, led2, led3, led4, led5, led6, led7, led8};

extern "C" void app_main(void)
{
    int i = 0;         // Start index for the LED
    int direction = 1; // Direction: 1 for right, -1 for left

    while(1)
    {        
        // เปิดสอง LED ที่ติดกัน
        leds[i].ON();
        if (i + direction >= 0 && i + direction < 8) {
            leds[i + direction].ON();
        }

        // หน่วงเวลาเพื่อให้ไฟติด
        vTaskDelay(200 / portTICK_PERIOD_MS);

        // ปิดสอง LED ที่ติดกัน
        leds[i].OFF();
        if (i + direction >= 0 && i + direction < 8) {
            leds[i + direction].OFF();
        }

        // อัปเดตตำแหน่งของ LED โดยเปลี่ยนทิศทางหากถึงขอบ
        i += direction;
        if (i >= 7 || i <= 0) {
            direction = -direction; // เปลี่ยนทิศทาง
        }
    }
}
