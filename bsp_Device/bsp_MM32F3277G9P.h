/*----------------------------------------------------------------------------------------------------
#	THIS FILE IS PART OF XEROLYSKINNER'S PROJECT
#	setup - The core part of the project
#
#	THIS PROGRAM IS FREE SOFTWARE
#
#	Copyright (c) 2021 XerolySkinner
#	E-mail:ZABBCCCBBAZ@163.COM
#	QQ:2715099320
#
#	All rights reserved.
*/

/*----------------------------------------------------------------------------------------------------
	����:bsp_MM32F3277G9P
	ʱ��:20211229-0121
	�޶�:20220808-0218
	����Ա:��Դ��
	˵��:
		[0]:���ĵ��ڰ����˳�ʼ������
*/
#ifndef _XEROLYSKINNER_BSP_MM32F3277G9P_H
#define _XEROLYSKINNER_BSP_MM32F3277G9P_H
#include "mm32_device.h"
#include "hal_gpio.h"
#include "hal_rcc.h"
#include "hal_tim.h"
#include "hal_misc.h"
#include "hal_uart.h"
#include "hal_spi.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	��������
//	
void MM32_Init(void);
void MM32_RCC_Init(void);
void MM32_GPIO_Init(void);
void MM32_UART_Init(void);
void MM32_NVIC_Init(void);
void MM32_TIM_Init(void);
void UART_Receive_DMA(UART_TypeDef* uart, uint32_t cmar, uint16_t cndtr);
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	��������
//	
#define		LED1_ON(void)	GPIO_WriteBit(GPIOH,GPIO_Pin_2,Bit_RESET)
#define		LED1_OFF(void)	GPIO_WriteBit(GPIOH,GPIO_Pin_2,Bit_SET)
#define		LED1_SW(void)	GPIO_WriteBit(GPIOH,GPIO_Pin_2,(BitAction)(!GPIO_ReadOutputDataBit(GPIOH,GPIO_Pin_2)))
	
#define		LED2_ON(void)	GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET)
#define		LED2_OFF(void)	GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_SET)
#define		LED2_SW(void)	GPIO_WriteBit(GPIOB,GPIO_Pin_13,(BitAction)(!GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_13)))
	
#define		DB1_ON(void)	GPIO_WriteBit(GPIOB,GPIO_Pin_9,Bit_RESET)
#define		DB1_OFF(void)	GPIO_WriteBit(GPIOB,GPIO_Pin_9,Bit_SET)
#define		DB1_SW(void)	GPIO_WriteBit(GPIOB,GPIO_Pin_9,(BitAction)(!GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_9)))

#define		DB2_ON(void)	GPIO_WriteBit(GPIOB,GPIO_Pin_8,Bit_RESET)
#define		DB2_OFF(void)	GPIO_WriteBit(GPIOB,GPIO_Pin_8,Bit_SET)
#define		DB2_SW(void)	GPIO_WriteBit(GPIOB,GPIO_Pin_8,(BitAction)(!GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_8)))
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	�ܽŶ���
//	IO�ڲ����궨��
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))
//	IO�ڵ�ַӳ��
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C
#define GPIOH_ODR_Addr    (GPIOH_BASE+12) 

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08
#define GPIOH_IDR_Addr    (GPIOH_BASE+8) 
//	IO�ڲ���,ֻ�Ե�һ��IO��
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //���
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //����
#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //���
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //����
#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //���
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //����
#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //���
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //����
#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //���
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //����
#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //���
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //����
#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //���
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //����
#define PHout(n)   BIT_ADDR(GPIOH_ODR_Addr,n)  //���
#define PHin(n)    BIT_ADDR(GPIOH_IDR_Addr,n)  //����
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
