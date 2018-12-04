/*===================================================

                  Local MCU Data DB C


GENERAL DESCRIPTION




Copyright (c) 2018 by Digen, Incorporated.  All Rights Reserved.
Digen Confidential and Proprietary.
=====================================================*/

/*====================================================

                        EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

when       who     what, where, why
--------   ---     ----------------------------------------------------------


*/

/*=====================================================

                     INCLUDE FILES FOR MODULE

=====================================================*/
#include "svclayer_McuDb.h"

#include "cust.h"
#include "common.h"
#include "legato.h"
#include "interfaces.h"
#include "svclayer_McuDb.h"



// Global Var. for Local Database
mcu_db_items_value_type mcu_local_db_items_value;

int get_string_num(char *string)
{
    int i = 0;
    int ret = 0;
    char buf[100];

    if(string == NULL)
    {
    	return ret;
    }

    memcpy(buf, string,	sizeof(buf));

    for( i = 0 ; buf[i]!= '\0' ; ++i);

    return i;
}

void mcu_db_init()
{

	memset(mcu_local_db_items_value.vin, 0, MAX_STRING_LENGTH);
	mcu_local_db_items_value.doorUnlockResp = DOOR_RESP_SUCCESS;
	mcu_local_db_items_value.doorLockResp = DOOR_RESP_SUCCESS;

	mcu_local_db_items_value.engStartResp.engineStartResult = ENG_START_RESP_SUCCESS;
	mcu_local_db_items_value.engStartResp.hvacStartResult = HVAC_START_RESP_SUCCESS;
	mcu_local_db_items_value.engStartResp.runningOffResult = RUNNING_OFF_RESP_DAFAULT_VALUE;
	mcu_local_db_items_value.engStartResp.defrostResult = DEFROST_START_RESP_DEFROST_ON;
	mcu_local_db_items_value.engStartResp.backHeatLineResult = DEFOGGER_START_DEFOGGER_ON;

	mcu_local_db_items_value.engStopResp.engineStopResult = ENG_STOP_RESP_SUCCESS;
	mcu_local_db_items_value.engStopResp.runningOffResult = RUNNING_OFF_RESP_DAFAULT_VALUE;

	mcu_local_db_items_value.hvacStopResp = HVAC_STOP_RESP_SUCCESS;

	mcu_local_db_items_value.lghtHornResp = LGHT_HORN_RESULT_SUCCESS;

	mcu_local_db_items_value.vehStsChkResp.keyStatus = KEY_STAT_STOPPED;
	mcu_local_db_items_value.vehStsChkResp.driverDoor = LOCK;
	mcu_local_db_items_value.vehStsChkResp.psngrDoor = LOCK;
	mcu_local_db_items_value.vehStsChkResp.RearDoor = LOCK;
	mcu_local_db_items_value.vehStsChkResp.driveDoorAjarSts = AJAR_CLOSE;
	mcu_local_db_items_value.vehStsChkResp.psngrDoorAjarSts = AJAR_CLOSE;
	mcu_local_db_items_value.vehStsChkResp.rlhDoorAjarSts = AJAR_CLOSE;
	mcu_local_db_items_value.vehStsChkResp.rrhDoorAjarSts = AJAR_CLOSE;
	mcu_local_db_items_value.vehStsChkResp.tailgateAjarSts = AJAR_CLOSE;
	mcu_local_db_items_value.vehStsChkResp.sunRoof = AJAR_CLOSE;
	mcu_local_db_items_value.vehStsChkResp.hoodAjarSts = AJAR_CLOSE;
	mcu_local_db_items_value.vehStsChkResp.headLamp = LAMP_OFF;

}

void mcu_db_put(mcu_db_items_type item, mcu_db_items_value_type *value_ptr)
{
    if(item > MCU_DB_ITEM_MAX)
    {
        LOGI("ERR, NO DB ITEM");
        return;			
    }

    switch(item)
    {
        case MCU_DB_VIN:
            memcpy(mcu_local_db_items_value.vin, value_ptr->vin, MAX_STRING_LENGTH);
            break;			

        case MCU_DB_DOOR_UNLOCK_RESP:
        	mcu_local_db_items_value.doorUnlockResp = value_ptr->doorUnlockResp;
        	break;

        case MCU_DB_DOOR_LOCK_RESP:
        	mcu_local_db_items_value.doorLockResp = value_ptr->doorLockResp;
        	break;

        case MCU_DB_ENG_START_RESP:
        	mcu_local_db_items_value.engStartResp = value_ptr->engStartResp;
        	break;

        case MCU_DB_ENG_STOP_RESP:
        	mcu_local_db_items_value.engStopResp = value_ptr->engStopResp;
        	break;

        case MCU_DB_HVAC_STOP_RESP:
        	mcu_local_db_items_value.hvacStopResp = value_ptr->hvacStopResp;
        	break;

        case MCU_DB_VEH_STATUS_CHK_RESP:
        	mcu_local_db_items_value.vehStsChkResp = value_ptr->vehStsChkResp;
        	break;

        default:
             LOGI("Bad item parameter %d ",item);
            break;
    }
}

void mcu_db_get(mcu_db_items_type item, mcu_db_items_value_type *value_ptr)
{

	if(item > MCU_DB_ITEM_MAX)
    {
        LOGI("ERR, NO DB ITEM");
        return;			
    }

    switch(item)
    {
        case MCU_DB_VIN:
            memcpy(value_ptr->vin, mcu_local_db_items_value.vin, MAX_STRING_LENGTH);
            break;

        case MCU_DB_DOOR_UNLOCK_RESP:
        	value_ptr->doorUnlockResp = mcu_local_db_items_value.doorUnlockResp;
        	break;

        case MCU_DB_DOOR_LOCK_RESP:
        	value_ptr->doorLockResp = mcu_local_db_items_value.doorLockResp;
        	break;

        case MCU_DB_ENG_START_RESP:
        	value_ptr->engStartResp = mcu_local_db_items_value.engStartResp;
        	break;

        case MCU_DB_ENG_STOP_RESP:
        	value_ptr->engStopResp = mcu_local_db_items_value.engStopResp;
        	break;

        case MCU_DB_HVAC_STOP_RESP:
        	value_ptr->hvacStopResp = mcu_local_db_items_value.hvacStopResp;
        	break;

        case MCU_DB_VEH_STATUS_CHK_RESP:
        	value_ptr->vehStsChkResp = mcu_local_db_items_value.vehStsChkResp;
        	break;

        default:
             LOGI("Bad item parameter %d ",item);
            break;

    }
}

