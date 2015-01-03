// PushButton.h

#ifndef _PUSHBUTTON_h
#define _PUSHBUTTON_h

#include "Arduino.h"
#include "IButton.h"

/// <summary>
/// Push Button
/// </summary>
class PushButton : public IButton
{
public:
	// <summary>
	/// Initializes a new instance of the <see cref="PushButton"/> class.
	/// </summary>
	/// <param name="pinNumber">The pin number.</param>
	/// <param name="debounceTimeInMiliseconds">The debounce time in miliseconds.</param>
	PushButton(byte pinNumber = 4, byte debounceTimeInMiliseconds = 20);
	
	/// <summary>
	/// Updates the state.
	/// </summary>
	virtual void UpdateState();

	/// <summary>
	/// Finalizes an instance of the <see cref="PushButton"/> class.
	/// </summary>
	virtual ~PushButton();
};

#endif

