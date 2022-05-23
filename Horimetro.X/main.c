/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 3 de Junho de 2021, 12:38
 */

#include "config.h"
#include <xc.h>
#include "lcd.h"
#include "timers.h"
#include "tempo.h"
#include "botao.h"
#include "teclado.h"
#include "eeprom.h"
<<<<<<< HEAD
#include "delay.h"
=======
>>>>>>> ab6b716bf61b999fd6ecb4cc8babc5c5259ca237


struct temporizadorT tempo[4];

void main (void)
{
<<<<<<< HEAD
  // char teste[]= "Teste:            ";
  // char tecla = 0;
  // int num = 0; 
    ANSEL = 0;
    lcd_init();
    T0_init();
    botao_init();
   teclado_init();
=======
   // char teste[]= "Tecla:            ";
   // char tecla;
    
    ANSEL = 1;
    lcd_init();
    T0_init();
    botao_init();
//    teclado_init();
>>>>>>> ab6b716bf61b999fd6ecb4cc8babc5c5259ca237

    lcd_print(0,0,"00:00      00:00");
    lcd_print(1,0,"00:00      00:00");
 
    T0_start(1000);
    resetTemporizador( &tempo[0] );
    resetTemporizador( &tempo[1] );
    resetTemporizador( &tempo[2] );
    resetTemporizador( &tempo[3] );
    
    //EEPROM_write(0,0);
    tempo[0].min = EEPROM_read( 0 );

<<<<<<< HEAD
    for( char i=0; i<64; i++ )
   {
        EEPROM_write(i,0);
        delay(100);
    }
    EEPROM_write(0,0);
    tempo[0].min = EEPROM_read( 0 );
    tempo[0].hor = EEPROM_read( 1 );
    tempo[0].dia = (int)EEPROM_read( 2 );
    tempo[1].min = EEPROM_read( 10 );
    tempo[1].dia = (int)EEPROM_read( 12 );
    tempo[2].min = EEPROM_read( 20 );
    tempo[2].hor = EEPROM_read( 21 );
    tempo[2].dia = (int)EEPROM_read( 22 );
    tempo[3].min = EEPROM_read( 30 );
    tempo[3].hor = EEPROM_read( 31 );
    tempo[3].dia = (int)EEPROM_read( 32 );

    

   //while (1)
   //{
   //     tecla = teclado();
   //     teste [7] = tecla;
   //     lcd_print(0,0,teste);
   //}
=======
    

   // while (1)
   // {
    //    tecla = teclado();
    //    teste [7] = tecla;
    //    lcd_print(0,0,teste);
   // }
>>>>>>> ab6b716bf61b999fd6ecb4cc8babc5c5259ca237
    
    while( 1 )
    {
        habTemporizador( &tempo[0], b0() );
        habTemporizador( &tempo[1], b1() );
        habTemporizador( &tempo[2], b2() );
        habTemporizador( &tempo[3], b3() );

        if( T0_status() == 0 )
        {
            T0_start(1000);
        
<<<<<<< HEAD
            temporizar( &tempo[0], 0 );
            temporizar( &tempo[1], 10 );
            temporizar( &tempo[2], 20 );
            temporizar( &tempo[3], 30 );

            lcd_print(0,2, ":");
            lcd_print(0,5, " ");
            lcd_print(0,13, ":");
            lcd_print(1,2, ":");
            lcd_print(1,5, " ");
            lcd_print(1,13, ":");

            lcd_num(0, 0, tempo[0].min, 2);
            lcd_num(0, 3, tempo[0].seg, 2);
            EEPROM_write(0,tempo[0].min );
            EEPROM_write(1,tempo[0].hor );
            EEPROM_write(2,tempo[0].dia );
=======
            temporizar( &tempo[0] );
            temporizar( &tempo[1] );
            temporizar( &tempo[2] );
            temporizar( &tempo[3] );
        
            lcd_num(0, 0, tempo[0].hor, 2);
            lcd_num(0, 3, tempo[0].min, 2);
            EEPROM_write(0, tempo[0].min );
>>>>>>> ab6b716bf61b999fd6ecb4cc8babc5c5259ca237
            
            lcd_num(0, 11, tempo[1].min, 2);
            lcd_num(0, 14, tempo[1].seg, 2);
            EEPROM_write(10,tempo[1].min );
            EEPROM_write(11,tempo[1].hor );
            EEPROM_write(12,tempo[1].dia );

            lcd_num(1, 0, tempo[2].hor, 2);
            lcd_num(1, 3, tempo[2].min, 2);
            EEPROM_write(20,tempo[2].min );
            EEPROM_write(21,tempo[2].hor );
            EEPROM_write(22,tempo[2].dia );

            lcd_num(1, 11, tempo[3].hor, 2);
            lcd_num(1, 14, tempo[3].min, 2);
            EEPROM_write(30,tempo[3].min );
            EEPROM_write(31,tempo[2].hor );
            EEPROM_write(32,tempo[2].dia );

        }
   }
}  