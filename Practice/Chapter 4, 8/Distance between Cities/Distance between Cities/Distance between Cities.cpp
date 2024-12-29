// Distance between Cities.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/***************************************
* Lesson 3: Chapter 4 Exercise 3
* Student: Edward Heinz
* Date: October 14th, 2023
******************************************/


#include <std_lib_facilities.h>

// Use the following mileage between the cities on your route "5.9 14.9 4.3 3.4 7.5 6.1 |"

int main()
{
    cout << "Enter a sequence of double values seperated by a space and followed by |. Eeach value will represent the distance between two cities along a given route.\n";
        vector<double> distances; 
    for (double distance; cin >> distance; ) 
        distances.push_back(distance); 
    double sum{ 0.0 };
    for (double distance : distances)
        sum += distance;
    cout << "Total distance: " << sum << '\n';
    sort(distances); 
    cout << "Smallest distance: " << distances[0] << '\n'
        << "Largest distance: " << distances[distances.size() - 1] << '\n';
    cout << "The mean distance between two cities is: " << sum / distances.size() << '\n';

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
