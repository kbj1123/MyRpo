#include "legato.h"
#include "interfaces.h"

#include "svclayer_McuDb.h"

COMPONENT_INIT
{
    LE_INFO("---------MCU MGR --------------");
    mcu_db_init();
}
