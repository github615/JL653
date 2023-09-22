#ifndef APEX_INIT
#define APEX_INIT

#ifdef __cplusplus
extern "C" {
#endif

#include "apex_types.h"

#define APEX_CONFIG_INIT(CONFIG_XML_NAME, PARTITION_NAME, RETURN_CODE) JL653_APEX_CONFIG_INIT(__FILE__, __FUNCTION__, __LINE__, CONFIG_XML_NAME, PARTITION_NAME, RETURN_CODE)
JL653SHELL_API void JL653_APEX_CONFIG_INIT (
  const char *location_file,
  const char *location_function,
  int location_line,
  /*in */ CONFIG_NAME_TYPE CONFIG_XML_NAME,
  /*in */ NAME_TYPE PARTITION_NAME,
  /*out*/ RETURN_CODE_TYPE *RETURN_CODE );

#ifdef __cplusplus
}
#endif

#endif
