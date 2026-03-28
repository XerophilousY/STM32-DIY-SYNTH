//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2018-10-31
//  最近修改   :
//  功能描述   : OLED I2C接口演示例程(STM32F103系列)
//              说明:
//              ----------------------------------------------------------------
//              GND  电源地
//              VCC  3.3v电源
//              D0   PA0（SCL）
//              D1   PA1（SDA）
//              RES  PA2（SPI模块改成IIC模块需要接此引脚，IIC模块用户请忽略）
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   :
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2018-10-31
//All rights reserved
//******************************************************************************/
#include "board.h"
#include "sys.h"
#include "oled.h"
#include "bmp.h"
#include "dht11.h"
#include "stdio.h"
#include "bsp_uart.h"
#include "led.h"
#include "iwdg.h"

int main(void)
{
  DHT11_GPIO_Init();
  board_init();
  OLED_Init();
	LED_Init();
  OLED_ColorTurn(0);//0正常显示，1 反色显示
  OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
  uart1_init(115200U);

	
		IWDG_Feed();//喂狗
		Flag_IWDG_Feed=0;//停止喂狗，准备复位
  while(1)
    {
		
      OLED_Refresh();
      DHT11_Read_Data();

	                 	//表头
						OLED_ShowChinese(0, 0, 0, 16, 1);							   //温
						OLED_ShowChinese(25, 0, 1, 16, 1);							 //湿
						OLED_ShowChinese(50, 0, 2, 16, 1);							 //度
						OLED_ShowChinese(75, 0, 3, 16, 1);							 //检
						OLED_ShowChinese(100, 0, 4, 16, 1);							 //测
			
			
			
			OLED_ShowChinese(0, 25, 0, 16, 1);							 //温
      OLED_ShowChinese(25, 25, 2, 16, 1);							//度
			OLED_ShowString(50,25,":",16,1);
			
      OLED_ShowNum(65, 25, Get_temperature(), 2, 16, 0);      //获取温度值
			OLED_ShowChinese(85,25,5,16,1);												 //温度单位
			
			
			
			
			
			OLED_ShowChinese(0, 45, 1, 16, 1);							//湿
    	OLED_ShowChinese(25, 45, 2, 16, 1);				     //度
			OLED_ShowString(50,45,":",16,1);
			
      OLED_ShowNum(65, 45, Get_humidity(), 2, 16, 0);      //获取湿度值
			OLED_ShowString(90,45,"%",16,1);								   //湿度单位
			
			
			LED_RUN=LED_ON;
      delay_ms(500);
		
		LED_RUN=LED_OFF;
     

    }
}

