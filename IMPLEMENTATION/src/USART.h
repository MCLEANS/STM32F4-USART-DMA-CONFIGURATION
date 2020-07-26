/*
 * USART.h
 *
 *  Created on: Jul 20, 2020
 *      Author: MCLEANS
 *
 *      N/B: CURRENT LIBRARY ONLY SUPPORTS USART 1,2,3;
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f4xx.h"
#define CLOCK_FREQ_APB1 42000000UL
#define CLOCK_FREQ_APB2 84000000UL
#define BUFFER_SIZE 1024

namespace custom_libraries {

enum _DMA{
	_DMA1,
	_DMA2
};

class USART {
private:
	USART_TypeDef *_USART;
	GPIO_TypeDef *GPIO;
	_DMA ACTUAL_DMA;
	DMA_Stream_TypeDef *DMA_STREAM;
	uint8_t RX_PIN;
	uint8_t TX_PIN;
	int baudrate;
	int buffer_position = 0;
private:
	char read_char();
	void print_char(char byte);
	void config_DMA();
	void reset_DMA();
public:
	char receive_buffer[BUFFER_SIZE];
public:
	USART(USART_TypeDef *_USART,
			GPIO_TypeDef *GPIO,
			_DMA ACTUAL_DMA,
			DMA_Stream_TypeDef *DMA_STREAM,
			uint8_t RX_PIN,
			uint8_t TX_PIN,
			int baudrate);
	~USART();
	void initialize();
	void print(char *byte);
	void println(char *byte);
	void read_string();
	void flush_buffer();

};

} /* namespace custom_libraries */

#endif /* USART_H_ */
