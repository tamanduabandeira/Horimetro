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

struct temporizadorT tempo[4];

void main (void)
{
    lcd_init();
    T0_init();
    botao_init();

    lcd_print(0,0,"00:00      00:00");
    lcd_print(1,0,"00:00      00:00");
    T0_start(1000);
    resetTemporizador( &tempo[0] );
    resetTemporizador( &tempo[1] );
    resetTemporizador( &tempo[2] );
    resetTemporizador( &tempo[3] );

    while( 1 )
    {
        habTemporizador( &tempo[0], b0() );
        habTemporizador( &tempo[1], b1() );

        if( T0_status() == 0 )
        {
            T0_start(1000);
        
            temporizar( &tempo[0] );
            temporizar( &tempo[1] );
            temporizar( &tempo[2] );
            temporizar( &tempo[3] );
        
            lcd_num(0, 0, tempo[0].hor, 2);
            lcd_num(0, 3, tempo[0].min, 2);

            lcd_num(0, 11, tempo[1].min, 2);
            lcd_num(0, 14, tempo[1].seg, 2);

            lcd_num(1, 0, tempo[2].min, 2);
            lcd_num(1, 3, tempo[2].seg, 2);

            lcd_num(1, 11, tempo[3].min, 2);
            lcd_num(1, 14, tempo[3].seg, 2);

        }
    }
}  