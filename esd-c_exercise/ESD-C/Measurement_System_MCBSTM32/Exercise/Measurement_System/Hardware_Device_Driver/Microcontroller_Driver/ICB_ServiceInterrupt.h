#ifndef __ICB_InterruptService_H
#define __ICB_InterruptService_H


#ifdef __cplusplus
extern "C" {
#endif

typedef void(*ICB_InterruptService_serviceInterrupt_fptr)(void* const ptrCallbackObject, void* par);

#ifdef __cplusplus
}
#endif


#endif // __ICB_InterruptService_H
