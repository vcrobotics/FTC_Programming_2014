#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S2,     IR1,            sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          upLeft,        tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,          upRight,       tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,          downLeft,      tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     downRight,     tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     flagMotor1,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     flagMotor,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){
		if (SensorValue(IR1) >= 7)
	{
		motor[flagMotor1] = 75;

		wait1Msec(2000);
}


		 else{

		motor[flagMotor1] = 0;
}

		}
