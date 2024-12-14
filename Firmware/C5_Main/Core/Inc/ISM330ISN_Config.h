/*
 * ISM330ISN_Config.h
 *
 *  Created on: Nov 30, 2024
 *      Author: user
 */

#ifndef INC_ISM330ISN_CONFIG_H_
#define INC_ISM330ISN_CONFIG_H_
#include "main.h"
#define ISM_Delay               HAL_Delay
#define ISM_WriteData           ISM_Write
#define ISM_ReceiveData         ISM_Receive
#define ISM_TransmitReceiveData ISM_TransmitReceive
#define ISM_CS_Low              ISM_CS_Low
#define ISM_CS_High             ISM_CS_High
#endif /* INC_ISM330ISN_CONFIG_H_ */
