/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "clockconfig.h"
#include "USART.h"
#include <string.h>

#define SERIAL_RX 10
#define SERIAL_TX 9
#define BAUDRATE 9600

custom_libraries::clock_config system_clock;
custom_libraries::USART serial(USART1,GPIOA,SERIAL_RX,SERIAL_TX,BAUDRATE);
			

int main(void)
{
	//initialize system clock to PLL 168MHz on AHB
	system_clock.initialize();
	serial.initialize();

	char response[] = "OK";
	char querry[] = "AT";

	serial.println(response);

	while(1){

		if(strncmp(serial.receive_buffer,querry,(sizeof(querry)/sizeof(char))-1) == 0){
			serial.flush_buffer();
			serial.println(response);
		}
	}
}
