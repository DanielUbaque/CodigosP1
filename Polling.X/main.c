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
    // Inicializacion de pines y perifericos
    init_IO();
    
    // Declaracion de variales
    unsigned long dataADC = 0;
    unsigned short *numberBCD = 0;
    unsigned short *displayData = 0;
    
    while(1)
    {
        dataADC = readADC();                //Leer ADC
        numberBCD = mathBCD(dataADC);       //Convertir a BCD
        displayData = math7Seg(numberBCD);  //Formato 7 segmentos
        
        //Enviamos el dato via UART
        printUART(ASCII_Con(numberBCD[2], numberBCD[1], numberBCD[0]));
        
        showNumbers(displayData);           //Mostrar en el display
        
    }
    
    return;
}