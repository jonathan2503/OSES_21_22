# Motor 
In this folder, control techniques for motors will be analysed.

## front directional motor
motor specifications (values extracted from interpolation) are not real, they are only a modelization to show how rt thread works on this element.

| Name             | value         | U.M.         |
| -------------    | ------------- |------------- |
| nominal voltage  | 12 |V |
| Coil resistance  | 12  |Ohm |
| zero load RPM  | 10 |RPM |
| mass  | 0.4 |kg |

       
### ATTENZIONE!  BELOW THERE IS THE INPUT AND OUTPUT COMUNICATION WHITH OTHER SOFTWARE COMPONENT 

![ ](https://github.com/jonathan2503/OSES_21_22/blob/a672e2d94582ffe474bcd994bd436a63847986b9/motor/imm/okkkk.png)

this schematic allows corner control of the stimulated motor: tests have shown that the motor responds correctly to stimuli.
the simulation resulted in a constant impulse of 1.5 sec to obtain a 90 degree angle in the anti-clockwise direction 

![ ](https://github.com/jonathan2503/OSES_21_22/blob/6ad8514bd9fe83c911792a1789303c80133c11d3/motor/imm/bo.png)



### BElow the code instruction
```c
/*
    STM32F401CC
 */

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
 *
 *
 *
 *
 *
 */
```

