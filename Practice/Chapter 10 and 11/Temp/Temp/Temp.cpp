// Temp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/***************************************
* Lesson 8: Chapter 10 ex 2 and 3
* Student : Edward Heinz
* Date : Jan 12, 2024
* *****************************************/
#include "std_lib_facilities.h"

//temp reading
struct Reading {
    int hour;           
    double temperature; 
    Reading() :hour(0), temperature(0) { }
    Reading(int h, double t) :hour(h), temperature(t) { }
};

bool operator<(const Reading& r1, const Reading& r2)
{
    return r1.temperature < r2.temperature;
}

ostream& operator<<(ostream& os, const Reading& r)
{
    return os << r.hour << ' ' << r.temperature;
}

istream& operator>>(istream& is, Reading& r)
{
    int hour;
    double temperature;
    is >> hour >> temperature;
    if (!is) return is;
    r = Reading(hour, temperature);
    return is;
}

const int max_temp = 108;
const int min_temp = -44;

// from file
void fill_from_file(vector<Reading>& readings, const string& name)
{
    ifstream ist(name.c_str());
    if (!ist) error("can't open input file", name);
    Reading r;
    while (ist >> r) {
        if (r.hour < 0 || r.hour>23) error("hour out of range");
        if (r.temperature<min_temp || r.temperature>max_temp)
            error("temperature out of range");
        readings.push_back(r);
    }
}

int main()
try {
    vector<Reading> readings;
    fill_from_file(readings, "in_hour_temps.txt");

    //median
    sort(readings.begin(), readings.end());
    double median = readings[readings.size() / 2].temperature;

    //averag
    double sum = 0;
    for (int i = 0; i < readings.size(); ++i) {
        sum += readings[i].temperature;
    }
    double avg = sum / readings.size();

   
    cout << "median temperature: " << median << " F" << endl;
    cout << "average temperature: " << avg << " F" << endl;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
