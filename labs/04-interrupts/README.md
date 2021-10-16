# Lab 4: Interrupts, timers - Vojtech Hroch

Part 2
A timer (or counter) is a hardware block within an MCU and can be used to measure time events. ATmega328P has three timers, called:
   * Timer/Counter0,
   * Timer/Counter1, and
   * Timer/Counter2.

T/C0 and T/C2 are 8-bit timers, where T/C1 is a 16-bit timer. The counter counts in synchronization with microcontroller clock from 0 up to 255 (for 8-bit counter) or 65,535 (for 16-bit). Different clock sources can be selected for each timer using a CPU frequency divider with fixed prescaler values, such as 8, 64, 256, 1024, and others.

The timer modules can be configured with several special purpose registers. According to the [ATmega328P datasheet](https://www.microchip.com/wwwproducts/en/ATmega328p) (eg in the **8-bit Timer/Counter0 with PWM > Register Description** section), which I/O registers and which bits configure the timer operations?

| **Module** | **Operation** | **I/O register(s)** | **Bit(s)** |
| :-: | :-- | :-: | :-- |
| Timer/Counter0 | Prescaler<br><br>8-bit data value<br>Overflow interrupt enable | TCNT1H<br>TCNT1L | <br><br><br> |
| Timer/Counter1 | Prescaler<br><br>16-bit data value<br>Overflow interrupt enable | TCCR1B<br><br>TCNT1H, TCNT1L<br>TIMSK1 | CS12, CS11, CS10<br>(000: stopped, 001: 1, 010: 8, 011: 64, 100: 256, 101: 1024)<br>TCNT1[15:0]<br>TOIE1 (1: enable, 0: disable) |
| Timer/Counter2 | Prescaler<br><br>8-bit data value<br>Overflow interrupt enable | <br><br><br> | <br><br><br> |

Part 3
| **Program address** | **Source** | **Vector name** | **Description** |
| :-: | :-- | :-- | :-- |
| 0x0000 | RESET  | -- | Reset of the system |
| 0x0002 | INT0   | `INT0_vect`| External interrupt request number 0 |
| 0x0004 | INT1   |            | External Interrupt Request 1   |
| 0x0006 | PCINT0 |            | Pin Change Interrupt Request 0 |
| 0x0008 | PCINT1 |            | Pin Change Interrupt Request 1 |
| 0x000A | PCINT2 |            | Pin Change Interrupt Request 2 |
| 0x000C | WDT    |            | Watchdog Time-out Interrupt    |
| 0x0012 | TIMER2_OVF |        | Timer/Counter2 Overflow    |
| 0x0018 | TIMER1_COMPB | `TIMER1_COMPB_vect` | Compare match between Timer/Counter1 value and channel B compare value |
| 0x001A | TIMER1_OVF | `TIMER1_OVF_vect` | Overflow of Timer/Counter1 value |
| 0x0020 | TIMER0_OVF |  | Timer/Counter0 Overflow |
| 0x0024 | USART_RX |  | USART Rx Complete |
| 0x002A | ADC |  | ADC Conversion Complet |
| 0x0030 | TWI |  | 2-wire Serial Interface|

# Lab 4: YOUR_FIRSTNAME FAMILYNAME

Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/xhroch01/Digital-electronics-2](https://github.com/xhroch01/Digital-electronics-2)


### Overflow times

1. Complete table with overflow times.

| **Module** | **Number of bits** | **1** | **8** | **32** | **64** | **128** | **256** | **1024** |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| Timer/Counter0 | 8  | 16u | 128u | -- | 1024 us| -- | 4,1 ms | 16,4 ms |
| Timer/Counter1 | 16 | 4,1 ms | 32,8 ms  | -- | 262,1 ms | -- | 1,05 s | 4,2 s   |
| Timer/Counter2 | 8  | 16u    | 128 u    |    | 1024 us  |    | 4,1 ms | 16,4 ms |


### Timer library

1. In your words, describe the difference between common C function and interrupt service routine.
   * Function
   * Interrupt service routine

2. Part of the header file listing with syntax highlighting, which defines settings for Timer/Counter0:

```c
/**
 * @name  Definitions of Timer/Counter0
 * @note  F_CPU = 16 MHz
 */
// WRITE YOUR CODE HERE
```

3. Flowchart figure for function `main()` and interrupt service routine `ISR(TIMER1_OVF_vect)` of application that ensures the flashing of one LED in the timer interruption. When the button is pressed, the blinking is faster, when the button is released, it is slower. Use only a timer overflow and not a delay library. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()


### Knight Rider

1. Scheme of Knight Rider application with four LEDs and a push button, connected according to Multi-function shield. Connect AVR device, LEDs, resistors, push button, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure]()
