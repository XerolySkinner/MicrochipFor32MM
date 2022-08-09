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
// <h>基本设置
// <o>线程优先级的最大级别<8-256>
//  <i>默认: 32
#define RT_THREAD_PRIORITY_MAX  8
// <o>操作系统滴答每秒
//  <i>默认: 1000(1ms)
#define RT_TICK_PER_SECOND  1000
// <o>CPU架构数据访问的对齐大小
//  <i>默认: 4
#define RT_ALIGN_SIZE   4
// <o>对象名称的最大长度<2-16>
//  <i>默认: 8
#define RT_NAME_MAX    16
// <c1>使用RT线程组件初始化
//  <i>使用RT线程组件初始化
#define RT_USING_COMPONENTS_INIT
// </c>

#define RT_USING_USER_MAIN

// <o>主线程的堆栈大小<1-4086>
//  <i>默认: 512
#define RT_MAIN_THREAD_STACK_SIZE     256

// </h>

// <h>调试配置
// <c1>启用内核调试配置
//  <i>默认：启用内核调试配置
//#define RT_DEBUG
// </c>
// <o>启用组件初始化和调试配置<0-1>
//  <i>默认: 0
#define RT_DEBUG_INIT 0
// <c1>线程堆栈溢出检测
//  <i> 不使能线程堆栈溢出检测
//#define RT_USING_OVERFLOW_CHECK
// </c>
// </h>

// <h>挂钩配置
// <c1>使用挂钩
//  <i>使用挂钩
//#define RT_USING_HOOK
// </c>
// <c1>使用空闲挂钩
//  <i>使用空闲挂钩
//#define RT_USING_IDLE_HOOK
// </c>
// </h>

// <e>软件定时器配置
// <i> 启用用户计时器
#define RT_USING_TIMER_SOFT         0
#if RT_USING_TIMER_SOFT == 0
    #undef RT_USING_TIMER_SOFT
#endif
// <o>定时器线程的优先级<0-31>
//  <i>默认: 4
#define RT_TIMER_THREAD_PRIO        4
// <o>计时器线程的堆栈大小<0-8192>
//  <i>默认: 512
#define RT_TIMER_THREAD_STACK_SIZE  512
// </e>

// <h>IPC（进程间通信）配置
// <c1>使用信号量
//  <i>使用信号量
#define RT_USING_SEMAPHORE
// </c>
// <c1>使用互斥
//  <i>使用互斥
//#define RT_USING_MUTEX
// </c>
// <c1>使用事件
//  <i>使用事件
//#define RT_USING_EVENT
// </c>
// <c1>使用邮箱
//  <i>使用邮箱
#define RT_USING_MAILBOX
// </c>
// <c1>使用消息队列
//  <i>使用消息队列
//#define RT_USING_MESSAGEQUEUE
// </c>
// </h>

// <h>内存管理配置
// <c1>动态堆管理
//  <i>动态堆管理
//#define RT_USING_HEAP
// </c>
// <c1>使用小内存
//  <i>使用小内存
#define RT_USING_SMALL_MEM
// </c>
// <c1>使用极小的内存
//  <i>使用极小的内存
//#define RT_USING_TINY_SIZE
// </c>
// </h>

// <h>控制台配置
// <c1>使用控制台
//  <i>使用控制台
#define RT_USING_CONSOLE
// </c>
// <o>控制台的缓冲区大小<1-1024>
//  <i>控制台的缓冲区大小
//  <i>默认值：128（128字节）
#define RT_CONSOLEBUF_SIZE          128
// </h>

#if defined(RT_USING_FINSH)
    #define FINSH_USING_MSH
    #define FINSH_USING_MSH_ONLY
    // <h>Finsh配置
    // <o>Finsh线程的优先级<1-7>
    //  <i>Finsh线程的优先级
    //  <i>默认: 6
    #define __FINSH_THREAD_PRIORITY     6
    //#define FINSH_THREAD_PRIORITY       (RT_THREAD_PRIORITY_MAX / 8 * __FINSH_THREAD_PRIORITY + 1)
    // <o>Finsh线程的堆栈<1-4096>
    //  <i>Finsh线程的堆栈
    //  <i>默认: 4096  (4096字节)
    //#define FINSH_THREAD_STACK_SIZE     512
    // <o>Finsh线程＜1-32＞的历史线
    //  <i>Finsh线程的历史线
    //  <i>默认: 5
    #define FINSH_HISTORY_LINES         1

    #define FINSH_USING_SYMTAB
    // </h>
#endif

// <<< end of configuration section >>>

#endif
