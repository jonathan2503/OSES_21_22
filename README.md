### OSES PROJECT
Matricola     | Name
------------- | -------------
301514 | Jonathan Damone
294974  |  Lorenzo  Mastrorosa
227170 |  Maciej    Lampart|


One sentence  Robot Proposal :
A robot has to navigate from point A to point B. 
The environment is simulated through a matrix where 0 is terrain that can be crossed a 1 is an obstacle that must be avoided. 
The matrix is stored on a file or, if reading the file ends up being too slow, on a variable in memory.
The robot can move only in 8 directions (up, down, left, right and diagonals).
## Motor instruction

```c

/*
 * *******************ISTRUZIONI D'USO***********************
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
 */
 
#define pin_neg  17
#define pin_pos  20
#define pin_rota_neg  15
#define pin_rota_pos  14
#define pin_end_blink  16
#define pin_fow  18

/*
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
 *
 */
```
