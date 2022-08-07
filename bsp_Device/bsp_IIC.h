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
	����:bsp_IIC
	ʱ��:20220729-2031
	����Ա:��Դ��
	˵��:IIC����
*/
#ifndef _XEROLYSKINNER_BSP_IIC_H
#define _XEROLYSKINNER_BSP_IIC_H
#define	IIC_ADDR_24C02 0x50

extern char (*bspIIC1[2])(char);
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	ǰ�ó���
//	
void IIC_Delay(void);
//	���䵥Ԫ
char IIC1_SDA(char var);
char IIC1_SCK(char var);
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	ǰ�ó���
//	
void IIC_Start(char (*bspIIC[])(char));
void IIC_Stop(char (*bspIIC[])(char));
void IIC_SendAck(char (*bspIIC[])(char),char ackbit);
char IIC_WaitAck(char (*bspIIC[])(char));
void IIC_SendByte(char (*bspIIC[])(char),unsigned char byt);
unsigned char IIC_RecByte(char (*bspIIC[])(char));

void IIC_WriteOneByte(char (*bspIIC[])(char),char id,char addr,char dat);
char IIC_ReadOneByte(char (*bspIIC[])(char),char id,char addr);
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
