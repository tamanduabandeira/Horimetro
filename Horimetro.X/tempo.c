/*
 * File:   tempo.c
 * Author: 21193459
 *
 * Created on 1 de Abril de 2022, 08:40
 */


#include <xc.h>
#include "tempo.h"
#include "timers.h"
#include "eeprom.h"

void temporizar0( struct temporizadorT * t )
{
    if( t->hab )
    {
        t->seg = ++t->seg % 60;
        if( t->seg == 0 )
        {
            t->min = ++t->min % 60;
            if( t->min == 0 )
            {
                t->hor = ++t->hor % 24;
                
                if(t->hor == 0)
                {
                    t->dia++;
                }
            } 
        }
    }
}

// adrs
// X0: min
// X1: horas
// X2: dias (baixa)
// X3: dias (alta)
void temporizar( struct temporizadorT * t, unsigned char adrs )
{
    if( t->hab )
    {
        t->seg = ++(t->seg) % 60;
        if( t->seg == 0 )
        {
            t->min = ++(t->min) % 60;
            EEPROM_write( adrs+0, t->min );
            if( t->min == 0 )
            {
                t->hor = ++(t->hor) % 24;
                EEPROM_write( adrs+1, t->hor );
                if(t->hor == 0)
                {
                    (t->dia)++;
                    EEPROM_write( adrs+2, t->dia % 256 );
                    EEPROM_write( adrs+3, t->dia / 256 );
                }
            } 
        }
    }
}


void habTemporizador( struct temporizadorT * t, unsigned char h )
{
    t->hab = h;
}

void resetTemporizador( struct temporizadorT * t )
{
    t->hab = 0;
    t->seg = 0;
    t->min = 0;
    t->hor = 0;
    t->dia = 0;
}