/* sail_actuator.c
 * Implementation of the actuator controller for the autonomous sailboat project.
 * Created by Manav Sohi.
 * Created by Oct 28, 2022.
 */

#include <asf.h>

#include "sail_pwm.h"
#include "sail_actuator.h"
#include "sail_debug.h"

#include <math.h>

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "sail_tasksinit.h"

#define TEST_ACTUATOR_DELAY_MS 10000

#define SAIL_ANGLE_MIN 20
#define SAIL_ANGLE_MAX 120

#define SAIL_ANGLE_THOLD 0.001

#define ACTUATOR_MIN_EXTENSION 0
#define ACTUATOR_MAX_EXTENSION 70 // In duty cycle, percent extension relative to 100%

uint8_t map_angle(float angle, float angle_min, float angle_max, float linear_min, float linear_max) 
{
	uint8_t linear_map = ACTUATOR_MIN_EXTENSION;
	
	if(fabs(angle_max - angle_min) < SAIL_ANGLE_THOLD) {
		return linear_map;
	}
	
	
	
	return linear_map;
}

void Test_Actuator(void){
	
	TickType_t testDelay = pdMS_TO_TICKS(TEST_ACTUATOR_DELAY_MS);
	
	uint8_t actuator_duty[8] = {0, 25, 50, 75, 100, 75, 50, 25};
	int idx = 0;
	
	while(1){
		taskENTER_CRITICAL();
		watchdog_counter |= 0x20;
		taskEXIT_CRITICAL();
		running_task = eUpdateCourse;
		DEBUG_Write("\n\r<<<<<<<<<<< Testing Actuator >>>>>>>>>>\n\r");
		idx = idx >= 8 ? 0 : idx;
		DEBUG_Write("\n\r idx: %d && Duty: %d%% \n\r", idx, actuator_duty[idx]);
		PWM_SetActuatorDuty(actuator_duty[idx]); 
		idx++;
		vTaskDelay(testDelay);
	}
}

