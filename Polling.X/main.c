/*
 * File:   newmain.c
 * Author: Rodion TC
 *
 * Created on 29 de enero de 2023, 12:27
 */


#include <xc.h>
#include "config.h"
#include "funtions.h"
#include "init.h"


void main(void) {
    init_IO();
    
    while(1)
    {
        unsigned long iADC = readADC();         //Leer ADC
        unsigned short *B = BinTOBcd(iADC);     //Convertir a BCD
        unsigned short* A = seg7(B);            //Formato 7 segmentos
        UART_print(ASCII_Con(B[2], B[1], B[0]));//Enviamos el dato via UART
        showNumbers(A);                         //Mostrar en el display
        
    }
    
    return;
}