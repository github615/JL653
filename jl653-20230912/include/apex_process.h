/*----------------------------------------------------------------*/
/* */
/* PROCESS constant and type definitions and management services */
/* */
/*----------------------------------------------------------------*/
#ifndef APEX_PROCESS
#define APEX_PROCESS

#ifdef __cplusplus
extern "C" {
#endif

#include "apex_types.h"

#define MAX_NUMBER_OF_PROCESSES SYSTEM_LIMIT_NUMBER_OF_PROCESSES
#define MIN_PRIORITY_VALUE 0
#define MAX_PRIORITY_VALUE 249
#define MAX_LOCK_LEVEL 16
#define MAX_STACK_SIZE 0x800000
typedef NAME_TYPE PROCESS_NAME_TYPE;
typedef APEX_INTEGER PROCESS_ID_TYPE;
typedef APEX_UNSIGNED STACK_SIZE_TYPE;
typedef APEX_INTEGER PRIORITY_TYPE;
typedef
  enum {
    DORMANT = 0,
    READY = 1,
    RUNNING = 2,
    WAITING = 3
} PROCESS_STATE_TYPE;
typedef enum { SOFT = 0, HARD = 1 } DEADLINE_TYPE;
typedef
struct {
  SYSTEM_TIME_TYPE PERIOD;
  SYSTEM_TIME_TYPE TIME_CAPACITY;
  SYSTEM_ADDRESS_TYPE ENTRY_POINT;
  STACK_SIZE_TYPE STACK_SIZE;
  PRIORITY_TYPE BASE_PRIORITY;
  DEADLINE_TYPE DEADLINE;
  PROCESS_NAME_TYPE NAME;
} PROCESS_ATTRIBUTE_TYPE;
typedef
struct {
  SYSTEM_TIME_TYPE DEADLINE_TIME;
  PRIORITY_TYPE CURRENT_PRIORITY;
  PROCESS_STATE_TYPE PROCESS_STATE;
  PROCESS_ATTRIBUTE_TYPE ATTRIBUTES;
} PROCESS_STATUS_TYPE;
#define CREATE_PROCESS(ATTRIBUTES, PROCESS_ID, RETURN_CODE) JL653_CREATE_PROCESS(__FILE__, __FUNCTION__, __LINE__, ATTRIBUTES, PROCESS_ID, RETURN_CODE)
JL653SHELL_API void JL653_CREATE_PROCESS (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ PROCESS_ATTRIBUTE_TYPE *ATTRIBUTES,
  /*out*/ PROCESS_ID_TYPE *PROCESS_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define SET_PRIORITY(PROCESS_ID, PRIORITY, RETURN_CODE) JL653_SET_PRIORITY(__FILE__, __FUNCTION__, __LINE__, PROCESS_ID, PRIORITY, RETURN_CODE)
JL653SHELL_API void JL653_SET_PRIORITY (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ PROCESS_ID_TYPE PROCESS_ID,
  /*in */ PRIORITY_TYPE PRIORITY,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define SUSPEND_SELF(TIME_OUT, RETURN_CODE) JL653_SUSPEND_SELF(__FILE__, __FUNCTION__, __LINE__, TIME_OUT, RETURN_CODE)
JL653SHELL_API void JL653_SUSPEND_SELF (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ SYSTEM_TIME_TYPE TIME_OUT,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define SUSPEND(PROCESS_ID, RETURN_CODE) JL653_SUSPEND(__FILE__, __FUNCTION__, __LINE__, PROCESS_ID, RETURN_CODE)
JL653SHELL_API void JL653_SUSPEND (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ PROCESS_ID_TYPE PROCESS_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define RESUME(PROCESS_ID, RETURN_CODE) JL653_RESUME(__FILE__, __FUNCTION__, __LINE__, PROCESS_ID, RETURN_CODE)
JL653SHELL_API void JL653_RESUME (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ PROCESS_ID_TYPE PROCESS_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define STOP_SELF() JL653_STOP_SELF(__FILE__, __FUNCTION__, __LINE__)
JL653SHELL_API void JL653_STOP_SELF (
  const char *location_file,
  const char *location_function,
  int location_line);
#define STOP(PROCESS_ID, RETURN_CODE) JL653_STOP(__FILE__, __FUNCTION__, __LINE__, PROCESS_ID, RETURN_CODE)
JL653SHELL_API void JL653_STOP (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ PROCESS_ID_TYPE PROCESS_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define START(PROCESS_ID, RETURN_CODE) JL653_START(__FILE__, __FUNCTION__, __LINE__, PROCESS_ID, RETURN_CODE)
JL653SHELL_API void JL653_START (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ PROCESS_ID_TYPE PROCESS_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define DELAYED_START(PROCESS_ID, DELAY_TIME, RETURN_CODE) JL653_DELAYED_START(__FILE__, __FUNCTION__, __LINE__, PROCESS_ID, DELAY_TIME, RETURN_CODE)
JL653SHELL_API void JL653_DELAYED_START (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ PROCESS_ID_TYPE PROCESS_ID,
  /*in */ SYSTEM_TIME_TYPE DELAY_TIME,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define LOCK_PREEMPTION(LOCK_LEVEL, RETURN_CODE) JL653_LOCK_PREEMPTION(__FILE__, __FUNCTION__, __LINE__, LOCK_LEVEL, RETURN_CODE)
JL653SHELL_API void JL653_LOCK_PREEMPTION (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*out*/ LOCK_LEVEL_TYPE *LOCK_LEVEL,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define UNLOCK_PREEMPTION(LOCK_LEVEL, RETURN_CODE) JL653_UNLOCK_PREEMPTION(__FILE__, __FUNCTION__, __LINE__, LOCK_LEVEL, RETURN_CODE)
JL653SHELL_API void JL653_UNLOCK_PREEMPTION (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*out*/ LOCK_LEVEL_TYPE *LOCK_LEVEL,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_MY_ID(PROCESS_ID, RETURN_CODE) JL653_GET_MY_ID(__FILE__, __FUNCTION__, __LINE__, PROCESS_ID, RETURN_CODE)
JL653SHELL_API void JL653_GET_MY_ID (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*out*/ PROCESS_ID_TYPE *PROCESS_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_PROCESS_ID(PROCESS_NAME, PROCESS_ID, RETURN_CODE) JL653_GET_PROCESS_ID(__FILE__, __FUNCTION__, __LINE__, PROCESS_NAME, PROCESS_ID, RETURN_CODE)
JL653SHELL_API void JL653_GET_PROCESS_ID (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ PROCESS_NAME_TYPE PROCESS_NAME,
  /*out*/ PROCESS_ID_TYPE *PROCESS_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_PROCESS_STATUS(PROCESS_ID, PROCESS_STATUS, RETURN_CODE) JL653_GET_PROCESS_STATUS(__FILE__, __FUNCTION__, __LINE__, PROCESS_ID, PROCESS_STATUS, RETURN_CODE)
JL653SHELL_API void JL653_GET_PROCESS_STATUS (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ PROCESS_ID_TYPE PROCESS_ID,
  /*out*/ PROCESS_STATUS_TYPE *PROCESS_STATUS,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

#ifdef __cplusplus
}
#endif

#endif
