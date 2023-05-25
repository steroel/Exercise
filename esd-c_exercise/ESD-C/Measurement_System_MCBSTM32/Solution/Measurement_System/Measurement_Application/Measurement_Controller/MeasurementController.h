#ifndef __MeasurementController_H
#define __MeasurementController_H


#ifdef __cplusplus
extern "C" {
#endif

#include "MeasurementController_Events.h"
#include "Typedefs.h"
#include "Measurement.h"
#include "StateMachine.h"

#define MEASUREMENT_AMOUNT 3
#define USERINDICATION_AMOUNT 3
#define USERINPUT_AMOUNT 2

typedef	struct MeasurementController
{
	StateMachine mStmMeasurementController;
	Measurement* mptrMeasurement[MEASUREMENT_AMOUNT];
	void*        mptrUserInput[USERINPUT_AMOUNT];
	void*        mptrUserIndication[USERINDICATION_AMOUNT];
	void*        mptrUserOutput;
	events_t     mCurrentEvent;
} MeasurementController;

void MeasurementController_construct(MeasurementController* const ptrMeasurementController);
void MeasurementController_destruct(MeasurementController* const ptrMeasurementController);

void MeasurementController_setMeasurement(MeasurementController* const ptrMeasurementController, void* ptrMeasurement, uint32_t indexMeasurement);
void MeasurementController_setUserInput(MeasurementController* const ptrMeasurementController, void* ptrUserInput, uint32_t indexUserInput);
void MeasurementController_setUserIndication(MeasurementController* const ptrMeasurementController, void* ptrUserIndication, uint32_t indexUserIndication);
void MeasurementController_setUserOutput(MeasurementController* const ptrMeasurementController, void* ptrUserOutput);

void MeasurementController_notifyNewMeasure(MeasurementController* const ptrMeasurementController);

void MeasurementController_execute(MeasurementController* const ptrMeasurementController);

#ifdef __cplusplus
}
#endif


#endif // _MesaurementController_H
