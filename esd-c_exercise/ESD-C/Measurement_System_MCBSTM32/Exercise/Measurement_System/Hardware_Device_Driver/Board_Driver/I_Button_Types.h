#ifndef __I_Button_Types_H
#define __I_Button_Types_H


#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	UndefinedButtonState = 0,
	ReleasedButtonState  = 1,
	PressingButtonState  = 2,
	PressedButtonState   = 3,
	ReleasingButtonState = 4
} buttonState_t;

	
#ifdef __cplusplus
}
#endif


#endif // __I_Button_Types_H
