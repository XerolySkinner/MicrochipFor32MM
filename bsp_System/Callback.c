/*----------------------------------------------------------------------------------------------------
#	THIS FILE IS PART OF XEROLYSKINNER'S PROJECT
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
	名字:Callback
	时间:
	程序员:梁源康
	说明:回调函数
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	头文件
#include "vartable.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序
//	
//	UART1中断函数
void UART1_IRQHandler(void){
	#ifdef USER_RT_Thread
	rt_interrupt_enter();
	#endif
	#ifdef USER_CONSOLE
	bsp_ConsoleJump(UART1);
	#endif
	//	TODO:Uart1中断处理函数
	#ifdef USER_RT_Thread
	rt_interrupt_leave();
	#endif
	}
//----------------------------------------------------------------------------------------------------
//	UART3中断函数
void UART3_IRQHandler(void){
	#ifdef USER_RT_Thread
	rt_interrupt_enter();
	rt_enter_critical();
	#endif
	#ifdef USER_CONSOLE
	bsp_ConsoleJump(UART3);
	#endif
	//	TODO:Uart1中断处理函数
	#ifdef USER_RT_Thread
	rt_exit_critical();
	rt_interrupt_leave();
	#endif
	}
//----------------------------------------------------------------------------------------------------
//	定时器中断函数
void TIM1_UP_IRQHandler(void){
	#ifdef USER_RT_Thread
	rt_interrupt_enter();
	#endif
	//	TODO:TIM1中断处理函数
	TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
	#ifdef USER_RT_Thread
	rt_interrupt_leave();
	#endif
	}
//	踢他定时器

//////////////////////////////////////////////////////////////////////////////////////////////////////
