#ifndef AutoNoStrafe_H
#define AutoNoStrafe_H

#include "WPILib.h"

class AutoNoStrafe: public Command
{
public:
	AutoNoStrafe();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
