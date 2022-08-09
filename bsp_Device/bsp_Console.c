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
	if(huart==UART1)DMA_Cmd(DMA1_Channel5, ENABLE);
	if(huart==UART2)DMA_Cmd(DMA1_Channel6, ENABLE);
	if(huart==UART3)DMA_Cmd(DMA1_Channel3, ENABLE);
	if(huart==UART6)DMA_Cmd(DMA1_Channel1, ENABLE);
	if(huart==UART4)DMA_Cmd(DMA2_Channel3, ENABLE);
	if(huart==UART5)DMA_Cmd(DMA2_Channel1, ENABLE);
	UART_Receive_DMA(huart,(uint32_t)console_buff,CONSOLE_BUFF_LEN);}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	接到回调函数指令
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
		DMA_Cmd(dmaCha, DISABLE);
		HAL_UART_IdleCpltCallback(huart);
		DMA_Cmd(dmaCha, ENABLE);
		UART_Receive_DMA(huart,(uint32_t)console_buff,CONSOLE_BUFF_LEN);
		UART_ClearITPendingBit(huart, UART_ICR_RXIDLE);}}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	回调处理函数
//		[0]:研究表明,使用RT-Thread系统的时候,本模块使用空闲中断会进行拆包,首字节会被单独拆开,
//			因此,使用系统的时候,包前缀00.绥靖政策.
//		[1]:我有预感,不要用00作为标识符,所以我讲00为帧头的数据作为空数据处理了.
//		[2]:还是在搭配系统的情况下,这个东西不能保证100正确接收到数据,建议还是加个帧尾判别为好
//		[3]:做实验的时候用的是蓝牙,也可能是蓝牙导致的这些问题.
void HAL_UART_IdleCpltCallback(UART_TypeDef *huart){
	if(console_buff[0]==0);
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	按钮识别区
	else if(console_buff[0]==1){
		switch(console_buff[1]){
		case 0:
			printf("\r\n按钮0\r\n");
			break;
		case 1:
			printf("\r\n按钮1\r\n");
			break;
		default:
			printf("\r\n按钮未知\r\n");
			break;}}
//----------------------------------------------------------------------------------------------------
//	包识别区-默认小端接收方式
	else if(console_buff[0]==2){
		memcpy(&consolePack,console_buff+1,sizeof(struct console_pack));
		printf("\r\n包接收数据:%d %d %d\r\n",consolePack.var0,consolePack.var1,consolePack.var2);
		}
//----------------------------------------------------------------------------------------------------
//	数值识别区
	else if(console_buff[0]==3)printf("\r\n2号:%d\r\n",console_num(int));
//----------------------------------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////
