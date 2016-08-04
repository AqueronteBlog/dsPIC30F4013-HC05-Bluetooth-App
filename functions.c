/**
* @file		functions.c
* @author	Manuel Caballero
* @date 	25/7/2016
* @brief 	Funciones del sistema.
* \copyright
* 	AqueronteBlog@gmail.com
*
* Este archivo es propiedad intelectual del blog Aqueronte,
* cuya direccion web, es la siguiente:
*
* 	http://unbarquero.blogspot.com/
*
* Se permite cualquier modificacion del archivo siempre y cuando
* se mantenga la autoria del autor.
*/
#include "functions.h"



/**
 *  \brief     void conf_IO (void)
 *  \details   Configura los pines del MCU a usar en este proyecto.
 *                  - Puerto B: LEDs.
 *              - RB9:  Salida.     LED         p38
 *              - RB10: Salida.     LED         p37
 *  			- RB11:	Salida.     LED         p36
 *  			- RB12:	Salida.     LED         p35
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      25/7/2016
 */
void conf_IO (void)
{
    // ADC DISABLED
    ADPCFGbits.PCFG9     =   1;
    ADPCFGbits.PCFG10    =   1;
    ADPCFGbits.PCFG11    =   1;
    ADPCFGbits.PCFG12    =   1;
    
    // PINs OUTPUT
    TRISBbits.TRISB9     =   0;
    TRISBbits.TRISB10    =   0;
    TRISBbits.TRISB11    =   0;
    TRISBbits.TRISB12    =   0;
    
    // All LEDs OFF
    LATBbits.LATB9       =   0;
    LATBbits.LATB10      =   0;
    LATBbits.LATB11      =   0;
    LATBbits.LATB12      =   0;
}



/**
 *  \brief     void conf_UART (void)
 *  \details   Configura el módulo UART a 9600 Baud Rate.
 *
 * 		· Reloj UART: PLL OFF: F_CY = ( F_OSC )/4 = ( 7.37 MHz )/4 = 1.8425 MHz
 * 		· Buad Rate ~ 9600:
 *
 *     		Baud Rate = F_CY/(16(X + 1))
 *
 *                  9600 = ( 1.8425·10^6 )/(16(X + 1))
 *
 * 		Por lo tanto:
 *
 *                  X ~ 10.995 = 11
 *
 *  \pre       Para ampliar información: DataSheet ( Reference Manual ) dsPIC30F4013, apartado 19.3
 *             UNIVERSAL ASYNCHRONOUS RECEIVER TRANSMITTER (UART)
 *  \pre       El reloj interno debe estar a 7.37 MHz.
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      25/7/2016
 */
void conf_UART (void)
{
    /*
    U2MODEbits.STSEL     =   0;     // 1-Stop bit
    U2MODEbits.PDSEL     =   0;     // No Parity, 8-Data bits
    U2MODEbits.ABAUD     =   0;     // Auto-Baud disabled
     */
    U2BRG                =   11;
    
    IEC1bits.U2RXIE      =   1;     // Enable Rx interrupt
    U2MODEbits.UARTEN    =   1;     // Enable UART
    U2STAbits.UTXEN      =   1;     // Enable UART TX
}
