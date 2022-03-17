/*
 Blink led on PIN0
 by Mischianti Renzo <http://www.mischianti.org>

 https://www.mischianti.org/2019/01/02/pcf8575-i2c-digital-i-o-expander-fast-easy-usage/
*/
//Mettre les crydom en reverse, entre pinX et VDD, pour activer le crydom quand le pin est bas.
#include "Arduino.h"
#include "PCF8575.h"

// Set i2c address
PCF8575 pcf8575(0x20);
//PCF8575 pcf8575(0x24);

void setup()
{
	Serial.begin(115200);

	// Set pinMode to OUTPUT
  pinMode(0,INPUT);
  pinMode(17,INPUT);
	pcf8575.pinMode(P0, OUTPUT);
  pcf8575.pinMode(P1,OUTPUT);
  pcf8575.pinMode(P15,OUTPUT);

	pcf8575.begin();
  pcf8575.digitalWrite(P0,HIGH);
  pcf8575.digitalWrite(P1,HIGH);
  pcf8575.digitalWrite(P15,HIGH);
}

void loop()
{
  Serial.println("High");
	pcf8575.digitalWrite(P0, HIGH);
  pcf8575.digitalWrite(P15,HIGH);
  delay(100);
  Serial.println(digitalRead(0));
  Serial.println(digitalRead(17));
	delay(2000);
  Serial.println("Low");
	pcf8575.digitalWrite(P0, LOW);
  pcf8575.digitalWrite(P15,LOW);
  Serial.println(digitalRead(0));
  Serial.println(digitalRead(17));
	delay(2000);
}
