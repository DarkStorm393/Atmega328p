#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"
#include "adc.h"

int main (void)
{
    ADC_WithInterrupt();
    init_usart(207);
    while (1)
    {
        char usart_main = UDR0;
        if (usart_main == '0')
        {
            //Selecciona el canal 0 del ADC.
            ADMUX &= ~(1<<MUX0);
        } else if (usart_main == '1')
        {
            //Selecciona el canal 1 del ADC.
	        ADMUX |= 1 << MUX0;
        }   
    }
}