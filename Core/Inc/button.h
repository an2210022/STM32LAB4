/*
 * MODE_BUTTON.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "main.h"
#ifndef INC_MODE_BUTTON_H_
#define INC_MODE_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET


int IsModeButtonPressed();
void getKeyInput1();


#endif /* INC_MODE_BUTTON_H_ */
