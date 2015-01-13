// 
// 
// 

#include "ITemperatureSensor.h"

/// <summary>
/// Initializes a new instance of the <see cref="ITemperatureSensor"/> class.
/// </summary>
/// <param name="pinNo">The pin no.</param>
ITemperatureSensor::ITemperatureSensor(byte pinNo)
{
	pinNumber = pinNo;
	currentTemeperature = 0;
}

/// <summary>
/// Finalizes an instance of the <see cref="ITemperatureSensor"/> class.
/// </summary>
ITemperatureSensor::~ITemperatureSensor()
{
	pinNumber = 0;
	currentTemeperature = 0;
}

/// <summary>
/// Currents the temperature.
/// </summary>
/// <returns></returns>
float ITemperatureSensor::CurrentTemperature()
{
	UpdateTemperature();
	return currentTemeperature;
}
