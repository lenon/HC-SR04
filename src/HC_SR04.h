#ifndef HC_SR04_H_
#define HC_SR04_H_

#include <Arduino.h>

class HC_SR04 {
public:
  HC_SR04(byte trigger_pin, byte echo_pin);
  unsigned long timing();
  double distanceInCm();
  static const double speedOfSound;

private:
  byte trigger_pin;
  byte echo_pin;
};

#endif
