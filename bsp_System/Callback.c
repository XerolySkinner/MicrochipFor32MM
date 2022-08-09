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
	����:Callback
	ʱ��:
	����Ա:��Դ��
	˵��:�ص�����
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	ͷ�ļ�
#include "vartable.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	����
//	
//	UART1�жϺ���
void UART1_IRQHandler(void){
	#ifdef USER_RT_Thread
	rt_interrupt_enter();
	#endif
	#ifdef USER_CONSOLE
	bsp_ConsoleJump(UART1);
	#endif
	//	TODO:Uart1�жϴ�����
	#ifdef USER_RT_Thread
	rt_interrupt_leave();
	#endif
	}
//----------------------------------------------------------------------------------------------------
//	UART3�жϺ���
void UART3_IRQHandler(void){
	#ifdef USER_RT_Thread
	rt_interrupt_enter();
	rt_enter_critical();
	#endif
	#ifdef USER_CONSOLE
	bsp_ConsoleJump(UART3);
	#endif
	//	TODO:Uart1�жϴ�����
	#ifdef USER_RT_Thread
	rt_exit_critical();
	rt_interrupt_leave();
	#endif
	}
//----------------------------------------------------------------------------------------------------
//	��ʱ���жϺ���
void TIM1_UP_IRQHandler(void){
	#ifdef USER_RT_Thread
	rt_interrupt_enter();
	#endif
	//	TODO:TIM1�жϴ�����
	TIM_ClearITPendingBit(TIM1,TIM_IT_Update);
	#ifdef USER_RT_Thread
	rt_interrupt_leave();
	#endif
	}
//	������ʱ��

//////////////////////////////////////////////////////////////////////////////////////////////////////
