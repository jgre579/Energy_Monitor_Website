/*
 * uart0.h
 *
 * Created: 12/08/2021 5:25:26 pm
 *  Author: jgre579
 */ 


#ifndef UART0_H_
#define UART0_H_
#include <avr/io.h>


void usart_init();
void usart_transmit(uint8_t data);
void usart_transmit_array(char message[]);




#endif /* UART0_H_ */