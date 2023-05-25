#include <stdio.h>
#include <math.h>

#include "MeasurementController.h"
#include "VoltageMeasurement.h"
#include "CurrentMeasurement.h"
#include "ResistanceMeasurement.h"

#include "I_UserInput.h"
#include "I_UserIndication.h"

// Forward declaration of the states (static members of the class MeasurementController)
static State mStateWelcome;
static State mStateMeasureVoltage;
static State mStateMeasureCurrent;
static State mStateMeasureResistance;

// Transition functions
// Transition function to sate mStateMeasureVoltage
static void OnTranstionToMeasureVoltage(Transition* const ptrThis, FsmData objData);
// Transition function to sate mStateMeasureCurrent
static void OnTranstionToMeasureCurrent(Transition* const ptrThis, FsmData objData);
// Transition function to sate mStateMeasureResistance
static void OnTranstionToMeasureResistance(Transition* const ptrThis, FsmData objData);

// Entry functions
// Entry function of the state mStateWelcome
static void OnEntryWelcome(State* const ptrThis, FsmData objData);
// Entry function of the state mStateMeasureVoltage
static void OnEntryMeasureVoltage(State* const ptrThis, FsmData objData);
// Entry function of the state mStateMeasureCurrent
static void OnEntryMeasureCurrent(State* const ptrThis, FsmData objData);
// Entry function of the state mStateMeasureResistance
static void OnEntryMeasureResistance(State* const ptrThis, FsmData objData);

// Transition tables
// Transition table of the state mStateWelcome
static Transition TransitionWelcome[] =
{
  { evModeDown, NULL, &OnTranstionToMeasureVoltage, &mStateMeasureVoltage },
  { evModeUp,   NULL, &OnTranstionToMeasureVoltage, &mStateMeasureVoltage }
};
// Transition table of the state mStateMeasureVoltage
static Transition TransitionMeasureVoltage[] =
{
  { evMeasure,  NULL, NULL,                            &mStateMeasureVoltage    },
  { evModeUp,   NULL, &OnTranstionToMeasureCurrent,    &mStateMeasureCurrent    },
  { evModeDown, NULL, &OnTranstionToMeasureResistance, &mStateMeasureResistance }
};
// Transition table of the state mStateMeasureCurrent
static Transition TransitionMeasureCurrent[] =
{
  { evMeasure,   NULL, NULL,                            &mStateMeasureCurrent    },
  { evModeUp,    NULL, &OnTranstionToMeasureResistance, &mStateMeasureResistance },
  { evModeDown,  NULL, &OnTranstionToMeasureVoltage,    &mStateMeasureVoltage    }
};
// Transition table of the state mStateMeasureResistance
static Transition TransitionMeasureResistance[] =
{
  { evMeasure,   NULL, NULL,                         &mStateMeasureResistance },
  { evModeUp,    NULL, &OnTranstionToMeasureVoltage, &mStateMeasureVoltage    },
  { evModeDown,  NULL, &OnTranstionToMeasureCurrent, &mStateMeasureCurrent    }
};

// State definitions
// Definition of the state mStateWelcome
static State mStateWelcome =
{
  &OnEntryWelcome, NULL,
  TRANSITIONS(TransitionWelcome)
};
// Definition of the state mStateMeasureVoltage
static State mStateMeasureVoltage =
{
  &OnEntryMeasureVoltage, NULL,
  TRANSITIONS(TransitionMeasureVoltage)
};
// Definition of the state mStateMeasureCurrent
static State mStateMeasureCurrent =
{
  &OnEntryMeasureCurrent, NULL,
  TRANSITIONS(TransitionMeasureCurrent)
};
// Definition of the state mStateMeasureResistance
static State mStateMeasureResistance =
{
  &OnEntryMeasureResistance, NULL,
  TRANSITIONS(TransitionMeasureResistance)
};
// Initializes the state machine for the measurement controller.
static void MeasurementController_startBehavior(MeasurementController* const ptrMeasurementController);
// Processes an event
static BOOL MeasurementController_processEvent(MeasurementController* const ptrMeasurementController);
// Operates the state machine

static void MeasurementController_testMeasurements(MeasurementController* const ptrMeasurementController);

void MeasurementController_construct(MeasurementController* const ptrMeasurementController)
{
	uint32_t locIndex = 0;
	
	if (ptrMeasurementController != nullptr)
	{
		for(locIndex = 0; locIndex < MEASUREMENT_AMOUNT; locIndex++)
		{
			ptrMeasurementController->mptrMeasurement[locIndex]    = nullptr;
		}
		for(locIndex = 0; locIndex < USERINDICATION_AMOUNT; locIndex++)
		{
			ptrMeasurementController->mptrUserIndication[locIndex] = nullptr;
		}
		for(locIndex = 0; locIndex < USERINPUT_AMOUNT; locIndex++)
		{
			ptrMeasurementController->mptrUserInput[locIndex] = nullptr;
		}
		ptrMeasurementController->mCurrentEvent = evNone;
	}
	else
	{
		//nothing to do
	}
}

void MeasurementController_destruct(MeasurementController* const ptrMeasurementController)
{
	// nothing to do
}

void MeasurementController_setMeasurement(MeasurementController* const ptrMeasurementController, void* ptrMeasurement, uint32_t indexMeasurement)
{
	if (ptrMeasurementController != nullptr)
	{
		if (indexMeasurement < MEASUREMENT_AMOUNT)
		{
			ptrMeasurementController->mptrMeasurement[indexMeasurement] = ptrMeasurement;
		}
		else
		{
			// nothing to do
		}
	}
	else
	{
		// nothing to do
	}
}

void MeasurementController_setUserInput(MeasurementController* const ptrMeasurementController, void* ptrUserInput, uint32_t indexUserInput)
{
	if (ptrMeasurementController != nullptr)
	{
		if (indexUserInput < USERINPUT_AMOUNT)
		{
			ptrMeasurementController->mptrUserInput[indexUserInput] = ptrUserInput;
		}
		else
		{
			// nothing to do
		}
	}
	else
	{
		// nothng to do
	}
}

void MeasurementController_setUserIndication(MeasurementController* const ptrMeasurementController, void* ptrUserIndication, uint32_t indexUserIndication)
{
	if (ptrMeasurementController != nullptr)
	{
		if (indexUserIndication < USERINDICATION_AMOUNT)
		{
			ptrMeasurementController->mptrUserIndication[indexUserIndication] = ptrUserIndication;
		}
		else
		{
			// nothing to do
		}
	}
	else
	{
		// nothing to do
	}
}

void MeasurementController_notifyNewMeasure(MeasurementController* const ptrMeasurementController)
{	
	if (ptrMeasurementController != nullptr)
	{
		ptrMeasurementController->mCurrentEvent = evMeasure;
	}
	else
	{
		// nothing to do
	}
}

static void OnTranstionToMeasureVoltage(Transition* const ptrThis, FsmData objData)
{
	char* locMeasuringMode = Measurement_getMeasuringMode(((MeasurementController*)objData.pData)->mptrMeasurement[0]);
		
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[0]);
	I_UserIndication_clear(((MeasurementController*)objData.pData)->mptrUserIndication[1]);
		
	printf("%s\n", locMeasuringMode);
	
	// to force a new measurement and dislplaying the measured value, even there is no value change
	Measurement_setCalculatedToUndefinedValue(((MeasurementController*)objData.pData)->mptrMeasurement[0]);
}

static void OnTranstionToMeasureCurrent(Transition* const ptrThis, FsmData objData)
{
	char* locMeasuringMode = Measurement_getMeasuringMode(((MeasurementController*)objData.pData)->mptrMeasurement[1]);
	
	I_UserIndication_clear(((MeasurementController*)objData.pData)->mptrUserIndication[0]);
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[1]);
		
	printf("%s\n", locMeasuringMode);
	
	// to force a new measurement and dislplaying the measured value, even there is no value change
	Measurement_setCalculatedToUndefinedValue(((MeasurementController*)objData.pData)->mptrMeasurement[1]);
}

static void OnTranstionToMeasureResistance(Transition* const ptrThis, FsmData objData)
{
	char* locMeasuringMode = Measurement_getMeasuringMode(((MeasurementController*)objData.pData)->mptrMeasurement[2]);
	
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[0]);
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[1]);
		
	printf("%s\n", locMeasuringMode);
	
	// to force a new measurement and dislplaying the measured value, even there is no value change
	Measurement_setCalculatedToUndefinedValue(((MeasurementController*)objData.pData)->mptrMeasurement[2]);
}

static void OnEntryWelcome(State* const ptrThis, FsmData objData)
{
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[0]);
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[1]);
			
	printf("\nMeasurement System Exercise\n");
	printf("Blue USER button short press or terminal input <Shift><A>:\n  Change measurement mode in one   direction ...\n");
	printf("Blue USER button long  press or terminal input <Shift><B>:\n  Change measurement mode in other direction ...\n");
}

static void OnEntryMeasureVoltage(State* const ptrThis, FsmData objData)
{
	float32_t       locActualMeasure   = 0.0;
	const float32_t locPreviousMeasure = Measurement_getCalculatedValue(((MeasurementController*)objData.pData)->mptrMeasurement[0]);
	char*           locMeasuringSymbol = Measurement_getMeasuringSymbol(((MeasurementController*)objData.pData)->mptrMeasurement[0]);
	char*           locMeasuringUnit   = Measurement_getMeasuringUnit  (((MeasurementController*)objData.pData)->mptrMeasurement[0]);
	char            locCharBuffer[5];	
	
	VoltageMeasurement_measure((VoltageMeasurement*)((MeasurementController*)objData.pData)->mptrMeasurement[0]);
	locActualMeasure = Measurement_getCalculatedValue(((MeasurementController*)objData.pData)->mptrMeasurement[0]);
	
	if (fabs(locActualMeasure-locPreviousMeasure) >= Measurement_getAccuracyValue(((MeasurementController*)objData.pData)->mptrMeasurement[0]))
	{
		snprintf (locCharBuffer, 5, "%f", locActualMeasure);
		printf("%s = %s %s\n", locMeasuringSymbol, locCharBuffer, locMeasuringUnit);
	}
	else
	{
		// nothing to do
	}
}

static void OnEntryMeasureCurrent(State* const ptrThis, FsmData objData)
{
	float32_t       locActualMeasure   = 0.0;
	const float32_t locPreviousMeasure = Measurement_getCalculatedValue(((MeasurementController*)objData.pData)->mptrMeasurement[1]);
	char*           locMeasuringSymbol = Measurement_getMeasuringSymbol(((MeasurementController*)objData.pData)->mptrMeasurement[1]);
	char*           locMeasuringUnit   = Measurement_getMeasuringUnit(((MeasurementController*)objData.pData)->mptrMeasurement[1]);
	char            locCharBuffer[6];	
	
	CurrentMeasurement_measure((CurrentMeasurement*)((MeasurementController*)objData.pData)->mptrMeasurement[1]);
	locActualMeasure = Measurement_getCalculatedValue(((MeasurementController*)objData.pData)->mptrMeasurement[1]);
	
	if (fabs(locActualMeasure-locPreviousMeasure) >= Measurement_getAccuracyValue(((MeasurementController*)objData.pData)->mptrMeasurement[1]))
	{
		snprintf (locCharBuffer, 6, "%f", locActualMeasure);
		printf("%s = %s %s\n", locMeasuringSymbol, locCharBuffer, locMeasuringUnit);
	}
	else
	{
		// nothing to do
	}
}

static void OnEntryMeasureResistance(State* const ptrThis, FsmData objData)
{
	float32_t       locActualMeasure   = 0.0;
	const float32_t locPreviousMeasure = Measurement_getCalculatedValue(((MeasurementController*)objData.pData)->mptrMeasurement[2]);
	char*           locMeasuringSymbol = Measurement_getMeasuringSymbol(((MeasurementController*)objData.pData)->mptrMeasurement[2]);
	char*           locMeasuringUnit   = Measurement_getMeasuringUnit(((MeasurementController*)objData.pData)->mptrMeasurement[2]);
	char            locCharBuffer[5];	
	
	ResistanceMeasurement_measure((ResistanceMeasurement*)((MeasurementController*)objData.pData)->mptrMeasurement[2]);
	locActualMeasure = Measurement_getCalculatedValue(((MeasurementController*)objData.pData)->mptrMeasurement[2]);
	
	if (fabs(locActualMeasure-locPreviousMeasure) >= Measurement_getAccuracyValue(((MeasurementController*)objData.pData)->mptrMeasurement[2]))
	{
		snprintf (locCharBuffer, 5, "%f", locActualMeasure);
		printf("%s = %s %s\n", locMeasuringSymbol, locCharBuffer, locMeasuringUnit);
	}
	else
	{
		// nothing to do
	}
}

static void MeasurementController_startBehavior(MeasurementController* const ptrMeasurementController)
{
  FsmData locObjData;
  locObjData.pData = ptrMeasurementController;

  StateMachine_start(&ptrMeasurementController->mStmMeasurementController, &mStateWelcome, locObjData);
}

static BOOL MeasurementController_processEvent(MeasurementController* const ptrMeasurementController)
{
  FsmData locObjData;
  locObjData.pData = ptrMeasurementController;

	return StateMachine_processEvent(&ptrMeasurementController->mStmMeasurementController, (uint32_t)ptrMeasurementController->mCurrentEvent, locObjData);
}

void MeasurementController_execute(MeasurementController* const ptrMeasurementController)
{
	userInputState_t locUserInputState = UndefinedUserInputState;
	
  // for measurement test only
  // MeasurementController_testMeasurements(ptrMeasurementController);
	
	MeasurementController_startBehavior(ptrMeasurementController);
	
	while(TRUE)	
	{
		I_UserInput_getState(ptrMeasurementController->mptrUserInput[0], &locUserInputState);
		switch(locUserInputState)
		{
			case ActiveA_UserInputState:
				ptrMeasurementController->mCurrentEvent = evModeUp;
			break;
			
			case ActiveB_UserInputState:
				ptrMeasurementController->mCurrentEvent = evModeDown;
			break;
			
			default:
					// nothing to do
			break;
		}
		
		if (ptrMeasurementController->mCurrentEvent != evNone)	// service events
		{
			MeasurementController_processEvent(ptrMeasurementController);
			ptrMeasurementController->mCurrentEvent = evNone;
		}
		else
		{
			// nothing to do
		}
	}
}

static void MeasurementController_testMeasurements(MeasurementController* const ptrMeasurementController)
{
	float32_t        locActualMeasure   = 0.0;
	float32_t        locPreviousMeasure = 0.0;
	char*            locMeasuringMode   = nullptr;
	char*            locMeasuringSymbol = nullptr;
	char*            locMeasuringUnit   = nullptr;
	userInputState_t locUserInputState  = UndefinedUserInputState;
	enum MeasureStatus_t {Disabled = 1, Enabled = 0 } locMeasureStatus = Disabled;
	
	printf("Blue USER button short press or terminal input <Shift><A>:\n  Measuerment start ...\n");
	printf("Blue USER button long  press or terminal input <Shift><B>:\n  Measuerment stop  ...\n");
	
	while(TRUE)
	{
		// evaluate push button / simulation
		I_UserInput_getState(ptrMeasurementController->mptrUserInput[0], &locUserInputState);
		switch(locUserInputState)
		{
			case ActiveA_UserInputState:
				printf("Blue USER button short press or terminal input <Shift><A> detected!\n");
				locMeasureStatus = Enabled;
			break;
			
			case ActiveB_UserInputState:
				printf("Blue USER button long press or terminal input <Shift><B> detected!\n");
				locMeasureStatus = Disabled;
			break;
			
			default:
					// nothing to do
			break;
		}
		
		if(locMeasureStatus == Enabled)
		{
			// voltage measurement output to serial
			locActualMeasure   = 0.0;
			locPreviousMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[0]);
			locMeasuringMode   = Measurement_getMeasuringMode(ptrMeasurementController->mptrMeasurement[0]);
			locMeasuringSymbol = Measurement_getMeasuringSymbol(ptrMeasurementController->mptrMeasurement[0]);
			locMeasuringUnit   = Measurement_getMeasuringUnit  (ptrMeasurementController->mptrMeasurement[0]);
			VoltageMeasurement_measure((VoltageMeasurement*)ptrMeasurementController->mptrMeasurement[0]);
			locActualMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[0]);
			
			if (fabs(locActualMeasure-locPreviousMeasure) >= Measurement_getAccuracyValue(ptrMeasurementController->mptrMeasurement[0]))
			{
				printf("%s: %s = %.2f %s\n", locMeasuringMode, locMeasuringSymbol, locActualMeasure, locMeasuringUnit);
			}
			
			// current measurement output to serial
			locPreviousMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[1]);
			locMeasuringMode   = Measurement_getMeasuringMode(ptrMeasurementController->mptrMeasurement[1]);
			locMeasuringSymbol = Measurement_getMeasuringSymbol(ptrMeasurementController->mptrMeasurement[1]);
			locMeasuringUnit   = Measurement_getMeasuringUnit  (ptrMeasurementController->mptrMeasurement[1]);
			CurrentMeasurement_measure((CurrentMeasurement*)ptrMeasurementController->mptrMeasurement[1]);
			locActualMeasure   = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[1]);
			
			if (fabs(locActualMeasure-locPreviousMeasure) >= Measurement_getAccuracyValue(ptrMeasurementController->mptrMeasurement[1]))
			{
				printf("%s: %s = %.3f %s\n", locMeasuringMode, locMeasuringSymbol, locActualMeasure, locMeasuringUnit);
			}
			
			// resistance measurement output to serial
			locActualMeasure   = 0.0;
			locPreviousMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[2]);
			locMeasuringMode   = Measurement_getMeasuringMode(ptrMeasurementController->mptrMeasurement[2]);
			locMeasuringSymbol = Measurement_getMeasuringSymbol(ptrMeasurementController->mptrMeasurement[2]);
			locMeasuringUnit   = Measurement_getMeasuringUnit  (ptrMeasurementController->mptrMeasurement[2]);
			ResistanceMeasurement_measure((ResistanceMeasurement*)ptrMeasurementController->mptrMeasurement[2]);
			locActualMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[2]);
			
			if (fabs(locActualMeasure-locPreviousMeasure) >= Measurement_getAccuracyValue(ptrMeasurementController->mptrMeasurement[2]))
			{
				printf("%s: %s = %.2f %s\n", locMeasuringMode, locMeasuringSymbol, locActualMeasure, locMeasuringUnit);
			}
		}
	}
}

