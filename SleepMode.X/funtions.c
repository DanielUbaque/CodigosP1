
#include <xc.h>
#include "config.h"
#include "funtions.h"

//Convertimos la lectura del ADC a un arreglo de tres posiciones, cada posicion es un digito 
//r[2] es el digito mas significativo unidades 1 V
//r[1] unidades 100 mV
//r[0] es el digito menos significativo unidades 10 mV

int* BinTOBcd(long iADC)
{

    static int r[3];
    r[0] = ((iADC*1000)/1024)%10;
    r[1] = (((iADC*1000)/1024)/10)%10;
    r[2] = (((iADC*1000)/1024)/10)/10;

    return r;

}

//Configura y lee el ADC
void readADC()
{
    ADCON0bits.ADON = 1;        //Habilitamos el ADC
    
    ADCON1bits.ADCS = 0b001;    //Seleccionamos el reloj de convercion
    
    ADCON0bits.CHS = 0b00000;   //Seleccionamos el canal
    
    ADCON1bits.ADFM = 1;        //Queremos el resultado con justificacion derecha
    
    ADCON0bits.GO_nDONE = 1;    //Iniciamos la convercion
    
    /*
    while(ADCON0bits.GO_nDONE); //Esperamos a que termine la convercion
    
    long r = (ADRESH<<8) + ADRESL;  //Concatenamos los valores de los registros
    return r;
     */
    
}



void UART_write(char c)
{
    TXREG = c;
    while(TXSTAbits.TRMT == 0);
}

void UART_print(unsigned char* cadena)
{
    while(*cadena != 0)
    {
        UART_write(*cadena);
        cadena++;
    }
    WDTCONbits.WDTPS = 0b01010;
    SLEEP();
}

unsigned char* ASCII_Con(int a, int b, int c)
{
    static char r[7];
    r[0] = a+48;
    r[1] = '.';
    r[2] = b+48;
    r[3] = c+48;
    r[4] = ' ';
    r[5] = 'V';
    r[6] = '\0';
    
    return r;
}
