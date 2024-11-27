/*
 * global.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "global.h"
int status = 0;
int mode = 1;
int count = 1;
int led_buffer[4];
int index = 0;
int timeRed = TIME_RED;
int timeAmber = TIME_AMBER;
int timeGreen = TIME_GREEN;
uint64_t wait = 0;
int wait1 = 0;
void LED7(void) {
	if(index == 4) {
		index = 0;
		count--;
		if(count == 0){
			count = timeRed;
		}
		UpdateBuffer(mode, count);
	}
    Update7SEG(index);
    index++;
}
void ResetStatus(void){
	status = INIT;
	mode = 1;
//	SCH_Add_Task(LED7, 0, 250);
}
