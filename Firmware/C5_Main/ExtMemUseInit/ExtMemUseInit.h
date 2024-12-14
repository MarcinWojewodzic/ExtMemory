/*
 * ExtMemUseInit.h
 *
 *  Created on: Dec 13, 2024
 *      Author: user
 */

#ifndef EXTMEMUSEINIT_H_
#define EXTMEMUSEINIT_H_
#define BOOTLOADER_ADDRESS 0x08000000
void ExternalMemmoryRun(void);
void ExternalMemoryCopyDataSection(void);
void ExternalMemorySetZeorsInBSSSection(void);
#define EXT_RAM_DATA __attribute__((section(".psram_data")))
#define EXT_RAM_BSS  __attribute__((section(".psram_bss")))
#endif /* EXTMEMUSEINIT_H_ */
