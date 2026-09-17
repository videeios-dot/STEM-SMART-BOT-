
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

const speed = 190; 

 void moveForward(){
moveMotor(frontLeftMotor, FORWARD, speed);
moveMotor(frontRightMotor, FORWARD, speed); 
moveMotor(backLeftMotor, FORWARD, speed);
moveMotor(backRightMotor, FORWARD, speed);
}
void turnLeft(90){
moveMotor(frontLeftMotor, BACKWARD);
moveMotor(frontRightMotor, FORWARD); 
moveMotor(backLeftMotor, BACKWARD);
moveMotor(backRightMotor, FORWARD);
}

void turnRight(90){
moveMotor(frontRightMotor, BACKWARD);
moveMotor(frontLeftMotor, FORWARD); 
moveMotor(backRightMotor, BACKWARD);
moveMotor(backLeftMotor, FORWARD);
}
float readDistance(){
digitalWrite(trig, LOW);
delayMicroseconds(2);

digitalWrite(trig, HIGH);
delayMicroseconds(10);

digitalWrite(trig, LOW);
 
duration = pulseIn(echo, HIGH);
distance= duration*0.0343 / 2
return distance;
}


void stopMotors(){
moveMotor(frontLeftMotor, STOP);
moveMotor(frontRightMotor, STOP); 
moveMotor(backLeftMotor, STOP);
moveMotor(backRightMotor, STOP);
}


void setup() {

pinMode(frontLeftMotor, OUTPUT);
pinMode(frontRightMotor, OUTPUT);
pinMode(backLeftMotor, OUTPUT);
pinmode(backRightMotor, OUTPUT);

pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

pinmode(ledOne, OUTPUT);
pinmode(ledTwo, OUTPUT);

stopMotors();

}

void loop(){
float distance = readDistance; 

if(distance > 10) {
moveForward();
 } else(distance< 10){
stopMotors();
steerLeft(90);
};
}