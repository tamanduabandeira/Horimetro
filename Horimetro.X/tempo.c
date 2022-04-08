/*
 * File:   tempo.c
 * Author: 21193459
 *
 * Created on 1 de Abril de 2022, 08:40
 */


#include <xc.h>
#include "tempo.h"
#include "timers.h"

void temporizar( struct temporizadorT * t )
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