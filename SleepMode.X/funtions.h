
/**
 * Se encarga de interpretar el valor obtenido del ADC a BCD
 * @param iADC lectura ADC
 * @return arreglo de 3 elementos que reprecentan el valor
 * BCD de la lectura de entrada, siendo el primer valor
 * el menos significativo o la lectura de 10 mV
 */
unsigned short* BinTOBcd(unsigned long iADC);

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
void UART_print(unsigned char* cadena);

/**
 * Genera una cadena de caracteres
 * @param a Digito mas significativo
 * @param b Digito del medio
 * @param c DIgito menos significativo
 * @return cadena de caracteres de entrada formateada para
 * la trasmicion serie
 */
unsigned char* ASCII_Con(unsigned short a, unsigned short b, unsigned short c);