// Drill 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/***************************************

* Lesson 7: Chapter 8 Exercise Drill 3
* Student: Edward Heinz
* Date: Jan 1, 2024
******************************************/


#include "std_lib_facilities.h"

namespace X {
    int var = 0;

    void print()
    {
        cout << "X: " << var << '\n';
    }
}

namespace Y {
    int var = 0;

    void print()
    {
        cout << "Y: " << var << '\n';
    }
}

namespace Z {
    int var = 0;

    void print()
    {
        cout << "Z: " << var << '\n';
    }
}

int main()
{
    X::var = 7;
    X::print();         // print X's var
    using namespace Y;
    var = 9;
    print();            // print Y's var
    {
        using Z::var;
        using Z::print;
        var = 11;
        print();        // print Z's var
    }
    print();            // print Y's var
    X::print();         // print X's var
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
