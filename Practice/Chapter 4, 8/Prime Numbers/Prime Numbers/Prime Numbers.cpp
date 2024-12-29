// Prime Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/***************************************
* Lesson 3: Chapter 4 Exercise 11
* Student: Edward Heinz
* Date: October 14th, 2023
******************************************/

//Create a program to find all the prime numbers between 1 and 100. One way to do this is to write a function that will 
// check if a number is prime (i.e., see if the number can be divided by a prime number smaller than itself) using a vector of 
// primes in order (so that if the vector is called primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.). Then write a loop that 
// goes from 1 to 100, checks each number to see if it is a prime, and stores each prime found in a vector. Write another loop that 
// lists the primes you found. You might check your result by comparing your vector of prime numbers with primes. Consider 2 the first 
// prime

#include "std_lib_facilities.h"

bool IsPrime(int i_nNumber, vector<int> i_naPrimes)
{  for (int prime : i_naPrimes)
    {if (i_nNumber < prime || i_nNumber % prime == 0)
            return false;
    }
    return true;
}
int main() {

    vector<int> naPrimes{ 2 };
    for (int nNumber = 1; nNumber <= 100; ++nNumber)
    {
        if (IsPrime(nNumber, naPrimes))
        {
            naPrimes.push_back(nNumber);
        }
    }

    cout << "Found prime numbers between 1 and 100: \n";
    for (int nPrime : naPrimes)
    {
        cout << nPrime << " ";
    }
    cout << '\n';
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

