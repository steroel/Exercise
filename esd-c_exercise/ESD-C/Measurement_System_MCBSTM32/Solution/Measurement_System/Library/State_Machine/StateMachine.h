#ifndef __StateMachine_H
#define __StateMachine_H


#ifdef __cplusplus
extern "C" {
#endif

#include "State.h"

// The final state
extern State StateFsmEnd;

// Foraward declaration
typedef struct _StateMachine StateMachine;

// state machine class

// defines the state machine
struct _StateMachine
{
    State* mPtrStateCurrent;
};

// Processes an event
BOOL StateMachine_processEvent(StateMachine* ptrThis, uint32_t nEvent, FsmData objData);

// Initializes the state machine.
void StateMachine_start(StateMachine* ptrThis, State* ptrStartState, FsmData objData);

#ifdef __cplusplus
}
#endif


#endif // __StateMachine_H
