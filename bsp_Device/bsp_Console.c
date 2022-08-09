/*----------------------------------------------------------------------------------------------------
#	THIS FILE IS A PART OF XerolySkinner's PROJECT
#
#	THIS PROGRAM IS FREE SOFTWARE
#
#	E-mail:ZABBCCCBBAZ@163.com
#	QQ:2715099320
#
#	Copyright (c) 2022 XerolySkinner
#	All rights reserved.
*/

/*----------------------------------------------------------------------------------------------------
	名字:bsp_Console
	时间:20220805-0424
	修订:20220808-0407
	程序员:梁源康
	说明:搭建上位机处理
		[0]:针对灵动芯片特制版本
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	头文件
#include "User.h"
#include "vartable.h"
#include "bsp_MM32F3277G9P.h"
#include "bsp_Console.h"
#include "stdio.h"
#include "string.h"
#include "hal_uart.h"
#include "hal_dma.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	变量和定义
//	
#define		console_num(num)	(*((num*)(console_buff+1)))
#define		CONSOLE_BUFF_LEN 	USER_CONSOLE_STACK
uint8_t 	console_buff[CONSOLE_BUFF_LEN]={0};
struct		console_pack consolePack={0,0,0};
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序
//	
void bsp_ConsoleInit(UART_TypeDef *huart){
	UART_ITConfig(huart,UART_IER_RXIDLE, ENABLE);
	UART_DMACmd(huart, UART_DMAReq_EN, ENABLE);
    DMA_Cmd(DMA1_Channel5, ENABLE);
	UART_Receive_DMA(huart,(uint32_t)console_buff,CONSOLE_BUFF_LEN);}
//----------------------------------------------------------------------------------------------------
void bsp_ConsoleJump(UART_TypeDef *huart){
	DMA_Channel_TypeDef* dmaCha=NULL;
	if(huart==UART1)dmaCha=DMA1_Channel5;
	if(huart==UART2)dmaCha=DMA1_Channel6;
	if(huart==UART3)dmaCha=DMA1_Channel3;
	if(huart==UART6)dmaCha=DMA1_Channel1;
	if(huart==UART4)dmaCha=DMA2_Channel3;
	if(huart==UART5)dmaCha=DMA2_Channel1;
	//	空闲中断跳转
	if(UART_GetITStatus(huart, UART_ISR_RXIDLE) != RESET){
		UART_ClearITPendingBit(huart, UART_ICR_RXIDLE);
		DMA_Cmd(dmaCha, DISABLE);
		HAL_UART_IdleCpltCallback(huart);
		DMA_Cmd(dmaCha, ENABLE);
		UART_Receive_DMA(huart,(uint32_t)console_buff,CONSOLE_BUFF_LEN);}}
//----------------------------------------------------------------------------------------------------
void HAL_UART_IdleCpltCallback(UART_TypeDef *huart){
	if(huart==UART1){
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	按钮识别区
		if(console_buff[0]==0){
			switch(console_buff[1]){
			case 0:
				printf("按钮0\r\n");
				break;
			case 1:
				printf("按钮1\r\n");
				break;
			default:
				printf("按钮未知\r\n");
				break;}}
//----------------------------------------------------------------------------------------------------
//	包识别区-默认小端接收方式
		if(console_buff[0]==1){
			memcpy(&consolePack,console_buff+1,sizeof(struct console_pack));
			printf("包接收数据:%d %d %d\r\n",consolePack.var0,consolePack.var1,consolePack.var2);
		}
//----------------------------------------------------------------------------------------------------
//	数值识别区
		if(console_buff[0]==2)printf("2号:%d\r\n",console_num(int));
//----------------------------------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////
