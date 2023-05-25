#ifndef __State_H
#define __State_H


#ifdef __cplusplus
extern "C" {
#endif

#include "StateMachineGlobals.h"

// Forward declaration
typedef struct _State State;

// Transition class

// Function pointer for transition action functions
typedef void(*TransitionActionPtr)(Transition* ptrThis, FsmData objData);

// Function pointer for condition functions
typedef BOOL(*TransitionConditionPtr)(Transition* ptrThis, FsmData objData);

// One transition
struct _Transition
{
    //int mEvent;
		uint32_t mEvent;
    TransitionConditionPtr mPtrCondition;
    TransitionActionPtr mPtrAction;
    State* mPtrNextState;
};

// State class

// Function pointer for state action functions
typedef void(*StateActionPtr)(State* ptrThis, FsmData objData);

// Defines a state
struct _State
{
    StateActionPtr mPtrOnEntry;
    StateActionPtr mPtrOnExit;
    //int mTransitions;
		uint32_t mTransitions;
    Transition* mTableTransitions;
};

// Processes an event, returns the subsequent state
State* State_getNextState(State* ptrThis, uint32_t nEvent, FsmData objData);

#ifdef __cplusplus
}
#endif


#endif // __State_H


