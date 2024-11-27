/*
 * fsm_auto.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "fsm_auto.h"
void fsm_auto_run(){
	switch (status) {
	    case INIT:
//	    	SCH_Init();
	    	mode = 1;
	        timeRed = TIME_RED;
	        timeAmber = TIME_AMBER;
	        timeGreen = TIME_GREEN;
	        status = RED1_GREEN2;
	        count = timeRed;
	        wait = timeGreen;
	        UpdateBuffer(mode, count);
//	        SCH_Add_Task(LED7, 0, 250);
	        break;

	    case RED1_GREEN2:
	        displayRED1();
	        displayGREEN2();
	        if(wait == 0){
	        	status = RED1_AMBER2;
	        	wait = timeAmber;
	        }
	        else{
	        	--wait;
	        }
	        if(IsModeButtonPressed(0) == 1){
//	        	SCH_Init();
	        	OFF();
	        	mode = 2;
	        	wait = 7;
	        	UpdateBuffer(mode, timeRed);
//	        	SCH_Add_Task(LED7, 0, 250);
//	        	ResetStatus();
	        	status = MAN_RED;
	        }
	        break;

	    case RED1_AMBER2:
	        displayRED1();
	        displayAMBER2();
	        if(wait == 0){
	        	 status = GREEN1_RED2;
	        	 wait = timeGreen;
	        }
	        else{
	        	 --wait;
	        }
	        if(IsModeButtonPressed(0) == 1){
	        //	        	SCH_Init();
	        	        	OFF();
	        	        	mode = 2;
	        	        	wait = 7;
	        	        	UpdateBuffer(mode, timeRed);
	        //	        	SCH_Add_Task(LED7, 0, 250);
//	        	        	ResetStatus();
	        	        	status = MAN_RED;
	        	        }
	        break;

	    case GREEN1_RED2:
	        displayGREEN1();
	        displayRED2();
	        if(wait == 0){
	        	status = AMBER1_RED2;
	        	wait = timeAmber;
	        }
	        else{
	        	--wait;
	        }
	        if(IsModeButtonPressed(0) == 1){
	        //	        	SCH_Init();
	        	        	OFF();
	        	        	mode = 2;
	        	        	wait = 7;
	        	        	UpdateBuffer(mode, timeRed);
	        //	        	SCH_Add_Task(LED7, 0, 250);
//	        	        	ResetStatus();
	        	        	status = MAN_RED;
	        	        }
	        break;

	    case AMBER1_RED2:
	        displayAMBER1();
	        displayRED2();
	        if(wait == 0){
	        	status = RED1_GREEN2;;
	        	wait = timeGreen;
	       }
	       else{
	        	--wait;
	       }
	        if(IsModeButtonPressed(0) == 1){
	        //	        	SCH_Init();
	        	        	OFF();
	        	        	mode = 2;
	        	        	wait = 7;
	        	        	UpdateBuffer(mode, timeRed);
	        //	        	SCH_Add_Task(LED7, 0, 250);
//	        	        	ResetStatus();
	        	        	status = MAN_RED;
	        	        }
	        break;

	    default:
	        break;
	    }

}

//void display(){
//	switch (status) {
//		    case INIT:
////		    	SCH_Init();
////		    	mode = 1;
////		        timeRed = TIME_RED;
////		        timeAmber = TIME_AMBER;
////		        timeGreen = TIME_GREEN;
//		        status = RED1_GREEN2;
////		        count = timeRed;
////		        wait = 0;
//		        UpdateBuffer(mode, count);
////		        SCH_Add_Task(LED7, 0, 250);
//		        break;
//
//		    case RED1_GREEN2:
//		        displayRED1();
//		        displayGREEN2();
////		        wait += timeGreen;
////		        status = RED1_AMBER2;
////		        if(IsModeButtonPressed(0) == 1){
////		        	SCH_Init();
////		        	OFF();
////		        	mode = 2;
////		        	wait = 0;
////		        	UpdateBuffer(mode, timeRed);
////		        	SCH_Add_Task(LED7, 0, 250);
////		        	SCH_Add_Task(BlinkRED, 0, 500);
////		        	SCH_Add_Task(ResetStatus, 7000, 0);
////		        	status = MAN_RED;
////		        }
//		        break;
//
//		    case RED1_AMBER2:
//		        displayRED1();
//		        displayAMBER2();
////		        wait += timeAmber;
//		        status = GREEN1_RED2;
////		        if(IsModeButtonPressed(0) == 1){
////		        	SCH_Init();
////		        	OFF();
////		        	mode = 2;
////		        	wait = 0;
////		        	UpdateBuffer(mode, timeRed);
////		        	SCH_Add_Task(LED7, 0, 250);
////		        	SCH_Add_Task(BlinkRED, 0, 500);
////		        	SCH_Add_Task(ResetStatus, 7000, 0);
////		        	status = MAN_RED;
////		        }
//		        break;
//
//		    case GREEN1_RED2:
//		        displayGREEN1();
//		        displayRED2();
////		        wait += timeGreen;
////		        status = AMBER1_RED2;
////		        if(IsModeButtonPressed(0) == 1){
////		        	SCH_Init();
////		        	OFF();
////		        	mode = 2;
////		        	wait = 0;
////		        	UpdateBuffer(mode, timeRed);
////		        	SCH_Add_Task(LED7, 0, 250);
////		        	SCH_Add_Task(BlinkRED, 0, 500);
////		        	SCH_Add_Task(ResetStatus, 7000, 0);
////		        	status = MAN_RED;
////		        }
//		        break;
//
//		    case AMBER1_RED2:
//		        displayAMBER1();
//		        displayRED2();
////		        wait += timeAmber;
////		        status = RED1_GREEN2;
////		        if(IsModeButtonPressed(0) == 1){
////		        	SCH_Init();
////		        	OFF();
////		        	mode = 2;
////		        	wait = 0;
////		        	UpdateBuffer(mode, timeRed);
////		        	SCH_Add_Task(LED7, 0, 250);
////		        	SCH_Add_Task(BlinkRED, 0, 500);
////		        	SCH_Add_Task(ResetStatus, 7000, 0);
////		        	status = MAN_RED;
////		        }
//		        break;
//
//		    default:
//		        break;
//		    }
//}

