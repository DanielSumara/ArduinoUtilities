// 
// 
// 

#include "PushButton.h"

/// <summary>
/// Initializes a new instance of the <see cref="PushButton"/> class.
/// </summary>
/// <param name="pinNumber">The pin number.</param>
/// <param name="debounceTimeInMiliseconds">The debounce time in miliseconds.</param>
PushButton::PushButton(byte pinNumber, byte debounceTimeInMiliseconds) : IButton(pinNumber, debounceTimeInMiliseconds)
{
}

/// <summary>
/// Finalizes an instance of the <see cref="PushButton"/> class.
/// </summary>
PushButton::~PushButton()
{
}

/// <summary>
/// Updates the state.
/// </summary>
void PushButton::UpdateState()
{
	boolean readedState = digitalRead(pinNumber);
	if (readedState != lastReadedState)
	{
		pushedTime = millis();
		lastReadedState = readedState;
		debounceState = Unstable;
	}
	else if (debounceState == Unstable && millis() - pushedTime >= debounceTime)
	{
		currentState = readedState == HIGH ? Pushed : Released;
		debounceState = Debounced;
	}
}
