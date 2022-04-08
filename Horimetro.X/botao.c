#include <xc.h>

#define B0      PORTDbits.RD0
#define B1      PORTDbits.RD1

void botao_init( void )
{
    TRISDbits.TRISD0 = 1;
    TRISDbits.TRISD1 = 1;
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
