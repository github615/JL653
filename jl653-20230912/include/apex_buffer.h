/*----------------------------------------------------------------*/
/* */
/* BUFFER constant and type definitions and management services */
/* */
/*----------------------------------------------------------------*/
#ifndef APEX_BUFFER
#define APEX_BUFFER

#ifdef __cplusplus
extern "C" {
#endif

#include "apex_types.h"

#define MAX_NUMBER_OF_BUFFERS SYSTEM_LIMIT_NUMBER_OF_BUFFERS
typedef NAME_TYPE BUFFER_NAME_TYPE;
typedef APEX_INTEGER BUFFER_ID_TYPE;
typedef
struct {
  MESSAGE_RANGE_TYPE NB_MESSAGE;
  MESSAGE_RANGE_TYPE MAX_NB_MESSAGE;
  MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE;
  WAITING_RANGE_TYPE WAITING_PROCESSES;
} BUFFER_STATUS_TYPE;

#define CREATE_BUFFER(BUFFER_NAME, MAX_MESSAGE_SIZE, MAX_NB_MESSAGE, QUEUING_DISCIPLINE, BUFFER_ID, RETURN_CODE) JL653_CREATE_BUFFER(__FILE__, __FUNCTION__, __LINE__, BUFFER_NAME, MAX_MESSAGE_SIZE, MAX_NB_MESSAGE, QUEUING_DISCIPLINE, BUFFER_ID, RETURN_CODE)
JL653SHELL_API void JL653_CREATE_BUFFER (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BUFFER_NAME_TYPE BUFFER_NAME,
  /*in */ MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE,
  /*in */ MESSAGE_RANGE_TYPE MAX_NB_MESSAGE,
  /*in */ QUEUING_DISCIPLINE_TYPE QUEUING_DISCIPLINE,
  /*out*/ BUFFER_ID_TYPE *BUFFER_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define SEND_BUFFER(BUFFER_ID, MESSAGE_ADDR, LENGTH, TIME_OUT, RETURN_CODE) JL653_SEND_BUFFER(__FILE__, __FUNCTION__, __LINE__, BUFFER_ID, MESSAGE_ADDR, LENGTH, TIME_OUT, RETURN_CODE)
JL653SHELL_API void JL653_SEND_BUFFER (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BUFFER_ID_TYPE BUFFER_ID,
  /*in */ MESSAGE_ADDR_TYPE MESSAGE_ADDR, /* by reference */
  /*in */ MESSAGE_SIZE_TYPE LENGTH,
  /*in */ SYSTEM_TIME_TYPE TIME_OUT,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define RECEIVE_BUFFER(BUFFER_ID, TIME_OUT, MESSAGE_ADDR, LENGTH, RETURN_CODE) JL653_RECEIVE_BUFFER(__FILE__, __FUNCTION__, __LINE__, BUFFER_ID, TIME_OUT, MESSAGE_ADDR, LENGTH, RETURN_CODE)
JL653SHELL_API void JL653_RECEIVE_BUFFER (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BUFFER_ID_TYPE BUFFER_ID,
  /*in */ SYSTEM_TIME_TYPE TIME_OUT,
  /*in */ MESSAGE_ADDR_TYPE MESSAGE_ADDR,
  /*out*/ MESSAGE_SIZE_TYPE *LENGTH,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_BUFFER_ID(BUFFER_NAME, BUFFER_ID, RETURN_CODE) JL653_GET_BUFFER_ID(__FILE__, __FUNCTION__, __LINE__, BUFFER_NAME, BUFFER_ID, RETURN_CODE)
JL653SHELL_API void JL653_GET_BUFFER_ID (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BUFFER_NAME_TYPE BUFFER_NAME,
  /*out*/ BUFFER_ID_TYPE *BUFFER_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_BUFFER_STATUS(BUFFER_ID, BUFFER_STATUS, RETURN_CODE) JL653_GET_BUFFER_STATUS(__FILE__, __FUNCTION__, __LINE__, BUFFER_ID, BUFFER_STATUS, RETURN_CODE)
JL653SHELL_API void JL653_GET_BUFFER_STATUS (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ BUFFER_ID_TYPE BUFFER_ID,
  /*out*/ BUFFER_STATUS_TYPE *BUFFER_STATUS,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

#ifdef __cplusplus
}
#endif

#endif
