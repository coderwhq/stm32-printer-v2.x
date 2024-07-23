/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "main.h"
#include "task.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
osMessageQId rxDataQueueHandle;

osThreadId waitPrintMsgTaskHandle;
osThreadId printTaskHandle;
osThreadId printPicTaskHandle;
osThreadId rollPaperTaskHandle;
/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId initialTestTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
extern void waitPrintMsgTask(void const *argument);
extern void printTask(void const *argument);
extern void printPicTask(void const *argument);
extern void rollPaperTask(void const *argument);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const *argument);
extern void initialTestTaskFun(void const *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize);

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize) {
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
    *ppxIdleTaskStackBuffer = &xIdleStack[0];
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
    /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* USER CODE BEGIN RTOS_MUTEX */
    /* add mutexes, ... */
    /* USER CODE END RTOS_MUTEX */

    /* USER CODE BEGIN RTOS_SEMAPHORES */
    /* add semaphores, ... */
    /* USER CODE END RTOS_SEMAPHORES */

    /* USER CODE BEGIN RTOS_TIMERS */
    /* start timers, add new ones, ... */
    /* USER CODE END RTOS_TIMERS */

    /* USER CODE BEGIN RTOS_QUEUES */
    /* add queues, ... */
    osMessageQDef(rxDataQueue, 30, void *);
    rxDataQueueHandle = osMessageCreate(osMessageQ(rxDataQueue), NULL);
    if (rxDataQueueHandle == NULL) {
        // error handle
    }
    /* USER CODE END RTOS_QUEUES */

    /* Create the thread(s) */
    /* definition and creation of defaultTask */
    osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
    defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

    /* definition and creation of initialTestTask */
    osThreadDef(initialTestTask, initialTestTaskFun, osPriorityIdle, 0, 128);
    initialTestTaskHandle = osThreadCreate(osThread(initialTestTask), NULL);

    /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */
    osThreadDef(waitPrintMsgTask, waitPrintMsgTask, osPriorityAboveNormal, 0, 128);
    waitPrintMsgTaskHandle = osThreadCreate(osThread(waitPrintMsgTask), NULL);

    osThreadDef(printTask, printTask, osPriorityRealtime, 0, 128);
    printTaskHandle = osThreadCreate(osThread(printTask), NULL);

    osThreadDef(printPicTask, printPicTask, osPriorityRealtime, 0, 128);
    printPicTaskHandle = osThreadCreate(osThread(printPicTask), NULL);

    osThreadDef(rollPaperTask, rollPaperTask, osPriorityRealtime, 0, 128);
    rollPaperTaskHandle = osThreadCreate(osThread(rollPaperTask), NULL);
    /* USER CODE END RTOS_THREADS */
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const *argument) {
    /* USER CODE BEGIN StartDefaultTask */
    /* Infinite loop */
    for (;;) {
        osDelay(1);
    }
    /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
