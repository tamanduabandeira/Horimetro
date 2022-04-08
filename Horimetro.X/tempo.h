#ifndef TEMPO_H
#define TEMPO_H

struct temporizadorT
{
    char hab;
    char seg;
    char min;
    char hor;
    int  dia;
};

void temporizar( struct temporizadorT * t );
void habTemporizador( struct temporizadorT * t, unsigned char h );
void resetTemporizador( struct temporizadorT * t );

#endif