#ifndef __I_UserOutput_H
#define __I_UserOutput_H


#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"
	
void I_UserOutput_clear(void* const ptrUserOutput);
void I_UserOutput_writeCharacterXY(void* const ptrUserOutput, uint32_t posX, uint32_t posY, char characterValue);
void I_UserOutput_writeStringXY(void* const ptrUserOutput, uint32_t posX, uint32_t posY, char* stringValue);
void I_UserOutput_writeBargraphXY(void* const ptrUserOutput, uint32_t posX, uint32_t posY, uint32_t valuePercent, uint32_t maxSegmentCount);

#ifdef __cplusplus
}
#endif


#endif // __I_UserOutput_H
