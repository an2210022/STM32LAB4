/*
 * fsm_man.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "fsm_man.h"
void fsm_man_run(){
	switch(status){
	case MAN_RED:
		UpdateBuffer(mode, timeRed);
		if(IsModeButtonPressed(0) == 1){
			SCH_Init();
			SCH_Add_Task(LED7, 0, 250);
			SCH_Add_Task(BlinkAMBER, 0, 500);
			mode = 3;
			UpdateBuffer(mode, TIME_AMBER);
			SCH_Add_Task(ResetStatus, 7000, 0);
			status = MAN_AMBER;
		}
		if(IsModeButtonPressed(1) == 1){
			if(timeRed < 99 && timeRed < 99 && timeGreen < 99){
			   SCH_Init();
			   timeRed++;
			   timeGreen++;
			   count = timeRed;
			   UpdateBuffer(mode, timeGreen);
			   SCH_Add_Task(LED7, 0, 250);
			   SCH_Add_Task(BlinkRED, 0, 500);
			   SCH_Add_Task(ResetStatus, 7000, 0);
			}
		}
		if(IsModeButtonPressed(2) == 1){
			SCH_Init();
			status = RED1_GREEN2;
			wait = 0;
			count = timeRed;
			UpdateBuffer(mode, count);
			SCH_Add_Task(LED7, 0, 250);
		}
		break;

	case MAN_AMBER:
//		SCH_Add_Task(BlinkAMBER, 0, 500);
		UpdateBuffer(mode, timeAmber);
		if(IsModeButtonPressed(0) == 1){
			SCH_Init();
			SCH_Add_Task(LED7, 0, 250);
			SCH_Add_Task(BlinkGREEN, 0, 500);
			mode = 4;
			UpdateBuffer(mode, TIME_GREEN);
			SCH_Add_Task(ResetStatus, 7000, 0);
			status = MAN_GREEN;
		}
		if(IsModeButtonPressed(1) == 1){
			if(timeRed < 99 && timeRed < 99 && timeGreen < 99){
			   SCH_Init();
			   timeAmber++;
			   timeRed++;
			   count = timeRed;
			   UpdateBuffer(mode, timeGreen);
			   SCH_Add_Task(LED7, 0, 250);
			   SCH_Add_Task(BlinkRED, 0, 500);
   			   SCH_Add_Task(ResetStatus, 7000, 0);
			}
		}
		if(IsModeButtonPressed(2) == 1){
			SCH_Init();
			status = RED1_GREEN2;
			wait = 0;
			count = timeRed;
			UpdateBuffer(mode, count);
			SCH_Add_Task(LED7, 0, 250);
		}
		break;

	case MAN_GREEN:
		UpdateBuffer(mode, timeGreen);
		if(IsModeButtonPressed(1) == 1){
			if(timeRed < 99 && timeRed < 99 && timeGreen < 99){
			   SCH_Init();
			   timeGreen++;
			   timeRed++;
			   count = timeRed;
			   UpdateBuffer(mode, timeGreen);
			   SCH_Add_Task(LED7, 0, 250);
			   SCH_Add_Task(BlinkRED, 0, 500);
			   SCH_Add_Task(ResetStatus, 7000, 0);
			}
		}
		if(IsModeButtonPressed(2) == 1){
			SCH_Init();
			status = RED1_GREEN2;
			wait = 0;
			count = timeRed;
			UpdateBuffer(mode, count);
			SCH_Add_Task(LED7, 0, 250);
		}
		if(IsModeButtonPressed(0) == 1){
			SCH_Init();
			status = INIT;
			count = TIME_RED;
			mode = 1;
			UpdateBuffer(mode, count);
		}
		break;
	default:
		break;
	}
}

