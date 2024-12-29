// English Grammar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/***************************************
* Lesson 5: Chapter 6 Exercise
* Student: Edward Heinz
* Date: October 29, 2023
******************************************/

//Write a program that checks if a sentence is correct according to the “English” grammar in §6.4.1.
//Assume that every sentence is terminated by a full stop (.) surrounded by whitespace. For example, birds fly but the fish swim .
//is a sentence, but birds fly but the fish swim (terminating dot missing) and birds fly but the fish swim. (no space before dot) are not.
//For each
//sentence entered, the program should simply respond “OK” or “not OK.” Hint: Don’t bother with tokens; just read into a string using >>.

#include "std_lib_facilities.h"

// string and putback

class String_stream {
public:
    String_stream();
    string get();
    void putback(string s);
private:
    bool full;
    string buffer;
};

String_stream::String_stream()
    :full(false), buffer("") { }

void String_stream::putback(string s)
{
    if (full) error("putback() into a full buffer");
    buffer = s;
    full = true;
}

string String_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }

    string s = "";
    cin >> s;
    return s;
}

String_stream sstr;

// conjunction bool
bool conjunctio()
{
    string s = sstr.get();
    if (s == "and" || s == "or" || s == "but")
        return true;
    return false;
}

// noun bool
bool noun()
{
    string s = sstr.get();
    if (s == "birds" || s == "fish" || s == "C++")
        return true;
    return false;
}

// verb bool
bool verb()
{
    string s = sstr.get();
    if (s == "rules" || s == "fly" || s == "swim")
        return true;
    return false;
}

// article bool
bool article()
{
    string s = sstr.get();
    if (s == "the")     // article before noun, check next string
        return noun();
    
    sstr.putback(s);
    return noun();
}

// sentence bool
bool sentence()
{
    return (article() && verb());
}

int main()
try 

{
    cout << "Type in a sentence and I will check the grammar.\n";
    bool is_ok = false;
    while (true) {
        is_ok = sentence(); //sentence is correct
        if (!is_ok) {
            cout << "Not OK\n";
            return 0;
        }
        string s = sstr.get();
        if (s == ".") {
            cout << "OK\n";
            return 0;
        }
        sstr.putback(s);
        is_ok = conjunctio();
        if (!is_ok) {
	        cout << "Not OK\n";
	        return 0;
        }
    }

}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
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
