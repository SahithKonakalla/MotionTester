#ifndef DriveForward_H
#define DriveForward_H

#include "../CommandBase.h"
#include "math.h"
#include <iostream>

class DriveForward : public CommandBase {
public:
	DriveForward(double set, double leftPower, double rightPower, int id = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double setpoint, average, speed;
	double lp, rp;
	int type;
};

#endif  // DriveForward_H
