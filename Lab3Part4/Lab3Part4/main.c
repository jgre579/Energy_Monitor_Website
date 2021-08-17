/*
 * Part4.c
 *
 * Created: 12/08/2021 4:22:40 pm
 * Author : jgre579
 */ 

#include "uart0.h"
#include <util/delay.h>
#include <stdbool.h>

// Function prototypes
void get_digits(char digit_array[], uint8_t size, uint16_t current_prime);
void calculate_primes(uint16_t* prime_array);


int main(void)
 {
    
	char message4Q6[4];
	char prime_message[3];
	
	uint16_t prime_array[300];
	uint16_t num = 0;
	uint8_t j = 2;
	
	usart_init(12);
	calculate_primes(prime_array);
	
	// For Q4.6 get_digits(message4Q6, 3, 345);
	
	
	while(1) {
		
		/* For Q4.6
		usart_transmit_array(message4Q6);
		_delay_ms(50);	
		usart_transmit(' '); //Transmit a space
		*/
		
		for (uint8_t i = 0; i <= 62; i++) {			
			
			get_digits(prime_message, 3, prime_array[i]);
			
			usart_transmit_array(prime_message);
			_delay_ms(50);
			usart_transmit(','); //Transmit a comma
			_delay_ms(50);
			usart_transmit(' '); //Transmit a space
		}
				
	}		

}

void get_digits(char digit_array[], uint8_t size, uint16_t number) {
	
	//Convert specific number to an array of its digits in ASCII encoding using the division by 10 and modulo.
	
	size -= 1;
	while (size != 255) {
		digit_array[size] = number % 10 + '0'; 
		number /= 10;
		size--;
	}
	
}

void calculate_primes(uint16_t* prime_array) {
	
	bool current_prime;
	uint16_t num_primes = 0;
	
	//Iterate through every number from 2-300, and check whether it could be divided cleanly (no reminder) by any number higher than 1 and less than 300.
	//If it can't we know it must be prime.
	 
	for(uint16_t i = 2; i <= 300; i++) {
		current_prime = true;
		for(uint16_t j = 2; j < i; j++) {
				
			if(i%j == 0) {
				current_prime = false;
			}	
		}
		
		if (current_prime) {
			prime_array[num_primes] = i;
			num_primes++;
		}	
	}	
}

