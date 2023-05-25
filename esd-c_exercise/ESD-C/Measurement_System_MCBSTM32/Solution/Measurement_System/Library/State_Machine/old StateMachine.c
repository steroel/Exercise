#include "StateMachine.h"

// The final state
State StateFsmEnd =
{
    NULL, NULL, 0, NULL
};

// Private declarations of internal functions of the state
void State_callOnEntry(State* ptrThis, FsmData objData);

// Processes an event
BOOL StateMachine_processEvent(StateMachine* ptrThis, int nEvent, FsmData objData)
{
    State* locPtrNextState;

    // browses the transition table of the current state
    locPtrNextState = State_getNextState(ptrThis->mPtrStateCurrent, nEvent, objData);

    if (locPtrNextState != NULL)
    {
        // make the new state the current one
        ptrThis->mPtrStateCurrent = locPtrNextState;

        // if there is an entry action -> process it
        State_callOnEntry(ptrThis->mPtrStateCurrent, objData);

        // If the machine reaches the final state -> return FALSE
        return ptrThis->mPtrStateCurrent != &StateFsmEnd;
    }

    return TRUE;
}

// Initializes the state machine.
void StateMachine_start(StateMachine* ptrThis, State* ptrStartState)
{
    FsmData locObjData;
    locObjData.lData = 0;

    ptrThis->mPtrStateCurrent = ptrStartState;

    // if there is an entry action -> process it
    State_callOnEntry(ptrThis->mPtrStateCurrent, locObjData);
}

