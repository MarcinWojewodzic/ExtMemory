/*
 * APSXX04L.c
 *
 *  Created on: Dec 6, 2024
 *      Author: user
 */
#include "APSXX04L.h"

#include "main.h"
#include "octospi.h"
static uint8_t APSXX04L_WriteCmdS(uint8_t Cmd)
{
   OSPI_RegularCmdTypeDef sCommand = { 0 };
   // Konfiguracja komendy
   sCommand.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
   sCommand.FlashId            = HAL_OSPI_FLASH_ID_1;
   sCommand.Instruction        = Cmd;
   sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
   sCommand.AddressMode        = HAL_OSPI_ADDRESS_NONE;
   sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
   sCommand.DataMode           = HAL_OSPI_DATA_NONE;
   sCommand.DummyCycles        = 0;
   if(HAL_OSPI_Command(&hospi1, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }
   return APSXX04L_OK;
}
static uint8_t APSXX04L_WriteCmdQ(uint8_t Cmd)
{
   OSPI_RegularCmdTypeDef sCommand = { 0 };
   // Konfiguracja komendy
   sCommand.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
   sCommand.FlashId            = HAL_OSPI_FLASH_ID_1;
   sCommand.Instruction        = Cmd;
   sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_4_LINES;
   sCommand.AddressMode        = HAL_OSPI_ADDRESS_NONE;
   sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
   sCommand.DataMode           = HAL_OSPI_DATA_NONE;
   sCommand.DummyCycles        = 0;
   if(HAL_OSPI_Command(&hospi1, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }
   return APSXX04L_OK;
}
static uint8_t APSXX04L_ReadDataRegS(uint8_t Reg, uint8_t *Data, uint8_t Size)
{
   OSPI_RegularCmdTypeDef sCommand = { 0 };

   /* Initialize the read register command */
   sCommand.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
   sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_1_LINE;
   sCommand.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
   sCommand.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
   sCommand.Instruction        = Reg;
   sCommand.AddressMode        = HAL_OSPI_ADDRESS_1_LINE;
   sCommand.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
   sCommand.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
   sCommand.Address            = Reg;
   sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
   sCommand.DataMode           = HAL_OSPI_DATA_1_LINE;
   sCommand.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
   sCommand.NbData             = Size;
   sCommand.DummyCycles        = 0;
   sCommand.DQSMode            = HAL_OSPI_DQS_DISABLE;
   sCommand.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

   /* Configure the command */
   if(HAL_OSPI_Command(&hospi1, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   /* Reception of the data */
   if(HAL_OSPI_Receive(&hospi1, (uint8_t *)Data, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   return APSXX04L_OK;
}
static uint8_t APSXX04L_ReadDataRegQ(uint8_t Reg, uint8_t *Data, uint8_t Size)
{
   OSPI_RegularCmdTypeDef sCommand = { 0 };

   /* Initialize the read register command */
   sCommand.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
   sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_4_LINES;
   sCommand.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
   sCommand.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
   sCommand.Instruction        = Reg;
   sCommand.AddressMode        = HAL_OSPI_ADDRESS_4_LINES;
   sCommand.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
   sCommand.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
   sCommand.Address            = Reg;
   sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
   sCommand.DataMode           = HAL_OSPI_DATA_4_LINES;
   sCommand.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
   sCommand.NbData             = Size;
   sCommand.DummyCycles        = 0;
   sCommand.DQSMode            = HAL_OSPI_DQS_DISABLE;
   sCommand.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

   /* Configure the command */
   if(HAL_OSPI_Command(&hospi1, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   /* Reception of the data */
   if(HAL_OSPI_Receive(&hospi1, (uint8_t *)Data, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   return APSXX04L_OK;
}
uint8_t APSXX04L_EnterMemoryMappedMode(void)
{
   OSPI_RegularCmdTypeDef sCommand        = { 0 };
   OSPI_MemoryMappedTypeDef sMemMappedCfg = { 0 };

   /* Initialize the write command */
   sCommand.OperationType      = HAL_OSPI_OPTYPE_WRITE_CFG;
   sCommand.FlashId            = HAL_OSPI_FLASH_ID_1;
   sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_4_LINES;
   sCommand.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
   sCommand.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
   sCommand.Instruction        = 0x02;
   sCommand.AddressMode        = HAL_OSPI_ADDRESS_4_LINES;
   sCommand.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
   sCommand.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
   sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
   sCommand.DataMode           = HAL_OSPI_DATA_4_LINES;
   sCommand.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
   sCommand.DummyCycles        = 0;
   sCommand.DQSMode            = HAL_OSPI_DQS_ENABLE;
   sCommand.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

   if(HAL_OSPI_Command(&hospi1, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }
   /* Initialize the read command */
   sCommand.OperationType      = HAL_OSPI_OPTYPE_READ_CFG;
   sCommand.FlashId            = HAL_OSPI_FLASH_ID_1;
   sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_4_LINES;
   sCommand.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
   sCommand.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
   sCommand.Instruction        = 0xEB;
   sCommand.AddressMode        = HAL_OSPI_ADDRESS_4_LINES;
   sCommand.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
   sCommand.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
   sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
   sCommand.DataMode           = HAL_OSPI_DATA_4_LINES;
   sCommand.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
   sCommand.DummyCycles        = 6;
   sCommand.DQSMode            = HAL_OSPI_DQS_DISABLE;
   sCommand.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

   if(HAL_OSPI_Command(&hospi1, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   /* OctoSPI activation of memory-mapped mode */
   sMemMappedCfg.TimeOutActivation = HAL_OSPI_TIMEOUT_COUNTER_DISABLE;
   sMemMappedCfg.TimeOutPeriod     = 0xFFU;

   if(HAL_OSPI_MemoryMapped(&hospi1, &sMemMappedCfg) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   return APSXX04L_OK;
}
static uint8_t APSXX04L_HighClcConfig(void)
{
   HAL_OSPI_DeInit(&hospi1);
   OSPIM_CfgTypeDef sOspiManagerCfg  = { 0 };
   hospi1.Instance                   = OCTOSPI1;
   hospi1.Init.FifoThreshold         = 1;
   hospi1.Init.DualQuad              = HAL_OSPI_DUALQUAD_DISABLE;
   hospi1.Init.MemoryType            = HAL_OSPI_MEMTYPE_APMEMORY;
   hospi1.Init.DeviceSize            = 23;
   hospi1.Init.ChipSelectHighTime    = 2;
   hospi1.Init.FreeRunningClock      = HAL_OSPI_FREERUNCLK_DISABLE;
   hospi1.Init.ClockMode             = HAL_OSPI_CLOCK_MODE_0;
   hospi1.Init.WrapSize              = HAL_OSPI_WRAP_NOT_SUPPORTED;
   hospi1.Init.ClockPrescaler        = 4;
   hospi1.Init.SampleShifting        = HAL_OSPI_SAMPLE_SHIFTING_HALFCYCLE;
   hospi1.Init.DelayHoldQuarterCycle = HAL_OSPI_DHQC_DISABLE;
   hospi1.Init.ChipSelectBoundary    = 0;
   hospi1.Init.DelayBlockBypass      = HAL_OSPI_DELAY_BLOCK_BYPASSED;
   hospi1.Init.MaxTran               = 255;
   hospi1.Init.Refresh               = 0;
   if(HAL_OSPI_Init(&hospi1) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }
   sOspiManagerCfg.ClkPort   = 1;
   sOspiManagerCfg.NCSPort   = 1;
   sOspiManagerCfg.IOLowPort = HAL_OSPIM_IOPORT_1_LOW;
   if(HAL_OSPIM_Config(&hospi1, &sOspiManagerCfg, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }
   return APSXX04L_OK;
}
uint8_t APSXX04L_Write(uint32_t Address, uint8_t *Data, uint32_t Size)
{
   OSPI_RegularCmdTypeDef sCommand = { 0 };

   /* Initialize the write command */
   sCommand.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
   sCommand.FlashId            = HAL_OSPI_FLASH_ID_1;
   sCommand.Instruction        = 0x2;
   sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_4_LINES;
   sCommand.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
   sCommand.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
   sCommand.Address            = Address;
   sCommand.AddressMode        = HAL_OSPI_ADDRESS_4_LINES;
   sCommand.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
   sCommand.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
   sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
   sCommand.DataMode           = HAL_OSPI_DATA_4_LINES;
   sCommand.NbData             = Size;
   sCommand.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
   sCommand.DummyCycles        = 0;
   sCommand.DQSMode            = HAL_OSPI_DQS_DISABLE;
   sCommand.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

   /* Configure the command */
   if(HAL_OSPI_Command(&hospi1, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   /* Transmission of the data */
   if(HAL_OSPI_Transmit(&hospi1, Data, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   return APSXX04L_OK;
}
uint8_t APSXX04L_Read(uint32_t Address, uint8_t *Data, uint32_t Size)
{
   OSPI_RegularCmdTypeDef sCommand = { 0 };

   /* Initialize the read command */
   sCommand.OperationType      = HAL_OSPI_OPTYPE_COMMON_CFG;
   sCommand.FlashId            = HAL_OSPI_FLASH_ID_1;
   sCommand.InstructionMode    = HAL_OSPI_INSTRUCTION_4_LINES;
   sCommand.InstructionSize    = HAL_OSPI_INSTRUCTION_8_BITS;
   sCommand.InstructionDtrMode = HAL_OSPI_INSTRUCTION_DTR_DISABLE;
   sCommand.Instruction        = 0xEB;
   sCommand.AddressMode        = HAL_OSPI_ADDRESS_4_LINES;
   sCommand.AddressSize        = HAL_OSPI_ADDRESS_24_BITS;
   sCommand.AddressDtrMode     = HAL_OSPI_ADDRESS_DTR_DISABLE;
   sCommand.Address            = Address;
   sCommand.AlternateBytesMode = HAL_OSPI_ALTERNATE_BYTES_NONE;
   sCommand.DataMode           = HAL_OSPI_DATA_4_LINES;
   sCommand.DataDtrMode        = HAL_OSPI_DATA_DTR_DISABLE;
   sCommand.NbData             = Size;
   sCommand.DummyCycles        = 6;
   sCommand.DQSMode            = HAL_OSPI_DQS_DISABLE;
   sCommand.SIOOMode           = HAL_OSPI_SIOO_INST_EVERY_CMD;

   /* Configure the command */
   if(HAL_OSPI_Command(&hospi1, &sCommand, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   /* Reception of the data */
   if(HAL_OSPI_Receive(&hospi1, Data, HAL_OSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
   {
      return APSXX04L_ERROR;
   }

   return APSXX04L_OK;
}
uint8_t APSXX04L_Init(void)
{
   uint8_t Temp[9];
   uint8_t Status;
   Status = APSXX04L_WriteCmdS(0x66);
   Status = APSXX04L_WriteCmdS(0x99);
   Status = APSXX04L_WriteCmdQ(0x66);
   Status = APSXX04L_WriteCmdQ(0x99);
   HAL_Delay(1);
   if(Status == APSXX04L_OK)
   {
      Status = APSXX04L_ReadDataRegS(0x9F, Temp, 9);
      if(Temp[1] == 93)
      {
         __DSB();

         Status = APSXX04L_WriteCmdS(0x35);
         if(Status == APSXX04L_OK)
         {
            Status = APSXX04L_HighClcConfig();
         }
      }
   }
   return Status;
}
