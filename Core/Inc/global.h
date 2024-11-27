/*
 * global.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "traffic_light.h"
#include "led7_segment.h"
#include "software_timer.h"
#include "main.h"
#include "scheduler.h"
#define INIT 5
#define RED1_GREEN2 1
#define RED1_AMBER2 2
#define GREEN1_RED2 3
#define AMBER1_RED2 4

#define MAN_RED 6
#define MAN_AMBER 7
#define MAN_GREEN 8
void LED7(void);
void ResetStatus(void);
extern int status;
extern int wait1;
extern int mode;
extern int led_buffer[4];
extern int index;
extern int count;
extern int timeRed;
extern int timeAmber;
extern int timeGreen;
extern uint64_t wait;
#define TIME_RED 5
#define TIME_GREEN 3
#define TIME_AMBER 2
#endif /* INC_GLOBAL_H_ */
