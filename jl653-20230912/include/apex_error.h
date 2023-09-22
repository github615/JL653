/*----------------------------------------------------------------*/
/* */
/* ERROR constant and type definitions and management services */
/* */
/*----------------------------------------------------------------*/
#ifndef APEX_ERROR
#define APEX_ERROR

#ifdef __cplusplus
extern "C" {
#endif

#include "apex_types.h"
#include "apex_process.h"

#define MAX_ERROR_MESSAGE_SIZE 128
typedef APEX_INTEGER ERROR_MESSAGE_SIZE_TYPE;
typedef APEX_BYTE ERROR_MESSAGE_TYPE[MAX_ERROR_MESSAGE_SIZE];
typedef
  enum {
    DEADLINE_MISSED = 0,
    APPLICATION_ERROR = 1,
    NUMERIC_ERROR = 2,
    ILLEGAL_REQUEST = 3,
    STACK_OVERFLOW = 4,
    MEMORY_VIOLATION = 5,
    HARDWARE_FAULT = 6,
    POWER_FAIL = 7
} ERROR_CODE_TYPE;
typedef
struct {
  ERROR_CODE_TYPE ERROR_CODE;
  ERROR_MESSAGE_SIZE_TYPE LENGTH;
  PROCESS_ID_TYPE FAILED_PROCESS_ID;
  SYSTEM_ADDRESS_TYPE FAILED_ADDRESS;
  ERROR_MESSAGE_TYPE MESSAGE;
} ERROR_STATUS_TYPE;
#define REPORT_APPLICATION_MESSAGE(MESSAGE_ADDR, LENGTH, RETURN_CODE) JL653_REPORT_APPLICATION_MESSAGE(__FILE__, __FUNCTION__, __LINE__, MESSAGE_ADDR, LENGTH, RETURN_CODE)
JL653SHELL_API void JL653_REPORT_APPLICATION_MESSAGE (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ MESSAGE_ADDR_TYPE MESSAGE_ADDR,
  /*in */ MESSAGE_SIZE_TYPE LENGTH,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define CREATE_ERROR_HANDLER(ENTRY_POINT, STACK_SIZE, RETURN_CODE) JL653_CREATE_ERROR_HANDLER(__FILE__, __FUNCTION__, __LINE__, ENTRY_POINT, STACK_SIZE, RETURN_CODE)
JL653SHELL_API void JL653_CREATE_ERROR_HANDLER (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ SYSTEM_ADDRESS_TYPE ENTRY_POINT,
  /*in */ STACK_SIZE_TYPE STACK_SIZE,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_ERROR_STATUS(ERROR_STATUS, RETURN_CODE) JL653_GET_ERROR_STATUS(__FILE__, __FUNCTION__, __LINE__, ERROR_STATUS, RETURN_CODE)
JL653SHELL_API void JL653_GET_ERROR_STATUS (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*out*/ ERROR_STATUS_TYPE *ERROR_STATUS,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define RAISE_APPLICATION_ERROR(ERROR_CODE, MESSAGE_ADDR, LENGTH, RETURN_CODE) JL653_RAISE_APPLICATION_ERROR(__FILE__, __FUNCTION__, __LINE__, ERROR_CODE, MESSAGE_ADDR, LENGTH, RETURN_CODE)
JL653SHELL_API void JL653_RAISE_APPLICATION_ERROR (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ ERROR_CODE_TYPE ERROR_CODE,
  /*in */ MESSAGE_ADDR_TYPE MESSAGE_ADDR,
  /*in */ ERROR_MESSAGE_SIZE_TYPE LENGTH,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

#ifdef __cplusplus
}
#endif

#endif