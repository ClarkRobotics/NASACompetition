/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 
 */

#define STEP 11
#define DIR 10//optional
#define RST 8//high
#define SLP 9//high
int brightness=0;
int fadeAmount=5;

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(STEP, OUTPUT);//the 
  pinMode(DIR, OUTPUT);
  pinMode(RST, OUTPUT);
  pinMode(SLP,OUTPUT);
  digitalWrite(DIR,1);
  digitalWrite(RST,1);
  digitalWrite(SLP,1);
  Serial.begin(9600);
  
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
  brightness=250;
  analogWrite(STEP, brightness);    

  // change the brightness for next time through the loop:
  //brightness = brightness + fadeAmount;
  
  
  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect   
  Serial.println(brightness);
  //delay(3000);                            
}

