#include "PushButton.h"

PushButton button;

void setup()
{
	button = PushButton(4, 20);
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