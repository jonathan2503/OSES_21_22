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

void receive_data( int* i,int* j);
void send_data(int i, int j);
void all_pin_low();
void all_pin_high();

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
           all_pin_low();
           rt_thread_delay(200);
           send_data(i,j);
           rt_thread_delay(200);
           rt_pin_write(PIN_PROTOCOL_2, PIN_HIGH);


           rt_thread_delay(200);


          while(!rt_pin_read(PIN_PROTOCOL_1)); //ASPETTO CHE PIN_PROTOCOL1 DIVENTI ALTO
          receive_data(&i,&j);
          rt_thread_delay(200);

          rt_pin_write(PIN_PROTOCOL_2, PIN_LOW);
          while(rt_pin_read(PIN_PROTOCOL_1));   //ASPETTO CHE PIN_PROTOCOL1 DIVENTI BASSO
          //all_pin_low();//da eliminare dopo
   }

    return RT_EOK;
}

//MOSTRO I DATI IN OUTPUT, funziona correttamente
void send_data(int i, int j){
if ((i-1<0)|| (matrix[i-1][j]==1))
      rt_pin_write(PIN_SENS_UP,PIN_HIGH);
  else
      rt_pin_write(PIN_SENS_UP,PIN_LOW);

  if ((i+1>=ROW_NUM)|| (matrix[i+1][j]==1))
      rt_pin_write(PIN_SENS_DOWN,PIN_HIGH);
     else
         rt_pin_write(PIN_SENS_DOWN,PIN_LOW);

  if ((j-1<0)|| (matrix[i][j-1]==1))
      rt_pin_write(PIN_SENS_LEFT,PIN_HIGH);
  else
         rt_pin_write(PIN_SENS_LEFT,PIN_LOW);

  if ((j+1>=COL_NUM)|| (matrix[i][j+1]==1))
          rt_pin_write(PIN_SENS_RIGHT,PIN_HIGH);
     else
         rt_pin_write(PIN_SENS_RIGHT,PIN_LOW);
}




void receive_data( int* i,int* j){
          if ((rt_pin_read(PIN_COM_0)==PIN_LOW)&&(rt_pin_read(PIN_COM_1)==PIN_LOW)){ //UP
              *i-=1;
              }

          else if ((rt_pin_read(PIN_COM_0)==PIN_HIGH)&&(rt_pin_read(PIN_COM_1)==PIN_LOW)){//DOWN
              *i+=1;

          }
          else if ((rt_pin_read(PIN_COM_0)==PIN_LOW)&&(rt_pin_read(PIN_COM_1)==PIN_HIGH)){//LEFT
              *j-=1;

          }
          else if ((rt_pin_read(PIN_COM_0)==PIN_HIGH)&&(rt_pin_read(PIN_COM_1)==PIN_HIGH)){//RIGHT
              *j+=1;

          }
          else{
              *i=-2;
              *j=-2;

          }
}

void all_pin_low(){
    rt_pin_write(PIN_SENS_UP,PIN_LOW);
    rt_pin_write(PIN_SENS_DOWN,PIN_LOW);
    rt_pin_write(PIN_SENS_LEFT,PIN_LOW);
    rt_pin_write(PIN_SENS_RIGHT,PIN_LOW);
}

void all_pin_high(){
    rt_pin_write(PIN_SENS_UP,PIN_HIGH);
        rt_pin_write(PIN_SENS_DOWN,PIN_HIGH);
        rt_pin_write(PIN_SENS_LEFT,PIN_HIGH);
        rt_pin_write(PIN_SENS_RIGHT,PIN_HIGH);
}


