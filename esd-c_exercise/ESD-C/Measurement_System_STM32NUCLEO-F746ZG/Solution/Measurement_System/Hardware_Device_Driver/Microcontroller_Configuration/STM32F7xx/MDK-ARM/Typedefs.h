// Typedefs based on
// Tool chain:  MDK-ARM
// Target:      ST STM32F7xx

#ifndef __Typedefs_H
#define __Typedefs_H

#ifdef __cplusplus
extern "C" {
#endif

typedef char sint8_t;
typedef unsigned char uint8_t;
typedef volatile char vsint8_t;
typedef volatile unsigned char vuint8_t;

typedef short sint16_t;
typedef unsigned short uint16_t;
typedef volatile short vsint16_t;
typedef volatile unsigned short vuint16_t;

typedef int sint32_t;
typedef unsigned int uint32_t;
typedef volatile int vsint32_t;
typedef volatile unsigned int vuint32_t;

typedef long sint64_t;
//typedef unsigned long uint64_t;
typedef volatile long vsint64_t;
typedef volatile unsigned long vuint64_t;

typedef float float32_t;
typedef double float64_t;

/*===================================================================*/
//typedef enum { FALSE = 0, TRUE  = !FALSE } bool;
//typedef enum { SUCCESS = 0, ERROR  = !SUCCESS } ERRORCODE;
/*===================================================================*/

//typedef enum
//{
//	SUCCESS = 0,
//	ERROR		= 1
//} status_t;


//#define NULL ((void*)0x0)
#define nullptr ((void*)0x0)
	
#ifdef __cplusplus
}
#endif

#endif // __Typedefs_H






