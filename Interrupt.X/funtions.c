
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

//Obtenos un arreglo que indica la representacion de un digito en el display
//Donde r[2] es el digito mas significativo
int* seg7(const int * iBCD)
{
    
    int numbers[10] = {
            //ABCDEFG
            0b1111110,      // numero: 0
            0b0110000,      // numere: 1
            0b1101101,      // numero: 2
            0b1111001,      // numero: 3
            0b0110011,      // numero: 4
            0b1011011,      // numero: 5
            0b1011111,      // numero: 6
            0b1110000,      // numero: 7
            0b1111111,      // numero: 8
            0b1111011,      // numero: 9
    };

    static int r[3];
    r[0] = numbers[iBCD[0]];
    r[1] = numbers[iBCD[1]];
    r[2] = numbers[iBCD[2]];

    return r;

}

//Configuramos la salida logica de los pines conectados al display
//digit es un arreglo/numero donde cada posicion/bit indica el estado de un led para representar un numero
void showNumber(int digit)
{
    ADis = !!(digit & (1<<6));
    BDis = !!(digit & (1<<5));
    CDis = !!(digit & (1<<4));
    DDis = !!(digit & (1<<3));
    EDis = !!(digit & (1<<2));
    FDis = !!(digit & (1<<1));
    GDis = digit & 1;
}


//Permite alternar entre el encendido y apagado de cada digito
//La idea es manejar una frecuencia lo suficientemente alta para que de la ilucion de tres digitos encendidos al tiempo
void showNumbers(int *digits, int n)
{
    
    //static int a = 0;

    if(n%3 == 0)
    {
        showNumber(digits[0]);
        T3 = 0;
        T1 = 1;
    }
    if(n%3 == 1)
    {
        showNumber(digits[1]);
        T2 = 0;
        T3 = 1;
    }
    if(n%3 == 2)
    {   
        showNumber(digits[2]);
        T1 = 0;
        T2 = 1;
    }
    
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
