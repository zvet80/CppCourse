#pragma once
#include "Environment.h"
#include "Character.h"

class JumpControl
{
	Environment _environment;
public:
	JumpControl();
	JumpControl(Environment newEnvironment) :
		_environment(newEnvironment) {};

	float maximumJumpHeight(Character);
	int timeOfJump();
	bool canJumpHeight(Character, float);


	~JumpControl();
};

