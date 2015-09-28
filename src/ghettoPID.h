/*
 * ghettoPID.h
 *
 *  Created on: Jul 29, 2015
 *      Author: Robotics
 */

#ifndef SRC_GHETTOPID_H_
#define SRC_GHETTOPID_H_
#include "WPILib.h"
#include "iostream"
#include "string"

class ghettoPID {
public:
	ghettoPID(float modifier, float fforward, std::string key, float maxspeed = 1.0);
	virtual ~ghettoPID();
	float Modifier, FForward, MaxSpeed;
	std::string Key;
	float Update(float setpoint, float input);
};

#endif /* SRC_GHETTOPID_H_ */
