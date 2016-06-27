// 04.InheritanceExtended.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Invoice.h"
#include "Store.h"
using namespace std;

int main()
{
	Item bonbon = Item("001", "bonbon", 2.5);
	Item gum = Item("002", "gum", 1.3);
	Item buiskit = Item("003", "buiskit", 5.2);
	Item gum2 = Item(gum);
	gum2.setId("004");
	vector<Item> inventory = vector<Item>{ bonbon, gum, buiskit, gum2 };
	vector<Item> invoiceItems = vector<Item>{};
	Invoice invoice = Invoice(invoiceItems);
	Store candy = Store("CandyShop", 12345678, "Somewhere in the middle of nowhere", inventory);

	cout << "Welcome to CandyShop!\nType:\nP - to make a purchase\nC - to clear all purchases\nT - to get total amount\nG - to get your change\nA - to enter admin mode and change item price" << endl;

	string inputItem;
	float inputGiven;
	float newPrice;
	char choice;
	cin >> choice;

	while (choice != '0')
	{
		switch (choice)
		{
		case 'P':cout << "Add an item to purchase";
			cout << "\nInput item id: ";
			cin >> inputItem;			
			invoice.AddItem(candy.GetItemById(inputItem));
			invoice.toString(candy, 0);
			break;
		case 'C': invoice.Clear(); cout << "Invoice cleared"; break;
		case 'T': cout << "Invoice total: " << invoice.GetTotal(); break;
		case 'G': cout << "Please enter the amount of money: " << endl;
			cin >> inputGiven;
			cout << "The change is " << invoice.GetChange(inputGiven) << " leva" << endl; break;
		case 'A': cout << "Admin mode:Change the price of item: ";
			cin >> inputItem;
			cout << "Enter new price: ";
			cin >> newPrice;
			candy.changePrice(inputItem, newPrice); break;
		default: cout << "Sorry, no such operation"; break;
		}

		cout << "\nChoose another operation or enter 0" << endl;
		cin >> choice;
	}
	return 0;
}

