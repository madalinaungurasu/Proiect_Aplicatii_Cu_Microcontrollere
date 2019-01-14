#include "PWM.h"


   #include <inttypes.h>
   #include <avr/io.h>
   #include <avr/interrupt.h>
   #include <avr/wdt.h>

void pwm_init()
{
 
   TCCR0A |= (1<<WGM00 | 1<<WGM01);// | 1<<WGM02);
   TCCR2A |= (1<<WGM20 | 1<<WGM21);// | 1<<WGM22);
	
	// Set clock source (prescaler)
	TCCR0B |= (1<<CS01 | 1<<CS00);
	TCCR2B |= (1<<CS21 | 1<<CS20);
	
	// Set to 50% duty cycle
	OCR0A = 0x80;
	OCR0B = 0x80;
	OCR2A =0x80;
	OCR2B = 0x80;
	
	// 4 PWM channel outputs
	DDRB |= 1<<PB3; // OC2A
	DDRD |= 1<<PD3; // OC2B
	DDRD |= 1<<PD5; // OC0B
	DDRD |= 1<<PD6; // OC0A	   
}
void pwm_enable(enum PWM_CHANNEL channel)
{
   if (channel & CHAN_OC0A) TCCR0A |= 1<<COM0A1;
   if (channel & CHAN_OC0B) TCCR0A |= 1<<COM0B1;
   if (channel & CHAN_OC2A) TCCR2A |= 1<<COM2A1;
   if (channel & CHAN_OC2B) TCCR2A |= 1<<COM2B1;
}
void pwm_disable(enum PWM_CHANNEL channel)
{	
   if (channel & CHAN_OC0A) TCCR0A &= ~(1<<COM0A1);
   if (channel & CHAN_OC0B) TCCR0A &= ~(1<<COM0B1);
   if (channel & CHAN_OC2A) TCCR2A &= ~(1<<COM2A1);
   if (channel & CHAN_OC2B) TCCR2A &= ~(1<<COM2B1);
   
}
void pwm_setDutycycle(enum PWM_CHANNEL channel, int dutycycle)
{
   	if (channel & CHAN_OC0A) OCR0A = dutycycle;
	if (channel & CHAN_OC0B) OCR0B = dutycycle;
	if (channel & CHAN_OC2A) OCR2A = dutycycle;
	if (channel & CHAN_OC2B) OCR2B = dutycycle;
	 wdt_reset();
}
