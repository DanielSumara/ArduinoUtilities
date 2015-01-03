#include "SwitchButton.h"
#include "PushButton.h"

SwitchButton button;

void setup()
{
	button = SwitchButton(4, 50);
	pinMode(8, OUTPUT);
}

void loop()
{
	button.UpdateState();
	if (button.CurrentState() == Pushed)
		digitalWrite(8, HIGH);
	else
		digitalWrite(8, LOW);
}