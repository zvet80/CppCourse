#pragma once
#include <string>
using namespace std;

class Environment
{
	unsigned int _identifier;
	string _name;
	float _gravity;
public:
	Environment();
	void setIdentifier(unsigned int);
	unsigned int identifier() const;
	void setName(string);
	string name() const;
	void setGravity(float);
	float gravity() const;
	~Environment();
};

