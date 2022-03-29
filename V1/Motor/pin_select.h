
#ifndef APPLICATIONS_PIN_SELECT_H_
#define APPLICATIONS_PIN_SELECT_H_
#include <rtthread.h>
#include <rtdevice.h>
#include <rtdbg.h>



//motors
#define pin_neg   6  //A6
#define pin_pos   7   //A7

#define pin_rota_neg   8   //A8
#define pin_rota_pos   9  //A9

#define pin_fow       10  //A10

#define pin_end_blink 11   //A11



// INPUT SENSORI A RECIVER

#define PIN_SENS_UP 17    //B1
#define PIN_SENS_DOWN 18  //B2
#define PIN_SENS_LEFT 19    //B3
#define PIN_SENS_RIGHT 20   //B4


// NEW DIR
#define PIN_COM_0 0          //A0
#define PIN_COM_1 1          //A1

// PIN DI SEGNALE CHE receiver HA FINITO   sender <= receiver
#define PIN_PROTOCOL_1 2    //A2

// PIN DI SEGNALE CHE SENDER HA FINITO   sender => receiver
#define PIN_PROTOCOL_2 3    //A3


#define PIN_CONTROL_1 21    //B5
#define PIN_CONTROL_2 22    //B6


/*
    __STM32_PIN(0 ,  A, 0 ),
    __STM32_PIN(1 ,  A, 1 ),
    __STM32_PIN(2 ,  A, 2 ),
    __STM32_PIN(3 ,  A, 3 ),
    __STM32_PIN(4 ,  A, 4 ),
    __STM32_PIN(5 ,  A, 5 ),
    __STM32_PIN(6 ,  A, 6 ),
    __STM32_PIN(7 ,  A, 7 ),
    __STM32_PIN(8 ,  A, 8 ),
    __STM32_PIN(9 ,  A, 9 ),
    __STM32_PIN(10,  A, 10),
    __STM32_PIN(11,  A, 11),
    __STM32_PIN(12,  A, 12),
    __STM32_PIN(13,  A, 13),
    __STM32_PIN(14,  A, 14),
    __STM32_PIN(15,  A, 15),


     __STM32_PIN(16,  B, 0),
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




#endif /* APPLICATIONS_PIN_SELECT_H_ */
