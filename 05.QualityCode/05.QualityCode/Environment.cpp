#include "stdafx.h"
#include "Environment.h"


Environment::Environment()
{
}

void Environment::setIdentifier(unsigned int)
{
}

unsigned int Environment::identifier() const
{
	return 0;
}

void Environment::setName(string)
{
}

string Environment::name() const
{
	return string();
}

void Environment::setGravity(float)
{
}

float Environment::gravity() const
{
	return 0.0f;
}


Environment::~Environment()
{
}
