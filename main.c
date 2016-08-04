/**
* @file		main.c
* @author	Manuel Caballero
* @date 	25/7/2016
* @brief 	Archivo principal.
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


#include "xc.h"
#include <stdint.h>
#include "variables.h"
#include "functions.h"
#include "interrupts.h"

/**
 *  \brief     int main( void )
 *  \details   This firmware turns an LED on/off ( there are four LEDs ) depending on
 *             the received command by the Bluetooth module: HC-05 ( by UART )
 * 
 *
 *  \author    Manuel Caballero
 *  \version   0.0
 *  \date      25/7/2016
 *  \pre       This firmware is tested on the dsPIC30F4013.
 *
 *  \pre       MPLAB X IDE v3.35.
 *  \pre       Compiler XC16 v1.22.
 */
int main(void) {    
    conf_IO     ();
    conf_UART   ();
    
    while( 1 ){
        Idle();                                                 // uC in Low Power
        
        switch ( RxBuff ){                                      // Change the state of the chosen LED
            case    0x01:
                LATBbits.LATB9   =  ~LATBbits.LATB9;
                break;
            case    0x02:
                LATBbits.LATB10   =  ~LATBbits.LATB10;
                break;
            case    0x03:
                LATBbits.LATB11   =  ~LATBbits.LATB11;
                break;
            case    0x04:
                LATBbits.LATB12   =  ~LATBbits.LATB12;
                break;
            default:
                LATB     &=   ~( LED1 | LED2 | LED3 | LED4 );   // Turn off all the LEDs
                break;
        }
    }
    
    return 0;
}
