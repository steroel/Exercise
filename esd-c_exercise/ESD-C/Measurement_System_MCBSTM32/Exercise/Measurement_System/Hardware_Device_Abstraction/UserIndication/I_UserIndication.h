#ifndef __I_UserIndication_H
#define __I_UserIndication_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"

void I_UserIndication_set(void* const ptrUserIndication);
void I_UserIndication_clear(void* const ptrUserIndication);
void I_UserIndication_alternate(void* const ptrUserIndication, uint32_t frequency_Hz);

#ifdef __cplusplus
}
#endif


#endif // __I_UserIndication_H
