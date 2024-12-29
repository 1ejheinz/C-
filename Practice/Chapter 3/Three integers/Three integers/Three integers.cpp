// Three integers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Two Integer values.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************
* Lesson 1: Chapter 2 Exercise 6
* Student: Edward Heinz
* Date: September, 28 2023
******************************************/
#include <std_lib_facilities.h>
using namespace std;

int main()
{
		int val1 = 0;
		int val2 = 0;
		int val3 = 0;
		cout << "Please enter three integer values: ";
		cin >> val1 >> val2 >> val3;
		cout << "values read : " << val1 << ", " << val2 << ", " << val3 << '\n';
		int smallest = 0;
		int middle = 0;
		int largest = 0;
		if (val1 <= val2 && val1 <= val3) {
			smallest = val1;
			if (val2 <= val3) {
				middle = val2;
				largest = val3;
			}
			else {
				middle = val3;
				largest = val2;
			}
		}
		else if (val2 <= val1 && val2 <= val3) {
			smallest = val2;
			if (val1 <= val3) {
				middle = val1;
				largest = val3;
			}
			else {
				middle = val3;
				largest = val1;
			}
		}
		else {	
			smallest = val3;
			if (val1 <= val2) {
				middle = val1;
				largest = val2;
			}
			else {
				middle = val2;
				largest = val1;
			}
		}

		cout << "values sorted : " << smallest << ", " << middle << ", " << largest << '\n';

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
