#ifndef __BEEP_H
#define __BEEP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes -----------------------------------------------------------------*/
#include "main.h"  // ????HAL??GPIO??

/* Function Prototypes ------------------------------------------------------*/
void BEEP_Setup(void);
void BEEP_On(uint32_t duration_ms);
void BEEP_Off(void);

#ifdef __cplusplus
}
#endif

#endif /* __BEEP_H */
