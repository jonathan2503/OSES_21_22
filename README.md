### OSES PROJECT



One sentence  Robot Proposal :
A robot has to navigate from point A to point B. 
The environment is simulated through a matrix where 0 is terrain that can be crossed a 1 is an obstacle that must be avoided. 
The matrix is stored on a file or, if reading the file ends up being too slow, on a variable in memory.
The robot can move only in 8 directions (up, down, left, right and diagonals).




# Demonstration:
For the source, download **v2.zip** where the two sources of rt_thread and also the proteus project are present.
below the demonstration that it works:



[![name](https://github.com/jonathan2503/OSES_21_22/blob/main/motor/imm/Screenshot%20(23).png)](https://www.youtube.com/watch?v=bR4b3S87ENY&t=13s)



## Motor 
In this folder, control techniques for motors will be analysed.

## front directional motor
motor specifications (values extracted from interpolation) are not real, they are only a modelization to show how rt thread works on this element.

| Name             | value         | U.M.         |
| -------------    | ------------- |------------- |
| nominal voltage  | 12 |V |
| Coil resistance  | 11  |Ohm |
| zero load RPM  | 30 |RPM |
| mass  | 0.1 |kg |

       
### ATTENZIONE!  BELOW THERE IS THE INPUT AND OUTPUT COMUNICATION WHITH OTHER SOFTWARE COMPONENT 

![ ](https://github.com/jonathan2503/OSES_21_22/blob/a672e2d94582ffe474bcd994bd436a63847986b9/motor/imm/okkkk.png)

this schematic allows corner control of the stimulated motor: tests have shown that the motor responds correctly to stimuli.
the simulation resulted in a constant impulse of 1.5 sec to obtain a 90 degree angle in the anti-clockwise direction 

![ ](https://github.com/jonathan2503/OSES_21_22/blob/6ad8514bd9fe83c911792a1789303c80133c11d3/motor/imm/bo.png)



### BElow the simple code 
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



         //controllo in angolazione con velocita angolare costante: [Orario]
         rt_pin_write(20, PIN_HIGH);
        // rt_thread_mdelay(1500); //90 gradi
        // rt_thread_mdelay(3000); //180 gradi
        //  rt_thread_mdelay(4500); //270 gradi
         rt_thread_mdelay(6000); //300  gradi
         rt_pin_write(20, PIN_LOW);
         
         //controllo in angolazione con velocita angolare costante: [Antiorario]
         rt_pin_write(17, PIN_HIGH);
        // rt_thread_mdelay(1500); //-90 gradi
        // rt_thread_mdelay(3000); //-180 gradi
        //  rt_thread_mdelay(4500); //-270 gradi
         rt_thread_mdelay(6000); //-300  gradi
         rt_pin_write(17, PIN_LOW);
        
        
        //led fine corsa
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

