//#define F_CPU 8000000UL
#include <util/delay.h>
#include "USART.h"
#include "LCD.h"
#include "NEW__TYPES.h"
#include "std_macros.h"
#include "MyMacros.h"
#include "SPI.h"
#include "TIM1.h"
#include "EEPROM_interface.h"
void SetPass(void);
void SERVO_ON(void);
int main(void)
{

	TIM1_voidInit();
		TIM1_voidSetIcuRegValue(20000);
		TIM1_voidEnable(2);
		//Global_Interrupt_Enable();

    SPI_vInitMaster();
	UART_vInit(9600);
	u8 R_PC;     //holds the value UART transmission
	LCD_vInit();
	u8 status = Entery_status ;//default status of the system
	u8 Password[4];
	u8 True_Password[4];
	EEPROM_vRead(EEPROM_PASS_ADDRESS,True_Password);
	u8 Password_flag =0;//indicates if there is any fault in the password entered by the user
	u16 temperatue= 0 ;


	DIO_vsetPINDir('B',4,HIGH);//DC_MOTOR pin that represents the AC


	// setting LEDs pins as output
	DIO_vsetPINDir('C',0,HIGH);
	DIO_vsetPINDir('C',1,HIGH);
	DIO_vsetPINDir('C',2,HIGH);
	DIO_vsetPINDir('C',3,HIGH);

	while (1)
	{

		switch(status)
				{


				/************this stage represent the entery mood os the system*************/
					case  Entery_status :
					       LCD_movecursor(1,1);
					       LCD_vSend_string("Welcole to Smart");
						   LCD_movecursor(2,1);
						   LCD_vSend_string("Home project :)");
						   _delay_ms(1000);
						   LCD_clearscreen();
						   LCD_movecursor(1,1);
						   LCD_vSend_string("You are at :");
						   LCD_movecursor(2,1);
						   LCD_vSend_string("Entery Mode");
					       _delay_ms(1000);
					       LCD_clearscreen();
						   status = Login_Status ;
						   break;
		          /***************at this stage the user is asked to enter the password**********************/
					case Login_Status :
					     LCD_movecursor(1,1);
					     LCD_vSend_string("Loging in.....");
						 _delay_ms(1500);
					     LCD_clearscreen();
						 LCD_movecursor(1,1);
						 LCD_vSend_string("Please Enter ");
						 LCD_movecursor(2,1);
						 LCD_vSend_string("Password :");
						 _delay_ms(1500);

						   u8 i=0;
						   for(i=0;i<=3;i++)
						   {
							   R_PC=UART_u8ReceiveData();
							   Password[i]=R_PC;
							   LCD_movecursor(2,(11+i));
							    LCD_vSend_char(R_PC);
								_delay_ms(250);
								LCD_movecursor(2,(11+i));
								LCD_vSend_char('X');
								_delay_ms(500);


						   }
						   _delay_ms(500);
						   LCD_clearscreen();
						   status =Chicking_password;
						   break;



						   /***********this stage represents cheking the password****************/
					    case Chicking_password :

					    	LCD_clearscreen();

					    	 for(i=0;i<=3;i++)
					    	 {

					    		if(Password[i]!=True_Password[i])//CHECKING IF THERE IS ANY WRONG NUMBER IN THE PASSWORD
					    			{
					    			Password_flag++ ;//RAIS THE FLAG TO INDECATE TJAT THE PASSWORD IS WRONG
					    			}

					    	 }
					    	 if(Password_flag>0)
					    	 {
					    	 	  LCD_clearscreen();
					    	 		LCD_movecursor(1,1);
					    	       LCD_vSend_string("WRONG PASSWORD");
					    	       LCD_movecursor(2,1);
					    	       LCD_vSend_string("Please Try Again");
					    	       Password_flag=0;
					    	       _delay_ms(500);
					    	 		 status = Entery_status ;//PREVENT THE YOUSER ATTEMP TO ENTER THE SYSTEM ,RETURN THE USER TO THE LOGGIN WINDOW
					    	 }
					    	 else
					    	 {
					    		 LCD_clearscreen();
					    		LCD_movecursor(1,1);
					    	  LCD_vSend_string("CORRECT PASSWORD");


					    		//Turn on Servo motor
					    	 SERVO_ON();//door is openning
					    		_delay_ms(500);
					    	 status = Main_menue ;//USER LOGGED IN
					    					    	 }


					break;
		          /*******************the options menue of the system***************************************/
					    case Main_menue :
					    	 LCD_clearscreen();
					    	LCD_movecursor(1,1);
					    	 LCD_vSend_string("A_C : (1) ");
					    	 LCD_movecursor(2,1);
					    	 LCD_vSend_string("Light : (2) ");

					    	 R_PC=UART_u8ReceiveData();//WAIT FOR THE USER TO CHOSE AN ELEMENT FROM THE MAIN MENUE TO GO FOR

					    	 switch(R_PC)
					    	 {
					    	 case '1':
					    		 _delay_ms(500);
					    		 status = A_C ;

					    		 break;


					    	 case '2' :
					    		 _delay_ms(500);
					    		 status =  Light ;
					    		 break;

					    	 }

					    	break;
		                 /***************AC status and temperature****************************/
					    	case A_C :



					    		temperatue = SPI_ui8TransmitRecive(AC_Riquest);//SEND THE AC code TO THE SLAVE TO GET THE LM35 SENSOR READING AFTER CONVERSION

					    		LCD_clearscreen();
					    		LCD_movecursor(1,1);
					            LCD_vSend_string("T=");


					    		if(temperatue<10)
					    				{
					    					LCD_movecursor(1,3);
					    					LCD_vSend_char(30);
					    					LCD_vSend_char((temperatue%10)+48);//represents the 1's digit + ASSCII of ZERO
					    					LCD_vSend_char('c');
					    					_delay_ms(500);
					    				}
					    				else if( temperatue<100)
					    				{
					    				LCD_movecursor(1,3);
					    				LCD_vSend_char((temperatue/10)+48);//rapresents the 10's digit+ ASSCII of ZERO
					    				LCD_vSend_char((temperatue%10)+48);//rapresents the 1's digit + ASSCII of ZERO
					    				LCD_vSend_char('c');
					    				_delay_ms(500);

					    		LCD_movecursor(1,8);
					    		LCD_vSend_string("AC:");

					    		switch(DIO_u8read('B',4))//CHECK WHETHER THE AC(DC MOTOR)IS ON OR OFF AND SHOW IT'S STATUS
					    		{
					    		case HIGH :
					    			LCD_vSend_string("ON(2)");

					    			break;
					    		case LOW :
					    		    LCD_vSend_string("OFF(2)");

					    			break;


					    		}

					    		LCD_movecursor(2,1);
					    		 LCD_vSend_string("Back:(1)");


					    		 R_PC=UART_u8ReceiveData();//WAIT FOR THE USER TO CHOSE AN ELEMENT
		                        switch(R_PC)
		                        {
		                        case '1' :
		                        	status = Main_menue ;
		                        break;
		                        case '2' :
		                             DIO_toggle('B',4) ;
		                        break;

		                        }

		                        break ;


		                        case Light :
		                        	LCD_clearscreen();
		                        	LCD_movecursor(1,1);
		                        	LCD_vSend_string("Status:");
		                        	u8 i =0;//REPRESENTS THE LEDS STATUS WICH IS ZERO BY DEFAULT
		                        	if(l==0)
		                        	{
		                        		LCD_vSend_string("OFF");
		                        		l++;
		                        	}	else
		                        	{
		                        		LCD_vSend_string("ON");
		                        		l=0;
		                        	}


		                        	LCD_movecursor(2,1);
		                        	LCD_vSend_string("Back:(1) Tog:(2)");
		                        	R_PC=UART_u8ReceiveData();
		                        	switch(R_PC)
		                        	 {
		                        	  case '1' :
		                        	  status = Main_menue ;
		                        	   break;
		                        	  case '2' :

		                        	       // DIO_toggle('C',0);
		                        	        //DIO_toggle('C',1);
		                        	        DIO_toggle('C',2);//TOGGLE LEDES
		                        	        //DIO_toggle('C',3);
		                        	            break;

		                          }
		                        	break;
				}






	}
}


void SERVO_ON(void)
{


	//	    // Move to 90 degrees
	//	    TIM1_voidSetCmpARegValue(1500);  // Adjust the value for precise 90 degrees
	//
	//	    // Wait for stability (optional)
	//	    _delay_ms(500);


	u16 u16Counter;

	// Move to 90 degrees
	for (u16Counter = 750; u16Counter < 1500; u16Counter++)
	{
		TIM1_voidSetCmpARegValue(u16Counter);
		_delay_ms(10);
		u16Counter	=        u16Counter+5	;
	}

	// Wait for stability (optional)
	_delay_ms(500);

	// Stop at 90 degrees
	TIM1_voidSetCmpARegValue(1500);  // Adjust the value for precise 90 degrees

	// You can add an optional delay for stability before returning, if needed
	// _delay_ms(500);
}

void SetPass(void)
{
	EEPROM_vWrite(EEPROM_PASS_ADDRESS,"1234");
}

