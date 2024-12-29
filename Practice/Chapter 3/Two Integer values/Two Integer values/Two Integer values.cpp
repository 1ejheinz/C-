// Two Integer values.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************
* Lesson 1: Chapter 2 Exercise 4
* Student: Edward Heinz
* Date: September, 13 2023
******************************************/
#include <std_lib_facilities.h>
using namespace std;

int main()
{
    cout << "Enter two integers\n";
    double val1, val2;
    cin >> val1 >> val2;

    double smaller, larger;
    if (val1 < val2)
    {
        smaller = val1;
        larger = val2;
    }
    else {
        smaller = val2;
        larger = val1;
    }

    double sum = val1 + val2;
    double difference = val1 - val2;
    double product = val1 * val2;
    double ratio = val1 / val2 * 100;

    cout << "smaller = " << smaller << "\n"
        << "larger = " << larger << "\n"
        << "sum = " << sum << "\n"
        << "difference = " << difference << "\n"
        << "product = " << product << "\n"
        << "ratio = " << ratio << "\n";

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
