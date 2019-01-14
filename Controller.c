
#include "Controller.h"
#include "PWM.h"
#include "Serial.h"
   #include <inttypes.h>
   #include <avr/io.h>
   #include <avr/interrupt.h>
   #include <avr/wdt.h>

void controller_update(char* data)
{
   //u,255,255,255,255
   /*if(data[0]=='u')
   {
    char r[]={data[2],data[3],data[4]};
    char g[]={data[6],data[7],data[8]};
    char b[]={data[10],data[11],data[12]};
    char w[]={data[14],data[15],data[16]};
    led_state.red=atoi(r);
    wdt_reset();
    led_state.green=atoi(g);
    wdt_reset();
    led_state.blue=atoi(b);
    wdt_reset();
    led_state.white=atoi(w);
    wdt_reset();
   }*/
   pwm_setDutycycle(CHAN_RED,led_state.red);
   pwm_setDutycycle(CHAN_GREEN,led_state.green);
   pwm_setDutycycle(CHAN_BLUE,led_state.blue);
   pwm_setDutycycle(CHAN_WHITE,led_state.white);
}
void controller_init()
{
   led_state.red=ON;
   led_state.green=ON;
   led_state.blue=ON;
   led_state.white=ON;
   
   pwm_enable(CHAN_RED);
   pwm_enable(CHAN_GREEN);
   pwm_enable(CHAN_BLUE);
   pwm_enable(CHAN_WHITE);
}


void controller_leds_on()
{
   pwm_setDutycycle(CHAN_RED,ON);
   pwm_setDutycycle(CHAN_GREEN,ON);
   pwm_setDutycycle(CHAN_BLUE,ON);
   pwm_setDutycycle(CHAN_WHITE,ON);
}

void controller_leds_medium()
{
   pwm_setDutycycle(CHAN_RED,127);
   pwm_setDutycycle(CHAN_GREEN,127);
   pwm_setDutycycle(CHAN_BLUE,127);
   pwm_setDutycycle(CHAN_WHITE,127);
}

void controller_leds_off()
{
   pwm_setDutycycle(CHAN_RED,OFF);
   pwm_setDutycycle(CHAN_GREEN,OFF);
   pwm_setDutycycle(CHAN_BLUE,OFF);
   pwm_setDutycycle(CHAN_WHITE,OFF);
}