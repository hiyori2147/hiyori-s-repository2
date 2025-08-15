#include "beep.h"
#include "tim.h"    // ???PWM?????TIM???

/* Private defines -----------------------------------------------------------*/
#define BEEP_GPIO_PORT    GPIOA
#define BEEP_PIN          GPIO_PIN_0      // ????????
#define BEEP_TIM_HANDLE   &htim3          // ??PWM??
#define BEEP_TIM_CHANNEL  TIM_CHANNEL_1   // ??PWM??

/* Private variables --------------------------------------------------------*/
static uint8_t beep_initialized = 0;

/**
  * @brief  ????????(GPIO?PWM)
  * @retval None
  */
void BEEP_Setup(void) {
    /* GPIO????? */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = BEEP_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStruct);
    
    /* ??:PWM????? */
    // HAL_TIM_PWM_Start(BEEP_TIM_HANDLE, BEEP_TIM_CHANNEL);
    // __HAL_TIM_SET_COMPARE(BEEP_TIM_HANDLE, BEEP_TIM_CHANNEL, 0); // ????
    
    beep_initialized = 1;
}

/**
  * @brief  ?????(??????)
  * @param  duration_ms: ????(??),0??????
  */
void BEEP_On(uint32_t duration_ms) {
    if(!beep_initialized) return;
    
    /* GPIO???? */
    HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_SET);
    
    /* ??:PWM???? */
    // __HAL_TIM_SET_COMPARE(BEEP_TIM_HANDLE, BEEP_TIM_CHANNEL, 500); // 50%???
    
    /* ?????? */
    if(duration_ms > 0) {
        HAL_Delay(duration_ms);
        BEEP_Off();
    }
}

/**
  * @brief  ?????
  */
void BEEP_Off(void) {
    if(!beep_initialized) return;
    
    /* GPIO???? */
    HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_PIN, GPIO_PIN_RESET);
    
    /* ??:PWM???? */
    // __HAL_TIM_SET_COMPARE(BEEP_TIM_HANDLE, BEEP_TIM_CHANNEL, 0);
}
