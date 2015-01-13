// ITemperatureSensor.h

#ifndef _ITEMPERATURESENSOR_h
#define _ITEMPERATURESENSOR_h

#include "Arduino.h"

/// <summary>
/// Base class for temperature sensors
/// </summary>
class ITemperatureSensor
{
 protected:
	 /// <summary>
	 /// The pin number
	 /// </summary>
	 byte pinNumber;

	 /// <summary>
	 /// The current temeperature
	 /// </summary>
	 float currentTemeperature;

	 /// <summary>
	 /// Updates the temperature.
	 /// </summary>
	 virtual void UpdateTemperature() = 0;
 public:

	 /// <summary>
	 /// Initializes a new instance of the <see cref="ITemperatureSensor"/> class.
	 /// </summary>
	 /// <param name="pinNumber">The pin number.</param>
	 ITemperatureSensor(byte pinNumber = 4);
	 
	 /// <summary>
	 /// Currents the temperature.
	 /// </summary>
	 /// <returns></returns>
	 float CurrentTemperature();

	 /// <summary>
	 /// Finalizes an instance of the <see cref="ITemperatureSensor"/> class.
	 /// </summary>
	 virtual ~ITemperatureSensor();
};

#endif

