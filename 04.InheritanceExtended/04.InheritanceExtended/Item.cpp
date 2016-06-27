#include "stdafx.h"
#include "Item.h"


Item::Item()
	:Item("", "", 0)
{
}

Item::Item(const Item & i)
{
	_id = i.id();
	_name = i.name();
	_price= i.price();
}

Item::Item(string id, string name, float price)
{
	setId(id);
	setName(name);
	setPrice(price);
}

void Item::setId(string id)
{
	if (id.length() == 0) return;
	_id = id;
}

string Item::id() const
{
	return _id;
}

void Item::setName(string name)
{
	if (name.length() == 0) return;
	_name = name;
}

string Item::name() const
{
	return _name;
}

void Item::setPrice(float price)
{
	if (price < 0) return;
	_price = price;
}

float Item::price() const
{
	return _price;
}

//float Item::operator + (const Item & anItem)
//{
//	return anItem.price();
//}

void Item::toString() const
{
	cout << _name + " " + to_string(_price) + " leva" << endl;
}


Item::~Item()
{
}
