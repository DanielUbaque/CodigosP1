/**
 * Configura la salida logica de los pines conectados al display
 * @param digit representacion bit a bit del estado logico necesario
 * para la reprecentacion decimal en el display
 */
void showNumber(unsigned short digit);
/**
 * Realiza un barrido a travez de los digitos del display mostrando
 * de manera individual cada digito, mediante Persistence of Vision
 * se da la ilucion de tener encendido al tiempo cada digito en
 * el display, adicinalmente se configura la frecuencia en el
 * archivo config.h
 * @param digits arreglo de tres elementos que contienen la representacion
 * logica para visualizar correctamente los digitos en el display
 */
void showNumbers(unsigned short *digits, int n);

/**
 * Formatea de BCD a 7 segmentos
 * @param iBCD arreglo de tres digitos en BCD a convertir
 * @return arreglo de tres digitos en formato 3 segmento,
 * la posicion inicial del apuntador o [0] es el bit menos
 * significativo
 */
unsigned short * math7Seg(const unsigned short *iBCD);

/**
 * Se encarga de interpretar el valor obtenido del ADC a BCD
 * @param iADC lectura ADC
 * @return arreglo de 3 elementos que reprecentan el valor
 * BCD de la lectura de entrada, siendo el primer valor
 * el menos significativo o la lectura de 10 mV
 */
unsigned short* mathBCD(unsigned long iADC);

/**
 * Comienza la converción del ADC, al final del proceso se desactiva
 * @return la lectura obtenida del ADC
 */
void readADC(void);


/**
 * Trasmite un caracter por TX
 * @param c valor a trasmitir
 */
void UART_write(unsigned char c);

/**
 * Realiza la trasmicion de una cadena de caracteres
 * @param cadena cadena de caracteres a transmitir
 */
void printUART(int n, unsigned char* cadena);

/**
 * Genera una cadena de caracteres
 * @param a Digito mas significativo
 * @param b Digito del medio
 * @param c DIgito menos significativo
 * @return cadena de caracteres de entrada formateada para
 * la trasmicion serie
 */
unsigned char* ASCII_Con(unsigned short a, unsigned short b, unsigned short c);