/*
 * scheduler.c
 *
 *  Created on: Nov 22, 2024
 *      Author: Admin
 */
#include "scheduler.h"
sTasks SCH_tasks_G[SCH_MAX_TASKS];
//uint8_t curr_idx_task = 0;
uint8_t start = 0;
uint8_t end = 0;

void SCH_Init(void){
	int i;
//	curr_idx_task = 0;
	for(i = 0; i < SCH_MAX_TASKS; i++){
		SCH_tasks_G[i].pTask = 0x0000;
		SCH_tasks_G[i].Delay = 0;
		SCH_tasks_G[i].Period = 0;
		SCH_tasks_G[i].RunMe = 0;
		SCH_tasks_G[i].isRun = 0;
	}
	start = end = 0;

}

void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	if ((end + 1) % SCH_MAX_TASKS != start) {
	        SCH_tasks_G[end].pTask = pFunction;
	        SCH_tasks_G[end].Delay = DELAY / 10;
	        SCH_tasks_G[end].Period = PERIOD / 10;
	        SCH_tasks_G[end].RunMe = 0;
	        SCH_tasks_G[end].isRun = 1;
	        end = (end + 1) % SCH_MAX_TASKS;
	    }
}

void SCH_Update(void) {
	uint8_t i = start;
	while (i != end) {
	      if (SCH_tasks_G[i].isRun) {
	          if (SCH_tasks_G[i].Delay > 0) {
	              SCH_tasks_G[i].Delay--;
	          } else {
	              SCH_tasks_G[i].RunMe++;
	              if (SCH_tasks_G[i].Period > 0) {
	                  SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
	                }
	            }
	        }
	        i = (i + 1) % SCH_MAX_TASKS;
	  }
}

 void SCH_Dispatch_Tasks(void){
	 uint8_t i = start;
	     while (i != end) {
	       if (SCH_tasks_G[i].isRun && SCH_tasks_G[i].RunMe > 0) {
	           SCH_tasks_G[i].RunMe--;
	           (*SCH_tasks_G[i].pTask)();
	           if (SCH_tasks_G[i].Period == 0) {
//	               SCH_tasks_G[i].isRun = 0;
	        	   SCH_Delete_Task(i);
	           }
//	           break;
	       }
	         i = (i + 1) % SCH_MAX_TASKS;
	     }
}

void SCH_Delete_Task(uint8_t task_index){
	if (start == end) return;
	else{
		SCH_tasks_G[task_index].pTask = 0x0000;
		SCH_tasks_G[task_index].Delay = 0;
		SCH_tasks_G[task_index].Period = 0;
		SCH_tasks_G[task_index].RunMe = 0;
		SCH_tasks_G[task_index].isRun = 0;
	    uint8_t i;
	    for (i = task_index; i < end; i = (i + 1) % SCH_MAX_TASKS) {
	        uint8_t next = (i + 1) % SCH_MAX_TASKS;
	        SCH_tasks_G[i] = SCH_tasks_G[next];
	    }
	    end = (end - 1) % SCH_MAX_TASKS;
	}
 }
