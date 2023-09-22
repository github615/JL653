/*-------------------------------------------------------------------*/
/* */
/* BLACKBOARD constant and type definitions and management services */
/* */
/*-------------------------------------------------------------------*/
#ifndef APEX_BLACKBOARD
#define APEX_BLACKBOARD

#ifdef __cplusplus
extern "C" {
#endif

#include "apex_types.h"
#include "apex_process.h"

#define MAX_NUMBER_OF_BLACKBOARDS SYSTEM_LIMIT_NUMBER_OF_BLACKBOARDS
typedef NAME_TYPE BLACKBOARD_NAME_TYPE;
typedef APEX_INTEGER BLACKBOARD_ID_TYPE;
typedef enum { EMPTY = 0, OCCUPIED = 1 } EMPTY_INDICATOR_TYPE;
typedef
struct {
  EMPTY_INDICATOR_TYPE EMPTY_INDICATOR;
  MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE;
  WAITING_RANGE_TYPE WAITING_PROCESSES;
} BLACKBOARD_STATUS_TYPE;
#define CREATE_BLACKBOARD(BLACKBOARD_NAME, MAX_MESSAGE_SIZE, BLACKBOARD_ID, RETURN_CODE) JL653_CREATE_BLACKBOARD(__FILE__, __FUNCTION__, __LINE__, BLACKBOARD_NAME, MAX_MESSAGE_SIZE, BLACKBOARD_ID, RETURN_CODE)
JL653SHELL_API void JL653_CREATE_BLACKBOARD (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BLACKBOARD_NAME_TYPE BLACKBOARD_NAME,
  /*in */ MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE,
  /*out*/ BLACKBOARD_ID_TYPE *BLACKBOARD_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define DISPLAY_BLACKBOARD(BLACKBOARD_ID, MESSAGE_ADDR, LENGTH, RETURN_CODE) JL653_DISPLAY_BLACKBOARD(__FILE__, __FUNCTION__, __LINE__, BLACKBOARD_ID, MESSAGE_ADDR, LENGTH, RETURN_CODE)
JL653SHELL_API void JL653_DISPLAY_BLACKBOARD (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BLACKBOARD_ID_TYPE BLACKBOARD_ID,
  /*in */ MESSAGE_ADDR_TYPE MESSAGE_ADDR, /* by reference */
  /*in */ MESSAGE_SIZE_TYPE LENGTH,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define READ_BLACKBOARD(BLACKBOARD_ID, TIME_OUT, MESSAGE_ADDR, LENGTH, RETURN_CODE) JL653_READ_BLACKBOARD(__FILE__, __FUNCTION__, __LINE__, BLACKBOARD_ID, TIME_OUT, MESSAGE_ADDR, LENGTH, RETURN_CODE)
JL653SHELL_API void JL653_READ_BLACKBOARD (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BLACKBOARD_ID_TYPE BLACKBOARD_ID,
  /*in */ SYSTEM_TIME_TYPE TIME_OUT,
  /*in */ MESSAGE_ADDR_TYPE MESSAGE_ADDR,
  /*out*/ MESSAGE_SIZE_TYPE *LENGTH,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define CLEAR_BLACKBOARD(BLACKBOARD_ID, RETURN_CODE) JL653_CLEAR_BLACKBOARD(__FILE__, __FUNCTION__, __LINE__, BLACKBOARD_ID, RETURN_CODE)
JL653SHELL_API void JL653_CLEAR_BLACKBOARD (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BLACKBOARD_ID_TYPE BLACKBOARD_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_BLACKBOARD_ID(BLACKBOARD_NAME, BLACKBOARD_ID, RETURN_CODE) JL653_GET_BLACKBOARD_ID(__FILE__, __FUNCTION__, __LINE__, BLACKBOARD_NAME, BLACKBOARD_ID, RETURN_CODE)
JL653SHELL_API void JL653_GET_BLACKBOARD_ID (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BLACKBOARD_NAME_TYPE BLACKBOARD_NAME,
  /*out*/ BLACKBOARD_ID_TYPE *BLACKBOARD_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_BLACKBOARD_STATUS(BLACKBOARD_ID, BLACKBOARD_STATUS, RETURN_CODE) JL653_GET_BLACKBOARD_STATUS(__FILE__, __FUNCTION__, __LINE__, BLACKBOARD_ID, BLACKBOARD_STATUS, RETURN_CODE)
JL653SHELL_API void JL653_GET_BLACKBOARD_STATUS (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BLACKBOARD_ID_TYPE BLACKBOARD_ID,
  /*out*/ BLACKBOARD_STATUS_TYPE *BLACKBOARD_STATUS,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

#ifdef __cplusplus
}
#endif

#endif
