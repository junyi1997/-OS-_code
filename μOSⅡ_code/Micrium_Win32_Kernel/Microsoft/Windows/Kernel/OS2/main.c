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

//static  OS_STK  StartupTaskStk[APP_CFG_STARTUP_TASK_STK_SIZE];




/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  StartupTask (void  *p_arg);


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
#include <windows.h>
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
/*
    OSTaskCreateExt( StartupTask,                               // Create the startup task                              
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
    /*
    *********************************************************************************************************
    *                                               Project1-2
    ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
    */

    //int resp_t1[2], resp_t2[2];
    //int input_t1=0, input_t2=0;
    int task1_in[3] = { 0, 8, 15 };
    int task2_in[3] = { 0, 2, 5 };
    int task3_in[3] = { 0, 0, 0 };

    /*
    ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
    *                                               Project1-2
    *********************************************************************************************************
    */
    /*
    *********************************************************************************************************
    *                                               HW00
    ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
    */

    #define TASK_STACKSIZE        2048
    #define TASK1_PRIORITY        2
    #define TASK2_PRIORITY        1
    #define TASK3_PRIORITY        3
    #define TASK1_ID              1
    #define TASK2_ID              2
    #define TASK3_ID              3
   


        static  void  task1(void* p_arg);
        static  void  task2(void* p_arg);
        static  void  task3(void* p_arg);

        static  OS_STK  TASK1_STK[TASK_STACKSIZE];
        static  OS_STK  TASK2_STK[TASK_STACKSIZE];
        static  OS_STK  TASK3_STK[TASK_STACKSIZE];

        OSTaskCreateExt(task1,                               /* Create the startup task*/
            0,
            &TASK1_STK[TASK_STACKSIZE - 1],
            TASK1_PRIORITY,
            TASK1_ID,
            &TASK1_STK[0],
            TASK_STACKSIZE,
            0,
            (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));
        OSTaskCreateExt(task2,                               /* Create the startup task*/
            0,
            &TASK2_STK[TASK_STACKSIZE - 1],
            TASK2_PRIORITY,
            TASK2_ID,
            &TASK2_STK[0],
            TASK_STACKSIZE,
            0,
            (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));
        /*
        OSTaskCreateExt(task3,                               
            0,
            &TASK3_STK[TASK_STACKSIZE - 1],
            TASK3_PRIORITY,
            TASK3_ID,
            &TASK3_STK[0],
            TASK_STACKSIZE,
            0,
            (OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR));        
        */



        OSTimeSet(0);                                               //OS_Time 歸零
    /*
    ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
    *                                               HW00
    *********************************************************************************************************
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

/*
*********************************************************************************************************
*                                               HW00
▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼

void  task1(void* p_arg) {
    (void)p_arg;
    while (1) {
        //printf("%d\t", OSTimeGet());      //print OSTime
        //printf("Task(1)\n");              //test delay
        OSTimeDly(1);
        //printf("delay3\n");
    }
}

void  task2(void* p_arg) {
    (void)p_arg;
    while (1) {
        //printf("%d\t", OSTimeGet());      //print OSTime
        //printf("Task(2)\n");              //test delay
        OSTimeDly(1);
        // printf("delay6\n");
    }
}

▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
*                                               HW00
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                               Project1-2
▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
*/

//int resp_t1[2], resp_t2[2];
//int input_t1=0, input_t2=0;
int task1_in[3] = { 0, 8, 15 };
int task2_in[3] = { 0, 2, 5 };
int task3_in[3] = { 0, 0, 0 };



void  task1(void* p_arg) {
    (void)p_arg;
    while (1) {
        //OSTimeDly(task1_in[0]);
        //printf("%d\t", OSTimeGet());      //print OSTime
        //printf("Task(1)開始,第%d次\n", input_t1);              //test delay
        //resp_t1[0] = OSTimeGet();
        //printf("%d\t", OSTimeGet());      //print OSTime
        //printf("\t\t\tTask(1)結束\n");              //test delay 
        //resp_t1[1] = OSTimeGet();
        //input_t1++;
        //printf("Task(1)執行時間：%d\n", resp_t1[1]- resp_t1[0]);

        Sleep(task1_in[1]*1000);
        
        if (task1_in[2] > task2_in[2]) {
            OSTimeDly(task1_in[2] - (task1_in[2] / task2_in[2] * task2_in[1] + task1_in[1]) + task2_in[1]);
        }
        else {
            OSTimeDly(task1_in[2] - task1_in[1]);
        }
        

    }
}

void  task2(void* p_arg) {
    (void)p_arg;
    while (1) {
        //OSTimeDly(task2_in[0]);
        //printf("%d\t", OSTimeGet());      //print OSTime
        //printf("Task(2)開始,第%d次\n", input_t2);             //test delay
        //resp_t2[0] = OSTimeGet();
        //printf("%d\t", OSTimeGet());      //print OSTime
        //printf("\t\t\tTask(2)結束\n");              //test delay
        //resp_t2[1] = OSTimeGet();
        //printf("Task(2)執行時間：%d\n", resp_t2[1] - input_t2* task2_in[2]);
        //input_t2++;
        Sleep(task2_in[1] * 1000);
        if (task2_in[2] > task1_in[2]) {
            OSTimeDly(task2_in[2] - (task2_in[2] / task1_in[2] * task1_in[1] + task2_in[1]) + task1_in[1]);
        }
        else {
            OSTimeDly(task2_in[2] - task2_in[1]);
        }
    }
}
/*
void  task3(void* p_arg) {
    (void)p_arg;
    while (1) {
        //printf("%d\t", OSTimeGet());      //print OSTime
        //printf("Task(3)\n");              //test delay
        //OSTimeDly(7);
        
        // printf("delay6\n");
    }
    //Sleep(7);
}
*/



/*
▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
*                                               Project1-2
*********************************************************************************************************
*/



