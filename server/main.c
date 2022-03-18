/*
-1) DO I DATI AL SENSORE
-2) AUTORIZZO LETTURA DATI ATTRAVERSO UN PROTOCOLLO
.
.
.
-3) ASPETTO L'AUTORIZZAZIONE A LEGGERE LA DIREZIONE
-4) LEGGO LA DIREZIONE



 */
#include <stdio.h>
#include <stdlib.h>
#include <rtthread.h>
#include <rtdevice.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#define PIN_PROTOCOL_1 2
#define PIN_PROTOCOL_2 3

#define PIN_COM_0 0
#define PIN_COM_1 1

#define PIN_SENS_UP 17
#define PIN_SENS_DOWN 18
#define PIN_SENS_LEFT 19
#define PIN_SENS_RIGHT 20

#define ROW_NUM 10
#define COL_NUM 10

int matrix[ROW_NUM][COL_NUM]=
       {{0, 0, 0, 0, 1, 0, 1, 0, 1, 1},
        {0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
        {1, 1, 0, 1, 1, 0, 0, 0, 1, 0}};

int main(void)
{


    int i, j;

    rt_pin_mode(PIN_PROTOCOL_1, PIN_MODE_INPUT);
    rt_pin_mode(PIN_PROTOCOL_2, PIN_MODE_OUTPUT);

    rt_pin_mode(PIN_COM_0, PIN_MODE_INPUT);
    rt_pin_mode(PIN_COM_1, PIN_MODE_INPUT);

    rt_pin_mode(PIN_SENS_UP, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_SENS_DOWN, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_SENS_LEFT, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_SENS_RIGHT, PIN_MODE_OUTPUT);

    rt_pin_write(PIN_PROTOCOL_2, PIN_LOW);

    i=0;//indice verticale
    j=0;//indice orizzontale


   while (1){

   //1) DO I DATI AL SENSORE
   if ((i-1<0)|| (matrix[i-1][j]==1))
       rt_pin_write(PIN_SENS_UP,PIN_HIGH);
   else
       rt_pin_write(PIN_SENS_UP,PIN_LOW);

   if ((i+1>ROW_NUM)|| (matrix[i+1][j]==1))
       rt_pin_write(PIN_SENS_DOWN,PIN_HIGH);
      else
          rt_pin_write(PIN_SENS_DOWN,PIN_LOW);

   if ((j-1<0)|| (matrix[i][j-1]==1))
       rt_pin_write(PIN_SENS_LEFT,PIN_HIGH);
      else
          rt_pin_write(PIN_SENS_LEFT,PIN_LOW);

   if ((j+1>COL_NUM)|| (matrix[i][j+1]==1))
           rt_pin_write(PIN_SENS_RIGHT,PIN_HIGH);
      else
          rt_pin_write(PIN_SENS_RIGHT,PIN_LOW);


   //2)AUTORIZZO LETTURA DATI
           rt_pin_write(PIN_PROTOCOL_2, PIN_HIGH);
           rt_thread_delay(200);

           //3)ASPETTO CHE IL CLIENT MI DIA L'AUTORIZZAZIONE A LEGGERE I DATI DELLA DIREZIONE
          while(!rt_pin_read(PIN_PROTOCOL_1));

          //4)LEGGO I DATI
          if ((rt_pin_read(PIN_COM_0))&&(rt_pin_read(PIN_COM_1))) //UP
              i-=1;
          else if ((rt_pin_read(PIN_COM_0))&&(!rt_pin_read(PIN_COM_1)))//DOWN
              i+=1;
          else if ((!rt_pin_read(PIN_COM_0))&&(rt_pin_read(PIN_COM_1)))//LEFT
              j-=1;
          else if ((rt_pin_read(PIN_COM_0))&&(!rt_pin_read(PIN_COM_1)))//RIGHT
              j+=1;

          //NEGO L'AUTORIZZAZIONE A LEGGERE I DATI DEL SENSORE
          rt_pin_write(PIN_PROTOCOL_2, PIN_LOW);
          rt_thread_delay(200);

   }

    return RT_EOK;
}


