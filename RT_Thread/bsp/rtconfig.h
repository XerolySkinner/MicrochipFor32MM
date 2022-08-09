/* RT-Thread config file */

#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

#include <rtthread.h>
#include "finsh_config.h"
#if defined(__CC_ARM) || defined(__CLANG_ARM)
// #include "RTE_Components.h"

#if defined(RTE_USING_FINSH)
#define RT_USING_FINSH
#endif //RTE_USING_FINSH

#endif //(__CC_ARM) || (__CLANG_ARM)

// <<< Use Configuration Wizard in Context Menu >>>
// <h>��������
// <o>�߳����ȼ�����󼶱�<8-256>
//  <i>Ĭ��: 32
#define RT_THREAD_PRIORITY_MAX  8
// <o>����ϵͳ�δ�ÿ��
//  <i>Ĭ��: 1000(1ms)
#define RT_TICK_PER_SECOND  1000
// <o>CPU�ܹ����ݷ��ʵĶ����С
//  <i>Ĭ��: 4
#define RT_ALIGN_SIZE   4
// <o>�������Ƶ���󳤶�<2-16>
//  <i>Ĭ��: 8
#define RT_NAME_MAX    16
// <c1>ʹ��RT�߳������ʼ��
//  <i>ʹ��RT�߳������ʼ��
#define RT_USING_COMPONENTS_INIT
// </c>

#define RT_USING_USER_MAIN

// <o>���̵߳Ķ�ջ��С<1-4086>
//  <i>Ĭ��: 512
#define RT_MAIN_THREAD_STACK_SIZE     256

// </h>

// <h>��������
// <c1>�����ں˵�������
//  <i>Ĭ�ϣ������ں˵�������
//#define RT_DEBUG
// </c>
// <o>���������ʼ���͵�������<0-1>
//  <i>Ĭ��: 0
#define RT_DEBUG_INIT 0
// <c1>�̶߳�ջ������
//  <i> ��ʹ���̶߳�ջ������
//#define RT_USING_OVERFLOW_CHECK
// </c>
// </h>

// <h>�ҹ�����
// <c1>ʹ�ùҹ�
//  <i>ʹ�ùҹ�
//#define RT_USING_HOOK
// </c>
// <c1>ʹ�ÿ��йҹ�
//  <i>ʹ�ÿ��йҹ�
//#define RT_USING_IDLE_HOOK
// </c>
// </h>

// <e>�����ʱ������
// <i> �����û���ʱ��
#define RT_USING_TIMER_SOFT         0
#if RT_USING_TIMER_SOFT == 0
    #undef RT_USING_TIMER_SOFT
#endif
// <o>��ʱ���̵߳����ȼ�<0-31>
//  <i>Ĭ��: 4
#define RT_TIMER_THREAD_PRIO        4
// <o>��ʱ���̵߳Ķ�ջ��С<0-8192>
//  <i>Ĭ��: 512
#define RT_TIMER_THREAD_STACK_SIZE  512
// </e>

// <h>IPC�����̼�ͨ�ţ�����
// <c1>ʹ���ź���
//  <i>ʹ���ź���
#define RT_USING_SEMAPHORE
// </c>
// <c1>ʹ�û���
//  <i>ʹ�û���
//#define RT_USING_MUTEX
// </c>
// <c1>ʹ���¼�
//  <i>ʹ���¼�
//#define RT_USING_EVENT
// </c>
// <c1>ʹ������
//  <i>ʹ������
#define RT_USING_MAILBOX
// </c>
// <c1>ʹ����Ϣ����
//  <i>ʹ����Ϣ����
//#define RT_USING_MESSAGEQUEUE
// </c>
// </h>

// <h>�ڴ��������
// <c1>��̬�ѹ���
//  <i>��̬�ѹ���
//#define RT_USING_HEAP
// </c>
// <c1>ʹ��С�ڴ�
//  <i>ʹ��С�ڴ�
#define RT_USING_SMALL_MEM
// </c>
// <c1>ʹ�ü�С���ڴ�
//  <i>ʹ�ü�С���ڴ�
//#define RT_USING_TINY_SIZE
// </c>
// </h>

// <h>����̨����
// <c1>ʹ�ÿ���̨
//  <i>ʹ�ÿ���̨
#define RT_USING_CONSOLE
// </c>
// <o>����̨�Ļ�������С<1-1024>
//  <i>����̨�Ļ�������С
//  <i>Ĭ��ֵ��128��128�ֽڣ�
#define RT_CONSOLEBUF_SIZE          128
// </h>

#if defined(RT_USING_FINSH)
    #define FINSH_USING_MSH
    #define FINSH_USING_MSH_ONLY
    // <h>Finsh����
    // <o>Finsh�̵߳����ȼ�<1-7>
    //  <i>Finsh�̵߳����ȼ�
    //  <i>Ĭ��: 6
    #define __FINSH_THREAD_PRIORITY     6
    //#define FINSH_THREAD_PRIORITY       (RT_THREAD_PRIORITY_MAX / 8 * __FINSH_THREAD_PRIORITY + 1)
    // <o>Finsh�̵߳Ķ�ջ<1-4096>
    //  <i>Finsh�̵߳Ķ�ջ
    //  <i>Ĭ��: 4096  (4096�ֽ�)
    //#define FINSH_THREAD_STACK_SIZE     512
    // <o>Finsh�̣߳�1-32������ʷ��
    //  <i>Finsh�̵߳���ʷ��
    //  <i>Ĭ��: 5
    #define FINSH_HISTORY_LINES         1

    #define FINSH_USING_SYMTAB
    // </h>
#endif

// <<< end of configuration section >>>

#endif
