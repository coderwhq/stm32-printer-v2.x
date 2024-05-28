/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SERIAL1_TX_PIN_Pin GPIO_PIN_2
#define SERIAL1_TX_PIN_GPIO_Port GPIOA
#define SERIAL1_RX_PIN_Pin GPIO_PIN_3
#define SERIAL1_RX_PIN_GPIO_Port GPIOA
#define SPI1_SCK_PIN_Pin GPIO_PIN_5
#define SPI1_SCK_PIN_GPIO_Port GPIOA
#define SPI1_MISO_PIN_Pin GPIO_PIN_6
#define SPI1_MISO_PIN_GPIO_Port GPIOA
#define SPI1_MOSI_PIN_Pin GPIO_PIN_7
#define SPI1_MOSI_PIN_GPIO_Port GPIOA
#define LED_PIN_Pin GPIO_PIN_0
#define LED_PIN_GPIO_Port GPIOB
#define PRINTER_LAT_PIN_Pin GPIO_PIN_1
#define PRINTER_LAT_PIN_GPIO_Port GPIOB
#define SERIAL2_TX_PIN_Pin GPIO_PIN_10
#define SERIAL2_TX_PIN_GPIO_Port GPIOB
#define SERIAL2_RX_PIN_Pin GPIO_PIN_11
#define SERIAL2_RX_PIN_GPIO_Port GPIOB
#define SPI2_SS_PIN_Pin GPIO_PIN_12
#define SPI2_SS_PIN_GPIO_Port GPIOB
#define SPI2_SCK_PIN_Pin GPIO_PIN_13
#define SPI2_SCK_PIN_GPIO_Port GPIOB
#define SPI2_MISO_PIN_Pin GPIO_PIN_14
#define SPI2_MISO_PIN_GPIO_Port GPIOB
#define SPI2_MOSI_PIN_Pin GPIO_PIN_15
#define SPI2_MOSI_PIN_GPIO_Port GPIOB
#define PRINTER_STB1_PIN_Pin GPIO_PIN_8
#define PRINTER_STB1_PIN_GPIO_Port GPIOA
#define PRINTER_STB2_PIN_Pin GPIO_PIN_9
#define PRINTER_STB2_PIN_GPIO_Port GPIOA
#define PRINTER_STB3_PIN_Pin GPIO_PIN_10
#define PRINTER_STB3_PIN_GPIO_Port GPIOA
#define PRINTER_STB4_PIN_Pin GPIO_PIN_11
#define PRINTER_STB4_PIN_GPIO_Port GPIOA
#define PRINTER_STB5_PIN_Pin GPIO_PIN_12
#define PRINTER_STB5_PIN_GPIO_Port GPIOA
#define PRINTER_STB6_PIN_Pin GPIO_PIN_15
#define PRINTER_STB6_PIN_GPIO_Port GPIOA
#define ROLL_BTN_PIN_Pin GPIO_PIN_4
#define ROLL_BTN_PIN_GPIO_Port GPIOB
#define PRINTER_B2_Pin GPIO_PIN_6
#define PRINTER_B2_GPIO_Port GPIOB
#define PRINTER_B1_Pin GPIO_PIN_7
#define PRINTER_B1_GPIO_Port GPIOB
#define PRINTER_A2_Pin GPIO_PIN_8
#define PRINTER_A2_GPIO_Port GPIOB
#define PRINTER_A1_Pin GPIO_PIN_9
#define PRINTER_A1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
/* LED */
#define USE_LOW_LEVEL_DRIVE 1

#if USE_LOW_LEVEL_DRIVE
#define ON GPIO_PIN_RESET
#define OFF GPIO_PIN_SET
#else
#define ON GPIO_PIN_SET
#define OFF GPIO_PIN_RESET
#endif

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
