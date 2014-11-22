#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     irSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     sonarSensor,    sensorSONAR)
#pragma config(Motor,  motorB,          feedingMotorDos, tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeftMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     backLeftMotor, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     frontRightMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     backRightMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorJ,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//int gain=5;
/*move forward funtion*/
int x =0;
int track = 17;
double halfTrack = 8.5;
double radius = 1.94;
float diameter=3.88;
float pi = 3.1415;
float circumference = diameter * pi;
float ticksPerInches = 1440/circumference;
float inchesPerTicks = circumference/1440;
float instructions [25][2];
int nTicks=0;


/*void forward (int speed)
	{
		motor(frontleft)=speed;
		motor(frontright)=speed;
		motor(backleft)=speed;
		motor(backright)=speed;
		wait1Msec(10);
	}
/*move backward function
void backward (int speed)
	{
		motor(frontleft)=-speed;
		motor(frontright)=-speed;
		motor(backleft)=-speed;
		motor(backright)=-speed;
		wait1Msec(10);
	}
/*turn right funtion
void turnRight (int speed)
	{
		motor(frontleft)=speed;
		motor(backleft)=speed;
		wait1Msec(10);
	}
/*turn left funtion
void turnLeft (int speed)
	{
		motor(frontright)=speed;
		motor(backright)=speed;
		wait1Msec(10);
	}
/*right wheels movement
void rightWheels (int speed)
	{
		motor[frontright]=-speed;
		motor[backright]=speed;
		//wait1Msec(10);
	}
/*left wheels movement*/
/*void leftWheels (int speed)
	{
		motor[frontleft]=speed;
		motor[backleft]=speed;
		//wait1Msec(10);
	}
*/
/*TANK DRIVE*/
void tankDrive()
	{
		motor[frontLeftMotor] = ((100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
		motor[backLeftMotor] = ((100.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0)*(joystick.joy1_y2/127.0));
		//right two motors controlled by the left joystick in controller one
		motor[frontRightMotor] = ((-100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
		motor[backRightMotor] = ((100.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0)*(joystick.joy1_y1/127.0));
	}
/*skim funtion*/
float skim(float v)
	{
		float gain =-0.5;
  // gain determines how much to skim off the top
  if (v > 1.0)
    return -((v - 1.0) * gain);
  else if (v < -1.0)
    return -((v + 1.0) * gain);
  else
    return 0;
	}
/*ARCADE DRIVE*/
void setMotorSpeed(float leftSide, float rightSide){
	motor[frontLeftMotor]=leftSide;
	motor[backLeftMotor]=leftSide;
	motor[frontRightMotor]=rightSide;
	motor[backRightMotor]=rightSide;
	}
float getDegrees(int nTicks){
	float degree = radius * nTicks/halfTrack
	return degree;
}
float getFeet(int nTicks){
	float inches;
		inches = nTicks*inchesPerTicks;
		return inches/12;
}
void printVals(){
	for(int i=0; i <25; i++){
			writeDebugStream("Value %d", i);
			writeDebugStream(": Index: %d", instructions[i][0]);
			//writeDebugStream("Distance(Degrees or Feet): %d", intstruction[i][1]);
			writeDebugStreamLine(" ");
	}
}
void storeVals(int i){
	if (joy1Btn(0)){
		nticks = nMotorEncoder[backLeftMotor];
		instructions [i] [0] = 1;
		//nticks = 0;
		//return i;
	}else if (joy1Btn(7)){
		nticks = nMotorEncoder[backLeftMotor];
		instructions [i] [0] = 2;
		//nticks = 0;
		//return i;
	}else if (joy1Btn(1)){
		//nticks = getnticks();
		if(instructions[i][0]==1){
			instructions [i] [1] = getFeet(nTicks);
		}else if(instructions[i][0]==2){
			instructions [i] [1] = getDegrees(nTicks);
			//x++;
		}
		x++;
		nMotorEncoder[backLeftMotor]=0;
		nTicks=0;
		//nticks = 0;
	}


}
void arcadeDrive(float throttle, float turn)
	{
		float leftSpeed, rightSpeed;
		if (throttle >= 0.05){
			leftSpeed= throttle + turn;
			rightSpeed= throttle - turn;
			leftSpeed+= skim(leftSpeed);
			rightSpeed+= skim(rightSpeed);
		}
		else if(throttle < -0.05){
			leftSpeed= throttle - turn;
			rightSpeed= throttle + turn;
			leftSpeed+= skim(leftSpeed);
			rightSpeed+= skim(rightSpeed);
		}

		motor[frontLeftMotor] = ((-100.0)*(leftSpeed/127.0)*(leftSpeed/127.0)*(leftSpeed/127.0));
		motor[backLeftMotor] = ((-100.0)*(leftSpeed/127.0)*(leftSpeed/127.0)*(leftSpeed/127.0));
		//right two motors controlled by the left joystick in controller one
		motor[frontRightMotor] = ((100.0)*(rightSpeed/127.0)*(rightSpeed/127.0)*(rightSpeed/127.0));
		motor[backRightMotor] = ((-100.0)*(rightSpeed/127.0)*(rightSpeed/127.0)*(rightSpeed/127.0));

		//while(true){
		if(x<26){
			storeVals(x);
	 	}

	}

/*void arcadeDrive1(float throttle, float turn)
	{
		float rightSpeed,leftSpeed,total,excess;

		total = throttle + turn;

		d
		if (throttle >= 0.05 and turn > 0) {
			leftSpeed= reduce(throttle + turn);
			rightSpeed= -excess;
		}
		else if (throttle <= -0.05) {
			leftSpeed= reduce(throttle - turn);
			rightSpeed= reduce(throttle + turn);
		}
		motor[frontleft] = ((-100.0)*leftSpeed)/127.0;
		motor[backleft] = ((-100.0)*leftSpeed)/127.0;
		motor[frontright] = ((100.0)*rightSpeed)/127.0;
		motor[backright] = ((-100.0)*rightSpeed)/127.0;
	}*/
task main()
{
	while (true){
	 	//arcadeDrive(joystick.joy1_y1, joystick.joy1_x2);
	 	/*if(x>25 && x!=27){
	 		printVals();
	 		x++;
	 	}*/
		arcadeDrive(joystick.joy1_y2,joystick.joy1_y1);
	}
}
