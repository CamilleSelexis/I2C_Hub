/*
 Blink led on PIN0
 by Mischianti Renzo <http://www.mischianti.org>

 https://www.mischianti.org/2019/01/02/pcf8575-i2c-digital-i-o-expander-fast-easy-usage/
*/
//Mettre les crydom en reverse, entre pinX et VDD, pour activer le crydom quand le pin est bas.
#include "Arduino.h"
#include "PCF8575.h"

// Set i2c address
//PCF8575 pcf8575(0x20);
PCF8575 pcf8575(0x24);

void setup()
{
	//Serial.begin(115200);

	// Set pinMode to OUTPUT
  pinMode(0,INPUT);
  pinMode(17,INPUT);
	pcf8575.pinMode(P0,OUTPUT);
  pcf8575.pinMode(P1,OUTPUT);
  pcf8575.pinMode(P2,OUTPUT);
  pcf8575.pinMode(P3,OUTPUT);
  pcf8575.pinMode(P4,OUTPUT);
  pcf8575.pinMode(P5,OUTPUT);
  pcf8575.pinMode(P6,OUTPUT);
  pcf8575.pinMode(P7,OUTPUT);
  
	pcf8575.begin();
  pcf8575.digitalWrite(P0,HIGH);
  pcf8575.digitalWrite(P1,HIGH);
  pcf8575.digitalWrite(P2,HIGH);
  pcf8575.digitalWrite(P3,HIGH);
  pcf8575.digitalWrite(P4,HIGH);
  pcf8575.digitalWrite(P5,HIGH);
  pcf8575.digitalWrite(P6,HIGH);
  pcf8575.digitalWrite(P7,HIGH);
}

void loop()
{
  //Serial.println("High");
	pcf8575.digitalWrite(P0,HIGH);
  pcf8575.digitalWrite(P1,HIGH);
  pcf8575.digitalWrite(P2,HIGH);
  pcf8575.digitalWrite(P3,HIGH);
  pcf8575.digitalWrite(P4,HIGH);
  pcf8575.digitalWrite(P5,HIGH);
  pcf8575.digitalWrite(P6,HIGH);
  pcf8575.digitalWrite(P7,HIGH);
  delay(100);
  delay(2000);
  //Serial.println("Low");
  pcf8575.digitalWrite(P0,LOW);
  pcf8575.digitalWrite(P1,LOW);
  pcf8575.digitalWrite(P2,LOW);
  pcf8575.digitalWrite(P3,LOW);
  pcf8575.digitalWrite(P4,LOW);
  pcf8575.digitalWrite(P5,LOW);
  pcf8575.digitalWrite(P6,LOW);
  pcf8575.digitalWrite(P7,LOW);
  delay(100);
	delay(2000);
}
