/*
 * bangbang.h
 *
 *  Created on: Jul 31, 2015
 *      Author: dmoses
 */

#ifndef SRC_BANGBANG_H_
#define SRC_BANGBANG_H_

#include "WPILib.h"

/* this is a simple implementation of a modified bang-bang controller
 * which includes a threshold for switching between minimum and maximum outputs.
 * For those new to this, a bang-bang controller only outputs maximum positive or negative power until reaching the target
 * This modified version can be though of as a "two-speed" control loop
 */
class bangbang {
public:
	bangbang(float threshold, float min, float max);
	virtual ~bangbang();
	float update(float input, float setpoint, float target);
	float threshold, max, min;
};

#endif /* SRC_BANGBANG_H_ */
