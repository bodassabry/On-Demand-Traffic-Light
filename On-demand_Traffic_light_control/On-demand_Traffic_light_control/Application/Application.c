/*
 * Application.c
 *
 * Created: 13/11/2022 12:37:16
 *  Author: future
 */ 
#include "Application.h"

bool button_check = false;

uint8_t led = 1, buttonTime = 0;

void APP_init()
{
	LED_init(LED_1_PORT, LED_1_PIN);
	LED_init(LED_2_PORT, LED_2_PIN);
	LED_init(LED_3_PORT, LED_3_PIN);
	LED_init(LED_4_PORT, LED_4_PIN);
	LED_init(LED_5_PORT, LED_5_PIN);
	LED_init(LED_6_PORT, LED_6_PIN);
	BUTTON_init(BUTTON_1_PORT, BUTTON_1_PIN);
	INTERRUPTS_init();
	
}

uint8_t x = 0;
void APP_start()
{
	while (1)
	{
		// Normal mode
		if(button_check == false){
			// *car's leds will change every 5 seconds
			switch (led)
			{
				case 1:
					while (button_check == false && x<10)
					{
						if (BUTTON_read(BUTTON_1_PORT, BUTTON_1_PIN) == 1)
						{
							buttonTime++;
						}
						LED_off(LED_2_PORT, LED_2_PIN);
						LED_on(LED_1_PORT, LED_1_PIN);
						delay(500);
						x++;
					}
					led++;
					x = 0;
				break;
				case 2:
					while (button_check == false && x<10)
					{
						if (BUTTON_read(BUTTON_1_PORT, BUTTON_1_PIN) == 1)
						{
							buttonTime++;
						}
						LED_off(LED_1_PORT, LED_1_PIN);
						LED_toggle(LED_2_PORT, LED_2_PIN);
						delay(500);
						x++;
					}
					led++;
					x = 0;
				break;
				case 3:
					while (button_check == false && x<10)
					{
						if (BUTTON_read(BUTTON_1_PORT, BUTTON_1_PIN) == 1)
						{
							buttonTime++;
						}
						LED_off(LED_2_PORT, LED_2_PIN);
						LED_on(LED_3_PORT, LED_3_PIN);
						delay(500);
						x++;
					}
					led++;
					x = 0;
				break;
				case 4:
					while (button_check == false && x<10)
					{
						if (BUTTON_read(BUTTON_1_PORT, BUTTON_1_PIN) == 1)
						{
							buttonTime++;
						}
						LED_off(LED_3_PORT, LED_3_PIN);
						LED_toggle(LED_2_PORT, LED_2_PIN);
						delay(500);
						x++;
					}
					led = 1;
					x = 0;
				break;
			}
		}
		// *when button is pressed, change to pedestrian mode
		
		// Pedestrian mode
		// *check which led is on for cars
		else if (button_check == true)
		{
		// if car's red is on, ped's green gets on for 5 seconds and car's red is on for 5 seconds
			if (LED_read(LED_3_PORT, LED_3_PIN) == 1)
			{
				LED_on(LED_4_PORT, LED_4_PIN);
				delay(5000);
				LED_off(LED_3_PORT, LED_3_PIN);
				for (int i=0; i<10; i++)
				{
					LED_toggle(LED_2_PORT, LED_2_PIN);
					LED_toggle(LED_5_PORT, LED_5_PIN);
					delay(500);
				}
				LED_off(LED_2_PORT, LED_2_PIN);
				LED_off(LED_5_PORT, LED_5_PIN);
				LED_off(LED_4_PORT, LED_4_PIN);
				LED_on(LED_1_PORT, LED_1_PIN);
				LED_on(LED_6_PORT, LED_6_PIN);
				delay(5000);
			}
		// else if car's green is on, ped's red is on for 5 seconds and both yellow will start blinking for 5 seconds
			else if (LED_read(LED_1_PORT, LED_1_PIN) == 1 || LED_read(LED_2_PORT, LED_2_PIN) == 1)
			{
				LED_on(LED_6_PORT, LED_6_PIN);
				for (int i=0; i<10; i++)
				{
					LED_toggle(LED_2_PORT, LED_2_PIN);
					LED_toggle(LED_5_PORT, LED_5_PIN);
					delay(500);
				}
		// then ped's green is on and car's red is on for 5 seconds
				LED_off(LED_6_PORT, LED_6_PIN);
				LED_off(LED_1_PORT, LED_1_PIN);
				LED_off(LED_2_PORT, LED_2_PIN);
				LED_off(LED_5_PORT, LED_5_PIN);
				LED_on(LED_3_PORT, LED_3_PIN);
				LED_on(LED_4_PORT, LED_4_PIN);
				delay(5000);
				LED_off(LED_3_PORT, LED_3_PIN);
				for (int i=0; i<10; i++)
				{
					LED_toggle(LED_2_PORT, LED_2_PIN);
					LED_toggle(LED_5_PORT, LED_5_PIN);
					delay(500);
				}
				LED_off(LED_2_PORT, LED_2_PIN);
				LED_off(LED_5_PORT, LED_5_PIN);
				LED_off(LED_4_PORT, LED_4_PIN);
				LED_on(LED_1_PORT, LED_1_PIN);
				LED_on(LED_6_PORT, LED_6_PIN);
				delay(5000);
			}
		// back to normal mode again
			LED_off(LED_6_PORT, LED_6_PIN);
			led = 2;
			button_check = false;
			buttonTime = 0;
		}
		
	}
}

ISR(EXT_INT_0){
	if (buttonTime>1)
	{
		buttonTime = 0;
	}
	else
	{
		button_check = true;
	}
}