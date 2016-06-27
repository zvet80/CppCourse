#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;

class Store
{
	string _name;
	long _bic;
	string _address;
	vector<Item> _items;

public:
	Store();
	Store(string, long, string, vector<Item>);
	Item GetItemById(string);
	void changePrice(string,float);
	void toString() const;
	friend class Invoice;
	~Store();
};

