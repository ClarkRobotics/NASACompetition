//  We need to link this file with other 
//*********************************

#include "./pwn.ino"

#define RELAY_A 2  // Pin for the A relay
#define RELAY_B 3  // Pin for the B relay

void extendActuator(int actuator) {
  //Set one relay one and the other off, this will move extend the actuator
  digitalWrite(RELAY_A, HIGH);
  digitalWrite(RELAY_B, LOW);
}

void retractActuator(int actuator) {
  //Set one relay off and the other on, this will move retract the actuator
  digitalWrite(RELAY_A, LOW);
  digitalWrite(RELAY_B, HIGH);
}

void stopActuator(int actuator) {
  //Set both relays off, this will stop the actuator in a braking
  digitalWrite(RELAY_A, LOW);
  digitalWrite(RELAY_B, LOW);
}
