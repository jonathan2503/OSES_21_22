#include <rtthread.h>
#include <rtdevice.h>
#include <rtdbg.h>

#include "communication_process.h"


void communication(int direction){
    all_pin_low();
    //rt_thread_delay(200);
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
   //rt_thread_delay(200);
   rt_pin_write(PIN_PROTOCOL_1,PIN_HIGH);

   //rt_thread_delay(200);
   while (rt_pin_read(PIN_PROTOCOL_2)); //ASPETTO CHE PIN_PROTOCOL2 DIVENTI BASSO
   //rt_thread_delay(200);
   rt_pin_write(PIN_PROTOCOL_1,PIN_LOW);
   //rt_thread_delay(200);

}


void all_pin_low(){
    rt_pin_write(PIN_COM_0, PIN_LOW);
    rt_pin_write(PIN_COM_1, PIN_LOW);
}
