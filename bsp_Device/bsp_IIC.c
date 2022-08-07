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

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	ͷ�ļ�
#include "vartable.h"
#include "bsp_IIC.h"
char (*bspIIC1[2])(char)={IIC1_SCK,IIC1_SDA};
#define bspIIC_SCK(IIC_VAR)	bspIIC[0](IIC_VAR)
#define bspIIC_SDA(IIC_VAR)	bspIIC[1](IIC_VAR)
enum{
	IIC_RESET,
	IIC_SET,
	IIC_READ};
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	�������
//	
//	��ʱ����
void IIC_Delay(void){
	unsigned char i=0;
	while(++i);}
//	IIC1SCK����
char IIC1_SCK(char var){
	if(var==IIC_RESET){
		HAL_GPIO_WritePin(IIC_SCK_GPIO_Port,IIC_SCK_Pin,GPIO_PIN_RESET);
		return 2;}
	else if(var==IIC_SET){
		HAL_GPIO_WritePin(IIC_SCK_GPIO_Port,IIC_SCK_Pin,GPIO_PIN_SET);
		return 2;}
	else{
		return HAL_GPIO_ReadPin(IIC_SCK_GPIO_Port,IIC_SCK_Pin);}
	}
//	IIC1SDA����
char IIC1_SDA(char var){
	if(var==IIC_RESET){
		HAL_GPIO_WritePin(IIC_SDA_GPIO_Port,IIC_SDA_Pin,GPIO_PIN_RESET);
		return 2;}
	else if(var==IIC_SET){
		HAL_GPIO_WritePin(IIC_SDA_GPIO_Port,IIC_SDA_Pin,GPIO_PIN_SET);
		return 2;}
	else{
		return HAL_GPIO_ReadPin(IIC_SDA_GPIO_Port,IIC_SDA_Pin);}
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	����
//	
//I2C���������ź�
void IIC_Start(char (*bspIIC[])(char)){
	bspIIC_SDA(SET);
    bspIIC_SDA(IIC_SET);
    bspIIC_SCK(IIC_SET);
    IIC_Delay();
    bspIIC_SDA(IIC_RESET);
    IIC_Delay();
    bspIIC_SCK(IIC_RESET);}
//I2C����ֹͣ�ź�
void IIC_Stop(char (*bspIIC[])(char)){
    bspIIC_SDA(IIC_RESET);
    bspIIC_SCK(IIC_SET);
    IIC_Delay();
    bspIIC_SDA(IIC_SET);
    IIC_Delay();}
//����Ӧ����Ӧ���ź�
void IIC_SendAck(char (*bspIIC[])(char),char ackbit){
    bspIIC_SCK(IIC_RESET);
	bspIIC_SDA(ackbit);
    IIC_Delay();
    bspIIC_SCK(IIC_SET);
    IIC_Delay();
    bspIIC_SCK(IIC_RESET);
    bspIIC_SDA(IIC_SET);
    IIC_Delay();}
//�ȴ�Ӧ��
char IIC_WaitAck(char (*bspIIC[])(char)){
    char ackbit;
    bspIIC_SCK(IIC_SET);
    IIC_Delay();
    ackbit = bspIIC_SDA(IIC_READ);
    bspIIC_SCK(IIC_RESET);
    IIC_Delay();
    return ackbit;}
//I2C���߷���һ���ֽ�����
void IIC_SendByte(char (*bspIIC[])(char),unsigned char byt){
    unsigned char i;
    for(i=0; i<8; i++){
		bspIIC_SCK(IIC_RESET);
		IIC_Delay();
		bspIIC_SDA((byt & 0x80)!=0);
		IIC_Delay();
		bspIIC_SCK(IIC_SET);
		byt <<= 1;
		IIC_Delay();}
    bspIIC_SCK(IIC_RESET);}
//I2C���߽���һ���ֽ�����
unsigned char IIC_RecByte(char (*bspIIC[])(char)){
    unsigned char i, da;
    for(i=0;i<8;i++){
    	bspIIC_SCK(IIC_SET);
		IIC_Delay();
		da <<= 1;
		if(bspIIC_SDA(IIC_READ))da |= 1;
		bspIIC_SCK(IIC_RESET);
		IIC_Delay();}
    return da;}
//----------------------------------------------------------------------------------------------------
void IIC_WriteOneByte(char (*bspIIC[])(char),char id,char addr,char dat){
	IIC_Start(bspIIC);
	IIC_SendByte(bspIIC,id<<1);
	IIC_WaitAck(bspIIC);
	IIC_SendByte(bspIIC,addr);
	IIC_WaitAck(bspIIC);
	IIC_SendByte(bspIIC,dat);
	IIC_WaitAck(bspIIC);
	IIC_Stop(bspIIC);}

char IIC_ReadOneByte(char (*bspIIC[])(char),char id,char addr){
	char temp=0;
	IIC_Start(bspIIC);
	IIC_SendByte(bspIIC,id<<1);
	IIC_WaitAck(bspIIC);
	IIC_SendByte(bspIIC,addr);
	IIC_SendAck(bspIIC,0);

	IIC_Start(bspIIC);
	IIC_SendByte(bspIIC,(id<<1)|0x01);
	IIC_SendAck(bspIIC,0);
	temp=IIC_RecByte(bspIIC);
	IIC_SendAck(bspIIC,1);

	IIC_Stop(bspIIC);
	return temp;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
