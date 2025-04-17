#include <SharpIR.h>
#include <CytronMotorDriver.h>


// Configure the motor driver.
CytronMD motor1(PWM_DIR, 9, 8);  // PWN is pin 9, DIR is pin 8
CytronMD motor2(PWM_DIR, 11, 13); // PWN is pin 11, DIR is pin 13

// Define sensor models and pins
SharpIR rightsensor(SharpIR::GP2Y0A41SK0F, A1);
SharpIR middlesensor(SharpIR::GP2Y0A41SK0F, A2);
SharpIR leftsensor(SharpIR::GP2Y0A41SK0F, A3);

//Line IR Decelartion
int Left_IRSensor = 7; // connect IR sensor module to Arduino pin D6
int Right_IRSensor = 6; // connect IR sensor module to Arduino pin D7

//Switch Decelartion
int startSwitch = 4;

//Motor functions

void moveforward(int chosen_forward) {
  motor1.setSpeed(chosen_forward);
  motor2.setSpeed(chosen_forward);
}

void moveback(int chosen_back) {
  motor1.setSpeed(chosen_back);
  motor2.setSpeed(chosen_back);
}

void turnright(int right, int left) {
  motor1.setSpeed(right);
  motor2.setSpeed(left);
}

void turnleft(int left, int right) { //
  motor1.setSpeed(left);
  motor2.setSpeed(right);
}

void nomove() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
}

void LineIR() {
  //IR Conditions
  if (digitalRead(Left_IRSensor) == 1 || digitalRead(Right_IRSensor) == 1) {
    // If the left side hits the line
    moveback(-115);
    delay(340); //how far back
    turnright(115, -115);
    delay(170 + random(20)); //how much it turns
  } else {
    moveforward(85);
  }
}


//LineIR Testing
void IRtest() {
  int state = 0;
  if (digitalRead(Left_IRSensor) == 0 && digitalRead(Right_IRSensor) == 1) {
    // If the left side hits the line
    state = 1;

  }
  else if (digitalRead(Right_IRSensor) == 0 && digitalRead(Left_IRSensor) == 1 ){
    // if the right side hits the line;
    state = 2;
  }
  else if (digitalRead(Right_IRSensor) == 1 && digitalRead(Left_IRSensor) == 1) {
    // if it just hits the line
    state = 3;
  }
  else {
    // does not see no line
    state = 0;
  }
  Serial.println(state);
  delay(500);
}

void Sharpir() {
  int rightdistance = rightsensor.getDistance();
  int middledistance = middlesensor.getDistance();
  int leftdistance = leftsensor.getDistance();

  if (middledistance < 24) {
    Serial.print("Middle: ");
    Serial.println(middledistance);
    moveforward(100);
  } else if (rightdistance < 24) {
    Serial.print("Right: ");
    Serial.println(rightdistance);
    turnright(100, -100);
  } else if (leftdistance < 24) {
    Serial.print("Left: ");
    Serial.println(leftdistance);
    turnleft(-100, 100);
  }
}

void setup() {
  Serial.begin(9600); // Enable serial communication
  pinMode(Left_IRSensor, INPUT);
  pinMode(Right_IRSensor, INPUT);
  delay(3000);
  //  nomove();
  //  delay(3000);
//    moveforward(100);
}

void loop() {
  LineIR();


//  IRtest();


}
