#ifndef __TEMP_H
#define __TEMP_H	
#include "LPC11xx.h"
#include "stdio.h"
#include "uart.h"
#include "oled.h"
void temp();
void UART_SendStr(char *pucStr);
void OLED_P6x8Str(uint8_t  x,uint8_t y,uint8_t ch[]);
//sprintf (GcRcvBuf, "temp=%f C\r\n", t);

#endif
