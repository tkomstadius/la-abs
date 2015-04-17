/*
  Name: hashTable.h
  Author: Aida Nordman
  Course: TND004, Lab 1
  Description: test program for class SET
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>  //transform
#include <cctype>     //tolower

#include "set.cpp"

using namespace std;

//Do not modify
int main()
{
    /*****************************************************
    * TEST PHASE 0                                       *
    * Default constructor, conversion constructor, and   *
    * operator<<                                         *
    ******************************************************/
    cout << "TEST PHASE 0: default and conversion constructor\n\n";

    Set<int> S3;
    Set<int> S4(-4);

    cout << "S3 = " << S3 << endl;
    cout << "S4 = " << S4 << endl;

    /*****************************************************
    * TEST PHASE 1                                       *
    * Constructor: create a Set from an array            *
    ******************************************************/
    cout << "\nTEST PHASE 1: constructor from an array\n\n";

    int A1[] = { 1, 3, 5 };
    int A2[] = { 2, 3, 4 };

    Set<int> S1(A1, 3);
    Set<int> S2(A2, 3);

    cout << "S1 = " << S1 << endl;
    cout << "S2 = " << S2 << endl;

    /*****************************************************
    * TEST PHASE 2                                       *
    * Copy constructor                                   *
    ******************************************************/
    cout << "\nTEST PHASE 2: copy constructor\n\n";

    Set<int> S5(S1);

    cout << "S5 = " << S5 << endl;

    /*****************************************************
    * TEST PHASE 3                                       *
    * Assignment operator: operator=                     *
    ******************************************************/
    cout << "\nTEST PHASE 3: operator=\n\n";

    S3 = S4 = S5;

    cout << "S3 = " << S3 << endl;
    cout << "S4 = " << S4 << endl;


    /*****************************************************
    * TEST PHASE 4                                       *
    * is_member                                          *
    ******************************************************/
    cout << "\nTEST PHASE 4: is_member\n\n";

    for (int i = 1; i <= 5; i++)
    {
        cout << "S3.is_member(" << i << ") ? "
             << (S3.is_member(i) ? 'T' : 'F') << endl;
    }
      cout << "\nS3.is_member(99999) ? "
           << (S3.is_member(99999) ? 'T' : 'F') << endl;

    /*****************************************************
    * TEST PHASE 5                                       *
    * cardinality                                        *
    ******************************************************/
    cout << "\nTEST PHASE 5: cardinality\n\n";

    cout << "S3.cardinality() = "
         << S3.cardinality() << endl;

    /*****************************************************
    * TEST PHASE 5                                       *
    * Overloaded operators: union, intersection, and     *
    * and difference                                     *
    ******************************************************/
    cout << "\nTEST PHASE 5: union, intersection, and difference\n\n";

    S3 = S1 + S2 + 4;
    S4 = S1 * S2;
    S5 = S1 - S2;

    cout << "S3 = " << S3 << endl;
    cout << "S4 = " << S4 << endl;
    cout << "S5 = " << S5 << endl;

    /*****************************************************
    * TEST PHASE 6                                       *
    * Overloaded operators: equality, subset, and        *
    * strict subset                                      *
    ******************************************************/
    cout << "\nTEST PHASE 6: equality, subset, strict subset\n\n";

    cout << "S2 == S3 ? " << (S2 == S3 ? 'T' : 'F') << endl;
    cout << "S2 <= S3 ? " << (S2 <= S3 ? 'T' : 'F') << endl;
    cout << "S2 <  S3 ? " << (S2 <  S3 ? 'T' : 'F') << endl;

    /*****************************************************
    * TEST PHASE 7                                       *
    * Overloaded operators: insert and delete one element*
    ******************************************************/
    cout << "\nTEST PHASE 7: insertion and deletion\n\n";

    //Note: conversion constructor is called
    S4 = 4 + S1 - 5 - 99999;
    S5 = S2 - 2 + 1 - 99999;

    cout << "S4 = " << S4 << endl;
    cout << "S5 = " << S5 << endl;

    /*****************************************************
    * TEST PHASE 8                                       *
    * Overloaded operators: equality, subset, and        *
    * strict subset                                      *
    ******************************************************/
    cout << "\nTEST PHASE 8: equality, subset, strict subset\n\n";
    cout << "S4 == S5 ? " << (S4 == S5 ? 'T' : 'F') << endl;
    cout << "S4 <= S5 ? " << (S4 <= S5 ? 'T' : 'F') << endl;
    cout << "S4 <  S5 ? " << (S4 <  S5 ? 'T' : 'F') << endl;

    /*****************************************************
    * TEST PHASE 9                                       *
    * Create a set of strings                            *
    ******************************************************/
    cout << "\nTEST PHASE 9: Create a set of strings\n\n";

    Set<string> words;

    string w;

    cout << "Enter some text (end with stop)" << endl;

    while(cin >> w && w != "stop")
    {
        //transform all upper-case letters to lower-case letters
        transform(w.begin(), w.end(), w.begin(), ::tolower);
        words = words + w;
    }

    cout << "The words sorted alphabetically: "
         << words << endl;


    return 0;
}
