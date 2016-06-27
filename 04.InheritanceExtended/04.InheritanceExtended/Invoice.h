#pragma once
#include <vector>
#include <iostream>
#include "Item.h"
#include "Store.h"

class Invoice
{
	vector<Item> _items;
public:
	Invoice(vector<Item>);
	void AddItem(Item);

	float GetTotal() const;
	float GetChange(float) const;
	void Clear();
	void toString(Store, float);

	~Invoice();
};

