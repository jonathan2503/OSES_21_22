
/*
 * *******************ISTRUZIONI D'USO  motori***********************
 * 1) impostare i pin del chip:
 *
 * - posizionamento dell' angolo della ruota anteriore
 *   pin_neg   //pin per rotazione negativa
 *   pin_pos   //pin per rotazione positiva  | -> anteriore
 *
 * -rotazione  ruota anteriore per raggiungere la direzione con tutta la macchina
 * pin_rota_neg //pin per rotazione negativa  |
 * pin_rota_pos //pin per rotazione positiva  | -> anteriore
 *
 * -motore di avanzamento nello spazio:
 * pin_fow  //pin per definire la fine del processo di rotazione|

#define pin_neg   25
#define pin_pos   26
#define pin_rota_neg   27
#define pin_rota_pos   29

#define pin_fow       30
#define pin_end_blink 31

 * *******************ISTRUZIONI D'USO***********************
 * 2) Chiamare le funzioni
 *    2.1) IMPORTANTE inizializare il sistema di orientamento
 *         ctrl_dir (35);
 *    2.2) ora devi solo segliere dove vuoi andare
 *
 *         ctrl_dir (0); //avanti
 *         ctrl_dir (1); //Destra
 *         ctrl_dir (2); //Sinistra
 *         ctrl_dir (3); //Dietro
 *
 *     2.3)una volta che hai chiamato la funzione questa si occupa
 *         sia di direzionare la macchina e poi avanza di uno slot
 *         verso la direzione scelta
 */




#ifndef APPLICATIONS_GKJ_H_
#define APPLICATIONS_GKJ_H_

#include <rtthread.h>
#include <rtdevice.h>
#include <rtdbg.h>
#include <stdio.h>
#include  "pin_select.h"

#define av 0
#define dx 1
#define sx 2
#define di 3

//altri moduli]
int bit_angolo ;
//mio output
int bit_stat_angolo;
//-------------interni--------------
//registro dello status attuale
int bit_reg ;
//controllo dell'angolazione
int tht ;
//funzione di inclinazione





void ctrl_dir ( int bit_angolo);
void theta(int tht);
void fow(void);

#endif /* APPLICATIONS_GKJ_H_ */
