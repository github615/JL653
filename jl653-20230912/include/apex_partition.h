/*----------------------------------------------------------------*/
/* */
/* PARTITION constant and type definitions and management services*/
/* */
/*----------------------------------------------------------------*/
#ifndef APEX_PARTITION
#define APEX_PARTITION

#ifdef __cplusplus
extern "C" {
#endif

#include "apex_types.h"

#define MAX_NUMBER_OF_PARTITIONS SYSTEM_LIMIT_NUMBER_OF_PARTITIONS
typedef
  enum {
    IDLE = 0,
    COLD_START = 1,
    WARM_START = 2,
    NORMAL = 3
} OPERATING_MODE_TYPE;
typedef APEX_INTEGER PARTITION_ID_TYPE;
typedef
  enum {
    NORMAL_START = 0,
    PARTITION_RESTART = 1,
    HM_MODULE_RESTART = 2,
    HM_PARTITION_RESTART = 3
} START_CONDITION_TYPE;
typedef
struct {
  SYSTEM_TIME_TYPE PERIOD;
  SYSTEM_TIME_TYPE DURATION;
  PARTITION_ID_TYPE IDENTIFIER;
  LOCK_LEVEL_TYPE LOCK_LEVEL;
  OPERATING_MODE_TYPE OPERATING_MODE;
  START_CONDITION_TYPE START_CONDITION;
} PARTITION_STATUS_TYPE;
#define GET_PARTITION_STATUS(PARTITION_STATUS, RETURN_CODE) JL653_GET_PARTITION_STATUS(__FILE__, __FUNCTION__, __LINE__, PARTITION_STATUS, RETURN_CODE)
JL653SHELL_API void JL653_GET_PARTITION_STATUS (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*out*/ PARTITION_STATUS_TYPE *PARTITION_STATUS,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );
#define SET_PARTITION_MODE(OPERATING_MODE, RETURN_CODE) JL653_SET_PARTITION_MODE(__FILE__, __FUNCTION__, __LINE__, OPERATING_MODE, RETURN_CODE)
JL653SHELL_API void JL653_SET_PARTITION_MODE (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ OPERATING_MODE_TYPE OPERATING_MODE,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

#ifdef __cplusplus
}
#endif

#endif
