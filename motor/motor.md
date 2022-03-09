# Motor 
In this folder, control techniques for motors will be analysed.

### front directional motor
this schematic allows corner control of the stimulated motor: tests have shown that the motor responds correctly to stimuli 

![] motor/imm/bo.png

```c
/*
    STM32F401CC
 */

#include <rtthread.h>
#include <rtdevice.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

int main(void)
{
    rt_pin_mode(16, PIN_MODE_OUTPUT);
    rt_pin_mode(17, PIN_MODE_OUTPUT);
    rt_pin_mode(20, PIN_MODE_OUTPUT);
    rt_pin_mode(31, PIN_MODE_OUTPUT);




         rt_pin_write(20, PIN_HIGH);
         rt_thread_mdelay(500); //5sec
         rt_pin_write(20, PIN_LOW);
         rt_thread_mdelay(100); //5sec
         rt_pin_write(17, PIN_HIGH);
         rt_thread_mdelay(500); //5sec
         rt_pin_write(17, PIN_LOW);
         rt_thread_mdelay(100); //5sec
         rt_pin_write(31, PIN_HIGH);







    return RT_EOK;
}

/*
 *  __STM32_PIN(16,  B, 0),
    __STM32_PIN(17,  B, 1),
    __STM32_PIN(18,  B, 2),
    __STM32_PIN(19,  B, 3),
    __STM32_PIN(20,  B, 4),
    __STM32_PIN(21,  B, 5),
    __STM32_PIN(22,  B, 6),
    __STM32_PIN(23,  B, 7),
    __STM32_PIN(24,  B, 8),
    __STM32_PIN(25,  B, 9),
    __STM32_PIN(26,  B, 10),
    __STM32_PIN(27,  B, 11),
    __STM32_PIN(28,  B, 12),
    __STM32_PIN(29,  B, 13),
    __STM32_PIN(30,  B, 14),
    __STM32_PIN(31,  B, 15),
 */

```

