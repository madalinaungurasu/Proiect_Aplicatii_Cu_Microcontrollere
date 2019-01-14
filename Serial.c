   #include "Serial.h"
   
   #include <inttypes.h>
   #include <avr/io.h>
   #include <avr/interrupt.h>
   void serial_begin(){
   // setting the baud rate  based on the datasheet 
    UBRR0H =0x00;//(unsigned char)  ( uValue>> 8);  // 0x00 
    UBRR0L =0x0C;//(unsigned char) uValue;  // 0x0C  
    // enabling TX & RX 
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)| (1 << RXCIE0);
    UCSR0A = (1<<UDRE0)|(1<<U2X0);
    UCSR0C =  (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stop // Enable the USART Recieve Complete interrupt (USART_RXC) 
   	sei();  // Enable the Global Interrupt Enable flag so that interrupts can be processed 
      }
      void serial_sendChar(char value)
      {
	while ((UCSR0A & (1 << UDRE0)) == 0) {
	   	wdt_reset();
	   };
	UDR0 = value;
	wdt_reset();
      }
      void serial_sendString(const char* value)
      {
	int i =0;
	
	while (value[i] != 0x00)
	{
		serial_sendChar(value[i]);
		i++;
	}
      wdt_reset();
      }
      char serial_getChar()
      {
	// Check to see if something was received
	while (!(UCSR0A & _BV(RXC0)));
	return (uint8_t) UDR0;
      }
      void serial_readString(char* rxstr)
{
	char* temp;
	temp = rxstr;

	while((*temp = serial_getChar()) != '\r')
	{
	      serial_sendChar(*temp);
		++temp;
	}
}
ISR (USART_RX_vect)
{
    // Get data from the USART in register
    serial.data_buffer[serial.ipos] = UDR0;
    serial_sendChar(serial.data_buffer[serial.ipos]);
    // End of line!
    if (serial.data_buffer[serial.ipos] == '\r') {
        serial.iready=1;
       serial.data_buffer[serial.ipos]='\0';
        // Reset to 0, ready to go again
        serial.ipos = 0;
    } else {
        serial.ipos++;
    }

    wdt_reset();
}