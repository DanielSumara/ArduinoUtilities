// DS18B20.h

#ifndef _DS18B20_h
#define _DS18B20_h

#include <OneWire.h>

#include "Arduino.h"
#include "ITemperatureSensor.h"

/// <summary>
/// Temperature accuracy
/// </summary>
enum Accuracy 
{
	Low = 0x1F,
	Normal = 0x3F,
	Good = 0x5F,
	VeryGood = 0x7F
};

/// <summary>
/// Temperature sensor DS18B20
/// </summary>
class DS18B20 : public ITemperatureSensor
{
protected:
	 OneWire *wire;
	 Accuracy accuracy;
	 uint8_t *deviceAddress;

	 uint8_t *scratchPad;
	 uint32_t lastConversationTime;
	 
	 virtual void UpdateTemperature();

	 void ReadScratchPad();
	 void WriteScratchPad();
	 bool IsConversationCompleted();
	 void BeginConversation();
	 void CalculateTemperature();
public:
	 DS18B20(uint8_t *deviceAddress, uint8_t pinNumber = 4, Accuracy accuracy = VeryGood);
	 void SetAccuracy(Accuracy accuracy);
	 virtual ~DS18B20();
};

#endif

