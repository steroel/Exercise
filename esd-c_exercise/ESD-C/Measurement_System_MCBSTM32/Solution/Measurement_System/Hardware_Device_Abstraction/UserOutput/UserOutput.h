#ifndef __UserOutput_H
#define __UserOutput_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Typedefs.h"	
	
typedef struct UserOutput
{
	void*    mptrUserOutputDevice;
	uint32_t mMaxX;
	uint32_t mMaxY;
} UserOutput;

#ifdef __cplusplus
}
#endif


#endif // __UserOutput_H
