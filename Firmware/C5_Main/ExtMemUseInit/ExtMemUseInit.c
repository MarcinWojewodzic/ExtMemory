/*
 * ExtMemUseInit.c
 *
 *  Created on: Dec 13, 2024
 *      Author: user
 */
#include "ExtMemUseInit.h"
#include "main.h"
void ExternalMemmoryRun(void)
{
   if((OCTOSPI1->CR & OCTOSPI_CR_FMODE_Msk) == OCTOSPI_CR_FMODE)
   {
      __NOP();
      __DSB();
      __enable_fault_irq();
      __enable_irq();
   }
   else
   {
      // Go to Bootloader
      __disable_irq();
      __disable_fault_irq();
      void (*app_reset_handler)(void) = (void *)(*((volatile uint32_t *)(BOOTLOADER_ADDRESS + 4U)));
      __set_MSP(*(volatile uint32_t *)BOOTLOADER_ADDRESS);
      app_reset_handler();
   }
}
void ExternalMemoryCopyDataSection(void)
{
   extern uint8_t _spsram_data;        // Początek PSRAM
   extern uint8_t _epsram_data;        // Koniec PSRAM
   extern uint8_t _sidata_psram_data;  // Dane w FLASH (LOADADDR(.psram_data))
   uint8_t *src = &_sidata_psram_data; // Dane źródłowe w FLASH
   uint8_t *dst = &_spsram_data;       // Adres docelowy w PSRAM
   while(dst < &_epsram_data)
   {
      *dst++ = *src++; // Kopiowanie słowo po słowie
   }
}
void ExternalMemorySetZeorsInBSSSection(void)
{
   extern uint8_t __psram_bss_start__;
   extern uint8_t __psram_bss_end__;
   uint8_t *dst = &__psram_bss_start__;
   while(dst < &__psram_bss_end__)
   {
      *dst++ = 0; // Zerowanie PSRAM .bss
   }
}
