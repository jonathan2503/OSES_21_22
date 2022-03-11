#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <rtthread.h>
#include "obstacle_process.h"
#include "navigation_process.h"
#include "motion_process.h"
#include "communication_process.h"

#define THREAD_STACK_SIZE   1024
#define THREAD_PRIORITY     20
#define THREAD_TIMESLICE    1
static void thread_entry(void* parameter);
int sample(void);


static void thread_obstacle(void* parameter);
static void thread_navigation(void* parameter);
static void thread_motion(void* parameter);
static void thread_communication(void* parameter);



static rt_thread_t tid = RT_NULL;
struct rt_semaphore sem_1;
struct rt_semaphore sem_2;
struct rt_semaphore sem_3;
struct rt_semaphore sem_4;

int obstacles[8]={0};
int direction[8]={0};

int main(void)
{
    printf("hello rt-thread\n");
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
   rt_kprintf("thread_obstacle starting... \n");
  // obstacle(parameter,obstacles);
   rt_sem_release(&sem_2);
   rt_thread_mdelay(20);
    }
   }



/* in base agli obstacles individua la direzione da seguire*/
static void thread_navigation(void* parameter)
{

    while (1){
    rt_sem_take(&sem_2, RT_WAITING_FOREVER);
    rt_kprintf("thread_navigation starting...\n");
    //navigation()
   rt_sem_release(&sem_3);
   rt_thread_mdelay(20);
    }
}

/*legge la direzione passata da navigation e comanda i motori di conseguenza*/
static void thread_motion(void* parameter){
    while (1){
    rt_sem_take(&sem_3, RT_WAITING_FOREVER);
    rt_kprintf("thread_motion starting... \n");
    //motion()
   rt_sem_release(&sem_4);
   rt_thread_mdelay(20);
    }
}


//viene comunicata la direzione(o il punto nella mappa) in cui siamo attualmente
static void thread_communication(void* parameter){

    while (1){
      rt_sem_take(&sem_4, RT_WAITING_FOREVER);
      rt_kprintf("thread_communication starting...\n");
      //communication()
     rt_sem_release(&sem_1);
     rt_thread_mdelay(20);
      }
}


/*SEQUENZA:
 * 1) obstacle,
 * 2) navigation
 * 3) motion
 * 4) communication (location)
 *
 *
 *
 */

