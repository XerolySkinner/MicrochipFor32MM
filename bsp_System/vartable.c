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
	说明:基础函数
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	头文件
#include "vartable.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序
//	
//	输出函数
#ifdef USER_PRINT
//	重定向基本输出输入于USART1
int fputc(int ch,FILE *f){
	UART_SendData(UART1,ch);
	while(!(UART1->CSR & UART_CSR_TXC));
    return ch;}
#endif
//----------------------------------------------------------------------------------------------------
#ifdef USER_RT_Thread
//	用于RT_Thread系统控制台输出
void rt_hw_console_output(const char *str){
	rt_enter_critical();
		while ( *str != '\0' ){
			if ( *str == '\n'){
				UART_SendData(UART1, '\r');
				while(!(UART1->CSR & UART_CSR_TXC));}
			UART_SendData(UART1, *str++);
			while(!(UART1->CSR & UART_CSR_TXC));}
	rt_exit_critical();}
//	用于RT_Thread系统控制台输入
char rt_hw_console_getchar(void){
    int ch = -1;
	if(UART_GetFlagStatus(UART1, UART_FLAG_RXAVL) != RESET){
        ch = UART_ReceiveData(UART1) & 0xFF;}
    return ch;}
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////////
