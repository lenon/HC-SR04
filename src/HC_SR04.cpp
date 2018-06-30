#include "HC_SR04.h"

const double HC_SR04::speedOfSound = 0.0343;

HC_SR04::HC_SR04(byte trigger_pin, byte echo_pin)
{
  this->trigger_pin = trigger_pin;
  this->echo_pin = echo_pin;

  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

unsigned long HC_SR04::timing()
{
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigger_pin, LOW);
  return pulseIn(echo_pin, HIGH);
}

double HC_SR04::distanceInCm()
{
  return timing() / 2 * speedOfSound;
}
