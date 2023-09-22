/*----------------------------------------------------------------*/
/* */
/* EVENT constant and type definitions and management services */
/* */
/*----------------------------------------------------------------*/
#ifndef APEX_EVENT
#define APEX_EVENT

#ifdef __cplusplus
extern "C" {
#endif

#include "apex_types.h"

#define MAX_NUMBER_OF_EVENTS SYSTEM_LIMIT_NUMBER_OF_EVENTS
typedef NAME_TYPE EVENT_NAME_TYPE;
typedef APEX_INTEGER EVENT_ID_TYPE;
typedef enum { DOWN = 0, UP = 1 } EVENT_STATE_TYPE;
typedef
struct {
  EVENT_STATE_TYPE EVENT_STATE;
  WAITING_RANGE_TYPE WAITING_PROCESSES;
} EVENT_STATUS_TYPE;
#define CREATE_EVENT(EVENT_NAME, EVENT_ID, RETURN_CODE) JL653_CREATE_EVENT(__FILE__, __FUNCTION__, __LINE__, EVENT_NAME, EVENT_ID, RETURN_CODE)
JL653SHELL_API void JL653_CREATE_EVENT (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ EVENT_NAME_TYPE EVENT_NAME,
  /*out*/ EVENT_ID_TYPE *EVENT_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define SET_EVENT(EVENT_ID, RETURN_CODE) JL653_SET_EVENT(__FILE__, __FUNCTION__, __LINE__, EVENT_ID, RETURN_CODE)
JL653SHELL_API void JL653_SET_EVENT (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ EVENT_ID_TYPE EVENT_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define RESET_EVENT(EVENT_ID, RETURN_CODE) JL653_RESET_EVENT(__FILE__, __FUNCTION__, __LINE__, EVENT_ID, RETURN_CODE)
JL653SHELL_API void JL653_RESET_EVENT (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ EVENT_ID_TYPE EVENT_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define WAIT_EVENT(EVENT_ID, TIME_OUT, RETURN_CODE) JL653_WAIT_EVENT(__FILE__, __FUNCTION__, __LINE__, EVENT_ID, TIME_OUT, RETURN_CODE)
JL653SHELL_API void JL653_WAIT_EVENT (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ EVENT_ID_TYPE EVENT_ID,
  /*in */ SYSTEM_TIME_TYPE TIME_OUT,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_EVENT_ID(EVENT_NAME, EVENT_ID, RETURN_CODE) JL653_GET_EVENT_ID(__FILE__, __FUNCTION__, __LINE__, EVENT_NAME, EVENT_ID, RETURN_CODE)
JL653SHELL_API void JL653_GET_EVENT_ID (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ EVENT_NAME_TYPE EVENT_NAME,
  /*out*/ EVENT_ID_TYPE *EVENT_ID,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_EVENT_STATUS(EVENT_ID, EVENT_STATUS, RETURN_CODE) JL653_GET_EVENT_STATUS(__FILE__, __FUNCTION__, __LINE__, EVENT_ID, EVENT_STATUS, RETURN_CODE)
JL653SHELL_API void JL653_GET_EVENT_STATUS (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ EVENT_ID_TYPE EVENT_ID,
  /*out*/ EVENT_STATUS_TYPE *EVENT_STATUS,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

#ifdef __cplusplus
}
#endif

#endif
