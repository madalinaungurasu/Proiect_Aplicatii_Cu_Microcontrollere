
#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#include "types.h"
#include "os.h"
#include "Controller.h"
#include "Serial.h"

//#include <LDrvPort.h>
//#include <LDrvPwm.h>

//#include <ApplLamp.h>

/*Local data at RAM*/
volatile uint8_t  OS_u8Cnt10ms;
volatile uint8_t  OS_u8Cnt50ms;
volatile uint16_t OS_u16Cnt100ms;
volatile uint16_t OS_u16Cnt500ms;

volatile UI8 ucTask500msCnt;

void OS_vTimerInit(void)
{
    /*Set Timer1 on Clear Timer on Compare Match (CTC) Mode
     * TCCR1 register: CTC1=1 -> CTC Mode, 8-bit with OCR1C top
     *                 CS13=1 CS12=0 CS11=0 CS10=1-> clkIO/256 from prescaler
     * Max value OCR1C = 0x9C
     * Timer set to generate interrupt at 5ms*/
	//TCCR0A = (1<<WGM01);
	//TCCR0B= (1<<CS02);
	//OCR0A =63;
   //TCCR1 = (1<<CTC1) | (1<<CS13) | (1<<CS10);
  // OCR1C = 0x9C;
  
  //switch os to tmimer1 instead of timer0
   TCCR1B |= (1 << WGM12) | (1 << CS11);
   
   // Load the high byte, then the low byte
   // into the output compare
   OCR1AH = (CTC_MATCH_OVERFLOW >> 8);
   OCR1AL = CTC_MATCH_OVERFLOW;
   
   // Enable the compare match interrupt

}

void OS_vCyclicTask5ms(void)
{
#ifdef OS_USE_TOGGLE_BIT
   PORTB ^= (1<<TOGGLE_PIN_OUT);
#endif

}

void OS_vCyclicTask10ms(void)
{

    //gvApplLampMain();
}

void OS_vCyclicTask50ms(void)
{
}

void OS_vCyclicTask100ms(void)
{
    wdt_reset();
}

void OS_vCyclicTask500ms(void)
{
}

void OS_vBackgroundTask(void)
{
	if(serial.iready == 1)
	{
		controller_update(serial.data_buffer);
		//serial_sendString("ready\r");
		serial.iready=0;
	}
	wdt_reset();
}

void OS_vStartFreeRunTimer(void)
{
   //TIMSK0 |= (1<<OCIE1A);
   TIMSK1 |= (1 << OCIE1A);
   sei();
}

/*Interrupt is generated every 5ms*/
ISR(TIMER1_COMPA_vect)
{
   OS_vCyclicTask5ms();

   /*Increase counters used for other OS cyclic functions*/
   OS_u8Cnt10ms++;
   OS_u8Cnt50ms++;
   OS_u16Cnt100ms++;
   OS_u16Cnt500ms++;
   wdt_reset();
}

