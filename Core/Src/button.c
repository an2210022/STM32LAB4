/*
 * MODE_BUTTON.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "button.h"
#include "main.h"
int KeyReg0[3] = {NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE};
int KeyReg3[3] = {NORMAL_STATE};
int Time = 200;
int ButtonFlag[3] = {0};


int IsModeButtonPressed(int pos){
	if(ButtonFlag[pos] == 1){
		ButtonFlag[pos] = 0;
		return 1;
	}
	return 0;
}

void MODEProcess(int idx){
	ButtonFlag[idx] = 1;
}
void getKeyInput1(){
	for (int i = 0; i < 3; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = (i == 0) ? HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) :
		             (i == 1) ? HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) :
		             HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE){
					MODEProcess(i);
					Time = 200;
				}
			}
			else{
				Time--;
				if(Time == 0){
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
