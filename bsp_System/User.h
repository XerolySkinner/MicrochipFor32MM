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
	名字:User.h
	时间:
	程序员:梁源康
	说明:用户设置
*/
#ifndef _XEROLYSKINNER_USER_H
#define _XEROLYSKINNER_USER_H
//////////////////////////////////////////////////////////////////////////////////////////////////////
//<<< Use Configuration Wizard in Context Menu >>>
//<h>调试功能设置
	//<c>全局调试模式
	#define	USER_DEBUG
	//</c>
	
	//<c>重定向输出
	#define	USER_PRINT
	//</c>
//</h>

//<c>使用RT_Thread
#define USER_RT_Thread
//</c>

//<h>启用相关NVIC中断
	//<c>使能UART1的NVIC中断
	#define USER_NVIC_UART1
	//</c>
	
	//<c>使能UART3的NVIC中断
	#define USER_NVIC_UART3
	//</c>
	
	//<c>使能TIM1的NVIC中断
	#define USER_NVIC_TIM1
	//</c>
//</h>

//<h>特殊功能
	//<c>使用控制台通讯
	#define USER_CONSOLE
	//</c>
	//<o>控制台可用栈长
	//<i>默认64,使用控制台通讯为前置选项
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
