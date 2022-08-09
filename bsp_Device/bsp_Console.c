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
	����:bsp_Console
	ʱ��:20220805-0424
	�޶�:20220808-0407
	����Ա:��Դ��
	˵��:���λ������
		[0]:����鶯оƬ���ư汾
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	ͷ�ļ�
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
//	�����Ͷ���
//	
#define		console_num(num)	(*((num*)(console_buff+1)))
#define		CONSOLE_BUFF_LEN 	USER_CONSOLE_STACK
uint8_t 	console_buff[CONSOLE_BUFF_LEN]={0};
struct		console_pack consolePack={0,0,0};
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	����
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
	//	�����ж���ת
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
//	��ťʶ����
		if(console_buff[0]==0){
			switch(console_buff[1]){
			case 0:
				printf("��ť0\r\n");
				break;
			case 1:
				printf("��ť1\r\n");
				break;
			default:
				printf("��ťδ֪\r\n");
				break;}}
//----------------------------------------------------------------------------------------------------
//	��ʶ����-Ĭ��С�˽��շ�ʽ
		if(console_buff[0]==1){
			memcpy(&consolePack,console_buff+1,sizeof(struct console_pack));
			printf("����������:%d %d %d\r\n",consolePack.var0,consolePack.var1,consolePack.var2);
		}
//----------------------------------------------------------------------------------------------------
//	��ֵʶ����
		if(console_buff[0]==2)printf("2��:%d\r\n",console_num(int));
//----------------------------------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////
