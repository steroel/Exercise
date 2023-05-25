#ifndef __I_UserIndication_Config_H
#define __I_UserIndication_Config_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

void I_UserIndication_open(void* const ptrUserIndication, const void* const ptrUserIndicationConfig);
void I_UserIndication_close(void* const ptrUserIndication);

#ifdef __cplusplus
}
#endif


#endif // __UserIndication_Config_H
