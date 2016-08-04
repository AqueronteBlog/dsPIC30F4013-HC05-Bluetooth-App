/**
* @file		interrupts.c
* @author	Manuel Caballero
* @date 	25/7/2016
* @brief 	Interrupciones del sistema.
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
#include "interrupts.h"


/**
 *  \brief     _U2RXInterrupt (void) interrupt service routine
 *  \details   Subrutina de interrupción de la UART modo Rx.
 *
 *             Almacena el dato recibido ( 1-Byte ) en la variable RxBuff.
 *               
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      25/7/2016
 */
void __attribute__ ((interrupt,no_auto_psv)) _U2RXInterrupt (void)
{
    if ( IFS1bits.U2RXIF  ==  1 ){
        RxBuff           =  U2RXREG;
        IFS1bits.U2RXIF  =  0;
    }
}


