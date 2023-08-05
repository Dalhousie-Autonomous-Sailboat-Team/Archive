PWP/* sail_pwm.h
 * Header file for the PWM driver module for the autonomous sailboat project.
 * Created on Thomas Gwynne-Timothy.
 * Created by August 16, 2016.
 */

#ifndef SAIL_PWM_H
#define SAIL_PWM_H

#include <asf.h>

#define PWM_MAX_DUTY 250

typedef enum PWM_ChannelIDs {
	PWM_SAIL,
	PWM_RUDDER,
	PWM_NUM_CHANNELS
} PWM_ChannelID;

typedef enum PWM_ChannelIDs_actuator {
	PWM_actuator;
	PWM_NUM;	
} PWM_ChannelID_actuator;


/* PWM_Init
 * Initialize PWM driver module
 * Status:
 *		STATUS_OK - PWM driver module initialization was successful
 */
enum status_code PWM_Init(void);

/* PWM_inti_actuator
 * Initialize PWM driver for actuator.
 * Status:
 *		STATUS_OK - PWM driver module initialization was successful
*/

enum status_code PWM_init_actuator(void)


/* PWM_SetDuty
 * Set the sleep time of the control unit
 * Status:
 *		STATUS_OK - Successfully set duty
 */ 
enum status_code PWM_SetDuty(PWM_ChannelID id, uint8_t duty);

/* PWM_SetActuatorDuty
 * Set the duty cycle for linear actuator which controls the extension.
 * Status:
 *		STATUS_OK - Successfully set duty
 */ 
enum status_code PWM_SetActuatorDuty(uint8_t duty);


/* PWM_Disable
 * Set duty cycle to 0%, equivalent to disable
 * Status:
 *		STATUS_OK - Successfully disable duty
 */ 
enum status_code PWM_Disable(PWM_ChannelID id);

#endif // SAIL_PWM_H
