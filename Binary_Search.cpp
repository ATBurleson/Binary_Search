// Binary_Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
* Developer: Austin Burleson
* Program: Binary Search
*
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Create an array of size 10, starting with 0; the array will hold 9 values.  The High value of this array
//is 50 and low value will be 0.  What a Binay search does is has a pointer at low and high, then adds and divides by
//two and sets the as the midpoint of the array.  This loops through the array until the value being search for is equal 
//to the midpoint value, search for 35.
//
//requirment are: 
//that the array must be sorted for this to work thereby cutting space and time.
int MyArray[] = { 2,20,30,47,65,67,98,200 };

//declare variables for holding the users name, value, low, high, and mid value.
string UserName;
int UsersValue = 0, SearchValue = 0;
int Resault = 0;
/**********************************************************************************************************************************************/

void DisplayArray()
{
	cout << "The array is: ";
	for (int i = 0; i < 8; i++)
	{
		cout << MyArray[i] << ", ";
	}
	cout << endl << endl;
}

void GetUserName()
{
	cout << "Please enter your name: ";
	getline(cin, UserName);
	cout << endl << endl;

	cout << "Hello, " << UserName << endl;
	cout << "PRESS ENTER" << endl;
	cin.ignore();
}

void GetUserValue()
{
	cout << "Enter the value you want to search for: ";
	cin >> UsersValue;
}

int SearchForValue(int MyArray[], int SIZE, int SearchValue)
{
	int low = 0;
	int high = SIZE - 1;
	int mid = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		
		if (SearchValue == MyArray[mid])
		{
			return mid;
			cout << "mid is: " << mid << endl;
		}
		else if (SearchValue > MyArray[mid])
		{
			low = mid + 1;
			cout << "mid is: " << mid << endl;
		}
		else
		{
			high = mid - 1;
			cout << "mid is: " << mid << endl;
		}
	}

	return -1;
}

void Check()
{
	if (Resault >= 0)
	{
		cout << "The number " << MyArray[Resault] << " is located at index " << Resault << endl;
	}
	else
	{
		cout << UsersValue << " not found!!! " << endl;
	}
}
/**********************************************************************************************************************************************/
int main()
{
	clock_t start, end;
	start = clock();

	DisplayArray();
	GetUserName();
	GetUserValue();
	Resault = SearchForValue(MyArray, 8, UsersValue);
	Check();

	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Execution time was: " << fixed << time_taken << setprecision(5) << " in SECONDS. "  << endl << endl;
}

