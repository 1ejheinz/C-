// calculator02buggy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************
* Lesson 5: Chapter 6 Drill
* Student: Edward Heinz
* Date: October 27, 2023
******************************************/
/*


    1. Take the calculator from the file calculator02buggy.cpp. Get it to compile. You need to find and fix a few bugs.
    Those bugs are not in the text in the book. Find the three logic errors deviously inserted in calculator02buggy.cpp and
    remove them so that the calculator produces correct results.

2. Change the character used as the exit command from q to x.

3. Change the character used as the print command from ; to =.

4. Add a greeting line in main():

"Welcome to our simple calculator.
Please enter expressions using floating-point numbers."

5. Improve that greeting by mentioning which operators are available and how to print and exit

*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {         
public:
    char kind;        
    double value;      
    Token(char ch)    
        :kind(ch), value(0) { }
    Token(char ch, double val)     
        :kind(ch), value(val) { }
};


class Token_stream {
public:
    Token_stream();   
    Token get();      
    void putback(Token t);    
private:
    bool full;        
    Token buffer;     
};

Token_stream::Token_stream()
    :full(false), buffer(0)    
{
}


void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       
    full = true;     
}


Token Token_stream::get()       
{
    if (full) {       
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '9':
    {
        cin.putback(ch);         
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}


Token_stream ts;        // provides get() and putback() 


double expression();    // declaration so that primary() can call expression()



// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");      
        return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;              
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}


// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract ERROR
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}


int main()
try
{
    cout << "Welcome to the simple calculator.\n"
        << "Please enter expressions using floating-point numbers.\n"
        << "Add, subtract, multiply and divide.\n"
        << "End with an = to print, x will quit.\n";

    while (cin) {
        cout << "=" << expression() << '\n';
    }
    keep_window_open();
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
