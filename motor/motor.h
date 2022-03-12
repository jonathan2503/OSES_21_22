#include <rtthread.h>
#include <rtdevice.h>
#include <rtdbg.h>
#include <stdio.h>


//Direzioni amesse

//rotazione su asse ruota 1
#define pin_neg  17 //pin per rotazione negativa |
#define pin_pos  20 //pin per rotazione positiva | -> anteriore asse z
//rotazione per girare su 1
#define pin_rota_neg  15 //pin per rotazione negativa della motrice |
#define pin_rota_pos  14 //pin per rotazione positiva della motrice | -> anteriore
////rotazione per girare su 1
#define pin_end_blink  16 //pin per definire la fine del processo di rotazione|

//movimento di spostamento
#define pin_fow  18 //pin per rotazione negativa della motrice |




//altri moduli]
int bit_angolo = 0;
//mio output
int bit_stat_angolo = 0;
//-------------interni--------------
//registro dello status attuale
int bit_reg = 0;
//controllo dell'angolazione
int tht = 0;
//funzione di inclinazione

#define av 0
#define dx 1
#define sx 2
#define di 3


void ctrl_dir (int bit_angolo);
void theta(int tht);
void fow(void);

