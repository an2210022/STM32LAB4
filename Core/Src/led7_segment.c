/*
 * display7SEG.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "main.h"
#include "led7_segment.h"
void display7SEG(int num){
		switch(num){
		case 0:
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin, 0);
			  	HAL_GPIO_WritePin(GPIOA, SEG6_Pin, 1);
			  	break;
		case 1:
			  	HAL_GPIO_WritePin(GPIOA, SEG1_Pin | SEG2_Pin, 0);
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin | SEG3_Pin, 1);
			  	break;
		case 2:
			  	HAL_GPIO_WritePin(GPIOA, SEG2_Pin | SEG5_Pin, 1);
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG4_Pin | SEG1_Pin | SEG6_Pin | SEG3_Pin, 0);
			  	break;
		case 3:
			  	HAL_GPIO_WritePin(GPIOA, SEG4_Pin | SEG5_Pin, 1);
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG2_Pin | SEG1_Pin | SEG6_Pin | SEG3_Pin, 0);
			  	break;
		case 4:
			  	HAL_GPIO_WritePin(GPIOA, SEG4_Pin | SEG3_Pin | SEG0_Pin, 1);
			  	HAL_GPIO_WritePin(GPIOA, SEG1_Pin | SEG2_Pin | SEG5_Pin | SEG6_Pin, 0);
			  	break;
		case 5:
			  	HAL_GPIO_WritePin(GPIOA, SEG4_Pin | SEG1_Pin, 1);
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG6_Pin | SEG5_Pin, 0);
			  	break;
		case 6:
			  	HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 1);
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG6_Pin | SEG5_Pin | SEG4_Pin, 0);
			  	break;
		case 7:
			  	HAL_GPIO_WritePin(GPIOA, SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 1);
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG1_Pin | SEG2_Pin, 0);
			  	break;
		case 8:
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
			  	break;
		case 9:
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
			  	HAL_GPIO_WritePin(GPIOA, SEG4_Pin, 1);
			  	break;
		default:
			  	HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 1);
			  	break;
		}
}

void Update7SEG(int cnt){
	switch(cnt){
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
		display7SEG(led_buffer[cnt]);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
		display7SEG(led_buffer[cnt]);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
		display7SEG(led_buffer[cnt]);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
		display7SEG(led_buffer[cnt]);
	break;

	default:
		break;
	}
}

void UpdateBuffer(int m, int time){
	led_buffer[0] = m/10;
	led_buffer[1] = m%10;
	led_buffer[2] = time/10;
	led_buffer[3] = time%10;
}
