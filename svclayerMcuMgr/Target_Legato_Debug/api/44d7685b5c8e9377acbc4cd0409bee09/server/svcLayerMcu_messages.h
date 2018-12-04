
/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef SVCLAYERMCU_MESSAGES_H_INCLUDE_GUARD
#define SVCLAYERMCU_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "ba20f5dc899c988c97fb3069d6ca9674"

#ifdef MK_TOOLS_BUILD
    extern const char** svcLayerMcu_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*svcLayerMcu_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "svcLayerMcu"
#endif


#define _MAX_MSG_SIZE 120

// Define the message type for communicating between client and server
typedef struct __attribute__((packed))
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;

#define _MSGID_svcLayerMcu_SetMcuCommand1 0
#define _MSGID_svcLayerMcu_SetMcuCommand2 1
#define _MSGID_svcLayerMcu_SetMcuCommand3 2
#define _MSGID_svcLayerMcu_GetMcuCommand1 3


#endif // SVCLAYERMCU_MESSAGES_H_INCLUDE_GUARD