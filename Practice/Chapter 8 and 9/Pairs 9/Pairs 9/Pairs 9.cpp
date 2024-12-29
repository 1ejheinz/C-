// Pairs 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************

* Lesson 7: Chapter 9 Exercise 2 and 3 
* Student : Edward Heinz
* Date : Jan 1, 2024
* *****************************************/

#include "std_lib_facilities.h"

class Name_pairs {
public:
    void read_names();
    void read_ages();
    void print();
    void sort_pairs();
private:
    vector<string> names;
    vector<double> ages;
};

void Name_pairs::read_names()
{
    cout << "Enter some names and type 'DONE' when you are finished.\n";

    for (string n; cin >> n; ) {
        if (n == "DONE") return;
        names.push_back(n);
    }
}

void Name_pairs::read_ages()
{
    cout << "For each name, enter the person's age.\n";

    for (string n : names) {
        cout << n << " => ";
        int a;
        cin >> a;
        ages.push_back(a);
    }
}

void Name_pairs::print()
{
    for (int i = 0; i < names.size(); ++i)
        cout << names[i] << " is " << ages[i] << " years old.\n";
}

void Name_pairs::sort_pairs()
{
    vector<string> temp_names = names;
    vector<double> sort_ages;
    sort(names);

    for (string n : names)
        for (int i = 0; i < temp_names.size(); ++i)
            if (temp_names[i] == n)
                sort_ages.push_back(ages[i]);

    ages = sort_ages;
}

int main()
try {
    Name_pairs np;
    np.read_names();
    np.read_ages();
    np.sort_pairs();
    np.print();
    return 0;
}
catch (exception& e) {
    cerr << e.what();
}
catch (...) {
    cerr << "unknown error\n";
}

/*
#include "../text_lib/std_lib_facilities.h"

class Name_pairs {
public:
    void read_names();
    void read_ages();
    void sort_pairs();

    string get_name(int i) { return names[i]; }
    int get_age(int i) { return ages[i]; }
    int get_size() { return names.size(); }
private:
    vector<string> names;
    vector<double> ages;
};

void Name_pairs::read_names()
{
    cout << "Enter some names and type 'DONE' when you are finished.\n";

    for (string n; cin >> n; ) {
        if (n == "DONE") return;
        names.push_back(n);
    }
}

void Name_pairs::read_ages()
{
    cout << "For each name, enter the person's age.\n";

    for (string n : names) {
        cout << n << " => ";
        int a;
        cin >> a;
        ages.push_back(a);
    }
}

void Name_pairs::sort_pairs()
{
    vector<string> temp_names = names;
    vector<double> sort_ages;
    sort(names);

    for (string n : names)
        for (int i = 0; i < temp_names.size(); ++i)
            if (temp_names[i] == n)
                sort_ages.push_back(ages[i]);

    ages = sort_ages;
}

ostream& operator<<(ostream& os, Name_pairs np)
{
    for (int i = 0; i < np.get_size(); ++i)
        os << np.get_name(i) << " is " << np.get_age(i) << " years old.\n";

    return os;
}

int main()
try {
    Name_pairs np;
    np.read_names();
    np.read_ages();
    np.sort_pairs();
    cout << np << '\n';
    return 0;
}
catch (exception& e) {
    cerr << e.what();
}
catch (...) {
    cerr << "unknown error\n";
}

*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
