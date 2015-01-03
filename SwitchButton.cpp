// 
// 
// 

#include "SwitchButton.h"

/// <summary>
/// Initializes a new instance of the <see cref="SwitchButton"/> class.
/// </summary>
/// <param name="pinNumber">The pin number.</param>
/// <param name="debounceTimeInMiliseconds">The debounce time in miliseconds.</param>
SwitchButton::SwitchButton(byte pinNumber, byte debounceTimeInMiliseconds) : IButton(pinNumber, debounceTimeInMiliseconds)
{
}

/// <summary>
/// Finalizes an instance of the <see cref="SwitchButton"/> class.
/// </summary>
SwitchButton::~SwitchButton()
{
}

/// <summary>
/// Updates the state.
/// </summary>
void SwitchButton::UpdateState()
{
	boolean readedState = digitalRead(pinNumber);
	if (readedState != lastReadedState)
	{
		pushedTime = millis();
		lastReadedState = readedState;
		debounceState = debounceState == Changed ? Debounced : Unstable;
	}
	else if (debounceState == Unstable && millis() - pushedTime >= debounceTime)
	{
		currentState = currentState == Pushed ? Released : Pushed;
		debounceState = Changed;
	}
}
