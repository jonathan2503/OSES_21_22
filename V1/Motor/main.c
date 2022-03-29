
#include <rtthread.h>
#include <rtdevice.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#define LED0_PIN    10
#include <rtdbg.h>

#include "obstacle_process.h"
#include "communication_process.h"
#include "navigate.h"
#include "pin_select.h"
#include "motor.h"


#define THREAD_STACK_SIZE   1024
#define THREAD_PRIORITY     20
#define THREAD_TIMESLICE    1

#define START_ROW 0
#define START_COL 0
#define DEST_ROW 9
#define DEST_COL 9



static void thread_obstacle(void* parameter);
static void thread_navigation(void* parameter);
static void thread_motion(void* parameter);
static void thread_communication(void* parameter);
int sample(void);

static rt_thread_t tid = RT_NULL;
struct rt_semaphore sem_1;
struct rt_semaphore sem_2;
struct rt_semaphore sem_3;
struct rt_semaphore sem_4;

int obstacles[4]={0};
int direction;


int main(void)
{

    //DOVRO' INIZIALIZZARE I PIN DI OUTPUT
    rt_pin_mode(PIN_COM_0, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_COM_1, PIN_MODE_OUTPUT);

    rt_pin_mode(PIN_SENS_UP, PIN_MODE_INPUT);
    rt_pin_mode(PIN_SENS_DOWN, PIN_MODE_INPUT);

    rt_pin_mode(PIN_SENS_LEFT, PIN_MODE_INPUT);
    rt_pin_mode(PIN_SENS_RIGHT, PIN_MODE_INPUT);

    rt_pin_mode(PIN_PROTOCOL_1, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_PROTOCOL_2, PIN_MODE_INPUT);

    rt_pin_mode(PIN_CONTROL_1, PIN_MODE_OUTPUT);
    rt_pin_mode(PIN_CONTROL_2, PIN_MODE_OUTPUT);

    rt_pin_write(PIN_COM_0, PIN_LOW);
    rt_pin_write(PIN_COM_1, PIN_LOW);

    rt_pin_write(PIN_PROTOCOL_1, PIN_LOW);

    rt_pin_write(PIN_CONTROL_1, PIN_LOW);
    rt_pin_write(PIN_CONTROL_2, PIN_LOW);

    sample();


    return 0;
}

int sample(void)
{

    rt_sem_init(&sem_1, "lock1",     1,      RT_IPC_FLAG_FIFO);
    rt_sem_init(&sem_2, "lock2",     0,      RT_IPC_FLAG_FIFO);
    rt_sem_init(&sem_3, "lock2",     0,      RT_IPC_FLAG_FIFO);
    rt_sem_init(&sem_4, "lock2",     0,      RT_IPC_FLAG_FIFO);


    tid = rt_thread_create("motion",
                            thread_motion, (void*)1,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);



    tid = rt_thread_create("obstacle",
                            thread_obstacle, (void*)1,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);



    tid = rt_thread_create("navigation",
                            thread_navigation, (void*)2,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);



    tid = rt_thread_create("communication",
                              thread_communication, (void*)2,
                              THREAD_STACK_SIZE,
                              THREAD_PRIORITY, THREAD_TIMESLICE);
      if (tid != RT_NULL)
          rt_thread_startup(tid);

  return 0;
}





static void thread_obstacle(void* parameter)
{

    while (1){

   rt_sem_take(&sem_1, RT_WAITING_FOREVER); //it takes the semaphore
   while (!rt_pin_read(PIN_PROTOCOL_2)); //ASPETTO CHE PIN_PROTOCOL2 DIVENTI ALTO
      obstacle(obstacles);
   rt_sem_release(&sem_2);
   rt_thread_mdelay(20);
    }
}



/* in base agli obstacles individua la direzione da seguire*/
static void thread_navigation(void* parameter)
{
    int a;
    initNavigation(START_ROW,START_COL,DEST_ROW,DEST_COL);
    while (1){
    rt_sem_take(&sem_2, RT_WAITING_FOREVER);
    a=navigate(obstacles,&direction);
    if (a==0){
       rt_pin_write(PIN_CONTROL_1, PIN_HIGH);
       while(1);
    }
    else if (direction==4){
        rt_pin_write(PIN_CONTROL_2, PIN_HIGH);
        while(1);
    }
   rt_sem_release(&sem_3);
   rt_thread_mdelay(20);
    }
}

/*legge la direzione passata da navigation e comanda i motori di conseguenza*/
static void thread_motion(void* parameter){
    while (1){
    rt_sem_take(&sem_3, RT_WAITING_FOREVER);
    //function
    if (direction == 0) {
        ctrl_dir (0);
        //avanti
    }
   else  if (direction == 1)
   {
       ctrl_dir (3);
       //dw
    }
   else  if (direction == 2)
   {
       ctrl_dir (2);
       //sx
    }

   else  if (direction == 3)
   {
       ctrl_dir (1);
       //sx
    }
   else {ctrl_dir (1);
                 }

     //end function
   rt_sem_release(&sem_4);
   rt_thread_mdelay(20);
    }
}


//viene comunicata la direzione(o il punto nella mappa) in cui siamo attualmente
static void thread_communication(void* parameter){
   // int i=0;
       while(1){

      rt_sem_take(&sem_4, RT_WAITING_FOREVER);
      //function
      communication(direction);
      //end function
      rt_sem_release(&sem_1);
      }
}




