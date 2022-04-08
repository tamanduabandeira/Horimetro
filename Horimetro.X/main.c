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


void main (void)
{
    lcd_init();
    T0_init();
    botao_init();

    lcd_print(0,0,"T1:  :  :   ");
    T0_start(1000);
    
    while( 1 )
    {
        if( b0() )
            T0_play();
        else
            T0_pause();
        tempo();
        lcd_num(0, 3, hor, 2);
        lcd_num(0, 6, min, 2);
        lcd_num(0, 9, seg, 2);
    }
}  