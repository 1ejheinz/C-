// Vowels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/***************************************
* Lesson 8: Chapter 11 ex 1,2,3
* Student : Edward Heinz
* Date : Jan 14, 2024
* *****************************************/

#include "std_lib_facilities.h"

string disemvowel(const string& s)
// removes vowels from a string
{
    string output = "";
    vector<char> vowels{ 'a', 'e', 'i', 'o', 'u' };

    for (char ch : s) {
        bool vowel = false;

        for (char v : vowels)
            if (ch == v) vowel = true;

        if (!vowel)
            output += ch;
    }

    return output;
}
bool search_word(string& word, string& line)
// search a line for a given word
// if found return true else return false
{
    stringstream ss{ line };

    for (string s; ss >> s; )
        if (s == word) return true;

    return false;
}

vector<string> get_lines(ifstream& ist)
// retrieve the contents of a file stream by line
{
    vector<string> lines;

    while (ist) {
        string line;
        getline(ist, line);
        lines.push_back(line);
    }

    if (!ist && !ist.eof())
        error("couldn't fill from file");

    return lines;
}

int main()
try {
    cout << "Enter the file to search:\n";
    string iname;
    cin >> iname;
    ifstream ist{ iname };
    if (!ist) error("could not read from file ", iname);

    cout << "Enter a word to search for:\n";
    string word;
    cin >> word;

    vector<string> lines = get_lines(ist);

    for (int i = 0; i < lines.size(); ++i)
        if (search_word(word, lines[i]))
            cout << i + 1 << ' ' << lines[i] << '\n';


        cout << "Please enter a file to make lowercase:\n";
        string iname2;
        cin >> iname2;
        ifstream ist2{ iname2 };
        if (!ist2) error("could not read from file ", iname2);

        cout << "Please enter a destination for output:\n";
        string oname;
        cin >> oname;
        ofstream ost{ oname };
        if (!ost) error("could not write to file ", oname);

        for (string s; ist >> s; ) {
            for (char& c : s)
                c = tolower(c);

            ost << s << ' ';
        }

        if (ist.eof())
            cout << iname << " read complete\n";
        else
            error("could not complete operation");
    
    
 
        cout << "Enter a file to disemvowel:\n";
        string iname3;
        cin >> iname3;
        ifstream ist3{ iname3 };
        if (!ist) error("could not read from file ", iname3);

        cout << "Enter a destination for the output:\n";
        string oname2;
        cin >> oname2;
        ofstream ost2{ oname2 };
        if (!ost) error("could not write to file ", oname2);

        while (ist) {
            string line;
            getline(ist, line);
            ost << disemvowel(line) << '\n';
        }

        if (!ist && !ist.eof())
            error("trouble while reading from stream");
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    
    catch (...) {
        cerr << "Error of unknown type\n";
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
