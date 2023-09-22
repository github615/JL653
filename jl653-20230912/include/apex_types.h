/* This is a compilable ANSI C specification of the APEX interface. */
/* The declarations of the services given below are taken from the */
/* standard, as are the enum types and the names of the others types. */
/* However, the definitions given for these others types, and the */
/* names and values given below for constants, are all implementation */
/* specific. */
/* This ANSI C specification follows the same structure (package) as */
/* the Ada specification. */
/*----------------------------------------------------------------*/
/* */
/* Global constant and type definitions */
/* */
/*----------------------------------------------------------------*/
#ifndef APEX_TYPES
#define APEX_TYPES

#ifdef __cplusplus
extern "C" {
#endif

#include "jl653shell.h"

/*---------------------------*/
/* Domain limits */
/*---------------------------*/
/* Domain dependent */
/* These values define the domain limits and are implementation dependent. */
#define SYSTEM_LIMIT_NUMBER_OF_PARTITIONS 255 /* module scope */
#define SYSTEM_LIMIT_NUMBER_OF_MESSAGES 512 /* module scope */
#define SYSTEM_LIMIT_MESSAGE_SIZE 0x100000 /* module scope */
#define SYSTEM_LIMIT_NUMBER_OF_MULTICAST 10 /* partition scope LRG added*/
#define SYSTEM_LIMIT_NUMBER_OF_PROCESSES 1024 /* partition scope */
#define SYSTEM_LIMIT_NUMBER_OF_SAMPLING_PORTS 1024 /* partition scope */
#define SYSTEM_LIMIT_NUMBER_OF_QUEUING_PORTS 1024 /* partition scope */
#define SYSTEM_LIMIT_NUMBER_OF_BUFFERS 512 /* partition scope */
#define SYSTEM_LIMIT_NUMBER_OF_BLACKBOARDS 512 /* partition scope */
#define SYSTEM_LIMIT_NUMBER_OF_SEMAPHORES 512 /* partition scope */
#define SYSTEM_LIMIT_NUMBER_OF_EVENTS 512 /* partition scope */

/*----------------------*/
/* Base APEX types */
/*----------------------*/
/* The actual size of these base types is system specific and the */
/* sizes must match the sizes used by the implementation of the */
/* underlying Operating System. */
typedef unsigned char APEX_BYTE; /* 8-bit unsigned */
typedef long APEX_INTEGER; /* 32-bit signed */
typedef unsigned long APEX_UNSIGNED; /* 32-bit unsigned */
typedef long long APEX_LONG_INTEGER; /* 64-bit signed */
/*----------------------*/
/* General APEX types */
/*----------------------*/
#undef NO_ERROR
typedef
  enum {
    NO_ERROR = 0, /* request valid and operation performed */
    NO_ACTION = 1, /* status of system unaffected by request */
    NOT_AVAILABLE = 2, /* resource required by request unavailable */
    INVALID_PARAM = 3, /* invalid parameter specified in request */
    INVALID_CONFIG = 4, /* parameter incompatible with configuration */
    INVALID_MODE = 5, /* request incompatible with current mode */
    TIMED_OUT = 6 /* time-out tied up with request has expired */
} RETURN_CODE_TYPE;

#define MAX_CONFIG_NAME_LENGHT 500
typedef char CONFIG_NAME_TYPE[MAX_CONFIG_NAME_LENGHT];

#define MAX_NAME_LENGTH 30
typedef char NAME_TYPE[MAX_NAME_LENGTH];
typedef void (* SYSTEM_ADDRESS_TYPE);
typedef APEX_BYTE * MESSAGE_ADDR_TYPE;
typedef APEX_INTEGER MESSAGE_SIZE_TYPE;
typedef APEX_INTEGER MESSAGE_RANGE_TYPE;
typedef enum { SOURCE = 0, DESTINATION = 1 } PORT_DIRECTION_TYPE;
typedef enum { FIFO = 0, PRIORITY = 1 } QUEUING_DISCIPLINE_TYPE;
typedef enum
{
  NOT_APPLICABLE = 0,
  SENDER_BLOCK = 1,
  RECEIVER_DISCARD = 2
} Protocol_t;
typedef APEX_LONG_INTEGER SYSTEM_TIME_TYPE;
/* 64-bit signed integer with a 1 nanosecond LSB */
#define INFINITE_TIME_VALUE -1

typedef APEX_INTEGER LOCK_LEVEL_TYPE;
typedef APEX_INTEGER WAITING_RANGE_TYPE;

#ifdef __cplusplus
}
#endif

#endif
