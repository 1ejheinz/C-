// CalcBuggy08ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************
* Lesson 6: Chapter 7 Exersizes 1,2,3,4---- couldn't get to run after days of attempts
* Student: Edward Heinz
* Date: November 24, 2023
******************************************/
/*
1. Allow underscores in the calculator’s variable names.

2. Provide an assignment operator, =, so that you can change the value of a variable after you introduce it using let. 
Discuss why that can be useful and how it can be a source of problems.

3. Provide named constants that you really can’t change the value of. 
Hint: You have to add a member to Variable that distinguishes between constants and variables and check for it in set_value(). 
If you want to let the user define constants (rather than just having pi and e defined as constants), 
you’ll have to add a notation to let the user express that, for example, const pi = 3.14;.

4. The get_value(), set_value(), is_declared(), and define_name() functions all operate on the variable var_table. 
Define a class called Symbol_table with a member var_table of type vector<Variable> and member functions get(), set(), is_declared(),
and declare(). Rewrite the calculator to use a variable of type Symbol_table.
*/

/*Grammar 

Calculation:
Statement
Print
Quit
Calculation Statement

Statement :
Declaration
Expression

Declaration :
"let" Name "=" Expression
"const" Name "=" Expression

Print :
;

Quit:
q

Expression :
Term
Expression + Term
Expression - Term
Term :
Primary
Term * Primary
Term / Primary
Term % Primary
Primary :
Number
Name
Name = Expression
(Expression)
-Primary
+ Primary
*/

#include "std_lib_facilities.h"


struct Token // Tokens have a kind, value and name are optional EJH 11/20 Changed to Class

{
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }                  
	Token(char ch, double val) :kind(ch), value(val) { }    
	Token(char ch, string n) :kind(ch), name(n) { }  //added make a token from char/string to get return Token(name, s); to process 11/23 EJH
};

// stream of tokens EJH 11/20


const char let = '#';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char help = 'h';
const char con = 'C';
const char square_root = 's';
const char exponent = '^';// added help token, square root, exponent 11/23 EJH
const char power = 'p';// added power 11/23 EJH
const string constkey = "const";	// const keyword
const string prompt = "> "; // moved up to here
const string result = "= "; 

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
		return Token (ch); 
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
			if (s == "exit") return Token(quit);
			if (s == "conkey") return Token(con);// added // to get to run initialy. Fixed exit to quit added let 11/23 EJH
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
	bool var; // const true or false
	Variable(string n, double v, bool va = true) :name(n), value(v), var(va) { }
};
class Symbol_table {
	vector<Variable> var_table;
	bool is_declared(string var);
public:
	double get_value(string s);
	double set_value(string s, double d);
	double define_name(string var, double val, bool write);
};
vector<Variable> var_table;//names = var_table
// retrieves a value from variable vector EJH 11/20
double get_value(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d) // changes the value of a variable EJH 11/20
{
	for (int i = 0; i <= var_table.size(); ++i)
		if (var_table[i].name == s) {
			if (var_table[i].var == false) error(s, " is a constant");
			var_table[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)// check to see if a given variable name has already been used EJH 11/20
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return true;
	return false;
}

Token_stream ts;
Symbol_table sym;

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
		

	{
		
		Token t2 = ts.get();
		if (t2.kind == '=') {
			return sym.set_value(t.name, expression());
		}
		else {
			return sym.get_value(t.name);
		}
	}
	case square_root: //added square with error 11/23
	{
		double d = primary();
		if (d < 0) error("Can't suare a negative number");
		return sqrt(d);
	}
	case power: // added 11/25 after I noticed it missing EJH
	{   t = ts.get();
	if (t.kind != '(') error("'(' expected");
	double d = expression();
	t = ts.get();
	if (t.kind != ',') error("',' expected");
	t = ts.get();
	if (t.kind != number) error("second argument of 'pow' is not a number");
	int i = int(t.value);
	if (i != t.value) error("second argument of 'pow' is not an integer");
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	return pow(d, i);
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

double Symbol_table::get_value(string s)
{
	for (const Variable& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined Variable ", s);
}

double Symbol_table::set_value(string s, double d)
{
	for (Variable& v : var_table)
		if (v.name == s) {
			if (v.var) {
				v.value = d;
				return d;
			}
			else
				error("Cannot overwrite constant ", s);
		}
	error("set: undefined variable ", s);
}

bool Symbol_table::is_declared(string var)
{
	for (const Variable& v : var_table)
		if (v.name == var) return true;
	return false;
}

double Symbol_table::define_name(string var, double val, bool write)
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{ var, val, write });
	return val;
}
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
	var_table.push_back(Variable(name, d));
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


void calculate()
{
	var_table.push_back(Variable("pi", 3.14159));   //names EJH 11/21
	var_table.push_back(Variable("e", 2.718281828));
	var_table.push_back(Variable("k", 1000));

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
