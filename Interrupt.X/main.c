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
        
        
    }
    
    return;
}

void __interrupt() interrupciones(void){
    
    // Declaracion de variables
    static int count = 0;
    static unsigned short* displayData;
    
    if(INTCONbits.TMR0IF == 1){             //Ha trascurrido 10 ms
        if(count == 100)                    //Ha transcurrido 1 segundo
        {
            readADC();
            count = 0;
        }
        count++;
        TMR0 = 217;
        INTCONbits.TMR0IF = 0;              //Reiniciamos la bandera
        showNumbers(displayData, count);
        return;
    }
    if(PIR1bits.ADIF == 1){                 //Finalizo la convercion ADC
        
        PIR1bits.ADIF = 0;
        ADCON0bits.ADON = 0;
        
        unsigned short *numberBCD = 
        mathBCD((unsigned long)((ADRESH<<8) + ADRESL));
        displayData = math7Seg(numberBCD);
        printUART(ASCII_Con(numberBCD[2], numberBCD[1], numberBCD[0]));
        return;
    }
    
}



