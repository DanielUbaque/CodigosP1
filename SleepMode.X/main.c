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

void __interrupt() INT_TMR0(void){
    

    
    if(PIR1bits.ADIF == 1){
        
        PIR1bits.ADIF = 0;
        ADCON0bits.ADON = 0;
        
        int *B = BinTOBcd(((ADRESH<<8) + ADRESL));
        //int *B = BinTOBcd(iADC);
        //int B[3] = {7, 8, 10};
        UART_print(ASCII_Con(B[2], B[1], B[0]));
        return;
    }
    
}



