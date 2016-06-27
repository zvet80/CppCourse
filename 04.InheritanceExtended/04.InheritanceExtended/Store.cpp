#include "stdafx.h"
#include "Store.h"


Store::Store()
	:Store("", 0, "", vector<Item>{})
{
}

Store::Store(string name, long bic, string address, vector<Item> items)
{
	_name = name;
	_bic = bic;
	_address = address;
	_items = items;
}

Item Store::GetItemById(string id)
{
	for (int i = 0; i < _items.size(); i++) {
		if (_items[i].id() == id)
		{
			return _items[i];
		}
	}
	//return Item();
}

void Store::changePrice(string itemId,float newPrice)
{
	for (int i = 0; i < _items.size(); i++) {
		if (_items[i].id() == itemId)
		{
			_items[i].setPrice(newPrice);
			cout << "Price changed!";
		}
	}
}

void Store::toString() const
{
	cout << "\n" + _name + "\nBIC: " + to_string(_bic) + "\nAddress: " + _address;
}


Store::~Store()
{
}
