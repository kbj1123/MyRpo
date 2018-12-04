/*===================================================

                  Local MCU DB Header


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



=====================================================*/

#ifndef __TCU_DB_H
#define __TCU_DB_H

#include "cust.h"
#include "common.h"


#define MAX_STRING_LENGTH	30
#define MAX_VER_STRING_LENGTH 60
#define MCC_MNC_SIZE		4

typedef enum {
  MCU_DB_VIN = 0,

  /* CMD RESPONSE START */
  MCU_DB_DOOR_UNLOCK_RESP,
  MCU_DB_DOOR_LOCK_RESP,
  MCU_DB_ENG_START_RESP,
  MCU_DB_ENG_STOP_RESP,
  MCU_DB_HVAC_STOP_RESP,
  MCU_DB_VEH_STATUS_CHK_RESP,
 /* CMD RESPONSE END */
  MCU_DB_ITEM_MAX              = 999 // LAST Item.
} mcu_db_items_type;

typedef enum{
	DOOR_RESP_NO_ACTIVATION = 0,
	DOOR_RESP_ANY_DOOR_OPEN = 1,
	DOOR_RESP_LOCK_SWITCH_FAIL = 2,
	DOOR_RESP_IGNITION_ON = 3,
	DOOR_RESP_ETC = 4,
	DOOR_RESP_SUCCESS = 100,
	DOOR_RESP_CAN_ERROR = 102,
	DOOR_RESP_INTERNAL_ERROR = 103,
	DOOR_RESP_TIME_OUT = 104,
	DOOR_RESP_MAX
}eRemoteCmdDoorResult;

typedef enum{
	ENG_START_RESP_NOT_PORKING = 0,
	ENG_START_RESP_DOOR_NOT_CLOSED = 1,
	ENG_START_RESP_DISARMING = 2,
	ENG_START_RESP_REMOTE_RUNNING_STATE = 3,
	ENG_START_RESP_NORMAL_RUNNING_STATE = 4,
	ENG_START_RESP_NO_RESPONSE = 5,
	ENG_START_RESP_IMMO_FAIL = 6,
	ENG_START_RESP_IGN_RELAY_OFF = 7,
	ENG_START_RESP_ESCL_FAIL = 8,
	ENG_START_RESP_SUCCESS = 100,
	ENG_START_RESP_NOT_REQUESTED = 101,
	ENG_START_RESP_CAN_ERROR = 102,
	ENG_START_RESP_INTERNAL_ERROR = 103,
	ENG_START_RESP_TIME_OUT = 104,
	ENG_START_RESP_RUNNING_OFF = 105,
	ENG_START_RESP_MAX
}eRemoteCmdEngStartResult;

typedef enum{
	ENG_STOP_RESP_ALREADY_OFF = 0,
	ENG_STOP_RESP_NORMAL_RUNNING_STATE = 1,
	ENG_STOP_RESP_OTHER_REASON = 2,
	ENG_STOP_RESP_SUCCESS = 100,
	ENG_STOP_RESP_CAN_ERROR = 102,
	ENG_STOP_RESP_INTERNAL_ERROR = 103,
	ENG_STOP_RESP_TIME_OUT = 104,
	ENG_STOP_RESP_RUNNING_OFF = 105,
	ENG_STOP_RESP_MAX
}eRemoteCmdEngStopResult;

typedef enum{
	RUNNING_OFF_RESP_NOT_PARKING = 0,
	RUNNING_OFF_RESP_DOOR_OPENED_AT_ARMING = 1,
	RUNNING_OFF_RESP_BRAKE_ON_AT_ARMING = 2,
	RUNNING_OFF_RESP_SSB_PUSHED = 3,
	RUNNING_OFF_RESP_10_MINS_OVER = 4,
	RUNNING_OFF_RESP_VEHICLE_MOVED = 5,
	RUNNING_OFF_RESP_IGN1_RELAY_FAIL = 6,
	RUNNING_OFF_RESP_FOB_AUTHENTICATION_FAIL = 7,
	RUNNING_OFF_RESP_ENGINE_OFF = 8,
	RUNNING_OFF_RESP_DAFAULT_VALUE = 254,
	RUNNING_OFF_RESP_NO_ENGINE_OFF = 255,
	RUNNING_OFF_RESP_MAX
}eRemoteCmdRunningOffResult;

typedef enum{
	HVAC_START_RESP_ALREADY_ON = 0,
	HVAC_START_RESP_ALREADY_OFF = 1,
	HVAC_START_RESP_NORMAL_RUNNING_STATE = 2,
	HVAC_START_RESP_ENGINE_STOP = 3,
	HVAC_START_RESP_OTHER_REASON = 14,
	HVAC_START_RESP_SUCCESS = 100,
	HVAC_START_RESP_NOT_REQUESTED = 101,
	HVAC_START_RESP_CAN_ERROR = 102,
	HVAC_START_RESP_CCU_INTERNAL_ERROR = 103,
	HVAC_START_RESP_TIME_OUT = 104,
	HVAC_START_RESP_ENGINE_FAILED = 106,
	HVAC_START_RESP_INVALID_TEMP_VALUE = 255,
	HVAC_START_RESP_MAX
}eRemoteCmdHvacStartResult;

typedef enum{
	HVAC_STOP_RESP_HVAC_ALREADY_ON = 0,
	HVAC_STOP_RESP_HVAC_ALREADY_OFF = 1,
	HVAC_STOP_RESP_NORMAL_RUNNING_STATE = 2,
	HVAC_STOP_RESP_ENGINE_STOP = 3,
	HVAC_STOP_RESP_OTHER_REASON = 14,
	HVAC_STOP_RESP_SUCCESS = 100,
	HVAC_STOP_RESP_CAN_ERROR = 102,
	HVAC_STOP_RESP_CCU_INTERNAL_ERROR = 103,
	HVAC_STOP_RESP_TIME_OUT = 104,
	HVAC_STOP_RESP_MAX
}eRemoteCmdHvacStopResult;

typedef enum{
	DEFROST_START_RESP_DEFROST_OFF = 0,
	DEFROST_START_RESP_DEFROST_ON = 1,
	DEFROST_START_RESP_NOT_REQUESTED = 101,
	DEFROST_START_RESP_CAN_ERROR = 102,
	DEFROST_START_RESP_CCU_INTERNAL_ERROR = 103,
	DEFROST_START_RESP_TIME_OUT = 104,
	DEFROST_START_RESP_ENGINE_FAILED = 106,
}eRemoteCmdDefrostResult;

typedef enum{
	DEFOGGER_START_DEFOGGER_OFF = 0,
	DEFOGGER_START_DEFOGGER_ON = 1,
	DEFOGGER_START_DEFOGGER_INIT = 2,
	DEFOGGER_START_DEFOGGER_INVALID = 3,
	DEFOGGER_START_NOT_REQUESTED = 101,
	DEFOGGER_START_CAN_ERROR = 102,
	DEFOGGER_START_CCU_INTERNAL_ERROR = 103,
	DEFOGGER_START_TIME_OUT = 104,
	DEFOGGER_START_ENGINE_FAILED = 106,
	DEFOGGER_START_MAX
}eRemoteCmdDefoggerStartResult;

typedef enum{
	LGHT_HORN_RESULT_NO_ACTIVATION = 0,
	LGHT_HORN_RESULT_IGNITION_ON = 1,
	LGHT_HORN_RESULT_SUCCESS = 100,
	LGHT_HORN_RESULT_CAN_ERROR = 102,
	LGHT_HORN_RESULT_CCU_INTERNAL_ERROR = 103,
	LGHT_HORN_RESULT_TIME_OUT = 104,
	LGHT_HORN_START_MAX
}eRemoteCmdLghtHornResult;

typedef enum{
	KEY_STAT_STOPPED = 0,
	KEY_STAT_CRANKING = 1,
	KEY_STAT_RUNNING = 2,
	KEY_STAT_STALLING = 3,
	KEY_STAT_NOT_DEFINED_01 = 4,
	KEY_STAT_NOT_DEFINED_02 = 5,
	KEY_STAT_NOT_DEFINED_03 = 6,
	KEY_STAT_SIGNAL_NOT_VALID = 7,
	KEY_STAT_MAX
}eKeyStatus;

typedef enum{
	LOCK = 0,
	UNLOCK = 1,
	LOCKUNCLOCK_MAX
}eLockUnlockStatus;

typedef enum{
	AJAR_CLOSE = 0,
	AJAR_OPEN = 1,
	AJAR_INIT = 2,
	AJAR_INVALID = 3,
	AJAR_STAT_MAX
}eAjarStatus;

typedef enum{
	LAMP_OFF = 0,
	LAMP_ON = 1,
	LAMP_INIT = 2,
	LAMP_INVALID = 3
}eHeadLampSts;

typedef struct{
	eRemoteCmdEngStartResult engineStartResult;
	eRemoteCmdRunningOffResult runningOffResult;
	eRemoteCmdHvacStartResult hvacStartResult;
	eRemoteCmdDefrostResult defrostResult;
	eRemoteCmdDefoggerStartResult backHeatLineResult;
}tRemoteCmdEngineStartRespType;

typedef struct{
	eRemoteCmdEngStopResult engineStopResult;
	eRemoteCmdRunningOffResult runningOffResult;
}tRemoteCmdEngineSopRespType;

typedef struct{
	  eKeyStatus keyStatus;
	  eLockUnlockStatus driverDoor;
	  eLockUnlockStatus psngrDoor;
	  eLockUnlockStatus RearDoor;
	  eAjarStatus sunRoof;
	  eHeadLampSts headLamp;
	  eAjarStatus driveDoorAjarSts;
	  eAjarStatus psngrDoorAjarSts;
	  eAjarStatus rlhDoorAjarSts;
	  eAjarStatus rrhDoorAjarSts;
	  eAjarStatus tailgateAjarSts;
	  eAjarStatus hoodAjarSts;
}tVehicleStatChkRespType;

typedef struct {
  char vin[MAX_STRING_LENGTH];
  eRemoteCmdDoorResult doorUnlockResp;
  eRemoteCmdDoorResult doorLockResp;
  tRemoteCmdEngineStartRespType engStartResp;
  tRemoteCmdEngineSopRespType engStopResp;
  eRemoteCmdHvacStopResult hvacStopResp;
  eRemoteCmdLghtHornResult lghtHornResp;
  tVehicleStatChkRespType vehStsChkResp;
}mcu_db_items_value_type;


int get_string_num(char *string);
void mcu_db_init();
#ifdef FEATURE_SIERRA_MODEM
LE_SHARED void mcu_db_put(mcu_db_items_type item, mcu_db_items_value_type *value_ptr);
LE_SHARED void mcu_db_get(mcu_db_items_type item, mcu_db_items_value_type *value_ptr);
#else
void mcu_db_put(mcu_db_items_type item, mcu_db_items_u *value_ptr);
void mcu_db_get(mcu_db_items_type item, mcu_db_items_u *value_ptr);
#endif

#endif //__TCU_DB_H


