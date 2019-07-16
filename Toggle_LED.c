#include "stm32f4xx.h"                 			 // Device header
//enable clock for ports A and C
int main (void) {
	 RCC->AHB1ENR |= 0x5; 				//Clock access to A and C enabled
	 GPIOA->MODER &= ~0x800;
	 GPIOA->MODER |= 0x400;				//01 to MODER5 -> PA5 output
	 GPIOC->MODER &= ~0xC000000; 			//clears MODER13 -> PC13 input
																	//pins are input by default, not necessary to clear bits
	 while (1) {
		 if (GPIOC->IDR & 0x2000) {		//if PC13 is HIGH (button is not pressed)
			 GPIOA->BSRR |= 0x200000; 
		}
		 else {
			 GPIOA->BSRR |= 0x20;
		 }
	 }
}
