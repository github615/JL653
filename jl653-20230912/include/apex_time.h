/*----------------------------------------------------------------*/
/* */
/* TIME constant and type definitions and management services */
/* */
/*----------------------------------------------------------------*/
#ifndef APEX_TIME
#define APEX_TIME

#ifdef __cplusplus
extern "C" {
#endif

#include "apex_types.h"

#define TIMED_WAIT(DELAY_TIME, RETURN_CODE) JL653_TIMED_WAIT(__FILE__, __FUNCTION__, __LINE__, DELAY_TIME, RETURN_CODE)
JL653SHELL_API void JL653_TIMED_WAIT (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ SYSTEM_TIME_TYPE DELAY_TIME,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define PERIODIC_WAIT(RETURN_CODE) JL653_PERIODIC_WAIT(__FILE__, __FUNCTION__, __LINE__, RETURN_CODE)
JL653SHELL_API void JL653_PERIODIC_WAIT (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define GET_TIME(SYSTEM_TIME, RETURN_CODE) JL653_GET_TIME(__FILE__, __FUNCTION__, __LINE__, SYSTEM_TIME, RETURN_CODE)
JL653SHELL_API void JL653_GET_TIME (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*out*/ SYSTEM_TIME_TYPE *SYSTEM_TIME,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define REPLENISH(BUDGET_TIME, RETURN_CODE) JL653_REPLENISH(__FILE__, __FUNCTION__, __LINE__, BUDGET_TIME, RETURN_CODE)
JL653SHELL_API void JL653_REPLENISH (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ SYSTEM_TIME_TYPE BUDGET_TIME,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

#ifdef __cplusplus
}
#endif

#endif