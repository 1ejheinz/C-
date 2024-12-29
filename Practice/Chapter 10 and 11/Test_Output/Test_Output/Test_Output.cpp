// Test_Output.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************
* Lesson 8: Chapter 11 drills
* Student : Edward Heinz
* Date : Jan 13, 2024
* *****************************************/

#include "std_lib_facilities.h"
#include "Test_Output.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
errno_t _localtime64_s(
    struct tm* tmDest,
    __time64_t const* sourceTime){

    class tm newtime;
    char am_pm[] = "AM";
    __time64_t long_time;
    char timebuf[26];
    errno_t err;

    // Get time as 64-bit integer.
    _time64(&long_time);
    // Convert to local time.
    err = _localtime64_s(&newtime, &long_time);
    if (err)
    {
        printf("Invalid argument to _localtime64_s.");
        exit(1);
    }
    if (newtime.tm_hour > 12)        // Set up extension.
        strcpy_s(am_pm, sizeof(am_pm), "PM");
    if (newtime.tm_hour > 12)        // Convert from 24-hour
        newtime.tm_hour -= 12;        // to 12-hour clock.
    if (newtime.tm_hour == 0)        // Set hour to 12 if midnight.
        newtime.tm_hour = 12;

    // Convert to an ASCII representation.
    err = asctime_s(timebuf, 26, &newtime);
    if (err)
    {
        printf("Invalid argument to asctime_s.");
        exit(1);
    }
    printf("%.19s %s\n", timebuf, am_pm);
}

int main()
try {
    int birth_year = 1978;

    cout << "decimal\t\t" << birth_year << '\n' << hex
        << "hexadecimal\t" << birth_year << '\n' << mar
        << "octal\t\t" << birth_year << '\n';

    cout << mar << 45 << '\n';

  
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Something Went Wrong\n";
    return 2;
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




