#include "DriveForward.h"

DriveForward::DriveForward(double set, double leftPower, double rightPower, int id = 0) {
	type = id
	lp = leftPower;
	rp = rightPower
	setpoint = set;
	Requires(drive);
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	drive->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
	drive->tankDrive(lp, rp);
	average = (drive->leftDistance + drive->rightDistance())/2;
	speed = drive->getSpeed();
	if (type == 1) {std::cout << "Distance: " + average << std::endl;}
	if (type == 2) {std::cout << "Velocity: " + speed << std::endl;}
	if (type == 3) {std::cout << "Velocity: " + speed  + "Motor Output: " + lp + "|" + rp << std::endl;}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	return (math.abs(setpoint-average) < 1.5);
}

// Called once after isFinished returns true
void DriveForward::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}
