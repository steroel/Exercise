#include "State.h"

// Calls the action function for a transition
void Transition_callAction(Transition* ptrThis, FsmData objData)
{
    if (ptrThis->mPtrAction != NULL)
    {
        (*ptrThis->mPtrAction)(ptrThis, objData);
    }
}

// Calls the entry action for a state
void State_callOnEntry(State* ptrThis, FsmData objData)
{
    if (ptrThis->mPtrOnEntry != NULL)
    {
        (*ptrThis->mPtrOnEntry)(ptrThis, objData);
    }
}

// Calls the exit action for a state
void State_callOnExit(State* ptrThis, FsmData objData)
{
    if (ptrThis->mPtrOnExit != NULL)
    {
        (*ptrThis->mPtrOnExit)(ptrThis, objData);
    }
}

// Processes an event, returns the subsequent state
State* State_getNextState(State* ptrThis, uint32_t nEvent, FsmData objData)
{
    BOOL locCondition;
    State* locPtrNextState = NULL;
    uint32_t i;

    // browses the table
    for (i = 0; i < ptrThis->mTransitions; i++)
    {
        // is it the right entry?
        if (ptrThis->mTableTransitions[i].mEvent == nEvent)
        {
            // look for a condition
            if (ptrThis->mTableTransitions[i].mPtrCondition != NULL)
            {
                locCondition = (*ptrThis->mTableTransitions[i].mPtrCondition)(&ptrThis->mTableTransitions[i], objData);
            }
            else
            {
                // without condition function the result is always TRUE
                locCondition = TRUE;
            }

            if (locCondition != FALSE)
            {
                // if there is an exit action -> process it
                State_callOnExit(ptrThis, objData);

                // read the next state from the table
                locPtrNextState = ptrThis->mTableTransitions[i].mPtrNextState;

                // if there is a transition action -> process it
                Transition_callAction(&ptrThis->mTableTransitions[i], objData);
            }
        }
    }

    return locPtrNextState;
}
