#ifndef __I_UserOutput_Config_H
#define __I_UserOutput_Config_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
	
void I_UserOutput_open(void* const ptrUserOutput, const void* const ptrUserOutputConfig);
void I_UserOutput_close(void* const ptrUserOutput);

#ifdef __cplusplus
}
#endif


#endif // __I_UserOutput_Config_H
