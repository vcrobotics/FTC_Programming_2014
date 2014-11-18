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

#include "IRTest.c"
//different variables assigned as floats
float pie = 3.14159;
float track = 17.0;
float halfTrack = track / 2.0;
float wheelDiam = 3.88;
float wheelRadius = wheelDiam / 2.0;
float wheelCircumference = wheelDiam * PI;
float ticksPerInches = 2160 / wheelCircumference;
float ticksPerInchesNeveRest=1680/wheelCircumference;
float halfRobotCircumference = track*pie;
float robotCircumference = track*2*pie;
float j = 0;
//float feet = 168;
//float motorSpeed = 50;

float determinePos (int value){
	}

float exponents (float value, int power){
	float i = value;
	for(j=1; j < power; j++){
		i = i*value;
		}
	return i;
}

float calcPercentErrorMoveForward (float feet){
		return (-0.0133125*exponents(feet,4))-(0.1575324074*exponents(feet,3))+(-0.6288680556*exponents(feet,2))-(0.9164814815*feet)+0.00302;
	}

void moveBackward(float feet, float motorSpeed)
{
	nMotorEncoder[backRightMotor] = 0;
	float inches= feet * 12;
	int nTicks=0.83*inches*ticksPerInches;
	while(abs(nMotorEncoder[backRightMotor]) < nTicks)
	{
			motor[frontRightMotor] = motorSpeed;
			motor[frontLeftMotor] = -motorSpeed;
			motor[backRightMotor] = -motorSpeed;
			motor[backLeftMotor] = -motorSpeed;
	}
	motor[frontLeftMotor] = 0;
	motor[frontRightMotor] = 0;
	motor[backRightMotor] = 0;
	motor[backLeftMotor] = 0;
}
void moveFoward(float feet, float motorSpeed)
{
	nMotorEncoder[backLeftMotor] = 0;
	float inches= 0.83 * feet * 12.0;
	inches-=4;
	float nTicks=inches*ticksPerInches;
	//nTicks -= nTicks * calcPercentErrorMoveForward(feet);
	//nTicks-=nTicks*0.295;
	//writeDebugStreamLc dine("ticks: %d", nTicks);
	while(abs(nMotorEncoder[backLeftMotor]) < nTicks)
	{

			motor[frontRightMotor] = -motorSpeed;
			motor[frontLeftMotor] = motorSpeed;
			motor[backRightMotor] = motorSpeed;
			motor[backLeftMotor] = motorSpeed;
			writeDebugStreamLine("ticks: %d", nMotorEncoder[backLeftMotor]);
	}

	motor[frontLeftMotor] = 0;
	motor[frontRightMotor] = 0;
	motor[backRightMotor] = 0;
	motor[backLeftMotor] = 0;

}

	void rightTwoWheelTurn(float degreesMoved, float motorSpeed)
	{
		nMotorEncoder[backLeftMotor] = 0;
		float nTicks = abs((degreesMoved*halfTrack)/(wheelRadius));
		//nticks= nticks* 1.3 * 5/ 9;
		while(abs(nMotorEncoder[backLeftMotor]) < nTicks*7.2)
	{
			motor[frontRightMotor] = motorSpeed;
			motor[frontLeftMotor] = motorSpeed;
			motor[backRightMotor] = -motorSpeed;
			motor[backLeftMotor] = motorSpeed;
	}
}
	void leftTwoWheelTurn(float degreesMoved, float motorSpeed)
	{
		nMotorEncoder[backLeftMotor] = 0;
		float nTicks = abs((degreesMoved*halfTrack)/(wheelRadius));
		//nticks= nticks* 1.3 * 5/ 9;
		while(abs(nMotorEncoder[backLeftMotor]) < nTicks*7.2)
	{
			motor[frontRightMotor] = -motorSpeed;
			motor[frontLeftMotor] = -motorSpeed;
			motor[backRightMotor] = motorSpeed;
			motor[backLeftMotor] = -motorSpeed;
	}
}
	void knockPole (int position){//position 1,2,or 3
			if(position==1){
				int nfeet=32.0/12.0;
				moveFoward(3.5, 75);
				wait1Msec(0.5);
				leftTwoWheelTurn(90.0, 75);
			}else if(position ==2){
				moveFoward(32.0/12.0, 50);
				//moveFoward(0,0);
				wait1Msec(0.5);
				rightTwoWheelTurn(12.0, 50);
				wait1Msec(0.5);
				moveFoward(15.0/12.0, 50);
				wait1Msec(0.5);
			}else if(position ==3 ){
				moveFoward(24.0/12.0, 50);
				wait1Msec(0.5);
			  rightTwoWheelTurn(20.0, 50);
			  wait1Msec(0.5);
				moveFoward(12.0/12.0, 50);
				wait1Msec(0.5);
				leftTwoWheelTurn(15.0, 50);
				wait1Msec(0.5);
				moveFoward(12.0/12.0, 50);
				wait1Msec(0.5);
			}
		}



	task main(){
	  	//int nfeet=55.0/12.0;
			//moveFoward(3.0, 50);
			//leftTwoWheelTurn(90,75)
			knockPole(1);
	 }
