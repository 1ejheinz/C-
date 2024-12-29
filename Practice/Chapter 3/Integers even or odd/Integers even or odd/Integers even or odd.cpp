// Integers even or odd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************
* Lesson 1: Chapter 2 Exercise 8
* Student: Edward Heinz
* Date: September, 28 2023
******************************************/
#include <std_lib_facilities.h>
using namespace std;

int main()
{
	int val = 0;
	cout << "Please enter integer: ";
	cin >> val;
	string res = "even";
	if (val % 2) res = "odd";	
    cout << "The value " << val << " is an " << res << " number\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
