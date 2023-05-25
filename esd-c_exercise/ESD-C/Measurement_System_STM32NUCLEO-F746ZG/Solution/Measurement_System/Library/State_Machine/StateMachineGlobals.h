#ifndef __StateMachineGlobals_H
#define __StateMachineGlobals_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// Forward declaration
typedef struct _Transition Transition;

enum Constants
{
    TRUE = 1,
    FALSE = 0,
    NoEvent = -1
};

#ifndef NULL
#define NULL    (void*)0
#endif

//#ifndef uint32_t
//typedef unsigned int uint32_t;
//#endif

typedef int BOOL;

// Universal data container
typedef union
{
    // Member used for numbers
    //long lData;
		uint32_t Data;
    // Member used for pointers
    void* pData;
} FsmData;

// helper macro
#define TRANSITIONS(tra)  sizeof(tra)/ sizeof(Transition), tra

#ifdef __cplusplus
}
#endif


#endif // __StateMachineGlobales_H
