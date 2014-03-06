//Setting up variable names and their respective pins
int  const SPR01 = 2;  //Speed Front Right Wheel
int const SPR02 = 3;  //Speed Rear Right Wheel
int const SPL01 = 4;  //Speed Front Left Wheel
int const SPL02 = 5;  //Speed Rear Left Wheel
int const DIRR01 = 23; //Direction FR Wheel
int const DIRR02 = 25; //Direction RR Wheel  
int const DIRL01 = 27; //Direction FL Wheel
int const DIRL02 = 29; //Direction RL Wheel  

void setup(void){

}

void loop(){
  digitalWrite(DIRR01,HIGH);
  //digitalWrite(in2,LOW);
  
    for(int fadeValue = 0; fadeValue<=255; fadeValue +=5){
  analogWrite(SPR01,fadeValue);
  delay(100);
    }

    for(int fadeValue = 255; fadeValue >= 0; fadeValue -=5){
      analogWrite(SPR0h1,fadeValue);
      delay(100);
    }
	
	// This is good!
}
