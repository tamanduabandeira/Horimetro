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


char min = 0, seg = 0;


void main(void)
{
    lcd_init();
    T0_init();

    lcd_print(0,0,"Tempo:   :   ");
    T0_start(1000);

    while( 1 )
    {
        if( T0_status() == 0 )
        {
            T0_start(1000);
            seg = ++seg % 60;
            if( seg == 0 )
            {
                ++min;
            }
        }
        lcd_num(0, 7, min, 2);
        lcd_num(0,10, seg, 2);
    }
}

void main2(void)
{
    lcd_init();

    T0_init();
    T1_init();
    T2_init(); 

    lcd_print(0,0," T0    T1    T2 ");
    T0_start(30000);
    T1_start(20000);
    T2_start(15000);

    while( 1 )
    {
        lcd_num(1,0, (signed)T0_status(), 5);
        lcd_num(1,6, (signed)T1_status(), 5);
        lcd_num(1,12,(signed)T2_status(), 5);
    }
}