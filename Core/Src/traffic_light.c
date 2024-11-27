/*
 * traffic_light.c
 *
 *  Created on: Oct 30, 2024
 *      Author: Admin
 */
#include "traffic_light.h"
void displayRED1(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
}
void displayAMBER1(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
}
void displayGREEN1(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
}
void displayRED2(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
}
void displayAMBER2(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
}
void displayGREEN2(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
}
void BlinkRED(){
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
}
void BlinkAMBER(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
}
void BlinkGREEN(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
}
void OFF(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
}
