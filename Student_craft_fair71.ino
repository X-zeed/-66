#include <Servo.h>. 

const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;
Servo myServo;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(12);
}
void loop() {

  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
//  
//  Serial.print(i);
//  Serial.print(",");
//  Serial.print(distance);
//  Serial.print(".");
  }
  for(int i=180;i>=0;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
//  Serial.print(i);
//  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  if(distance<20){
    if(i>=0&&i<=60){
      Serial.println("Right");
    }
    else if(i>=61&&i<=120){
      Serial.println("Mid");
    }
    else if(i>=121&&i<=180){
      Serial.println("Left");
    }
  }
  }
}
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance;
}
