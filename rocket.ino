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
  // put your main code here, to run repeatedly:
  adjust_servo();
}

//allows the user to choose which servo to adjust
int get_servo(){
  Serial.write("Choose a servo to adjust: ");
  if(Serial.available()){
      char servo_number = Serial.read();
      if((servo_number != "1") || (servo_number != "2") || (servo_number != "3")){
        Serial.write("\r\nYou Chose an invalid servo to adjust\r\n");
        return -1; 
       }
      //returns the servo to adjust from the user
      return atoi(servo_number);
   }
  return 0;
}

void adjust_servo(){
      int servo_id = get_servo();
      if(servo_id == 1){
          Serial.write("Adjusting Servo 1: choose angle(10 - 170 degrees): ");
          int angle = atoi(Serial.read());
          servo_one.write(angle);
      }
      else if (servo_id == 2){          
          Serial.write("Adjusting Servo 2: choose angle(10 - 170 degrees): ");
          int angle = atoi(Serial.read());
          servo_two.write(angle);
      }
      else if (servo_id == 3){
          Serial.write("Adjusting Servo 3: choose angle(10 - 170 degrees): ");
          int angle = atoi(Serial.read());
          servo_three.write(angle);
      }
      else{
          Serial.write("Improper servo id!\r\n");
          return;
      } 
}
