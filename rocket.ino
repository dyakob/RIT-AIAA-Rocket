#include "Servo.h"

void setup() {
  // put your setup code here, to run once:
  Servo servo_one;
  Servo servo_two;
  Servo servo_three;
  
  servo_one.attach(3);
  servo_two.attach(5);
  servo_three.attach(6);

  //enable uart communication for debgging servo adjustments
  Serial.begin(9600); 
}

void loop() {
  //initialize the servo and angle values to be adjusted by user 
  int srvo = 0;
  int ang = 0;
  
  //constantly gets a srvo value form the user until appropriate value, 1 through 3, is selected  
  while(srvo == 0){
      srvo = get_servo();
  }
  //waits for user to adjust the servo by an appropiate amount, between 10 and 170 degrees
  while(ang == 0){
      ang = get_angle();
  }

  adjust the user selected servo to the user selected angle
  adjust_servo(srvo, ang);
}

/* 
 * Returns: a number typed by the user
*/
 int get_integer(){
  String value = Serial.readString();
  return value.toInt(); 
 }


/*
 * Returns: desired servo id,  if user doesn't type an integer between 1 and 3 a 0 is returned
*/
 int get_servo(){
  Serial.print("Select your Servo:");
  int servo_id = get_integer();
  if((servo_id < 1) || (servo_id > 3)){
    Serial.println("Incorrect servo option, Try again!");
    return 0;   
  }
  Serial.println(servo_id); 
  return servo_id;
 }

/*
 * Returns: desired angle,  if user doesn't type an integer between 10 and 170, a 0 is returned
*/
 int get_angle(){
  Serial.print("Select your angle:");
  int angle = get_integer();
  if((angle < 10) || (angle > 170)){
    Serial.println("Incorrect angle option, Try again!");
    return 0;   
  }
  Serial.println(angle); 
  return angle;
 }

/*
 * PARAMS: servo - integer id of the servo to be turned
 *         angle - angle to turn the servo to 
 * Returns: void
*/
void adjust_servo(int servo, int angle){
      if(servo == 1){
          Serial.println("Adjusting Servo 1!");
          servo_one.write(angle);
      }
      else if (servo_id == 2){          
          Serial.println("Adjusting Servo 2!");
          servo_two.write(angle);
      }
      else if (servo_id == 3){
          Serial.println("Adjusting Servo 3");
          servo_three.write(angle);
      }
      else{
          Serial.write("Improper servo id!\r\n");
      }
      return; 
}
