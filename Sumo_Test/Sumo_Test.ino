#include <Ultrasonic.h>


Ultrasonic ultrasonic(5,3);

const int IN1=6;
const int IN2=9;
const int IN3=10;
const int IN4=11;
#define IR_sensor_left A0 // front sensor
#define IR_sensor_right A1 // rear sensor
int distance ;

void setup() 
{
Serial.begin(9600);
delay (5000); // as per sumo compat roles
}

void loop()
{
  
 int IR_left = analogRead(IR_sensor_left);
 int IR_right = analogRead(IR_sensor_right);
 distance = ultrasonic.read();
 FORWARD(255);
 delay(3000);
 ROTATE(200);
 delay(1500);
 
 while (distance <= 50 ) {
    Stop();
    FORWARD(255);
    distance= ultrasonic.read();
    while (distance>50){
      break;
      ROTATE(220);
      delay(1500);
      FORWARD(255);
      delay(1000);
      }
    
    distance = ultrasonic.read();
    IR_left = analogRead(IR_sensor_left);
    IR_right = analogRead(IR_sensor_right);
    if ( IR_left >= 70 || IR_right >= 70 ) {
      break;
      }
      delay(10); 

 }
    
  
  
if (IR_left < 70 || IR_right <70 )  // < 60 means white line
   {
   Stop();
   delay (50);
   BACKWARD(255);
   delay(500);
   ROTATE(200);
   delay(1500);
   } 
   


Serial.print(distance);
Serial.println("cm");
//Serial.println("IR front :");
//Serial.println(IR_left); 
//Serial.println("IR back :");
//Serial.println(IR_right);  


} 
void FORWARD(int Speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,Speed);
}
void BACKWARD (int Speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(IN1,0);
  analogWrite(IN2,Speed);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}
void ROTATE (int Speed)
{
  //When we want to let Motor To Rotate ,
  // just void this part on the loop section .
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}
void Stop(){
  //When we want to  Motor To stop ,
  // just void this part on the loop section .
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}
//void initialRotate(int distance){ //change delay time to determine how far it rotates
//  ROTATE(200);
//  delay(250);
//  FORWARD(255);
//  delay(1000);
//  Stop();
//}
//void searchandDestroy (int distance, int IR_left, int IR_right){
//  while (distance < 70 ) {
//    FORWARD(255); 
//    distance = ultrasonic.read();
//    IR_left = analogRead(IR_sensor_front);
//    IR_right = analogRead(IR_sensor_back);
//    if ( IR_left > 60 || IR_right > 60 ) { 
//      break;
//      }
//    delay(10); }
//}
