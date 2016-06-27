#pragma once
#include <string>
#include <iostream>

using namespace std;
class Item
{
	string _id;
	string _name;
	float _price;
public:
	Item();
	Item(const Item&i);
	Item(string, string, float);

	void setId(string);
	string id() const;
	void setName(string);
	string name() const;
	void setPrice(float);
	float price() const;
	//float operator + (const Item &anItem);
	void toString() const;
	~Item();
};

