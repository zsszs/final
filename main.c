
#include "LPC11xx.h"
#include "uart.h"
#include "delay.h"
#include "ADC.h"
#include "oled.h"
#include "ui.h"
#include "Key.h"
#include "temp.h"
#include <stdio.h>
#include <string.h>

int main()
{ 
	key_init();
	UART_Init ();
	ADC_Init ();
	OLED_Init();

	while(1)
	{    
	 Main_UI();		
	}

	}
