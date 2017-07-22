/*
  # This script has been inspired by DFRobot Sample : http://www.dfrobot.com/wiki/index.php/Cherokey_4WD_Mobile_Platform_(SKU:ROB0102)
  
  # this script is distributed under Creative Commons Attribution-ShareAlike 3.0 License
*/
const int E1 = 5;     //M1 Speed Control
const int E2 = 6;     //M2 Speed Control
const int M1 = 4;     //M1 Direction Control
const int M2 = 7;     //M1 Direction Control

void initMotor(){
  // init motors
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);  
    
  // init pins
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW); 
}
  
void stop(void){                 //stop
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}  

void advance(char a,char b){           //forward
  analogWrite (E1,a);             //PWM speed control
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}  
void back_off (char a,char b) {          //back
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);   
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_L (char a,char b) {           //turn left
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b) {           //turn right
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
