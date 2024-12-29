// X and Y.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Do Chapter 10 Drills 1, 2, 3, and 4
/***************************************
* Lesson 8: Chapter 10 Drill
* Student : Edward Heinz
* Date : Jan 10, 2024
* *****************************************/

// Chapter 10, drill

#include "std_lib_facilities.h"


struct Point {
    int x;
    int y;
    Point() :x(0), y(0) { }
    Point(int xx, int yy) :x(xx), y(yy) { }
};

bool operator==(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1 == p2);
}

ostream& operator<<(ostream& os, const Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

istream& operator>>(istream& is, Point& p)
{
    int x, y;
    char ch1, ch2, ch3;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
        is.clear(ios_base::failbit);
        return is;
    }
    p = Point(x, y);
    return is;
}


void print_vector(const vector<Point>& points)
{
    for (int i = 0; i < points.size(); ++i)
        cout << points[i] << endl;
}

//print to file
void write_to_file(const vector<Point>& points, const string& name)
{
    ofstream ost(name.c_str());
    if (!ost) error("can't open output file ", name);
    for (int i = 0; i < points.size(); ++i)
        ost << points[i] << endl;
}

//read from file
void fill_from_file(vector<Point>& points, const string& name)
{
    ifstream ist(name.c_str());
    if (!ist) error("can't open input file, ", name);
    Point pp;
    while (ist >> pp) points.push_back(pp);
}


int main()
try {
    // enter points
    vector<Point> original_points;
    cout << "Enter 7 pairs in (x,y) format:\n";
    for (int i = 0; i < 7; ++i) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    }

    // print points
    cout << "\nOriginal Points:\n";
    print_vector(original_points);

    // write points to txt
    string filename = "mydata.txt";
    write_to_file(original_points, filename);




}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
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
