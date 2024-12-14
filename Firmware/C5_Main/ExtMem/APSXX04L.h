/*
 * APSXZ04L.h
 *
 *  Created on: Dec 6, 2024
 *      Author: user
 */

#ifndef APSXX04L_H_
#define APSXX04L_H_
#include "main.h"
#define APSXX04L_ERROR -1
#define APSXX04L_OK    1
uint8_t APSXX04L_Init(void);
uint8_t APSXX04L_Read(uint32_t Address, uint8_t *Data, uint32_t Size);
uint8_t APSXX04L_Write(uint32_t Address, uint8_t *Data, uint32_t Size);
uint8_t APSXX04L_EnterMemoryMappedMode(void);
#endif /* APSXZ04L_H_ */
