/*
 * USART.h
 *
 *  Created on: Jul 20, 2020
 *      Author: MCLEANS
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f4xx.h"
#define CLOCK_FREQ_APB1 42000000UL
#define CLOCK_FREQ_APB2 84000000UL
#define BUFFER_SIZE 1024

namespace custom_libraries {

class USART {
private:
	USART_TypeDef *_USART;
	GPIO_TypeDef *GPIO;
	uint8_t RX_PIN;
	uint8_t TX_PIN;
	int baudrate;
	int buffer_position = 0;
private:
	char read_char();
	void print_char(char byte);
public:
	char receive_buffer[BUFFER_SIZE];
public:
	USART(USART_TypeDef *_USART,GPIO_TypeDef *GPIO,uint8_t RX_PIN,uint8_t TX_PIN,int baudrate);
	~USART();
	void initialize();
	void print(char *byte);
	void println(char *byte);
	void read_string();
	void flush_buffer();
};

} /* namespace custom_libraries */

#endif /* USART_H_ */
