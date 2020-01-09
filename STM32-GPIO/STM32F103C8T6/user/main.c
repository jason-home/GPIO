#include "stm32f10x.h"
void LED0_Config(void);
void LED0_On(void);
void LED0_Off(void);
void Delay(unsigned long x);

int main()
{
		LED0_Config();
		while(1)
		{
			LED0_On();
			Delay(0x0FFFFF);
			LED0_Off();
			Delay(0x0FFFFF);
		}
	LED0_Off();
}

void LED0_Config()
{
    GPIO_InitTypeDef t_gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    
    t_gpio.GPIO_Pin=GPIO_Pin_7;
    t_gpio.GPIO_Mode=GPIO_Mode_Out_PP;
    t_gpio.GPIO_Speed=GPIO_Speed_2MHz;
    GPIO_Init(GPIOA,&t_gpio);
   
}

void LED0_On()
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);
}

void LED0_Off()
{
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
}

void Delay(unsigned long x)
{
	unsigned long j;
	for(j=0;j<x;j++);
}
