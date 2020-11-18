/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//PROGRAMME: 247-637 S-0009
//DESCRIPTION: programme qui va de pair avec S-0008
//HISTORIQUE:
// 2019-10-27, Yves Roy: création
#include "stm32f4xx_hal.h"


/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CS_I2C_SPI_Pin GPIO_PIN_3
#define CS_I2C_SPI_GPIO_Port GPIOE
#define triac_Pin GPIO_PIN_6
#define triac_GPIO_Port GPIOE
#define passageParZero_Pin GPIO_PIN_13
#define passageParZero_GPIO_Port GPIOC
#define PC14_OSC32_IN_Pin GPIO_PIN_14
#define PC14_OSC32_IN_GPIO_Port GPIOC
#define PC15_OSC32_OUT_Pin GPIO_PIN_15
#define PC15_OSC32_OUT_GPIO_Port GPIOC
#define PH0_OSC_IN_Pin GPIO_PIN_0
#define PH0_OSC_IN_GPIO_Port GPIOH
#define PH1_OSC_OUT_Pin GPIO_PIN_1
#define PH1_OSC_OUT_GPIO_Port GPIOH
#define OTG_FS_PowerSwitchOn_Pin GPIO_PIN_0
#define OTG_FS_PowerSwitchOn_GPIO_Port GPIOC
#define PDM_OUT_Pin GPIO_PIN_3
#define PDM_OUT_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_0
#define B1_GPIO_Port GPIOA
#define stepMotorB2_Pin GPIO_PIN_5
#define stepMotorB2_GPIO_Port GPIOA
#define stepMotorA2_Pin GPIO_PIN_6
#define stepMotorA2_GPIO_Port GPIOA
#define stepMotorB1_Pin GPIO_PIN_7
#define stepMotorB1_GPIO_Port GPIOA
#define BOOT1_Pin GPIO_PIN_2
#define BOOT1_GPIO_Port GPIOB
#define CLK_IN_Pin GPIO_PIN_10
#define CLK_IN_GPIO_Port GPIOB
#define LD4_Pin GPIO_PIN_12
#define LD4_GPIO_Port GPIOD
#define LD3_Pin GPIO_PIN_13
#define LD3_GPIO_Port GPIOD
#define LD5_Pin GPIO_PIN_14
#define LD5_GPIO_Port GPIOD
#define LD6_Pin GPIO_PIN_15
#define LD6_GPIO_Port GPIOD
#define I2S3_MCK_Pin GPIO_PIN_7
#define I2S3_MCK_GPIO_Port GPIOC
#define redLightInColumn_Pin GPIO_PIN_8
#define redLightInColumn_GPIO_Port GPIOC
#define yellowLightInColumn_Pin GPIO_PIN_9
#define yellowLightInColumn_GPIO_Port GPIOC
#define greenLightInColumn_Pin GPIO_PIN_8
#define greenLightInColumn_GPIO_Port GPIOA
#define VBUS_FS_Pin GPIO_PIN_9
#define VBUS_FS_GPIO_Port GPIOA
#define OTG_FS_ID_Pin GPIO_PIN_10
#define OTG_FS_ID_GPIO_Port GPIOA
#define OTG_FS_DM_Pin GPIO_PIN_11
#define OTG_FS_DM_GPIO_Port GPIOA
#define OTG_FS_DP_Pin GPIO_PIN_12
#define OTG_FS_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define I2S3_SCK_Pin GPIO_PIN_10
#define I2S3_SCK_GPIO_Port GPIOC
#define I2S3_SD_Pin GPIO_PIN_12
#define I2S3_SD_GPIO_Port GPIOC
#define Audio_RST_Pin GPIO_PIN_4
#define Audio_RST_GPIO_Port GPIOD
#define OTG_FS_OverCurrent_Pin GPIO_PIN_5
#define OTG_FS_OverCurrent_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define Audio_SCL_Pin GPIO_PIN_6
#define Audio_SCL_GPIO_Port GPIOB
#define Audio_SDA_Pin GPIO_PIN_9
#define Audio_SDA_GPIO_Port GPIOB
#define stepMotorA1_Pin GPIO_PIN_0
#define stepMotorA1_GPIO_Port GPIOE
#define MEMS_INT2_Pin GPIO_PIN_1
#define MEMS_INT2_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

//DEFINITIONS REQUISES PAR LE PROGRAMME:
//Dépendances matérielles:
#define FREQUENCE_D_OSCILLATEUR_EN_KHZ  84000.0

//Dépendances logicielles:
#define FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ 2000.0
#define PILOTETIMER1MODE2_TAUX_DE_BITS 19200.0
#define PILOTETIMER6UP_COMPTE_MAXIMAL  (\
  (unsigned int)((FREQUENCE_D_OSCILLATEUR_EN_KHZ \
  /FREQUENCE_DE_LA_BASE_DE_TEMPS_EN_HZ * 1000.0)-1.0))

#define PILOTECAN1_IDENTIFICATION_EN_TRANSMISSION  (0x246<<5)
#define PILOTECAN1_IDENTIFICATION_EN_RECEPTION  (0x245<<5) //0x246
#define PILOTECAN1_MASQUE_11_BITS_EN_RECEPTION  (0x0) //0x000
#define SERVICEPROTOCOLE637_FREQUENCE_MAXIMALE_DES_TRANSMISSIONS_EN_HZ 500.0
#define SERVICEPROTOCOLE637_NOMBRE_DE_DONNEES_MAXIMUM  16
#define SERVICEPROTOCOLE637_DEBUT_DE_TRAME  '$'    //0x24
#define SERVICEPROTOCOLE637_INSERTION 0x00
#define SERVICEPROTOCOLE637_TEMPS_D_ATTENTE_MAXIMAL_EN_MS 4
#define SERVICEPROTOCOLE637_FREQUENCE_MAXIMALE_DES_LECTURES_EN_HZ 2000.0
#define INTERFACEB1_FREQUENCE_DES_LECTURES_EN_HZ  100.0
#define INTERFACEB1_NOMBRE_MINIMUM_DE_LECTURES_PAR_DECISION 10
#define PROCESSUSCLIGNOTANT_TEMPS_COURT_ETEINT_EN_MS  300
#define PROCESSUSCLIGNOTANT_TEMPS_COURT_ALLUME_EN_MS  200
#define PROCESSUSCLIGNOTANT_TEMPS_LONG_ETEINT_EN_MS  500
#define PROCESSUSCLIGNOTANT_TEMPS_LONG_ALLUME_EN_MS  1000
#define PROCESSUSBOUTONCONNECTE_TEMPS_MAXIMAL_POUR_RECEVOIR_EN_MS 100

// base de temps
#define SERVICEBASEDETEMPS_NOMBRE_DE_PHASES 7

// IOs
// digital
#define PCF8574A_CHIP_ADDRESS_0 0x70
#define PCF8574A_CHIP_ADDRESS_1 0x72
#define PCF8574A_CHIP_ADDRESS_2 0x74
#define PCF8574A_CHIP_ADDRESS_3 0x76
#define PCF8574A_CHIP_ADDRESS_4 0x78

// analog
#define MCP3021_CHIP_ADDRESS 0xc8
#define ADC_BYTE_TO_VOLTS_FACTOR 0.01953125

//INFORMATION PUBLIQUE:

//Fonctions publiques:
void neFaitRien(void);

//Variables publiques:
//copiez et adaptes les lignes qui suivent dans les fichiers .h des modules
//qui utilisent ces variables qui sont definies par htim6
//extern TIM_HandleTypeDef htim6;
//extern UART_HandleTypeDef huart2;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
