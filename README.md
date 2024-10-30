# ESP32_ESP-IDF_7segment-cook-book-4
## 1.ระบุตัวอย่างที่ใช้ ว่าเอามาจากตัวอย่างไหน


## 2.ระบุว่า จะแก้ไขตรงไหนบ้าง เพื่ออะไร
เปลี่ยนชื่อไฟล์แล้วทำการเพิ่มโค้ดดังต่อไปนี้เพื่อให้ไฟวิ่งเเสดงผลติดทีละสองดวง
![image](https://github.com/user-attachments/assets/3399b379-2bc6-4dac-bca5-a7e07562210d)
```c
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

```
เปลี่ยนชื่อไฟล์แล้วทำการเพิ่มโค้ดดังต่อไปนี้
![image](https://github.com/user-attachments/assets/3fd87889-9af6-418d-99c8-751dfe1ab463)

``` cpp
#include <stdio.h>
#include "LED.h"

LED::LED(int Pin)
{
    PinNumber = Pin;
    gpio_set_direction((gpio_num_t)PinNumber, GPIO_MODE_OUTPUT);
}

void LED::ON()
{
    gpio_set_level((gpio_num_t)PinNumber,1);
}

void LED::OFF()
{
    gpio_set_level((gpio_num_t)PinNumber,0);
}


```

## 3.ขั้นตอนการทำ
![image](https://github.com/user-attachments/assets/fee2c7f5-1036-44ca-99f8-879bc19aa2b1)
![image](https://github.com/user-attachments/assets/b8dd3115-2063-4fad-a16b-684882dfd1a3)
![image](https://github.com/user-attachments/assets/289e785d-b136-421c-80eb-78ceb566562a)
เปลี่ยนชื่อไฟล์แล้วทำการเพิ่มโค้ดดังต่อไปนี้
![image](https://github.com/user-attachments/assets/3399b379-2bc6-4dac-bca5-a7e07562210d)
```c
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

```
เปลี่ยนชื่อไฟล์แล้วทำการเพิ่มโค้ดดังต่อไปนี้
![image](https://github.com/user-attachments/assets/3fd87889-9af6-418d-99c8-751dfe1ab463)

``` cpp
#include <stdio.h>
#include "LED.h"

LED::LED(int Pin)
{
    PinNumber = Pin;
    gpio_set_direction((gpio_num_t)PinNumber, GPIO_MODE_OUTPUT);
}

void LED::ON()
{
    gpio_set_level((gpio_num_t)PinNumber,1);
}

void LED::OFF()
{
    gpio_set_level((gpio_num_t)PinNumber,0);
}


```
ทดสอบโปรเเกรม

## 4.ผลลัพธ์
https://drive.google.com/file/d/1c30UvHVBH-vL76lMENOBeU4XGhoAKmkl/view?usp=sharing

## 5.สรุปผล
เปิดสอง LED: leds[i].ON(); และ leds[i + direction].ON(); จะเปิดไฟ LED สองดวงที่อยู่ติดกัน
ปิดสอง LED: leds[i].OFF(); และ leds[i + direction].OFF(); จะปิดไฟ LED สองดวงในตำแหน่งที่เพิ่งเปิดไว้
