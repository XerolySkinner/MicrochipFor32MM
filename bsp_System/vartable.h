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
	名字:vartable
	时间:
	程序员:梁源康
	说明:向量表
*/
#include "stdint.h"
#include "User.h"
#include "bsp_MM32F3277G9P.h"
#include "bsp_IIC.h"
#include "stdio.h"

#ifdef USER_CONSOLE
#include "bsp_Console.h"
#endif

#ifdef USER_RT_Thread
#include <rtthread.h>
#include "bsp_RT.h"
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _XEROLYSKINNER_VARTABLE_H
#define _XEROLYSKINNER_VARTABLE_H

#ifdef USER_RT_Thread
#define osDelay(time) rt_thread_mdelay(time)
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序
//	
int main(void);
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
