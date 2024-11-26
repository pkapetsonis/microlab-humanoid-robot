
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x40);       // called this way, it uses the default address 0x40   

#define SERVOMIN  125                                             // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  625  

int motors[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

// this is the 'maximum' pulse length count (out of 4096)

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  board1.begin();
  board1.setPWMFreq(60);

  // int angles[] = {0, 0};
  // setAllMotorsAngles(motors, angles);
  // delay(5000);
}

void loop() {

//  setMotorAngle(0, 0);
//  setMotorAngle(1, 0);

//  delay(1000);

//  setMotorAngle(0, 180);
//  setMotorAngle(1, 180);

//  delay(2000);

    // int angles[] = {0, 0};
    // setAllMotorsAngles(motors, angles);

    // delay(5000);

    // int angles1[] = {180, 180};
    // setAllMotorsAngles(motors, angles1);

    // delay(5000);

    setAllMotorsAngle(motors, 0);

    delay(5000);

    setAllMotorsAngle(motors, 90);

    delay(5000);

}

int setMotorAngle(int motor, int ang) {                      //gets angle in degree and returns the pulse width  
    int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);  // map angle of 0 to 180 to Servo min and Servo max 
    board1.setPWM(motor, 0, pulse);
}

void setAllMotorsAngles(int motors[], int angles[]) {                      //gets angle in degree and returns the pulse width  
    for(int i=0; i < 16; i++){ 
      int pulse = map(angles[i],0, 180, SERVOMIN,SERVOMAX);
      board1.setPWM(motors[i], 0, pulse);
    }
}

void setAllMotorsAngle(int motors[], int angle) {                      //gets angle in degree and returns the pulse width  
    for(int i=0; i < 16; i++){ 
      int pulse = map(angle ,0, 180, SERVOMIN,SERVOMAX);
      board1.setPWM(motors[i], 0, pulse);
    }
}