#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <stdlib.h>
#include <inttypes.h>

#define OFF 0
#define ON 255

//starea led la toate
struct LEDState{
uint8_t red;
uint8_t green;
uint8_t blue;
uint8_t white;
}led_state;

void controller_update(char* data);
void controller_init();
void controller_leds_on();
void controller_leds_medium();
void controller_leds_off();


#endif
