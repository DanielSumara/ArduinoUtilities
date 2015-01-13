// 
// 
// 

#include "DS18B20.h"

/// <summary>
/// Commands for OneWire protocol
/// </summary>
enum OneWireCommands
{
	/// <summary>
	/// Tells device to take a temperature reading and put it on the scratchpad
	/// </summary>
	StartConversation = 0x44,

	/// <summary>
	/// Copy EEPROM
	/// </summary>
	CopyScratch = 0x48,

	/// <summary>
	/// Read EEPROM
	/// </summary>
	ReadScratch = 0xBE,

	/// <summary>
	/// Write to EEPROM
	/// </summary>
	WriteScratch = 0x4E,

	/// <summary>
	/// Reload from last known
	/// </summary>
	RecallScratch = 0xB8,

	/// <summary>
	/// Determine if device needs parasite power
	/// </summary>
	ReadPowerSupply = 0xB4,

	/// <summary>
	/// Query bus for devices with an alarm condition
	/// </summary>
	AlarmSearch = 0xEC
};

/// <summary>
/// Scratchpad locations
/// </summary>
enum ScratchpadLocation
{
	/// <summary>
	/// The temporary LSB
	/// </summary>
	TempLSB = 0,

	/// <summary>
	/// The temporary MSB
	/// </summary>
	TempMSB,

	/// <summary>
	/// The high alarm temperature
	/// </summary>
	HighAlarmTemperature,

	/// <summary>
	/// The low alarm temperature
	/// </summary>
	LowAlarmTemperature,

	/// <summary>
	/// The configuration
	/// </summary>
	Configuration,

	/// <summary>
	/// The internal byte
	/// </summary>
	InternalByte,

	/// <summary>
	/// The count remain
	/// </summary>
	CountRemain,

	/// <summary>
	/// The count per c
	/// </summary>
	CountPerC,

	/// <summary>
	/// The scratch pad CRC
	/// </summary>
	ScratchPadCRC
};

DS18B20::DS18B20(uint8_t *deviceAddress, uint8_t pinNumber, Accuracy accuracy) : ITemperatureSensor(pinNumber)
{
	this->wire = new OneWire(pinNumber);

	this->deviceAddress = new uint8_t[8];
	for (int i = 0; i < 8; i++)
		this->deviceAddress[i] = deviceAddress[i];

	this->accuracy = accuracy;

	lastConversationTime = 0;
	scratchPad = new uint8_t[9];
	ReadScratchPad();

	if (accuracy != VeryGood)
		WriteScratchPad();
}

DS18B20::~DS18B20()
{
	lastConversationTime = 0;

	wire = NULL;
	for (int i = 0; i < 8; i++)
		deviceAddress[i] = 0;
	delete [] deviceAddress;
	accuracy = VeryGood;
	for (int i = 0; i < 9; i++)
		scratchPad[i] = 0;
	delete[] scratchPad;
}

void DS18B20::ReadScratchPad()
{
	wire->reset();
	wire->select(deviceAddress);
	wire->write(ReadScratch);

	wire->read_bytes(scratchPad, 9);
}

void DS18B20::WriteScratchPad()
{
	wire->reset();
	wire->select(deviceAddress);
	wire->write(WriteScratch);

	wire->write(scratchPad[HighAlarmTemperature]);
	wire->write(scratchPad[LowAlarmTemperature]);
	
	//wire->write(scratchPad[Configuration]);
	wire->write(accuracy);
	
	wire->reset();
	wire->select(deviceAddress);
	wire->write(CopyScratch);
}

void DS18B20::SetAccuracy(Accuracy newAccuracy)
{
	if (accuracy != newAccuracy)
	{
		accuracy = newAccuracy;
		WriteScratchPad();
	}
}

void DS18B20::UpdateTemperature()
{
	if (IsConversationCompleted())
	{
		CalculateTemperature();
		BeginConversation();
	}
}

bool DS18B20::IsConversationCompleted()
{
	uint32_t actualTime = millis();

	// value overflow protection
	if (lastConversationTime != 0 && actualTime < 1000)
		return true;

	uint16_t calculationTime = 0;
	switch (accuracy)
	{
		case Low:
			calculationTime = 94;
			break;
		case Normal:
			calculationTime = 188;
			break;
		case Good:
			calculationTime = 375;
			break;
		case VeryGood:
			calculationTime = 750;
			break;
	}
	return (actualTime - lastConversationTime) > calculationTime;
}

void DS18B20::CalculateTemperature()
{
	ReadScratchPad();

	if (OneWire::crc8(scratchPad, 8) != scratchPad[8])
		currentTemeperature = -127.0;
	else
	{
		int16_t rawData = word(scratchPad[1], scratchPad[0]);
		switch (accuracy)
		{
		case Low:
			rawData >>= 3;
			currentTemeperature = rawData * 0.5;
			break;
		case Normal:
			rawData >>= 2;
			currentTemeperature = rawData * 0.25;
			break;
		case Good:
			rawData >>= 1;
			currentTemeperature = rawData * 0.125;
			break;
		case VeryGood:
			currentTemeperature = rawData * 0.0625;
			break;
		}
	}
	
	Serial.print("Temperatura w: ");
	Serial.print(millis());
	Serial.print(" to: ");
	Serial.println(currentTemeperature, 10);
}

void DS18B20::BeginConversation()
{
	wire->reset();
	wire->select(deviceAddress);
	wire->write(StartConversation);
	lastConversationTime = millis();
}
