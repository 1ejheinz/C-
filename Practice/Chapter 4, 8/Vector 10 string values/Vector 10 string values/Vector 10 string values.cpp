
/***************************************
* Lesson 3: Chapter 4 Exercise 3
* Student: Edward Heinz
* Date: October 14th, 2023
******************************************/

// Make a vector holding the ten string values "zero", "one", . . . "nine". Use that in a program that converts a digit to its 
// corresponding spelled-out value; e.g., the input 7 gives the output seven. Have the same program, using the same input loop, 
// convert spelled-out numbers into their digit form; e.g., the input seven gives the output 7"

//Do both as part of the same program. For the first part, create a vector of integers.  No vector is needed for the second part.  
// Use an if-else structure 
// to determine the numeric equivalent of the string entered.  If a string that does not match is entered, generate an error message.

#include "std_lib_facilities.h"


vector<string> stringDigits{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string input{ "Enter digits from 0 to 9 as either spelled out number or integer which will be converted two ways\n" };

int convertStringToInt(string digit)
{
    for (int i = 0; i < stringDigits.size(); ++i)
    {
        if (stringDigits[i] == digit)
            return i;
    }
    cout << "Error: digit not in vector\n";
    cout << input;
    return -1;
}

string convertIntToString(int digit)
{
    if (0 <= digit && digit <= 9)
    {
        return stringDigits[digit];
    }
    else
    {
        cout << "Error: digit not in vector\n";
        cout << input;
        return " ";
    }
}

int main()
{ cout << input;

    string digit;
    int value;
    bool validinput{ true };
    while (validinput)
    {
        if (cin >> value)
        {
            string result = convertIntToString(value);
            if (" " != result)
                cout << result << '\n';

        }
        else
        {
            cin.clear(); 
            cin >> digit;
            if (digit == "|")
                validinput = false;
            else
            {
                int result = convertStringToInt(digit);
                if (-1 != result)
                    cout << result << '\n';
            }

        }

    }

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
        