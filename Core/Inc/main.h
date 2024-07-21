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
#include "cmsis_os.h"
#include "spi.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#ifdef __cplusplus
extern "C" {
#endif
extern osMessageQId rxDataQueueHandle;
extern osThreadId waitPrintMsgTaskHandle;
extern osThreadId printTaskHandle;
extern osThreadId printPicTaskHandle;
extern osThreadId rollPaperTaskHandle;

void SystemClock_Config(void);
void MX_FREERTOS_Init(void);

#ifdef __cplusplus
}
#endif
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SERIAL1_TX_Pin GPIO_PIN_2
#define SERIAL1_TX_GPIO_Port GPIOA
#define SERIAL1_RX_Pin GPIO_PIN_3
#define SERIAL1_RX_GPIO_Port GPIOA
#define SPI1_SCK_Pin GPIO_PIN_5
#define SPI1_SCK_GPIO_Port GPIOA
#define SPI1_MISO_Pin GPIO_PIN_6
#define SPI1_MISO_GPIO_Port GPIOA
#define SPI1_MOSI_Pin GPIO_PIN_7
#define SPI1_MOSI_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_0
#define LED_GPIO_Port GPIOB
#define PRINTER_LAT_Pin GPIO_PIN_1
#define PRINTER_LAT_GPIO_Port GPIOB
#define SERIAL2_TX_Pin GPIO_PIN_10
#define SERIAL2_TX_GPIO_Port GPIOB
#define SERIAL2_RX_Pin GPIO_PIN_11
#define SERIAL2_RX_GPIO_Port GPIOB
#define SPI2_SS_Pin GPIO_PIN_12
#define SPI2_SS_GPIO_Port GPIOB
#define SPI2_SCK_Pin GPIO_PIN_13
#define SPI2_SCK_GPIO_Port GPIOB
#define SPI2_MISO_Pin GPIO_PIN_14
#define SPI2_MISO_GPIO_Port GPIOB
#define SPI2_MOSI_Pin GPIO_PIN_15
#define SPI2_MOSI_GPIO_Port GPIOB
#define PRINTER_STB1_Pin GPIO_PIN_8
#define PRINTER_STB1_GPIO_Port GPIOA
#define PRINTER_STB2_Pin GPIO_PIN_9
#define PRINTER_STB2_GPIO_Port GPIOA
#define PRINTER_STB3_Pin GPIO_PIN_10
#define PRINTER_STB3_GPIO_Port GPIOA
#define PRINTER_STB4_Pin GPIO_PIN_11
#define PRINTER_STB4_GPIO_Port GPIOA
#define PRINTER_STB5_Pin GPIO_PIN_12
#define PRINTER_STB5_GPIO_Port GPIOA
#define PRINTER_STB6_Pin GPIO_PIN_15
#define PRINTER_STB6_GPIO_Port GPIOA
#define ROLL_BTN_Pin GPIO_PIN_4
#define ROLL_BTN_GPIO_Port GPIOB
#define PRINTER_B2_Pin GPIO_PIN_6
#define PRINTER_B2_GPIO_Port GPIOB
#define PRINTER_B1_Pin GPIO_PIN_7
#define PRINTER_B1_GPIO_Port GPIOB
#define PRINTER_A2_Pin GPIO_PIN_8
#define PRINTER_A2_GPIO_Port GPIOB
#define PRINTER_A1_Pin GPIO_PIN_9
#define PRINTER_A1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
// user environment
#define PRINTER_STBs_GPIO_PORT GPIOA

#define FONT_SIZE_PX 32

#define LINE_DOT_PX 384
#define LINE_MAX_BYTE (LINE_DOT_PX / 8)

#define CHARACTER_BYTE_WIDTH 4
#define LETTER_BYTE_WIDTH 2

// spi & huart
#define PRINTER_SPIx hspi1
#define FONT_BITMAP_SPIx hspi2
#define SERIAL_PORT huart2
#define BLUETEETH_PORT huart3

// Printer
#define DOT_LINE_SIZE LINE_MAX_BYTE
#define USE_CIRCLE_HEAT 1
#define HEAT_TIME 5
#define LAT_TIME 1
#define DOT_LINE_RUN_STEP 4
#define LINE_SPACE_RUN_STEP (uint8_t)(FONT_SIZE_PX * 1.5)
#define SEGMENT_SPACE_RUN_STEP (LINE_SPACE_RUN_STEP * 3)

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
