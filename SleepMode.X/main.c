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
        readADC();
    }
    return;
}

void __interrupt() Interrupciones(void){
    
    if(PIR1bits.ADIF == 1){         //Cuando termino de realizar la convercion
        
        PIR1bits.ADIF = 0;
        ADCON0bits.ADON = 0;
        
        unsigned short *numberBCD = 
        mathBCD((unsigned long)((ADRESH<<8) + ADRESL));
        printUART(ASCII_Con(numberBCD[2], numberBCD[1], numberBCD[0]));
        return;
    }
}



