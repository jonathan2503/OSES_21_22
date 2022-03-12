#include "motor.h"


void ctrl_dir (int bit_angolo)
{



       switch  (bit_angolo)
       {

           case 0:

                  if (bit_reg = av )
                  {

                  theta(0);//rot 0
                  }
                  else if (bit_reg = dx)
                  {

                  theta(9);//rot -90
                  bit_reg = av;

                  }
                  else if (bit_reg = sx) {

                      theta(90);//rot 90
                      bit_reg = av;

                  }
                  else if (bit_reg = di) {
                      theta(180);//rot 180
                      bit_reg = av;

                  }
                  else {
                      theta(0);//rot 0

                  }
              break;

           case 1: //dx

                  if (bit_reg = av ) {

                  theta(90);//rot -90
                  bit_reg = dx;
                  }
                  else if (bit_reg = dx) {

                  theta(0);//0


                  }
                  else if (bit_reg = sx) {

                      theta(180);//rot 90
                      bit_reg = dx;

                  }
                  else if (bit_reg = di) {
                      theta(180);//rot 180
                      bit_reg = dx;

                  }
                  else {
                      theta(9);//rot 0

                  }

             break;

           case 2: // sx

                  if (bit_reg = av ) {

                  theta(90);//rot -90
                  bit_reg = sx;
                  }
                  else if (bit_reg = dx) {

                  theta(180);//0
                  bit_reg = sx;

                  }
                  else if (bit_reg = sx) {

                      theta(0);//rot 90


                  }
                  else if (bit_reg = di) {
                      theta(9);//rot -90
                      bit_reg = sx;

                  }
                  else {
                      theta(0);//rot 0

                  }

             break;

           case 3: // di

                             if (bit_reg = av ) {

                             theta(180);//rot 180
                             bit_reg = di;
                             }
                             else if (bit_reg = dx) {

                             theta(90);//0
                             bit_reg = di;

                             }
                             else if (bit_reg = sx) {

                                 theta(9);//rot 90
                                 bit_reg = di;


                             }
                             else if (bit_reg = di) {
                                 theta(0);//rot -90


                             }
                             else {
                                 theta(0);//rot 0

                             }

                        break;
           default:
               theta(0);//rot 0
       }










void theta(int tht)
{
    rt_pin_mode(pin_rota_neg, PIN_MODE_OUTPUT);
    rt_pin_mode(pin_rota_pos, PIN_MODE_OUTPUT);
    rt_pin_mode(pin_pos, PIN_MODE_OUTPUT);
    rt_pin_mode(pin_neg, PIN_MODE_OUTPUT);
    rt_pin_mode(pin_end_blink, PIN_MODE_OUTPUT);


    switch (tht){
                  case 90:
                      rt_pin_write(pin_end_blink, PIN_LOW);
                      //+90

                   rt_pin_write(pin_pos, PIN_HIGH);
                   rt_thread_mdelay(1500);
                   rt_pin_write(pin_pos, PIN_LOW);
                    //rotazione pos
                   rt_pin_write(pin_rota_pos, PIN_HIGH);
                   rt_thread_mdelay(5000);
                   rt_pin_write(pin_rota_pos, PIN_LOW);
                   // ristabilisco la posizione frontale
                   rt_pin_write(pin_neg, PIN_HIGH);
                   rt_thread_mdelay(1500);
                   rt_pin_write(pin_neg, PIN_LOW);
                   //ok end
                   rt_thread_mdelay(100);
                   rt_pin_write(pin_end_blink, PIN_HIGH);

                       break;
                  case 180:
                      rt_pin_write(pin_end_blink, PIN_LOW);
                                  //+180
                                  rt_pin_write(pin_pos, PIN_HIGH);
                                  rt_thread_mdelay(1500);
                                  rt_pin_write(pin_pos, PIN_LOW);
                                  //rotazione pos
                                 rt_pin_write(pin_rota_pos, PIN_HIGH);
                                 rt_thread_mdelay(10000);
                                 rt_pin_write(pin_rota_pos, PIN_LOW);
                                 // ristabilisco la posizione frontale
                                 rt_pin_write(pin_neg, PIN_HIGH);
                                 rt_thread_mdelay(1500);
                                 rt_pin_write(pin_neg, PIN_LOW);
                                 //ok end
                                 rt_thread_mdelay(100);
                                 rt_pin_write(pin_end_blink, PIN_HIGH);
                                      break;
                              case 270:
                                  rt_pin_write(pin_end_blink, PIN_LOW);
                                  //+270
                                  rt_pin_write(pin_pos, PIN_HIGH);
                                  rt_thread_mdelay(1500);
                                  rt_pin_write(pin_pos, PIN_LOW);
                                  //rotazione pos
                                 rt_pin_write(pin_rota_pos, PIN_HIGH);
                                 rt_thread_mdelay(15000);
                                 rt_pin_write(pin_rota_pos, PIN_LOW);
                                 // ristabilisco la posizione frontale
                                 rt_pin_write(pin_neg, PIN_HIGH);
                                 rt_thread_mdelay(1500);
                                 rt_pin_write(pin_neg, PIN_LOW);
                                 //ok end
                                 rt_thread_mdelay(100);
                                 rt_pin_write(pin_end_blink, PIN_HIGH);
                                      break;
                  //negative way

                              case 9:
                                  rt_pin_write(pin_end_blink, PIN_LOW);
                                  //-90
                                  rt_pin_write(pin_neg, PIN_HIGH);
                                  rt_thread_mdelay(1500);
                                  rt_pin_write(pin_neg, PIN_LOW);
                                  //rotazione neg
                                 rt_pin_write(pin_rota_neg, PIN_HIGH);
                                 rt_thread_mdelay(5000);
                                 rt_pin_write(pin_rota_neg, PIN_LOW);
                                 // ristabilisco la posizione frontale
                                 rt_pin_write(pin_pos, PIN_HIGH);
                                 rt_thread_mdelay(1500);
                                 rt_pin_write(pin_pos, PIN_LOW);
                                 //ok end
                                 rt_thread_mdelay(100);
                                 rt_pin_write(pin_end_blink, PIN_HIGH);
                                      break;
                              case 18:
                                  rt_pin_write(pin_end_blink, PIN_LOW);
                                  //-180
                                  rt_pin_write(pin_neg, PIN_HIGH);
                                  rt_thread_mdelay(1500);
                                  rt_pin_write(pin_neg, PIN_LOW);
                                  //rotazione neg
                                 rt_pin_write(pin_rota_neg, PIN_HIGH);
                                 rt_thread_mdelay(10000);
                                 rt_pin_write(pin_rota_neg, PIN_LOW);
                                 // ristabilisco la posizione frontale
                                 rt_pin_write(pin_pos, PIN_HIGH);
                                 rt_thread_mdelay(1500);
                                 rt_pin_write(pin_pos, PIN_LOW);
                                 //ok end
                                 rt_thread_mdelay(100);
                                 rt_pin_write(pin_end_blink, PIN_HIGH);

                                      break;
                              case 27:
                                  rt_pin_write(pin_end_blink, PIN_LOW);
                                  //-270
                                  rt_pin_write(pin_neg, PIN_HIGH);
                                  rt_thread_mdelay(1500);
                                  rt_pin_write(pin_neg, PIN_LOW);
                                  //rotazione neg
                                 rt_pin_write(pin_rota_neg, PIN_HIGH);
                                 rt_thread_mdelay(15000);
                                 rt_pin_write(pin_rota_neg, PIN_LOW);
                                 // ristabilisco la posizione frontale
                                 rt_pin_write(pin_pos, PIN_HIGH);
                                 rt_thread_mdelay(1500);
                                 rt_pin_write(pin_pos, PIN_LOW);
                                 //ok end
                                 rt_thread_mdelay(100);
                                 rt_pin_write(pin_end_blink, PIN_HIGH);
                                      break;



                              default:
                                  rt_pin_write(pin_end_blink, PIN_LOW);
                                  rt_pin_write(pin_pos, PIN_HIGH);
                                  rt_thread_mdelay(10);
                                  rt_pin_write(pin_pos, PIN_LOW);
                                  rt_pin_write(pin_neg, PIN_HIGH);
                                  rt_thread_mdelay(10);
                                  rt_pin_write(pin_neg, PIN_LOW);
                                  //ok end
                                  rt_thread_mdelay(100);
                                  rt_pin_write(pin_end_blink, PIN_LOW);
    }
}
    }

void fow()
{
    rt_pin_mode(pin_fow, PIN_MODE_OUTPUT);
    rt_pin_write(pin_fow, PIN_HIGH);
    rt_thread_mdelay(5000);
    rt_pin_write(pin_fow, PIN_LOW);

}



