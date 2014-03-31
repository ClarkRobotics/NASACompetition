#define RELAY_A 7  // Pin for the A relay
#define RELAY_B 8  // Pin for the B relay

void extendActuator();
void retractActuator();
void stopActuator();
void moveActuator(float percent);

float position;
int maxDelay;

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  retractActuator();
  delay(23000);
  position = 0;
  maxDelay = 21083;  //Calculated value to extend 11 inches.
}

void loop() {
  moveActuator(1);
}

void extendActuator() {
  //Set one relay one and the other off, this will move extend the actuator
  digitalWrite(RELAY_A, HIGH);
  digitalWrite(RELAY_B, LOW);
}

void retractActuator() {
  //Set one relay off and the other on, this will move retract the actuator
  digitalWrite(RELAY_A, LOW);
  digitalWrite(RELAY_B, HIGH);
}

void stopActuator() {
  //Set both relays off, this will stop the actuator in a braking
  digitalWrite(RELAY_A, LOW);
  digitalWrite(RELAY_B, LOW);
}

void moveActuator(float percent) {
  if (percent <= 1.0 && percent >= 0) {
    if(percent < position) {
      retractActuator();
      delay(maxDelay*(position-percent));
    } else if (percent > position) {
      extendActuator();
      delay(maxDelay*(percent-position));
    }
    position=percent;
    stopActuator();
  } else {
    Serial.write("percent cannot be above 100% or less than 0%");
  };
}
