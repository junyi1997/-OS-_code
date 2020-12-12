/*
*********************************************************************************************************
*                                            EXAMPLE CODE
*
*               This file is provided as an example on how to use Micrium products.
*
*               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
*               your application products.  Example code may be used as is, in whole or in
*               part, or may be used as a reference only. This file can be modified as
*               required to meet the end-product requirements.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can find our product's user manual, API reference, release notes and
*               more information at https://doc.micrium.com.
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                              uC/OS-II
*                                            EXAMPLE CODE
*
* Filename : main.c
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*/

#include  <cpu.h>
#include  <lib_mem.h>
#include  <os.h>

#include  "app_cfg.h"


/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/
#define TASK_STACKSIZE      2048
#define TASK1_PRIORITY      1
#define TASK2_PRIORITY      2
#define TASK3_PRIORITY      3
#define TASK4_PRIORITY      5
#define TASK5_PRIORITY      4
#define TASK1_ID            1
#define TASK2_ID            2
#define TASK3_ID            3
#define TASK4_ID            4
#define TASK5_ID            5

static  OS_STK  StartupTaskStk[APP_CFG_STARTUP_TASK_STK_SIZE];
static  OS_STK  Task1_STK[TASK_STACKSIZE];
static  OS_STK  Task2_STK[TASK_STACKSIZE];
static  OS_STK  Task3_STK[TASK_STACKSIZE];
static  OS_STK  Task4_STK[TASK_STACKSIZE];
static  OS_STK  Task5_STK[TASK_STACKSIZE];


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  StartupTask (void  *p_arg);
static  void  task1(void* p_arg);
static  void  task2(void* p_arg);
static  void  task3(void* p_arg);
static  void  task4(void* p_arg);
static  void  task5(void* p_arg);


/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Arguments   : none
*
* Returns     : none
*
* Notes       : none
*********************************************************************************************************
*/

int  main (void)
{
#if OS_TASK_NAME_EN > 0u
    CPU_INT08U  os_err;
#endif


    CPU_IntInit();

    Mem_Init();                                                 /* Initialize Memory Managment Module                   */
    CPU_IntDis();                                               /* Disable all Interrupts                               */
    CPU_Init();                                                 /* Initialize the uC/CPU services                       */

    OSInit();                                                   /* Initialize uC/OS-II                                  */

    TimeTask task1_set = {0, 2, 6};      //set : {start time, work time, period time}
    TimeTask task2_set = {0, 5, 9};      //set : {start time, work time, period time}
    TimeTask task3_set = { 0, 5, 20 };      //set : {start time, work time, period time}
    TimeTask task4_set = { 12, 3, 28 };      //set : {start time, work time, period time}
    TimeTask task5_set = { 14, 2, 39 };      //set : {start time, work time, period time}


    OSTaskCreateExt(
        task1,
        &task1_set,
        &Task1_STK[TASK_STACKSIZE - 1],
        TASK1_PRIORITY,
        TASK1_ID,
        &Task1_STK[0],
        TASK_STACKSIZE,
        &task1_set,
        (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

    OSTaskCreateExt(
        task2,
        &task2_set,
        &Task2_STK[TASK_STACKSIZE - 1],
        TASK2_PRIORITY,
        TASK2_ID,
        &Task2_STK[0],
        TASK_STACKSIZE,
        &task2_set,
        (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));


    OSTaskCreateExt(
        task3,
        &task3_set,
        &Task3_STK[TASK_STACKSIZE - 1],
        TASK3_PRIORITY,
        TASK3_ID,
        &Task3_STK[0],
        TASK_STACKSIZE,
        &task3_set,
        (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));


    OSTaskCreateExt(
        task4,
        &task4_set,
        &Task4_STK[TASK_STACKSIZE - 1],
        TASK4_PRIORITY,
        TASK4_ID,
        &Task4_STK[0],
        TASK_STACKSIZE,
        &task4_set,
        (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));


    OSTaskCreateExt(
        task5,
        &task5_set,
        &Task5_STK[TASK_STACKSIZE - 1],
        TASK5_PRIORITY,
        TASK5_ID,
        &Task5_STK[0],
        TASK_STACKSIZE,
        &task5_set,
        (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

/*  //sample
    OSTaskCreateExt( StartupTask,                               Create the startup task                             
                     0,
                    &StartupTaskStk[APP_CFG_STARTUP_TASK_STK_SIZE - 1u],
                     APP_CFG_STARTUP_TASK_PRIO,
                     APP_CFG_STARTUP_TASK_PRIO,
                    &StartupTaskStk[0u],
                     APP_CFG_STARTUP_TASK_STK_SIZE,
                     0u,
                    (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));

#if OS_TASK_NAME_EN > 0u
    OSTaskNameSet(         APP_CFG_STARTUP_TASK_PRIO,
                  (INT8U *)"Startup Task",
                           &os_err);
#endif
*/
    OSStart();                                                  /* Start multitasking (i.e. give control to uC/OS-II)   */

    while (DEF_ON) {                                            /* Should Never Get Here.                               */
        ;
    }
}


/*
*********************************************************************************************************
*                                            STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'StartupTask()' by 'OSTaskCreate()'.
*
* Returns     : none
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  StartupTask (void *p_arg)
{
   (void)p_arg;

    OS_TRACE_INIT();                                            /* Initialize the uC/OS-II Trace recorder               */

#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&err);                               /* Compute CPU capacity with no task running            */
#endif

#ifdef CPU_CFG_INT_DIS_MEAS_EN
    CPU_IntDisMeasMaxCurReset();
#endif
    
    APP_TRACE_DBG(("uCOS-III is Running...\n\r"));

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
        OSTimeDlyHMSM(0u, 0u, 1u, 0u);
		APP_TRACE_DBG(("Time: %d\n\r", OSTimeGet()));
    }
}

void task1(void *p_arg) {
    (void)p_arg;
    while (1) { 
        ;
    }
}

void task2(void* p_arg) {
    (void)p_arg;
    while (1) {
        ;
    }
}

void task3(void* p_arg) {
    (void)p_arg;
    while (1) {
        ;
    }
}

void task4(void* p_arg) {
    (void)p_arg;
    while (1) {
        ;
    }
}

void task5(void* p_arg) {
    (void)p_arg;
    while (1) {
        ;
    }
}