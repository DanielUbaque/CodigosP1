#include <xc.h>
#include "config.h"
#include "funtions.h"

/**
 * Se encarga de interpretar el valor obtenido del ADC a BCD
 * @param iADC lectura ADC
 * @return arreglo de 3 elementos que reprecentan el valor
 * BCD de la lectura de entrada, siendo el primer valor
 * el menos significativo o la lectura de 10 mV
 */
unsigned short *mathBCD(unsigned long iADC) {

    static unsigned short r[3];
    r[0] = ((iADC * 1000) / 1024) % 10;
    r[1] = (((iADC * 1000) / 1024) / 10) % 10;
    r[2] = (((iADC * 1000) / 1024) / 10) / 10;

    return r;

}

/**
 * Comienza la converción del ADC, al final del proceso se desactiva
 * @return la lectura obtenida del ADC
 */
void readADC(void) {
    
    ADCON0bits.ADON = 1;        //Habilitamos el ADC
        
    ADCON0bits.GO_nDONE = 1;    //Iniciamos la convercion
}


/**
 * Trasmite un caracter por el pin TX
 * @param c caracter a trasmitir
 */
void UART_write(unsigned char c) {
    TXREG = c;
}

/**
 * Realiza la trasmicion de una cadena de caracteres
 * @param cadena cadena de caracteres a transmitir
 */
void printUART(int n, unsigned char* cadena)
{
    static int i = 0;
    if (i == n)
    {
        i = 0;
        SLEEP();
        return;
    }
    
    UART_write(*(cadena + i));
    i = i+1;
}

/**
 * Genera una cadena de caracteres
 * @param a Digito mas significativo
 * @param b Digito del medio
 * @param c DIgito menos significativo
 * @return cadena de caracteres de entrada formateada para
 * la trasmicion serie
 */
unsigned char *ASCII_Con(unsigned short a, unsigned short b, unsigned short c) {
    static unsigned char r[4];
    r[0] = (char) (a + 48);
    r[1] = (char) (b + 48);
    r[2] = (char) (c + 48);
    r[3] = '\n';

    return r;
}