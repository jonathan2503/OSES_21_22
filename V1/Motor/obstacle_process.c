#include <rtthread.h>
#include <rtdevice.h>
#include <rtdbg.h>


#include "obstacle_process.h"

void obstacle(int obstacles[]){
if (rt_pin_read(PIN_SENS_UP))
    obstacles[0]=1;
else
    obstacles[0]=0;

if (rt_pin_read(PIN_SENS_DOWN))
    obstacles[1]=1;
else
    obstacles[1]=0;

if (rt_pin_read(PIN_SENS_LEFT))
    obstacles[2]=1;
else
    obstacles[2]=0;

if (rt_pin_read(PIN_SENS_RIGHT))
    obstacles[3]=1;
else
    obstacles[3]=0;
}
