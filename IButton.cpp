// 
// 
// 

#include "IButton.h"

/// <summary>
/// Initializes a new instance of the <see cref="IButton" /> class.
/// </summary>
/// <param name="pinNumber">The pin number.</param>
/// <param name="debounceTimeInMiliseconds">The debounce time in miliseconds.</param>
IButton::IButton(byte pinNo, byte debounceTimeInMiliseconds)
{
	pinNumber = pinNo;
	pinMode(pinNo, INPUT);

	debounceTime = debounceTimeInMiliseconds;

	currentState = Released;
	lastReadedState = LOW;
	pushedTime = millis();
	debounceState = Debounced;
}

/// <summary>
/// Finalizes an instance of the <see cref="IButton"/> class.
/// </summary>
IButton::~IButton()
{
	debounceState = Debounced;
	currentState = Released;
	debounceTime = 0;
	lastReadedState = LOW;
	pinNumber = 0;
	pushedTime = 0;
}

/// <summary>
/// Sets the pin number.
/// </summary>
/// <param name="pinNo">The pin no.</param>
void IButton::SetPinNumber(byte pinNo)
{
	pinNumber = pinNo;
}

/// <summary>
/// Sets the debounce time.
/// </summary>
/// <param name="debounceTimeInMiliseconds">The debounce time in miliseconds.</param>
void IButton::SetDebounceTime(byte debounceTimeInMiliseconds)
{
	debounceTime = debounceTimeInMiliseconds;
}

/// <summary>
/// Get the state.
/// </summary>
/// <returns></returns>
ButtonState IButton::CurrentState()
{
	return currentState;
}
