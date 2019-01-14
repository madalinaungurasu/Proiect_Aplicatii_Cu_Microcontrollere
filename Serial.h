#pragma once
#ifndef SERIAL_H
#define SERIAL_H
#include <avr/wdt.h>
void serial_begin();
void serial_sendChar(char value);
void serial_sendString(const char* value);
char serial_getChar();
struct serial_data{
char data_buffer[255];
int iready;
int ipos;
}serial;


#endif

