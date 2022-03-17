#include "PCF8575.h"

PCF8575 PCF(0x20);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.println(__FILE__);
Serial.print("PCF8575_test version:");
Serial.println(PCF8575_LIB_VERSION);

PCF.begin();

uint16_t x = PCF.read16();
printHex(x);
delay(1000);
}

void loop()
{
  Serial.println("HLT");
  while (Serial.available() == 0);
  switch(Serial.read())
  {
    case 'H': doHigh(); break;
    case 'L': doLow(); break;
    case 'T': doToggle(); break;
  }
}


void doHigh()
{
  PCF.write16(HIGH);
  int x = PCF.read16();
  Serial.print("Read ");
  printHex(x);
}


void doLow()
{
  PCF.write(4, LOW);
  int x = PCF.read16();
  Serial.print("Read ");
  printHex(x);
}


void doToggle()
{
  PCF.toggle(4);
  int x = PCF.read16();
  Serial.print("Read ");
  printHex(x);
}


void printHex(uint16_t x)
{
  if (x < 0x1000) Serial.print('0');
  if (x < 0x100)  Serial.print('0');
  if (x < 0x10)   Serial.print('0');
  Serial.println(x, HEX);
}


// -- END OF FILE --
