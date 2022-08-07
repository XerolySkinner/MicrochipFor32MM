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
	名字:bsp_MM32F3277G9P
	时间:20211229-0121
	修订:20220808-0218
	程序员:梁源康
	说明:
		[0]:本文档内包括了初始化内容
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	头文件
#include "mm32_device.h"
#include "hal_gpio.h"
#include "hal_rcc.h"
#include "hal_tim.h"
#include "hal_dma.h"
#include "hal_misc.h"
#include "hal_uart.h"
#include "hal_spi.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	全局变量
//
#define		TESUTO_UART		UART1		//调试通信用
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序
//	
void MM32_RCC_Init(void){//时钟由此开启
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOB,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOC,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOD,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOE,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOF,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOG,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOH,ENABLE);
	
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_UART3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_UART1,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_TIM1,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_TIM2,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_TIM3,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_TIM4,ENABLE);
	return;}
//----------------------------------------------------------------------------------------------------
void MM32_GPIO_Init(void){//管脚初始化
	GPIO_InitTypeDef GPIOSET_Init;
	GPIO_StructInit(&GPIOSET_Init);
	//管脚启用
	GPIOSET_Init.GPIO_Speed=GPIO_Speed_50MHz;
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_Out_PP;
	//涉及灯
		GPIOSET_Init.GPIO_Pin=GPIO_Pin_13;
		GPIO_Init(GPIOB,&GPIOSET_Init);
		GPIOSET_Init.GPIO_Pin=GPIO_Pin_2;
		GPIO_Init(GPIOH,&GPIOSET_Init);
	//涉及蜂鸣器
	GPIOSET_Init.GPIO_Pin=GPIO_Pin_12;
		GPIO_Init(GPIOD,&GPIOSET_Init);
	//涉及PWM
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);

	GPIOSET_Init.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIOSET_Init.GPIO_Pin=
		GPIO_Pin_0|
		GPIO_Pin_1|
		GPIO_Pin_2|
		GPIO_Pin_3;
		GPIO_Init(GPIOA,&GPIOSET_Init);
	//涉及编码器
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_2);
	
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_IPU;
	GPIOSET_Init.GPIO_Pin=
		GPIO_Pin_4|
		GPIO_Pin_5|
		GPIO_Pin_6|
		GPIO_Pin_7;
		GPIO_Init(GPIOB,&GPIOSET_Init);
	//涉及按钮
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_IPU;
	GPIOSET_Init.GPIO_Pin=
		GPIO_Pin_0|
		GPIO_Pin_1|
		GPIO_Pin_2|
		GPIO_Pin_3|
		GPIO_Pin_14|
		GPIO_Pin_15;
	GPIO_Init(GPIOD,&GPIOSET_Init);
	//涉及UART
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_7);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_7);
	
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_7);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_7);
	
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIOSET_Init.GPIO_Pin=GPIO_Pin_10;
	GPIO_Init(GPIOC,&GPIOSET_Init);
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_IPU;
	GPIOSET_Init.GPIO_Pin=GPIO_Pin_11;
	GPIO_Init(GPIOC,&GPIOSET_Init);
	
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIOSET_Init.GPIO_Pin=GPIO_Pin_9;
	GPIO_Init(GPIOA,&GPIOSET_Init);
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_IPU;
	GPIOSET_Init.GPIO_Pin=GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIOSET_Init);	
	//涉及MPU6050
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_Out_OD;
	GPIOSET_Init.GPIO_Pin=GPIO_Pin_14;
	GPIO_Init(GPIOB,&GPIOSET_Init);
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_Out_OD;
	GPIOSET_Init.GPIO_Pin=GPIO_Pin_15;
	GPIO_Init(GPIOB,&GPIOSET_Init);
	//涉及马达转向
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOSET_Init.GPIO_Pin=GPIO_Pin_13|GPIO_Pin_12|GPIO_Pin_11|GPIO_Pin_10;
	GPIO_Init(GPIOB,&GPIOSET_Init);
	//涉及调试
	GPIOSET_Init.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOSET_Init.GPIO_Pin=GPIO_Pin_9;
	GPIO_Init(GPIOB,&GPIOSET_Init);
//管脚状态初始化
	GPIO_WriteBit(GPIOH,GPIO_Pin_2,Bit_RESET);
	GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET);
	return;}
//----------------------------------------------------------------------------------------------------
void MM32_UART_Init(void){
	UART_InitTypeDef 		UARTSET_Init;
	UARTSET_Init.BaudRate=115200;
	UARTSET_Init.WordLength = UART_WordLength_8b;
	UARTSET_Init.StopBits = UART_StopBits_1;
	UARTSET_Init.Parity = UART_Parity_No;
	UARTSET_Init.HWFlowControl=UART_HWFlowControl_None;
	UARTSET_Init.Mode = UART_Mode_Rx | UART_Mode_Tx;
	UART_Init(UART3,&UARTSET_Init);
	UART_Init(UART1,&UARTSET_Init);
	UART_Cmd(UART3,ENABLE);
	UART_Cmd(UART1,ENABLE);
	return;}
//----------------------------------------------------------------------------------------------------
void UART_Receive_DMA(UART_TypeDef* uart, uint32_t cmar, uint16_t cndtr){
    DMA_InitTypeDef  DMA_StructInit;
	DMA_Channel_TypeDef* dmaCha=NULL;

	if(uart==UART1)dmaCha=DMA1_Channel5;
	else if(uart==UART2)dmaCha=DMA1_Channel6;
	else if(uart==UART3)dmaCha=DMA1_Channel3;
	else if(uart==UART6)dmaCha=DMA1_Channel1;
	else RCC_AHBPeriphClockCmd(RCC_AHBENR_DMA2, ENABLE);
	
	if(uart==UART4)dmaCha=DMA2_Channel3;
	else if(uart==UART5)dmaCha=DMA2_Channel1;
	else RCC_AHBPeriphClockCmd(RCC_AHBENR_DMA1, ENABLE);
	
    DMA_DeInit(dmaCha);
    DMA_StructInit.DMA_PeripheralBaseAddr	= (uint32_t)&uart->RDR;
    DMA_StructInit.DMA_MemoryBaseAddr		= cmar;
    DMA_StructInit.DMA_DIR					= DMA_DIR_PeripheralSRC;		//外设到内存
    DMA_StructInit.DMA_BufferSize			= cndtr;						//DMA 通道的 DMA 缓存的大小
    DMA_StructInit.DMA_PeripheralInc		= DMA_PeripheralInc_Disable; 	//外设地址不变
    DMA_StructInit.DMA_MemoryInc			= DMA_MemoryInc_Enable;      	//内存地址递增
    DMA_StructInit.DMA_PeripheralDataSize	= DMA_PeripheralDataSize_Byte;	//8 位
    DMA_StructInit.DMA_MemoryDataSize		= DMA_MemoryDataSize_Byte;		//8 位
    DMA_StructInit.DMA_Mode					= DMA_Mode_Normal;				//正常缓存模式
    DMA_StructInit.DMA_Priority				= DMA_Priority_Medium;			//优先级中
    DMA_StructInit.DMA_M2M					= DMA_M2M_Disable;
    DMA_StructInit.DMA_Auto_reload			= DMA_Auto_Reload_Disable;
    DMA_Init(dmaCha, &DMA_StructInit);

    UART_DMACmd(uart, UART_DMAReq_EN, ENABLE);
    DMA_Cmd(dmaCha, ENABLE);}
//----------------------------------------------------------------------------------------------------
void MM32_NVIC_Init(void){
	NVIC_InitTypeDef		NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructure.NVIC_IRQChannel = UART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	UART_ITConfig(UART3,UART_IT_RXIEN,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = UART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	UART_ITConfig(UART1,UART_IT_RXIEN,ENABLE);
	
//	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);
	return;}
//----------------------------------------------------------------------------------------------------
void MM32_TIM_Init(void){
	TIM_TimeBaseInitTypeDef	TIMSET_Init;
	TIM_OCInitTypeDef		TIMOC_Init;
	TIM_ICInitTypeDef		TIMIC_Init;
//	定时器(PWM)
	TIMSET_Init.TIM_Period=100;
	TIMSET_Init.TIM_Prescaler=1024;
	TIMSET_Init.TIM_ClockDivision=TIM_CKD_DIV1;
	TIMSET_Init.TIM_CounterMode=TIM_CounterMode_Down;
	TIM_TimeBaseInit(TIM2,&TIMSET_Init);
	
	TIMOC_Init.TIM_OCMode = TIM_OCMode_PWM1;
	TIMOC_Init.TIM_OutputState = TIM_OutputState_Enable;
	TIMOC_Init. TIM_Pulse=0;
	TIMOC_Init.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC1Init(TIM2,&TIMOC_Init);
	TIM_OC2Init(TIM2,&TIMOC_Init);
	TIM_OC3Init(TIM2,&TIMOC_Init);
	TIM_OC4Init(TIM2,&TIMOC_Init);
	
	TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM2,ENABLE);
//	定时器(编码器)
	TIM_TimeBaseStructInit(&TIMSET_Init);
	TIMSET_Init.TIM_Prescaler = 0x0; // 预分频器 
	TIMSET_Init.TIM_Period = 0xFFFF; //设定计数器自动重装值
	TIMSET_Init.TIM_ClockDivision = TIM_CKD_DIV1;//选择时钟分频：不分频
	TIMSET_Init.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM4, &TIMSET_Init);
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使用编码器模式3
	TIM_ICStructInit(&TIMIC_Init);
	TIMIC_Init.TIM_ICFilter = 10;
	TIM_ICInit(TIM4, &TIMIC_Init);
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);//清除TIM的更新标志位
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	//Reset counter
	TIM_SetCounter(TIM4,0);
	TIM_Cmd(TIM4, ENABLE); 
	
	TIM_TimeBaseStructInit(&TIMSET_Init);
	TIMSET_Init.TIM_Prescaler = 0x0; // 预分频器 
	TIMSET_Init.TIM_Period = 0xFFFF; //设定计数器自动重装值
	TIMSET_Init.TIM_ClockDivision = TIM_CKD_DIV1;//选择时钟分频：不分频
	TIMSET_Init.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM3, &TIMSET_Init);
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使用编码器模式3
	TIM_ICStructInit(&TIMIC_Init);
	TIMIC_Init.TIM_ICFilter = 10;
	TIM_ICInit(TIM3, &TIMIC_Init);
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);//清除TIM的更新标志位
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	//Reset counter
	TIM_SetCounter(TIM3,0);
	TIM_Cmd(TIM3, ENABLE);
	return;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//	初始化程序
void MM32_Init(void){
	MM32_RCC_Init();
	MM32_GPIO_Init();
	MM32_UART_Init();
	MM32_TIM_Init();
	MM32_NVIC_Init();
	return;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
