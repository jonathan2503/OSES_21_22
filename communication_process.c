#include <rtthread.h>
#include <rtdevice.h>
#include <rtdbg.h>

#include "communication_process.h"

void communication(int direction){

   switch (direction){

   case 0:
       rt_pin_write(PIN_COM_0, PIN_LOW);
       rt_pin_write(PIN_COM_1, PIN_LOW);
       break;

   case 1:
         rt_pin_write(PIN_COM_0, PIN_HIGH);
         rt_pin_write(PIN_COM_1, PIN_LOW);
         break;

   case 2:
         rt_pin_write(PIN_COM_0, PIN_LOW);
         rt_pin_write(PIN_COM_1, PIN_HIGH);
         break;

   case 3:
         rt_pin_write(PIN_COM_0, PIN_HIGH);
         rt_pin_write(PIN_COM_1, PIN_HIGH);
         break;

   }
}
