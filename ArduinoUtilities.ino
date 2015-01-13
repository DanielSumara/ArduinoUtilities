#include <OneWire.h>

#include "DS18B20.h"
#include "ITemperatureSensor.h"
#include "Arduino.h"

DS18B20 *sensor;
byte address[] = { 0x28, 0x4A, 0x68, 0x5D, 0x6, 0x0, 0x0, 0x1F };

void setup()
{
	Serial.begin(9600);
	while (!Serial)
		;
	
	sensor = new DS18B20(address, 10);
}

void loop()
{
	sensor->CurrentTemperature();
}
