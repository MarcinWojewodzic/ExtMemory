/*
 * Bootloader.h
 *
 *  Created on: Dec 7, 2024
 *      Author: user
 */

#ifndef BOOTLOADER_BOOTLOADER_H_
#define BOOTLOADER_BOOTLOADER_H_
#include "main.h"
#define BL_TRANSITION_TABLE_SIZE sizeof(BLTransitionTable) / sizeof(BLTransitionTable_TypeDef)
#define APP_START_ADDRESS        0x0800A000
typedef enum
{
   BL_STATE_INIT,
   BL_STATE_TEST_MEMORY,
   BL_STATE_ERROR,
   BL_STATE_END
} BLState_TypeDef;
typedef enum
{
   BL_EVENT_NOTHING,
   BL_EVENT_INIT_OK,
   BL_EVENT_TEST_OK,
   BL_EVENT_ERROR
} BLEvent_TypeDef;
typedef enum
{
   BL_STATUS_ERROR,
   BL_STATUS_OK
} BLStatus_TypeDef;
typedef struct
{
   BLState_TypeDef Source;
   BLState_TypeDef Destination;
   BLEvent_TypeDef Event;
} BLTransitionTable_TypeDef;
typedef struct
{
   BLStatus_TypeDef (*BLFunction)(void);
} BLVectorTable_TypeDef;
typedef struct
{
   BLState_TypeDef State;
   BLEvent_TypeDef Event;
} BL_TypeDef;
void BL_Handle(void);
#endif /* BOOTLOADER_BOOTLOADER_H_ */
