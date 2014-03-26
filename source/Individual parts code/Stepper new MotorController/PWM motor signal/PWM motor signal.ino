#define STEP 11
#define DIR 10//optional
#define RST 8//high
#define SLP 9//high

// the setup routine runs once when you press reset:
void setup()  {
  // declare pin 9 to be an output:
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(RST, OUTPUT);
  pinMode(SLP,OUTPUT);
  
  digitalWrite(RST, LOW);
  digitalWrite(STEP, LOW);
  digitalWrite(SLP,LOW);
  digitalWrite(DIR, LOW);
  delay(50);
  digitalWrite(RST,HIGH);
  delay(50);
  digitalWrite(SLP, HIGH);
  delay(50);
  //digitalWrite(RST, HIGH);

  Serial.begin(9600); 
}

long int iter=0;

// the loop routine runs over and over again forever:
void loop()  { 
  digitalWrite(STEP, HIGH);
  delayMicroseconds(500);  //500 - good!
  digitalWrite(STEP, LOW);
  delayMicroseconds(200);  //200=12 sec/rev; 500=18 sec/rev

  ++iter;
  if (iter==20000) {digitalWrite(DIR,HIGH);delay(25);} // 20000 microsteps=360 degrees (1 step=0.018 deg)
  if (iter==40000) {iter=0;digitalWrite(DIR,LOW);delay(25);}

}

