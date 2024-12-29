// Calc08Buggy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/***************************************
* Lesson 6: Chapter 7 Drill
* Student: Edward Heinz
* Date: November 12, 2023
******************************************/
/*

1. Starting from the file calculator08buggy.cpp, get the calculator to compile.

2. Go through the entire program and add appropriate comments.

3. As you commented, you found errors (deviously inserted especially for you to find). Fix them; they are not in the text of the book.

4. Testing: prepare a set of inputs and use them to test the calculator. Is your list pretty complete? What should you
look for? Include negative values, 0, very small, very large, and “silly” inputs.

5. Do the testing and fix any bugs that you missed when you commented.

6. Add a predefined name k meaning 1000.

7. Give the user a square root function sqrt(), for example, sqrt(2+6.7). Naturally, the value of sqrt(x)
is the square root of x; for example, sqrt(9) is 3. Use the standard library sqrt() function that is available
through the header std_lib_facilities.h. Remember to update the comments, including the grammar.

8. Catch attempts to take the square root of a negative number and print an appropriate error message.

9. Allow the user to use pow(x,i) to mean “Multiply x with itself i times”; for example, pow(2.5,3) is 2.5*2.5*2.5.
Require i to be an integer using the technique we used for %.

10. Change the “declaration keyword” from let to #.

11. Change the “quit keyword” from quit to exit. That will involve defining a string for quit just as we did for let in §7.8.2

Note: When commenting the drill:

Do NOT comment every line
DO include comments for
each class, structure, and function should include
your name
date
purpose
revision history
major logic component
Only for this drill
leave the old code in as a comment
immediately below the old code put the
new or modified code
comment the new or modified code
Note:  Include specific test cases.  The maximum number of test cases should be 20.  Include as many different scenarios as you can.


#include "std_lib_facilities.h"

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s = ch;
			cin.unget();
			if (s == "let") return Token(let);
			if (s == "quit") return Token(name);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
*/

#include "std_lib_facilities.h"

struct Token // Tokens have a kind, value and name are optional EJH 11/20

{
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n) { } //added make a token from char/string to get return Token(name, s); to process 11/23 EJH
};
// stream of tokens EJH 11/20
class Token_stream {
	bool full;
	Token buffer;
public:
	// Constructor EJH 11/20
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = '#';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char help = 'h';
const char square_root = 's';
const char exponent = '^';// added help token, square root, exponent 11/23 EJH
const char power = 'p';// added power 11/23 EJH

Token Token_stream::get()// Check buffer first EJH 11/20
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case quit:        //Added quit, square, exponent and let 11/21 EJH
	case square_root:
	case exponent:
	case let:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	// if digit take the whole number EJH 11/20
	double val;
	cin >> val;
	return Token(number, val);
	}//  unregisterd tokens accumulate. alpha chars and digits into variable name EJH 11/20
	default:
		if (isalpha(ch)) {
			//unregistered token to accumulate alpha ch 11/23 EJH
			
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == "let") return Token(let);
			if (s == "exit") return Token(quit); // added // to get to run initialy. Fixed exit to quit added let 11/23 EJH
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)  // ignore all tokens up to c 11/20 EJH
{// first look in buffer EJH 11/20
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;
	// search input EJH 11/20
	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable // Variable name and a value EJH 11/20
{
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;
// retrieves a value from variable vector EJH 11/20
double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d) // changes the value of a variable EJH 11/20
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)// check to see if a given variable name has already been used EJH 11/20
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();


double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	return d;
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case square_root: //added square with error 11/23
	{
		double d = primary();
		if (d < 0) error("Can't suare a negative number");
		return sqrt(d);
	}
	default:
		error("primary expected");
	}
}


	
	
	

double pow(double base, double exp) //added POW 11/23 EJH
{
	int x = narrow_cast<int>(exp);

	double n = 1;
	double b;

	if (exp < 0) {
		b = 1 / base;
		x *= -1;
	}
	else
		b = base;

	for (int i = 0; i < x; ++i)
		n *= b;

	return n;
}
double secondary() //added secondary 11/23
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '^':
			return pow(left, primary());
		default:
			ts.unget(t);
			return left;
		}
	}
}
double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");// name already defined EJH 11/20
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate() 
{
	names.push_back(Variable("pi", 3.14159));   //names EJH 11/21
	names.push_back(Variable("e", 2.718281828));
	names.push_back(Variable("k", 1000));

	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}

//Revision history : 11 / 23 EJH
//Took out unregistered token rev 1 took out token to run program and put if (s == "let") return Token(let);
//if (s == "exit") return Token(quit);
//Added comments
//Added names varibles in calculate
//Added q and h
//Added quit q, square s, exponent ^, power
//let to #
// updated cases
//cleaned up 11/24



 //TESTING
 

// (4 + 8) * 20 / 2
// let x = 7
// let x3 = 20 / 7
// 2+5, 10-4, 11+3, 16-20
// let x=2 x * x2 * pi x^2
// let x=2 x * x * 2 * pi x^2
 //s(2+6.7)
 //s(2+(-6.7))
 

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
