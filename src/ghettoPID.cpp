/*
 * ghettoPID.cpp
 *
 *  Created on: Jul 29, 2015
 *      Author: Robotics
 */

#include "ghettoPID.h"


ghettoPID::ghettoPID(float modifier, float fforward, std::string key, float maxspeed) {
	// TODO Auto-generated constructor stub
	this->Modifier = modifier;
	this->FForward = fforward;
	this->MaxSpeed = maxspeed;
	this->Key = key;
}

ghettoPID::~ghettoPID() {
	// TODO Auto-generated destructor stub
}

/* generates a sigmoid curve based on the inputs and paramters */
float ghettoPID::Update(float setpoint, float input) {
	float error = setpoint - input;
	float result = 0.0;
	if (error > 0) {
		result =  (((error) / Modifier + fabs(error)) + FForward) * MaxSpeed;
		result = fmin(result, 1);
	} else if(error < 0 ) {
		result =  (((error) / Modifier + fabs(error)) - FForward) * MaxSpeed;
		result = fmax(-1, result);
	} else {
		result = 0.0;
	}
	SmartDashboard::PutNumber(this->Key, result);
	return result;
}

