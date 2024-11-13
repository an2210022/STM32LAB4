/*
 * fsm_auto.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "fsm_auto.h"
void fsm_auto_run(){
	switch(status){
	case INIT:
		setTimer3(250);
		timeRed = TIME_RED;
		timeAmber = TIME_AMBER;
		timeGreen = TIME_GREEN;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_All, 1);
		status = RED1_GREEN2;
		mode = 1;
		UpdateBuffer(mode, count);
		setTimer1(timeGreen*1000);
		if(IsModeButtonPressed(0) == 1){
			mode = 2;
			UpdateBuffer(mode, timeRed);
			status = MAN_RED;
			setTimer2(7000);
			setTimer1(500);
			setTimer3(250);
		}
		break;
	case RED1_GREEN2:
		displayRED1();
		displayGREEN2();
		if(timer1_flag == 1){
			status = RED1_AMBER2;
			setTimer1(timeAmber*1000);
		}
		if(IsModeButtonPressed(0) == 1){
			mode = 2;
			UpdateBuffer(mode, timeRed);
			status = MAN_RED;
			setTimer1(500);
			setTimer2(7000);
			setTimer3(250);
		}
		break;
	case RED1_AMBER2:
		displayRED1();
		displayAMBER2();
		if(timer1_flag == 1){
			status = GREEN1_RED2;
			setTimer1(timeGreen*1000);
		}
		if(IsModeButtonPressed(0) == 1){
			mode = 2;
			UpdateBuffer(mode, timeRed);
			status = MAN_RED;
			setTimer1(500);
			setTimer2(7000);
			setTimer3(250);
		}
		break;
	case GREEN1_RED2:
		displayGREEN1();
		displayRED2();
		if(timer1_flag == 1){
			status = AMBER1_RED2;
			setTimer1(timeAmber*1000);
		}
		if(IsModeButtonPressed(0) == 1){
			mode = 2;
			UpdateBuffer(mode, timeRed);
			status = MAN_RED;
			setTimer1(500);
			setTimer2(7000);
			setTimer3(250);
		}
		break;
	case AMBER1_RED2:
		displayAMBER1();
		displayRED2();
		if(timer1_flag == 1){
			status = RED1_GREEN2;
			setTimer1(timeGreen*1000);
		}
		if(IsModeButtonPressed(0) == 1){
			mode = 2;
			UpdateBuffer(mode, timeRed);
			status = MAN_RED;
			setTimer1(500);
			setTimer2(7000);
			setTimer3(250);
		}
		break;
	default:
		break;
	}
	if(timer3_flag == 1){
		if(index == 4) {index = 0; count++; UpdateBuffer(mode, count);}
		setTimer3(250);
		Update7SEG(index++);
	}
}

