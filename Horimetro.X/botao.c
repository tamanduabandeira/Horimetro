#include <xc.h>

#define B0      PORTAbits.RA0
#define B1      PORTAbits.RA1
#define B2      PORTAbits.RA2
#define B3      PORTAbits.RA3


void botao_init( void )
{
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
}


// ************************** Botão 0

char b0( void )
{
    return( B0 );
}

char b0Anterior=0;
char b0_bordaSubida( void )
{
    // b0: 000000000001111111111111100000000
    // ret:000000000001000000000000000000000
    char aux;
    aux = B0 && !b0Anterior;
    b0Anterior = B0;
    return( aux );
}
char b0_bordaDescida( void )
{
    // b0: 000000000001111111111111100000000
    // ret:000000000000000000000000010000000
    char aux;
    aux = !B0 && b0Anterior;
    b0Anterior = B0;
    return( aux );
}
char b0_borda( void )
{
    // b0: 000000000001111111111111100000000
    // ret:000000000001000000000000010000000
    char aux;
    aux = (B0 && !b0Anterior) || (!B0 && b0Anterior);
    b0Anterior = B0;
    return( aux );
}



// ************************** Botão 1

char b1( void )
{
   return( B1 );
}

char b1Anterior=0;
char b1_bordaSubida( void )
{
    // b1: 000000000001111111111111100000000
    // ret:000000000001000000000000000000000
    char aux;
    aux = B1 && !b1Anterior;
    b1Anterior = B1;
    return( aux );
}
char b1_bordaDescida( void )
{
    // b1: 000000000001111111111111100000000
    // ret:000000000000000000000000010000000
    char aux;
    aux = !B1 && b1Anterior;
    b1Anterior = B1;
    return( aux );
}
char b1_borda( void )
{
    // b1: 000000000001111111111111100000000
    // ret:000000000001000000000000010000000
    char aux;
    aux = (B1 && !b1Anterior) || (!B1 && b1Anterior);
    b1Anterior = B1;
    return( aux );
}

char b2( void )
{
    return( B2 );
}

char b2Anterior=0;
char b2_bordaSubida( void )
{
    // b0: 000000000001111111111111100000000
    // ret:000000000001000000000000000000000
    char aux;
    aux = B2 && !b2Anterior;
    b2Anterior = B2;
    return( aux );
}
char b2_bordaDescida( void )
{
    // b0: 000000000001111111111111100000000
    // ret:000000000000000000000000010000000
    char aux;
    aux = !B2 && b2Anterior;
    b2Anterior = B2;
    return( aux );
}
char b2_borda( void )
{
    // b0: 000000000001111111111111100000000
    // ret:000000000001000000000000010000000
    char aux;
    aux = (B2 && !b2Anterior) || (!B2 && b2Anterior);
    b2Anterior = B2;
    return( aux );
}

char b3( void )
{
    return( B3 );
}

char b3Anterior=0;
char b3_bordaSubida( void )
{
    // b0: 000000000001111111111111100000000
    // ret:000000000001000000000000000000000
    char aux;
    aux = B3 && !b3Anterior;
    b3Anterior = B3;
    return( aux );
}
char b3_bordaDescida( void )
{
    // b0: 000000000001111111111111100000000
    // ret:000000000000000000000000010000000
    char aux;
    aux = !B3 && b3Anterior;
    b3Anterior = B3;
    return( aux );
}
char b3_borda( void )
{
    // b0: 000000000001111111111111100000000
    // ret:000000000001000000000000010000000
    char aux;
    aux = (B3 && !b3Anterior) || (!B3 && b3Anterior);
    b3Anterior = B3;
    return( aux );
}
