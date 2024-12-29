// Drill 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************

* Lesson 7: Chapter 8 Exercise Drill 2
* Student: Edward Heinz
* Date: Jan 1, 2024
******************************************/



#include "std_lib_facilities.h"

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/*
void swap_cr(const int& a, const int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
*/

int main()
{
    int x = 7;
int y =9;
swap_r(x,y);
swap_v(7,9);
const int cx = 7;
const int cy = 9;
swap_v(cx,cy);
swap_v(7.7,9.9);
double dx = 7.7;
double dy = 9.9;
swap_v(dx,dy);
swap_v(7.7,9.9);

    cout << "x: " << x << '\n'
        << "y: " << y << '\n'
        << "cx: " << cx << '\n'
        << "cy: " << cy << '\n'
        << "dx: " << dx << '\n'
        << "dy: " << dy << '\n';
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
