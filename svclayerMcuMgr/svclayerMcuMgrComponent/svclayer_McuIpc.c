/*===================================================

                  SERVICE LAYER MCU IPC File


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

#include "legato.h"
#include "interfaces.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

le_result_t svcLayerMcu_SetMcuCommand1
(
    int32_t value1
)
{
	LE_INFO("svcLayerMcu_SetMcuCommand1 command : %d",value1);

	if(value1 == 1)
	{
		LE_INFO(" value 1 command");
		//send_test_data_one();
	}

	if(value1 == 2)
	{
		LE_INFO(" value 2 command");
		//send_test_data_two();
	}

	return LE_OK;
}
le_result_t svcLayerMcu_SetMcuCommand2
(
	const char* LE_NONNULL message
)
{
	LE_INFO("svcLayerMcu_SetNcuCommand2 command : %s",message);

	return LE_OK;
}

/// For Call related IPC
le_result_t svcLayerMcu_SetMcuCommand3
(
	int32_t value1,
	const char* LE_NONNULL message
)
{
	LE_INFO("svcLayerMcu_SetNcuCommand3 command(0x%x) string: %s",value1, message);
	//process_svclayerIfMsg(value1, message);

	return LE_OK;
}
le_result_t svcLayerMcu_GetMcuCommand1
(
    char* message, size_t messageSize
)
{

#if 1
	char temp[100];
	int i = 2;
	memset(temp,0,100);
	sprintf(temp,"MCU test num %d",i);
	LE_INFO("Tx String is %s",temp);


	memcpy(message, temp, 100);
#endif
	LE_INFO("svcLayerMcu_GetNcuCommand1");
	return LE_OK;
}



