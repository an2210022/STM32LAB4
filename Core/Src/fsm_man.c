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
		BlinkRED();
		if(IsModeButtonPressed(0) == 1){
			OFF();
			mode = 3;
			UpdateBuffer(mode, TIME_AMBER);
			status = MAN_AMBER;
			wait = 7;
		}
		if(IsModeButtonPressed(1) == 1){
			if(timeRed < 99 && timeRed < 99 && timeGreen < 99){
//			   SCH_Init();
			   timeRed++;
			   timeGreen++;
			   count = timeRed;
			   UpdateBuffer(mode, count);
			   wait = 7;
			}
		}
		if(wait == 0){
			status = INIT;
		}
		else{
			--wait;
		}
		if(IsModeButtonPressed(2) == 1){
			count = timeRed;
			wait = timeGreen;
			status = RED1_GREEN2;
//			OFF();
			UpdateBuffer(mode, count);
		}
		break;

	case MAN_AMBER:
		BlinkAMBER();
		UpdateBuffer(mode, timeAmber);
		if(IsModeButtonPressed(0) == 1){
					OFF();
					mode = 4;
					UpdateBuffer(mode, timeGreen);
					status = MAN_GREEN;
					wait = 7;
		}
		if(IsModeButtonPressed(1) == 1){
			if(timeRed < 99 && timeRed < 99 && timeGreen < 99){
//			   SCH_Init();
			   timeAmber++;
			   timeRed++;
			   count = timeAmber;
			   UpdateBuffer(mode, count);
			   wait = 7;
			}
		}
		if(wait == 0){
					status = INIT;
				}
				else{
					--wait;
				}
		if(IsModeButtonPressed(2) == 1){
			count = timeRed;
			wait = timeGreen;
			status = RED1_GREEN2;
			UpdateBuffer(mode, count);
		}
		break;

	case MAN_GREEN:
		BlinkGREEN();
		UpdateBuffer(mode, timeGreen);
		if(IsModeButtonPressed(1) == 1){
			if(timeRed < 99 && timeRed < 99 && timeGreen < 99){
//			   SCH_Init();
			   timeGreen++;
			   timeRed++;
			   count = timeGreen;
			   UpdateBuffer(mode, count);
			   wait = 7;
			}
		}
		if(wait == 0){
					status = INIT;
				}
				else{
					--wait;
				}
		if(IsModeButtonPressed(2) == 1){
			count = timeRed;
			wait = timeGreen;
			status = RED1_GREEN2;
			UpdateBuffer(mode, count);
		}
		if(IsModeButtonPressed(0) == 1){
//			SCH_Init();
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

