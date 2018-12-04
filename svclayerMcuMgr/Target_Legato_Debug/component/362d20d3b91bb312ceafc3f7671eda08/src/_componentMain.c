/*
 * AUTO-GENERATED _componentMain.c for the svclayerMcuMgrComponent component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _svclayerMcuMgrComponent_svcLayerMcu_ServiceInstanceName;
const char** svcLayerMcu_ServiceInstanceNamePtr = &_svclayerMcuMgrComponent_svcLayerMcu_ServiceInstanceName;
void svcLayerMcu_AdvertiseService(void);
// Component log session variables.
le_log_SessionRef_t svclayerMcuMgrComponent_LogSession;
le_log_Level_t* svclayerMcuMgrComponent_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _svclayerMcuMgrComponent_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _svclayerMcuMgrComponent_Init(void)
{
    LE_DEBUG("Initializing svclayerMcuMgrComponent component library.");

    // Advertise server-side IPC interfaces.
    svcLayerMcu_AdvertiseService();

    // Register the component with the Log Daemon.
    svclayerMcuMgrComponent_LogSession = log_RegComponent("svclayerMcuMgrComponent", &svclayerMcuMgrComponent_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_svclayerMcuMgrComponent_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
