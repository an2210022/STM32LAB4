/*
 * led7_segment.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_
#include "main.h"
#include "global.h"
void display7SEG(int num);
void Update7SEG(int cnt);
void UpdateBuffer(int m, int time);
void SEG0(void);
void SEG1(void);
void SEG2(void);
void SEG3(void);

#endif /* INC_LED7_SEGMENT_H_ */
