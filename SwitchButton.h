// SwitchButton.h

#ifndef _SWITCHBUTTON_h
#define _SWITCHBUTTON_h

#include "Arduino.h"
#include "IButton.h"

/// <summary>
/// Switch Button
/// </summary>
class SwitchButton : public IButton
{
 public:
	 /// <summary>
	 /// Initializes a new instance of the <see cref="SwitchButton"/> class.
	 /// </summary>
	 /// <param name="pinNumber">The pin number.</param>
	 /// <param name="debounceTimeInMiliseconds">The debounce time in miliseconds.</param>
	 SwitchButton(byte pinNumber = 4, byte debounceTimeInMiliseconds = 20);

	 /// <summary>
	 /// Updates the state.
	 /// </summary>
	 virtual void UpdateState();

	 /// <summary>
	 /// Finalizes an instance of the <see cref="SwitchButton"/> class.
	 /// </summary>
	 virtual ~SwitchButton();
};

#endif

