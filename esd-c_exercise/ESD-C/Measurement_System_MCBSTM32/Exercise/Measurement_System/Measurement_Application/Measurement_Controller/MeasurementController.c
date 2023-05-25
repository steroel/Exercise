#include <stdio.h>
#include <math.h>

#include "MeasurementController.h"
#include "VoltageMeasurement.h"
#include "CurrentMeasurement.h"
#include "ResistanceMeasurement.h"

#include "I_UserInput.h"
#include "I_UserIndication.h"
#include "I_UserOutput.h"

// Forward declaration of the states (static members of the class MeasurementController)
static State mStateWelcome;
static State mStateMeasureVoltage;
//** some missing states

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
// Entry function of the state mSt_MeasureVoltage
static void OnEntryMeasureVoltage(State* const ptrThis, FsmData objData);
// Entry function of the state mSt_MeasureCurrent
static void OnEntryMeasureCurrent(State* const ptrThis, FsmData objData);
// Entry function of the state mSt_MeasureResistance
static void OnEntryMeasureResistance(State* const ptrThis, FsmData objData);

// Transition tables
// Transition table of the state mStateWelcome
static Transition TransitionWelcome[] =
{
  { evModeDown, NULL, &OnTranstionToMeasureVoltage, &mStateMeasureVoltage },
  { evModeUp,   NULL, &OnTranstionToMeasureVoltage, &mStateMeasureVoltage }
};
// Transition table of the state mStateMeasureVoltage
//** add transitions with evModeUp und evModeDown

// Transition table of the state mStateMeasureCurrent
//** add transitions with evModeUp und evModeDown

// Transition table of the state mStateMeasureResistance
//** add transitions with evModeUp und evModeDown

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
  NULL, NULL, NULL //** add state definition
};
// Definition of the state mStateMeasureCurrent
//** add state definition

// Definition of the state mStateMeasureResistance
//** add state definition

// Initializes the state machine for the measurement controller
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
		ptrMeasurementController->mptrUserOutput = nullptr;
		//** add initialization of mCurrentEvent;
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

void MeasurementController_setUserOutput(MeasurementController* const ptrMeasurementController, void* ptrUserOutput)
{
	if (ptrMeasurementController != nullptr)
	{
		ptrMeasurementController->mptrUserOutput = ptrUserOutput;
	}
	else
	{
		// nothing to do
	}
}

//** implementation definition of analog measurement callback function

static void OnTranstionToMeasureVoltage(Transition* const ptrThis, FsmData objData)
{
	char* locMeasuringMode = Measurement_getMeasuringMode(((MeasurementController*)objData.pData)->mptrMeasurement[0]);
		
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[0]);
	I_UserIndication_clear(((MeasurementController*)objData.pData)->mptrUserIndication[1]);
	I_UserIndication_clear(((MeasurementController*)objData.pData)->mptrUserIndication[2]);
		
	I_UserOutput_clear(((MeasurementController*)objData.pData)->mptrUserOutput);
	I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput, 0, 0, locMeasuringMode);
	
	printf("%s\n", locMeasuringMode);
	
	// to force a new measurement and dislplaying the measured value, even there is no value change
	Measurement_setCalculatedToUndefinedValue(((MeasurementController*)objData.pData)->mptrMeasurement[0]);
}

//** OnTransition function definition for state ...
/*
{
	char* locMeasuringMode = Measurement_getMeasuringMode(((MeasurementController*)objData.pData)->mptrMeasurement[1]);
	
	I_UserIndication_clear(((MeasurementController*)objData.pData)->mptrUserIndication[0]);
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[1]);
	I_UserIndication_clear(((MeasurementController*)objData.pData)->mptrUserIndication[2]);
		
	I_UserOutput_clear(((MeasurementController*)objData.pData)->mptrUserOutput);
	I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput, 0, 0, locMeasuringMode);
	
	printf("%s\n", locMeasuringMode);
	
	// to force a new measurement and dislplaying the measured value, even there is no value change
	Measurement_setCalculatedToUndefinedValue(((MeasurementController*)objData.pData)->mptrMeasurement[1]);
}
*/

//** OnTransition function definition for state ...
/*
{
	char* locMeasuringMode = Measurement_getMeasuringMode(((MeasurementController*)objData.pData)->mptrMeasurement[2]);
	
	I_UserIndication_clear(((MeasurementController*)objData.pData)->mptrUserIndication[0]);
	I_UserIndication_clear(((MeasurementController*)objData.pData)->mptrUserIndication[1]);
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[2]);
		
	I_UserOutput_clear(((MeasurementController*)objData.pData)->mptrUserOutput);
	I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput, 0, 0, locMeasuringMode);
	
	printf("%s\n", locMeasuringMode);
	
	// to force a new measurement and dislplaying the measured value, even there is no value change
	Measurement_setCalculatedToUndefinedValue(((MeasurementController*)objData.pData)->mptrMeasurement[2]);
}
*/

static void OnEntryWelcome(State* const ptrThis, FsmData objData)
{
	I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput, 0, 0, " Measure System ");
	I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput, 0, 1, "  MicroConsult  ");
	
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[0]);
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[1]);
	I_UserIndication_set(((MeasurementController*)objData.pData)->mptrUserIndication[2]);
			
	printf("ESD-C Seminar\n");
	printf("MicroConsult GmbH\n");
	printf("Measurement System Exercise\n");
}


//** OnEntry function definition for state ...
/*
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
	
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput,  0, 1, locMeasuringSymbol);
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput,  2, 1, "=");
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput,  4, 1, &locCharBuffer[0]);
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput, 10, 1, locMeasuringUnit);
	
		printf("%s = ", locMeasuringSymbol);
		printf("%s ",   locCharBuffer);
		printf("%s\n",  locMeasuringUnit);
	}
	else
	{
		// nothing to do
	}
}
*/

//** OnEntry function definition for state ...
/*
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
		
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput,  0, 1, locMeasuringSymbol);
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput,  2, 1, "=");
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput,  4, 1, &locCharBuffer[0]);
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput, 10, 1, locMeasuringUnit);
	
		printf("%s = ", locMeasuringSymbol);
		printf("%s ",   locCharBuffer);
		printf("%s\n",  locMeasuringUnit);
	}
	else
	{
		// nothing to do
	}
}
*/

//** OnEntry function definition for state ...
/*
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
	
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput,  0, 1, locMeasuringSymbol);
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput,  2, 1, "=");
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput,  4, 1, &locCharBuffer[0]);
		I_UserOutput_writeStringXY(((MeasurementController*)objData.pData)->mptrUserOutput, 10, 1, locMeasuringUnit);
	
		printf("%s = ", locMeasuringSymbol);
		printf("%s ",   locCharBuffer);
		printf("%s\n",  locMeasuringUnit);
	}
	else
	{
		// nothing to do
	}
}
*/

//** Start behavior function definition for state ...
/*
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
*/

void MeasurementController_execute(MeasurementController* const ptrMeasurementController)
{
	userInputState_t locUserInputState = UndefinedUserInputState;
	
	//** start behavior
	
	//** remove the following code line after state machine implementation
	MeasurementController_testMeasurements(ptrMeasurementController);
		
	while(TRUE)	
	{
		I_UserInput_getState(ptrMeasurementController->mptrUserInput[0], &locUserInputState);
		if (locUserInputState == ActiveUserInputState)
		{
			//** set event
		}
		else
		{
			// nothing to do
		}
		
		I_UserInput_getState(ptrMeasurementController->mptrUserInput[1], &locUserInputState);
		if (locUserInputState == ActiveUserInputState)
		{
			//** set event
		}
		else
		{
			// nothing to do
		}
		
		//** if (... != evNone)	// service events
		{
			//** process events
		}
		//** else
		{
			// nothing to do
		}
	}
}

static void MeasurementController_testMeasurements(MeasurementController* const ptrMeasurementController)
{
	float32_t locActualMeasure   = 0.0;
	float32_t locPreviousMeasure = 0.0;
	char*     locMeasuringSymbol;
	char*     locMeasuringUnit;
	char      locCharBuffer[5];	
	
	I_UserOutput_writeStringXY(ptrMeasurementController->mptrUserOutput, 0, 0, " Measure System ");
	I_UserOutput_writeStringXY(ptrMeasurementController->mptrUserOutput, 0, 1, "  MicroConsult  ");
	printf("ESD-C Seminar\n");
	printf("MicroConsult GmbH\n");
	printf("Measurement System Exercise\n");
	
	while(TRUE)
	{
		// voltage measurement output to serial
		locActualMeasure   = 0.0;
		locPreviousMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[0]);
		locMeasuringSymbol = Measurement_getMeasuringSymbol(ptrMeasurementController->mptrMeasurement[0]);
		locMeasuringUnit   = Measurement_getMeasuringUnit  (ptrMeasurementController->mptrMeasurement[0]);
		VoltageMeasurement_measure((VoltageMeasurement*)ptrMeasurementController->mptrMeasurement[0]);
		locActualMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[0]);
		
		if (fabs(locActualMeasure-locPreviousMeasure) >= Measurement_getAccuracyValue(ptrMeasurementController->mptrMeasurement[0]))
		{
			printf("Voltage\n");
			snprintf (locCharBuffer, 5, "%f", locActualMeasure);
			printf("%s = ", locMeasuringSymbol);
			printf("%s ",   locCharBuffer);
			printf("%s\n",  locMeasuringUnit);
		}
		
		// current measurement output to serial
		locPreviousMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[1]);
		locMeasuringSymbol = Measurement_getMeasuringSymbol(ptrMeasurementController->mptrMeasurement[1]);
		locMeasuringUnit   = Measurement_getMeasuringUnit  (ptrMeasurementController->mptrMeasurement[1]);
		CurrentMeasurement_measure((CurrentMeasurement*)ptrMeasurementController->mptrMeasurement[1]);
		locActualMeasure   = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[1]);
		
		if (fabs(locActualMeasure-locPreviousMeasure) >= Measurement_getAccuracyValue(ptrMeasurementController->mptrMeasurement[1]))
		{
			printf("Current\n");
			snprintf (locCharBuffer, 6, "%f", locActualMeasure);
			printf("%s = ", locMeasuringSymbol);
			printf("%s ",   locCharBuffer);
			printf("%s\n",  locMeasuringUnit);
		}
		
		// resistance measurement output to serial
		locActualMeasure   = 0.0;
		locPreviousMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[2]);
		locMeasuringSymbol = Measurement_getMeasuringSymbol(ptrMeasurementController->mptrMeasurement[2]);
		locMeasuringUnit   = Measurement_getMeasuringUnit  (ptrMeasurementController->mptrMeasurement[2]);
		ResistanceMeasurement_measure((ResistanceMeasurement*)ptrMeasurementController->mptrMeasurement[2]);
		locActualMeasure = Measurement_getCalculatedValue(ptrMeasurementController->mptrMeasurement[2]);
		
		if (fabs(locActualMeasure-locPreviousMeasure) >= Measurement_getAccuracyValue(ptrMeasurementController->mptrMeasurement[2]))
		{
			printf("Resistance\n");
			snprintf (locCharBuffer, 5, "%f", locActualMeasure);
			printf("%s = ", locMeasuringSymbol);
			printf("%s ",   locCharBuffer);
			printf("%s\n",  locMeasuringUnit);
		}
	}
}
