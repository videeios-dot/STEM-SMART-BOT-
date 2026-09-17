
// =========================

// PIN / MOTOR NAMES

// =========================

// Motor channels on the Acebott shield

int frontLeftMotor  = 1;   // M1

int frontRightMotor = 2;   // M2

int backLeftMotor   = 3;   // M3

int backRightMotor  = 4;   // M4

// Ultrasonic sensor

int trig = 13;

int echo = 14;

// Trace sensor

int traceSensor = 35;

// LEDs

int ledOne = 2;

int ledTwo = 12;

const int speed = 190; 
// =========================
// ROUTE MEMORY
// =========================

#define LEFT  1
#define RIGHT 2

int route[20];
int routeLength = 0;
// =========================

// drive forward function
 void moveForward(){
moveMotor(frontLeftMotor, FORWARD, speed);
moveMotor(frontRightMotor, FORWARD, speed); 
moveMotor(backLeftMotor, FORWARD, speed);
moveMotor(backRightMotor, FORWARD, speed);
}
// turn left function
void turnLeft90(int degrees){
moveMotor(frontLeftMotor, BACKWARD);
moveMotor(frontRightMotor, FORWARD); 
moveMotor(backLeftMotor, BACKWARD);
moveMotor(backRightMotor, FORWARD);

delay(500);
stopMotors(); 
}
// turn right function
void turnRight90(int degrees){
moveMotor(frontRightMotor, BACKWARD);
moveMotor(frontLeftMotor, FORWARD); 
moveMotor(backRightMotor, BACKWARD);
moveMotor(backLeftMotor, FORWARD);

delay(500);
stopMotors();
}

//==================
// the car can now move forward, turn a 90degrees left or right 
//===================

//===============================
//the ultrasonic sensor is reading the distance from the obstacle


float readDistance(){
digitalWrite(trig, LOW);
delayMicroseconds(2);

digitalWrite(trig, HIGH);
delayMicroseconds(10);

digitalWrite(trig, LOW);
 
long duration = pulseIn(echo, HIGH);
float distance= duration * 0.0343 / 2 ;
return distance;
}

//================================

// for when the car sees an obstacle in the next 20cm , it stops all motors
void stopMotors(){
moveMotor(frontLeftMotor, STOP);
moveMotor(frontRightMotor, STOP); 
moveMotor(backLeftMotor, STOP);
moveMotor(backRightMotor, STOP);
}

//================================

// this section, is for the second round , the car is supposed to record each turn it takes . We then use this to make it faster in the second round 
void recordLeftTurn() {

  if (routeLength < 20) {
    route[routeLength] = LEFT;
    routeLength++;
  }

  turnLeft90();
}



void recordRightTurn() {
  if (routeLength < 20) {
    route[routeLength] = RIGHT;
    routeLength++;
  }

  turnRight90();
}

// =================================

float scanLeft(){
lookLeft();
delay(500);

float leftDistance = readDistance ;
return leftDistance ; 
}

float scanRight(){
lookRight();
delay(500);

float rightDistance = readDistance ;
return rightDistance ; 
}

void setup() {

pinMode(frontLeftMotor, OUTPUT);
pinMode(frontRightMotor, OUTPUT);
pinMode(backLeftMotor, OUTPUT);
pinMode(backRightMotor, OUTPUT);

pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

pinMode(ledOne, OUTPUT);
 pinMode(ledTwo, OUTPUT);

stopMotors();

}

void loop(){
float distance = readDistance(); 

if(distance > 10) {
moveForward();
 } else{
stopMotors();
turnLeft90();
};
}