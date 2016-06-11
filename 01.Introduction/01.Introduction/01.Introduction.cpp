// 01.Introduction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

void GetLowerUpper(string a)
{
	int lower = 0;
	int upper = 0;
	int total = a.length();
	for (int i = 0; i < total; i++)
	{
		if (int(a[i]) >= 65 && int(a[i]) <= 90)
		{
			upper++;
		}
		else if (int(a[i]) >= 97 && int(a[i]) <= 122)
		{
			lower++;
		}
	}
	cout << "lower: " << lower << endl << "upper: " << upper << endl << "other:" << total - upper - lower << endl;
	;
}

int CountLetter(string text, char letter)
{
	int count = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == letter)
		{
			count++;
		}
	}
	return count;
}

double SquareRoot(double x)
{
	return sqrt(x);
}

int main()
{
	cout << "Task1: Enter symbols: " << endl;
	string letters;
	getline(cin, letters);
	GetLowerUpper(letters);
	////////////////////////
	cout << "Task2: Count letters: " << endl;
	string text;
	char letter;
	cout << "Enter text: ";
	getline(cin, text);
	cout << "Enter a letter to search: ";
	cin >> letter;
	cout << "Letter: " << letter << " is found " << CountLetter(text, letter) << " times" << endl;
	//////////////////////////
	cout << "Task2: Get square root: " << endl;
	double x;
	cout << "Enter a positive number: ";
	cin >> x;
	cout << "The square root of " << x << " is: " << SquareRoot(x) << endl;
	//////////////////////////
	cout << "Task2: Sum the numbers in array: " << endl;
	int arr[] = { 24, 2, 3, 53, 3, 5, 2, 27, 2, 1 };
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		sum += arr[i];
	}
	cout << sum << endl;
	return 0;
}

