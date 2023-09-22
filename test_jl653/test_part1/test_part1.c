/* --------------------------- 序言 ---------------------------------*/
/**
 **********************************************************************
 *
 * (C) 2023
 *
 * @功能描述
 *
 **********************************************************************
*/
/* --------------------------- 文件包含 -----------------------------*/
#include "apex_lib.h"
#include <windows.h>
#include <stdio.h>

/* --------------------------- 宏定义 -------------------------------*/
#define One_Second 1000000000LL
#define One_MS     1000000LL

/* --------------------------- 类型定义 -----------------------------*/

/* --------------------------- 变量定义 -----------------------------*/
PROCESS_ID_TYPE Process_1_Id;
PROCESS_ID_TYPE Process_2_Id;

/* --------------------------- 函数定义 -----------------------------*/
/**
 **********************************************************************
 *
 * @功能描述
 *
 **********************************************************************
*/
void Process_1_Procedure()
{
  RETURN_CODE_TYPE Return_Code;
  SYSTEM_TIME_TYPE SYSTEM_TIME;

  GET_TIME(&SYSTEM_TIME, &Return_Code);

  printf("=============Process_1 start SYSTEM_TIME=%lf\n", (DOUBLE)SYSTEM_TIME / (double)One_Second);

  for (;;)
  {
  	printf("Process_1_Procedure run\n");

    PERIODIC_WAIT (&Return_Code);
  }
}
/**
 **********************************************************************
 *
 * @功能描述
 *
 **********************************************************************
*/
void Process_2_Procedure()
{
  RETURN_CODE_TYPE Return_Code;
  SYSTEM_TIME_TYPE SYSTEM_TIME;

  GET_TIME(&SYSTEM_TIME, &Return_Code);

  printf("****    Process_2 start SYSTEM_TIME=%lf\n", (DOUBLE)SYSTEM_TIME / (double)One_Second);

  for (;;)
  {
    printf("Process_2_Procedure run\n");

    TIMED_WAIT (2 * One_Second, &Return_Code);
  }
}
/**
 **********************************************************************
 *
 * @功能描述
 *
 **********************************************************************
*/
void create_processes()
{
  RETURN_CODE_TYPE Return_Code;

  PROCESS_ATTRIBUTE_TYPE Process_1_Attribute = {
    One_Second * 1,
    -1,
    Process_1_Procedure,
    0x8000,
    100,
    SOFT,
    "p1"
  };

  PROCESS_ATTRIBUTE_TYPE Process_2_Attribute = {
    -1,
    -1,
    Process_2_Procedure,
    0x8000,
    2,
    SOFT,
    "P2"
  };

  PROCESS_ID_TYPE pid;

  CREATE_PROCESS(&Process_1_Attribute, &Process_1_Id, &Return_Code);
  GET_PROCESS_ID("p1", &pid, &Return_Code);
  CREATE_PROCESS(&Process_2_Attribute, &Process_2_Id, &Return_Code);
  START(Process_1_Id, &Return_Code);
  START(Process_2_Id, &Return_Code);
}
/**
 **********************************************************************
 *
 * @功能描述
 *
 **********************************************************************
*/
int main(int argc, char **argv)
{
  RETURN_CODE_TYPE Return_Code;
  QUEUING_PORT_ID_TYPE queue1_id;
  SAMPLING_PORT_ID_TYPE sample1_id;

  CREATE_QUEUING_PORT("queue1", 10, 5, SOURCE, FIFO, &queue1_id, &Return_Code);
  CREATE_SAMPLING_PORT("queue1", 10, SOURCE, One_Second, &sample1_id, &Return_Code);

  create_processes();
	SET_PARTITION_MODE(NORMAL, &Return_Code);

	for (;;)
	{
		Sleep(1000);
	} 
	return 0;
}
