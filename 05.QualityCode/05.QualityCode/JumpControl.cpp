#include "stdafx.h"
#include "JumpControl.h"


JumpControl::JumpControl()
{
}

float JumpControl::maximumJumpHeight(Character character)
{
	float ymax;
	ymax = character.jumpSpeed()*character.jumpSpeed() / (2 * this->_environment.gravity());
	return ymax;
}

int JumpControl::timeOfJump()
{
	return 0;
}

bool JumpControl::canJumpHeight(Character character, float height)
{
	return this->maximumJumpHeight(character) > height;
}


JumpControl::~JumpControl()
{
}
