/**
  ******************************************************************************
  * @file    MB_eeprom.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    29-May-2012
  * @brief   This file contains all the functions prototypes for the EEPROM 
  *          emulation firmware library.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 
/*
		MODIFIED by Hexabitz for BitzOS (BOS) V0.2.2 - Copyright (C) 2017-2020 Hexabitz
    All rights reserved
*/
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MB_EEPROM_H
#define __MB_EEPROM_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Memory map: - STM32F091CB
				- Application: 0x08000000 - 0x0801D7FF >> 118 KB
		 - Read-only (RO): 0x0801D800 - 0x0801DFFF >> 2 KB, used to store topology information and Command Snippets
		- Emulated EEPROM: 0x0801E000 - 0x0801FFFF >> 8 KB, fits 1024 16-bit variables in 2 main-duplicate pages (A and B)
*/

#define APP_START_ADDRESS  		((uint32_t)0x08000000) 
#define RO_START_ADDRESS  		((uint32_t)0x0801D800) 
#define RO_MID_ADDRESS  			((uint32_t)0x0801DC00) 	// Snippets are stored here
#define EEPROM_START_ADDRESS  ((uint32_t)0x0801E000) 
#define FLASH_SIZE						((uint32_t)0x20000)			// All sizes in bytes
#define SRAM_SIZE							((uint32_t)0x8000)
#define PAGE_SIZE             ((uint32_t)0x0800)  		/* Page size = 2KByte for STM32F07x and STM32F09x devices */
#define NumOfPages						(FLASH_SIZE/PAGE_SIZE)


/* Pages A and B base and end addresses - Each page is extended into two pages 1 and 2 */
#define PAGEA1_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + 0x0000))
#define PAGEA1_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (PAGE_SIZE - 1)))
#define PAGEA2_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + PAGE_SIZE))
#define PAGEA2_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (2 * PAGE_SIZE - 1)))

#define PAGEB1_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + (2 * PAGE_SIZE)))
#define PAGEB1_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (3 * PAGE_SIZE - 1)))
#define PAGEB2_BASE_ADDRESS    ((uint32_t)(EEPROM_START_ADDRESS + (3 * PAGE_SIZE)))
#define PAGEB2_END_ADDRESS     ((uint32_t)(EEPROM_START_ADDRESS + (4 * PAGE_SIZE - 1)))


/* Used Flash pages for EEPROM emulation - Each one is twice page size */
#define PAGEA                 ((uint16_t)0x0000)
#define PAGEB                 ((uint16_t)0x0002)

/* No valid page define */
#define NO_VALID_PAGE         ((uint16_t)0x00AB)

/* Page status definitions */
#define ERASED                ((uint16_t)0xFFFF)     /* Page is empty */
#define RECEIVE_DATA          ((uint16_t)0xEEEE)     /* Page is marked to receive data */
#define VALID_PAGE            ((uint16_t)0x0000)     /* Page containing valid data */

/* Valid pages in read and write defines */
#define READ_FROM_VALID_PAGE  ((uint8_t)0x00)
#define WRITE_IN_VALID_PAGE   ((uint8_t)0x01)

/* Page full define */
#define PAGE_FULL             ((uint8_t)0x80)

/* EEPROM Variables' number (up to 1024 16-bit variables) */
#define NumOfEEPROMvar       1024				

/* EEPROM virtual addresses */
#define _EE_WATER_METER_LSB        1000
#define _EE_WATER_METER_MSB        998

/* Exported variables --------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint16_t EE_Init(void);
uint16_t EE_Format(void);
uint16_t EE_ReadVariable(uint16_t VirtAddress, uint16_t* Data);
uint16_t EE_WriteVariable(uint16_t VirtAddress, uint16_t Data);
uint16_t Flash_WriteVariable(uint32_t Address, uint16_t Data);


#endif /* __MB_EEPROM_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
