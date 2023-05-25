#ifndef __MeasurementController_Events_H
#define __MeasurementController_Events_H


#ifdef __cplusplus
extern "C" {
#endif

// Event definitions
typedef enum
{
    evNone     = 0,
    evModeDown = 1,
    evModeUp   = 2,
    evMeasure  = 3
} events_t;

#ifdef __cplusplus
}
#endif


#endif // _MesaurementController_Events_H
