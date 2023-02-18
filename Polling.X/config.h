
// PIC16F1827 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


// Macros para la asignacion de pines, y escritura en las salidas

#define T1 LATAbits.LATA1       //Salida T1
#define T2 LATAbits.LATA2       //Salida T2
#define T3 LATAbits.LATA3       //Salida T3

#define ADis LATAbits.LATA4     //Escritura segmento A
#define BDis LATAbits.LATA6     //Escritura segmento B
#define CDis LATAbits.LATA7     //Escritura segmento C
#define DDis LATBbits.LATB0     //Escritura segmento D
#define EDis LATBbits.LATB3     //Escritura segmento E
#define FDis LATBbits.LATB4     //Escritura segmento F
#define GDis LATBbits.LATB5     //Escritura segmento G

#define RX TRISBbits.TRISB1     //Pin de recepcion
#define TX TRISBbits.TRISB2     //Pin de trasmicion


#define _XTAL_FREQ 4000000      //Frecuencia del oscilador
#define DELAY_SYS 10            //Perido para la actualizacion del display

#include <xc.h>


