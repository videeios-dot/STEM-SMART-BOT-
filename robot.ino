
int frontLeftMotor = .... ;
int frontRightMotor = .... ;
int backLeftMotor = .... ;
int backRightMotor = .... ; 
int trig = .... ; 
int traceSensor = .... ; 
int ledOne = .... ;
int ledTwo = .... ; 
int echo =....; 



 void moveForward(){
moveMotor(frontLeftMotor, FORWARD);
moveMotor(frontRightMotor, FORWARD); 
moveMotor(backLeftMotor, FORWARD);
moveMotor(backRightMotor, FORWARD);
}
void steerLeft(90){
}
void stopMotos(){
}


void setup() {

pinMode(frontLeftMotor, OUTPUT);
pinMode(frontRightMotor, OUTPUT);
pinMode(backLeftMotor, OUTPUT);
pinmode(backRightMotor, OUTPUT);
pinMode(trig, OUTPUT);
//int traceSensor = .... ; 
pinmode(ledOne, OUTPUT);
pinmode(ledTwo, OUTPUT);

}

void loop(){

digitalWrite(trig, HIGH);
//distance = read length 

if(distance > 10) {
moveForward();
 } else if (distance< 10){
stopMotors();
steerLeft(90);
}else {
};
}