/*
 * uart0.c
 *
 * Created: 12/08/2021 5:25:00 pm
 *  Author: jgre579
 */ 

#include "uart0.h"
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>


void usart_init(uint16_t ubrr) {
	
	UCSR0B |= (1<<TXEN0); //Enable Transmission
	UBRR0 = ubrr; //Set baud rate pre scale.
	
	
	
}

void usart_transmit(uint8_t data) {
	
	while(UCSR0A & (1<<UDRE0) == 0) { //Check if UART is ready to send another byte. If not block till its free.
		;
	}	
	
	UDR0 = data;
}


void usart_transmit_array(char message[]) {
	
	for (uint8_t i = 0; i <= 4; i++) {
		_delay_ms(50);
		usart_transmit(message[i]);
	}
	
}