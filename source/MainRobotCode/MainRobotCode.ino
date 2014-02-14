//Setting up variable names and their respective pins
int const SPR1 = 2;  //Speed Front Right Wheel 
int const SPR2 = 3;  //Speed Rear Right Wheel 
int const SPL1 = 4;  //Speed Front Left Wheel
int const SPL2 = 5;  //Speed Rear Left Wheel
int const DIRR1 = 23; //Direction FR Wheel
int const DIRR2 = 25; //Direction RR Wheel  
int const DIRL1 = 27; //Direction FL Wheel
int const DIRL2 = 29; //Direction RL Wheel

void setup(){
  
}

void loop(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  
    for(int fadeValue = 0; fadeValue<=255; fadeValue +=5){
  analogWrite(EN1,fadeValue);
  delay(100);
    }

    for(int fadeValue = 255; fadeValue >= 0; fadeValue -=5){
      analogWrite(EN1,fadeValue);
      delay(100);
    }
	
	// This is good!
}
