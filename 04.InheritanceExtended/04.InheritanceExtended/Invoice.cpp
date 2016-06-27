#include "stdafx.h"
#include "Invoice.h"
#include "Store.h"


Invoice::Invoice(vector<Item> items)
{
	_items = items;
}

void Invoice::AddItem(Item item)
{
	_items.push_back(item);
}

float Invoice::GetTotal() const
{
	float sum = 0;
	for (int i = 0; i < _items.size(); i++)
	{
		sum += _items[i].price();
	}
	return sum;
}

float Invoice::GetChange(float given) const
{
	return given - GetTotal();
}

void Invoice::Clear()
{
	_items.clear();
}

void Invoice::toString(Store store, float given)
{
	cout << store._name << endl;
	cout << "BIC: " + to_string(store._bic) << endl;
	cout << "Address: " + store._address << endl;
	cout << "Purchases: " << endl;
	for (int i = 0; i < this->_items.size(); i++)
	{
		cout << this->_items[i].name() + " " + to_string(_items[i].price()) << endl;
	}
	cout << "\Purchases Total: " + to_string(this->GetTotal()) + " leva" << endl;
	cout << "Given: " + to_string(given) + " leva" << endl;
	cout << "Change: " + to_string(this->GetChange(given)) + " leva" << endl;

}


Invoice::~Invoice()
{
}
