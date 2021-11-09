 # Lab 7: Vojtěch Hroch

Link to this file in your GitHub repository:

[https://github.com/your-github-account/repository-name/lab_name](https://github.com/xhroch01/Digital-electronics-2)

### Analog-to-Digital Conversion

| **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 |
   | Up     | 0.495&nbsp;V | 101 | 99 |
   | Down   | 1,203 V     | 246    | 257 |
   | Left   | 1.970 V     | 403   | 409 |
   | Select | 3,182 V      | 651    | 640 |
   | none   |  5 V      | 1023   | 1023 |
 
 
2. Code listing of ACD interrupt service routine for sending data to the LCD/UART and identification of the pressed button. Always use syntax highlighting and meaningful comments:

```c
ISR(ADC_vect)
{
    // WRITE YOUR CODE HERE
    uint16_t value = 0;
    char lcd_string[4] = "0000";

    value = ADC;                  // Copy ADC result to 16-bit variable
    itoa(value, lcd_string, 10);  // Convert decimal value to string
    
	lcd_clrscr();
 
	lcd_gotoxy(1, 0); lcd_puts("value:");
	lcd_gotoxy(3, 1); lcd_puts("key:");
 

	if(value > 1023)
	{
		lcd_gotoxy(8, 0);
		lcd_puts(lcd_string);
		itoa(value, lcd_string, 16);
		lcd_gotoxy(8, 1);
		lcd_puts("non");
		lcd_gotoxy(13,0);
		lcd_puts(lcd_string);
		uart_puts(lcd_string);
		uart_puts("\n\r");
	}
	
	else if(value > 640)
	{
		lcd_gotoxy(8, 0);
		lcd_puts(lcd_string);
		itoa(value, lcd_string, 16);
		lcd_gotoxy(8, 1);
		lcd_puts("select");
		lcd_gotoxy(13,0);
		lcd_puts(lcd_string);
		uart_puts(lcd_string);
		uart_puts("\n\r");
		
	else if(value > 409)
	{
		lcd_gotoxy(8, 0);
		lcd_puts(lcd_string);
		itoa(value, lcd_string, 16);
		lcd_gotoxy(8, 1);
		lcd_puts("left");
		lcd_gotoxy(13,0);
		lcd_puts(lcd_string);
		uart_puts(lcd_string);
		uart_puts("\n\r");
	}
			
	else if(value > 257)
	{
		 lcd_gotoxy(8, 0);
		 lcd_puts(lcd_string);
		 itoa(value, lcd_string, 16);
		 lcd_gotoxy(8, 1);
		 lcd_puts("Down");
		 lcd_gotoxy(13,0);
		 lcd_puts(lcd_string);
		 uart_puts(lcd_string);
		 uart_puts("\n\r");
	}
	
	else if(value > 99)
	{
		lcd_gotoxy(8, 0);
		lcd_puts(lcd_string);
		itoa(value, lcd_string, 16);
		lcd_gotoxy(8, 1);
		lcd_puts("Up");
		lcd_gotoxy(13,0);
		lcd_puts(lcd_string);
		uart_puts(lcd_string);
		uart_puts("\n\r");
	}
	
	else if(value > 0)
	{
		lcd_gotoxy(8, 0);
		lcd_puts(lcd_string);
		itoa(value, lcd_string, 16);
		lcd_gotoxy(8, 1);
		lcd_puts("Right");
		lcd_gotoxy(13,0);
		lcd_puts(lcd_string);
		uart_puts(lcd_string);
		uart_puts("\n\r");
	}
		
}

```

### UART communication

1. (Hand-drawn) picture of UART signal when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd).

   ![your figure](IMAGES/prubeh.jpg)

2. Flowchart figure for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure](IMAGES/graf.jpg)

### Temperature meter

Consider an application for temperature measurement and display. Use temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, one LED and a push button. After pressing the button, the temperature is measured, its value is displayed on the LCD and data is sent to the UART. When the temperature is too high, the LED will start blinking.

1. Scheme of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure](IMAGES/zapojeni.jpg)
