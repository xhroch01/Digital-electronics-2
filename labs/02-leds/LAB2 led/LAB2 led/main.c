#define LED_GREEN   PB5
#define LED_RED		PC1     // AVR pin where green LED is connected
#define BLINK_DELAY 500
#define BUTTON		PD2
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions

/* Functions ---------------------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs when a push button is pressed.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Green LED at port B
    // Set pin as output in Data Direction Register...
    // ...and turn LED off in Data Register
    // Configure the second LED at port C

	DDRB =	DDRB | (1<<LED_GREEN);
	PORTB =	PORTB & ~(1<<LED_GREEN);

    DDRC =	DDRC | (1<<LED_RED);
    PORTC =	PORTC & ~(1<<LED_RED);

    // Infinite loop
    while (1)
    {
		if(bit_is_clear(PIND, PD2))
	    {
			PORTC = PORTC ^ (1<<LED_RED);
			PORTB = PORTB ^ (1<<LED_GREEN);
	    }
    
	}

    // Will never reach this
    return 0;
}