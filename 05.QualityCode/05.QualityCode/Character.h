#pragma once
#include <string>
using namespace std;

class Character
{
	unsigned int _identifier;
	string _name;
	float _mass;
	float _jumpSpeed;
public:
	Character();
	Character(unsigned int, string,float, float);
	void setIdentifier(unsigned int);
	unsigned int identifier() const;
	void setName(string);
	string name() const;
	void setMass(float);
	float mass() const;
	void setJumpSpeed(float);
	float jumpSpeed() const;

	~Character();
};

