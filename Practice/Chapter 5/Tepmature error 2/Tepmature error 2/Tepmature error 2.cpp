// Tepmature error 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************
* Lesson 4: Chapter 5 Exercise 3
* Student : Edward Heinz
* Date : October 21st, 2023
* *****************************************/




// //The following program takes in a temperature value in Celsius and converts it to Kelvin. 
// //Absolute zero is the lowest temperature that can be reached; it is –273.15°C, or 0K. The program, even when corrected,
// //will produce erroneous results when
// //given a temperature below this. Place a check in the main program that will produce an error if a temperature is given below –273.15°C.

#include <std_lib_facilities.h>

double c_to_k(double c) // converts Celsius to Kelvin
{
	double k = c + 273.15;
	return k;
}


int main()
{
	cout << "Enter Temperature in Celsius: ";


	double c; // declare input variable
	cin >> c; // retrieve temperature to input variable

	if ( c < (double)(-273.15))
	{
	
		cout << "The temperature needs to be above  -273.15";
	}


	double k = c_to_k(double(c)); // convert temperature

	
	cout << k << '/n'; // print out temperature
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
