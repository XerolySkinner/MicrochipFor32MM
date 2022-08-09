/*----------------------------------------------------------------------------------------------------
#	THIS FILE IS PART OF XEROLYSKINNER'S PROJECT
#	User - The core part of the project
#
#	THIS PROGRAM IS FREE SOFTWARE
#
#	Copyright (c) 2022 XerolySkinner
#	E-mail:ZABBCCCBBAZ@163.COM
#	QQ:2715099320
#
#	All rights reserved.
*/

/*----------------------------------------------------------------------------------------------------
	����:User.h
	ʱ��:
	����Ա:��Դ��
	˵��:�û�����
*/
#ifndef _XEROLYSKINNER_USER_H
#define _XEROLYSKINNER_USER_H
//////////////////////////////////////////////////////////////////////////////////////////////////////
//<<< Use Configuration Wizard in Context Menu >>>
//<h>���Թ�������
	//<c>ȫ�ֵ���ģʽ
	#define	USER_DEBUG
	//</c>
	
	//<c>�ض������
	#define	USER_PRINT
	//</c>
//</h>

//<c>ʹ��RT_Thread
#define USER_RT_Thread
//</c>

//<h>�������NVIC�ж�
	//<c>ʹ��UART1��NVIC�ж�
	#define USER_NVIC_UART1
	//</c>
	
	//<c>ʹ��UART3��NVIC�ж�
	#define USER_NVIC_UART3
	//</c>
	
	//<c>ʹ��TIM1��NVIC�ж�
	#define USER_NVIC_TIM1
	//</c>
//</h>

//<h>���⹦��
	//<c>ʹ�ÿ���̨ͨѶ
	#define USER_CONSOLE
	//</c>
	//<o>����̨����ջ��
	//<i>Ĭ��64,ʹ�ÿ���̨ͨѶΪǰ��ѡ��
	#define USER_CONSOLE_STACK 64
//</h>
//<<< end of configuration section >>>
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef USER_RT_Thread
#define	rt_enter_critical();	;
#define	rt_exit_critical();		;
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
