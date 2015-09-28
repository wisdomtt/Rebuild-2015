/*
 * bangbang.cpp
 *
 *  Created on: Jul 31, 2015
 *      Author: dmoses
 */

#include "bangbang.h"

/* The default constructor for the modified bang-bang controller.
 * threshold: the dividing line between the minimum and maximum power output.
 * Ex: if the error is greater than the threshold, output max power, etc.
 * min: minimum power output
 * max: maximum power output
 */
bangbang::bangbang(float threshold, float min, float max) {
	// TODO Auto-generated constructor stub
	this->threshold = threshold;
	this->min = min;
	this->max = max;
}

bangbang::~bangbang() {
	// TODO Auto-generated destructor stub
}

/* When the error is positive and greater than the output threshold, output positive max power
 * however, when the error is less than the threshold, output minimum positive power.
 * The same happens when the error is negative, except the output is now negative.
 * The error is simply the distance from where you are to where you want to be.
 */
float bangbang::update(float input, float setpoint, float target) {
	float error = setpoint - input;
	if (error > 0 && error > this->threshold) {
		return this->max;
	} else if (error > 0 && error <= this->threshold) {
		return this->min;
	} else if (error < 0 && fabs(error) > fabs(this->threshold)) {
		return -this->max;
	} else if (error < 0 && fabs(error) <= fabs(this->threshold)) {
		return -this->min;
	} else {
		return 0;
	}
}
