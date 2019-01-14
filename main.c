#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

//Include local modules
#include "types.h"
#include "os.h"
#include "Serial.h"
#include "PWM.h"
#include "Controller.h"

//#include <delay.h>
//#include <LDrvPort.h>
//#include <LDrvPwm.h>

//#include <ApplLamp.h>

int main(void)
{
    wdt_enable(WDTO_2S);


    wdt_reset();

	serial_begin();
	pwm_init();
	controller_init();
	OS_vTimerInit();

    OS_vStartFreeRunTimer();
    controller_leds_medium();

    while (1)
    {
        if (OS_u8Cnt10ms >= OS_10ms_RUN_TIMER)
        {
            OS_vCyclicTask10ms();
            OS_u8Cnt10ms = 0;
        }

        if (OS_u8Cnt50ms >= OS_50ms_RUN_TIMER)
        {
            OS_vCyclicTask50ms();
            OS_u8Cnt50ms = 0;
        }

        if (OS_u16Cnt100ms >= OS_100ms_RUN_TIMER)
        {
            OS_vCyclicTask100ms();
            OS_u16Cnt100ms = 0;
        }

        if (OS_u16Cnt500ms >= OS_500ms_RUN_TIMER)
        {
            OS_vCyclicTask500ms();
            OS_u16Cnt500ms = 0;
        }

        OS_vBackgroundTask();
    }
    return (1);
}
