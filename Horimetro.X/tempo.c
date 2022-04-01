/*
 * File:   tempo.c
 * Author: 21193459
 *
 * Created on 1 de Abril de 2022, 08:40
 */


#include <xc.h>
#include "tempo.h"
#include "timers.h"

char min = 0, seg = 0, hor = 0, dia = 0;

void tempo (void)
{
    if( T0_status() == 0 )
    {
        T0_start(1000);
        seg = ++seg % 60;
        if( seg == 0 )
        {
           min= ++min % 60;
           if( min == 0)
          {
              hor = ++hor %24;
              if(hor == 0)
              {
                  dia = ++dia;
              }
          } 
        }
    }
}