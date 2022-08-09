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
	名字:bsp_RT
	时间:202208082126
	程序员:梁源康
	说明:RT-Thread相关使用
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	头文件
#include "User.h"
#ifdef USER_RT_Thread
#include <rtthread.h>
extern void XerolySkinner_main(void* parameter);
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	进程注册
//	
static struct	rt_thread XerolySkinner_main_thread;
static char		XerolySkinner_main_stack[512];
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序
//	
void RT_Thread_app_Init(void){
	//此处可以插入进程
	rt_thread_init(
		&XerolySkinner_main_thread,			//线程控制代号
		"XerolySkinner_main",				//线程名字字符串
		XerolySkinner_main,					//入口函数名
		RT_NULL,							//空
		XerolySkinner_main_stack,			//栈首地址
		sizeof(XerolySkinner_main_stack),	//栈堆大小
		1,									//优先级
		10);								//时间片
	rt_thread_startup(&XerolySkinner_main_thread);
	return;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
