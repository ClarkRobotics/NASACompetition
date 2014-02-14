//Setting up variable names and their respective pins
int const DMR1 = 2;  //Drive Motor Right 1 (front)
int const DMR2 = 3;  //Drive Motor Right 2 (back)
int const DML1 = 4;  //Drive Motor Left 1 (front)
int const DML2 = 5;  //Drive Motor left 2 (back)
int const AM = 6;    //Auger Motor
int const ACT = 7;   //Actuator Motor


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
}
