// IButton.h

#ifndef _IBUTTON_h
#define _IBUTTON_h

#include "Arduino.h"

/// <summary>
/// Button state
/// </summary>
enum ButtonState 
{
	/// <summary>
	/// The released
	/// </summary>
	Released,

	/// <summary>
	/// The pushed
	/// </summary>
	Pushed
};

/// <summary>
/// Debounce state 
/// </summary>
enum DebounceState 
{
	/// <summary>
	/// The debounced
	/// </summary>
	Debounced,
	
	/// <summary>
	/// The unstable
	/// </summary>
	Unstable
};

/// <summary>
/// Base class for buttons
/// </summary>
class IButton
{
 protected:
	 /// <summary>
	 /// The pin number
	 /// </summary>
	 byte pinNumber;

	 /// <summary>
	 /// The debounce time
	 /// </summary>
	 byte debounceTime;

	 /// <summary>
	 /// The current state
	 /// </summary>
	 ButtonState currentState;

	 /// <summary>
	 /// The last readed state
	 /// </summary>
	 boolean lastReadedState;

	 /// <summary>
	 /// How long ago the button was pushed
	 /// </summary>
	 unsigned long pushedTime;

	 /// <summary>
	 /// The debounce state
	 /// </summary>
	 DebounceState debounceState;

 public:
	 /// <summary>
	 /// Initializes a new instance of the <see cref="IButton"/> class.
	 /// </summary>
	 /// <param name="pinNumber">The pin number. Default equal "4".</param>
	 /// <param name="debounceTimeInMiliseconds">The debounce time in miliseconds. Default equal "20"</param>
	 IButton(byte pinNumber = 4, byte debounceTimeInMiliseconds = 20);

	 /// <summary>
	 /// Attaches the button to specified pin number.
	 /// </summary>
	 /// <param name="pinNumber">The pin number.</param>
	 void SetPinNumber(byte pinNumber);

	 /// <summary>
	 /// Sets the debounce time.
	 /// </summary>
	 /// <param name="timeInMiliseconds">The time in miliseconds.</param>
	 void SetDebounceTime(byte timeInMiliseconds);

	 /// <summary>
	 /// Updates the state.
	 /// </summary>
	 virtual void UpdateState() = 0;

	 /// <summary>
	 /// Get current state.
	 /// </summary>
	 /// <returns></returns>
	 ButtonState CurrentState();

	 /// <summary>
	 /// Finalizes an instance of the <see cref="IButton"/> class.
	 /// </summary>
	 virtual ~IButton();
};

#endif
