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
	名字:MainSystem
	时间:
	程序员:梁源康
	说明:主程序
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	头文件
#include "vartable.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序
//	
//----------------------------------------------------------------------------------------------------
//	初始化程序,先于main执行,更改启动文件.s
void mainSetup(void){
	MM32_Init();}
//----------------------------------------------------------------------------------------------------
//	main线程
int main(void){
	bsp_RT_Init();
	rt_enter_critical();
	printf("[0]线程挂入:main\r\n");
	rt_exit_critical();
	while(1){
		osDelay(6000);
		rt_enter_critical();
		DB1_SW();
		rt_exit_critical();
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////
