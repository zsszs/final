#include "LPC11xx.h"
#include "ui.h"
#include "oled.h"
#include "delay.h"
#include "key.h"
#include "temp.h"
//typedef enum
//{
//    KEY_DOWN  =   0,         
//    KEY_UP    =   1,         
//	
//} KEY_STATUS;
static uint8_t Arrow = 3,KEY_=0;

uint8_t AR[]="->";  // ��ʾ��ͷ
uint8_t AC[]="  ";  //

void KEY_Service()
{
	 KEY_=0;
	if((LPC_GPIO3->DATA&(1<<0)) == KEY_DOWN)     
	{
		
	  KEY_ = 1;
    delay();
		             
	} 
	
	if((LPC_GPIO3->DATA&(1<<1)) == KEY_DOWN)     
	{
		
	  KEY_ = 2;
    delay();
		            
	} 
	
	if((LPC_GPIO3->DATA&(1<<2)) == KEY_DOWN)     
	{
		
	  KEY_ = 3;
    delay();
		            
	} 
  
	if((LPC_GPIO3->DATA&(1<<3)) == KEY_DOWN)     
	{
		
	  KEY_ = 4;
    delay();
		            
	} 
}

uint8_t Main_Menu()
{
    
  uint8_t S3[]="   ---MAIN_MENU--- ";
	uint8_t S4[]="   temperature_test";
	uint8_t S5[]="   logo    ";
	uint8_t S6[]="   basic_information ";
	uint8_t S7[]="   Time_and_date ";

  OLED_CLS();                             
	//Draw_BMP(18,0,101,1,TOP_Phantom);
	OLED_P6x8Str(0,1,S3);
	OLED_P6x8Str(0,3,S4);
	OLED_P6x8Str(0,4,S5);
	OLED_P6x8Str(0,5,S6);
  OLED_P6x8Str(0,6,S7);

  OLED_P6x8Str(0,Arrow,AR);

    while(1)
    {
      KEY_ = 0;
      KEY_Service();  

      switch(KEY_)
      {
        case 1:
          OLED_P6x8Str(0,Arrow,AC);
			    Arrow--;
			      if(Arrow < 3) Arrow=6;
			        OLED_P6x8Str(0,Arrow,AR);
              KEY_ = 0;
			break;

        case 2:
          OLED_P6x8Str(0,Arrow,AC);
			    Arrow++;
			      if(Arrow > 6) Arrow=3;
			        OLED_P6x8Str(0,Arrow,AR);
              KEY_ = 0;
			break;
				
				case 3:
            switch(Arrow)
				{
					case 3:  return temperature_test_id;    break;  
          case 4:  return logo_id;                 break; 
					case 5:  return basic_information_id;  break;           
					case 6:  return Time_and_date_id;        break;
				}
                 KEY_ = 0;
				break;

        case 4:
            KEY_ = 0;
			return MAIN_MENU_ID;

			break;

		default:
			KEY_ = 0;break;
			}

	   }
	 }	

	 

uint8_t Main_UI()		 
{	

while(1)
{	
 switch(Main_Menu())
        {
        case 1:                                        
          OLED_CLS();
          while(1)
          {
            temp();
            if((LPC_GPIO3->DATA&(1<<3)) == KEY_DOWN) 
              break;
          }
          break;
     /************************?????????************************/    
        case 2:                                        
          OLED_CLS();
          OLED_P6x8Str(1,1,"Motor PWM Value:");
          OLED_P6x8Str(10,3,"RPM_Count:");
          OLED_P6x8Str(0,7,"Back");  
				 if((LPC_GPIO3->DATA&(1<<3)) == KEY_DOWN) 
          break;
          
     /***************************??????**************************/    
        case 3:                                         
          OLED_CLS();
          while(1)
          {
            OLED_P6x8Str(1,1,"zhang");
            if((LPC_GPIO3->DATA&(1<<3)) == KEY_DOWN) 
              break;
          }
          break;		

				}		 
}
 }   
