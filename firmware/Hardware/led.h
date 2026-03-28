#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED_RUN  	  						PCout(13)
#define KEY_SDCARD_CK 		      PBin(11)  //SD插入监测
#define KEY_SDCARD_WP 		      PAin(1)  //SD写保护或出厂格式化

#define BEEP 		      					PBout(6)  //蜂鸣器控制

#define LED_ON     0
#define LED_OFF    1

#define BEEP_ON     1
#define BEEP_OFF    0
//初始化
void LED_Init(void);

		 				    
#endif
