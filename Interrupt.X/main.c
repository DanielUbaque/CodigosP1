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

void __interrupt() INT_TMR0(void){
    
    static int count = 0;
    static int* A ;
    
    if(INTCONbits.TMR0IF == 1){
        if(count == 40)
        {
            ADis = ! ADis;
            readADC();
            count = 0;
        }
        //ADis = ! ADis; 
        count++;
        TMR0 = 158;
        INTCONbits.TMR0IF = 0;
        showNumbers(A, count);
        return;
    }
    if(PIR1bits.ADIF == 1){
        
        BDis = ! BDis; 
        PIR1bits.ADIF = 0;
        ADCON0bits.ADON = 0;
        
        int *B = BinTOBcd(((ADRESH<<8) + ADRESL));
        //int *B = BinTOBcd(iADC);
        //int B[3] = {7, 8, 10};
        A = seg7(B);
        UART_print(ASCII_Con(B[2], B[1], B[0]));
        return;
    }
    
}



