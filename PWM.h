#ifndef PWM_H
#define PWM_H
#include <stdlib.h>
#include <inttypes.h>

enum PWM_CHANNEL 
{
	
	// Name by color
	CHAN_RED		= 1,
	CHAN_GREEN		= 1<<1,
	CHAN_BLUE		= 1<<2,
	CHAN_WHITE		= 1<<3,
	
	// Name by index
	CHAN_1			= 1,
	CHAN_2			= 1<<1,
	CHAN_3			= 1<<2,
	CHAN_4			= 1<<3,
	
	// Name by port
	CHAN_PD6		= 1,
	CHAN_PD5		= 1<<1,
	CHAN_PB3		= 1<<2,
	CHAN_PD3		= 1<<3,
	
	// Name by register
	CHAN_OC0A		= 1,
	CHAN_OC0B		= 1<<1,
	CHAN_OC2A		= 1<<2,
	CHAN_OC2B		= 1<<3
	
};

void pwm_init();
void pwm_enable(enum PWM_CHANNEL channel);
void pwm_disable(enum PWM_CHANNEL channel);
void pwm_setDutycycle(enum PWM_CHANNEL channel, int dutycycle);

#endif
