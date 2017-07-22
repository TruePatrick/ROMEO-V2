/*
  # This code has been inspired by an article from Dominique Meurisse : http://arduino103.blogspot.fr/2011/06/detecteur-de-proximite-infrarouge-sharp.html
  #
  # this script is distributed under Creative Commons Attribution-ShareAlike 3.0 License
*/
boolean obstacle = false;

#define trigPin 13
#define echoPin 12
#define led 8
#define led2 7

void Explore(){
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  // read distance index
  distance = (duration/2) / 29.1;


  // if distance outside 5 - 20 cm range
  if(distance>10){
    obstacle = false;
    advance (200,200);
  }
  else {
   if(distance<=1){
      back_off (100,100);
    }
   else{
      
obstacle = true;
      
      // turn depending on servo middle position (here 74)
      if(GetPosition() > GetMiddlePosition()){
        turn_R (200,200); 
        
        // force servo to turn in the direction of the obstacle
        SetServoDirection(0);
      }
      else{
        turn_L (200,200);
     
        // force servo to turn in the direction of the obstacle
        SetServoDirection(1);
      }
    }
  }
}


