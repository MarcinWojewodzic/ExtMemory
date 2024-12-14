/*
 * Bootloader.c
 *
 *  Created on: Dec 7, 2024
 *      Author: user
 */

#include "Bootloader.h"
#include "APSXX04L.h"
#include "main.h"
#include "stdio.h"
static BLStatus_TypeDef BL_InitFunction(void);
static BLStatus_TypeDef BL_TestMemoryFuction(void);
static BLStatus_TypeDef BL_EndFunction(void);
static BLStatus_TypeDef BL_ErrorFunction(void);
static void BL_ChangeState(void);
__IO static BL_TypeDef Bl                            = { 0 };
static BLTransitionTable_TypeDef BLTransitionTable[] = { { BL_STATE_INIT, BL_STATE_TEST_MEMORY, BL_EVENT_INIT_OK },
                                                         { BL_STATE_TEST_MEMORY, BL_STATE_END, BL_EVENT_TEST_OK },
                                                         { BL_STATE_INIT, BL_STATE_ERROR, BL_EVENT_ERROR },
                                                         { BL_STATE_TEST_MEMORY, BL_STATE_ERROR, BL_EVENT_ERROR } };
static BLVectorTable_TypeDef BLVectorTable[]         = { { BL_InitFunction }, { BL_TestMemoryFuction }, { BL_ErrorFunction }, { BL_EndFunction } };
void BL_Handle(void)
{
   if(BLVectorTable[Bl.State].BLFunction != NULL)
   {
      if(BLVectorTable[Bl.State].BLFunction() != BL_STATUS_OK)
      {
         Bl.Event = BL_EVENT_ERROR;
      }
   }
   BL_ChangeState();
}
static BLStatus_TypeDef BL_InitFunction(void)
{
   BLStatus_TypeDef Status = BL_STATUS_OK;
   if(APSXX04L_Init() == APSXX04L_ERROR)
   {
      Status = BL_STATUS_ERROR;
   }
   Bl.Event = BL_EVENT_INIT_OK;
   return Status;
}
static BLStatus_TypeDef BL_TestMemoryFuction(void)
{
   BLStatus_TypeDef Status = BL_STATUS_OK;
   uint8_t TempWrite[256]  = { 0 };
   uint8_t TempRead[256]   = { 0 };
   for(int i = 0; i < 256; i++)
   {
      TempWrite[i] = i;
   }
   if(APSXX04L_Write(0x0, TempWrite, 256) != APSXX04L_OK)
   {
      Status = BL_STATUS_ERROR;
   }
   else if(APSXX04L_Read(0x0, TempRead, 256) != APSXX04L_OK)
   {
      Status = BL_STATUS_ERROR;
   }
   else
   {
      for(int i = 0; i < 256; i++)
      {
         if(TempWrite[i] != TempRead[i])
         {
            Status = BL_STATUS_ERROR;
         }
      }
   }
   Bl.Event = BL_EVENT_TEST_OK;
   return Status;
}
static BLStatus_TypeDef BL_EndFunction(void)
{
   BLStatus_TypeDef Status = BL_STATUS_ERROR;
   if(APSXX04L_EnterMemoryMappedMode() == APSXX04L_OK)
   {
      __disable_irq();
      __disable_fault_irq();
      void (*app_reset_handler)(void) = (void *)(*((volatile uint32_t *)(0x08020000 + 4U)));
      __set_MSP(*(volatile uint32_t *)0x08020000);
      app_reset_handler();
   }
   return Status;
}
static BLStatus_TypeDef BL_ErrorFunction(void)
{
   BLStatus_TypeDef Status = BL_STATUS_ERROR;
   while(1)
      ;
   return Status;
}
static void BL_ChangeState(void)
{
   for(int i = 0; i < BL_TRANSITION_TABLE_SIZE; i++)
   {
      if(Bl.State == BLTransitionTable[i].Source && Bl.Event == BLTransitionTable[i].Event)
      {
         Bl.State = BLTransitionTable[1].Destination;
         Bl.Event = BL_EVENT_NOTHING;
         return;
      }
   }
   Bl.Event = BL_EVENT_NOTHING;
   return;
}
