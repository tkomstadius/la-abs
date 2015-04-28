/**********************************************
* File: test1.cpp                             *
* Author: Aida Nordman                        *
* Course: TND004, Lab 3                       *
* Date: VT2, 2015                             *
* Description: test program                   *
***********************************************/

#include "threaded_BST.h"
#include "BiIterator.h"

#include <iostream>
#include <iomanip>

using namespace std;


/*******************************
* 1. Main function             *
********************************/


int main()
{
    /******************************************************
    *PHASE 0: constructor, empty(), size()                *
    ******************************************************/
    cout << "**TEST PHASE 0: constructor, empty, size"
         << endl << endl;

    MAP table;

    if (table.empty())
        cout << "Table is empty!" << endl;

    cout << "Number of elements = "
         << table.size() << endl << endl;

    /******************************************************
    *PHASE 1: insert()                                    *
    *         create the tree of slide 9, Fö 6            *
    *******************************************************/
//    cout << "\**TEST PHASE 1: insert"
//         << endl << endl;
//
//    string V[] = {"6", "4", "5", "8", "7", "2"};
//
//    for(int i = 0; i < 6; i++)
//    {
//        ELEMENT e(V[i],0);
//        table.insert(e);
//    }
//
//    cout << "Tree: ";
//    table.display();
//    cout << endl;
//
//    /******************************************************
//    *PHASE 2: operator[], find(), iterators               *
//    *******************************************************/
//    cout << "\n**TEST PHASE 2: operator[], find(), iterators"
//         << endl << endl;
//
//    for(int i = 0; i < 6; i++)
//    {
//       cout << table[V[i]].first << " "
//            << table[V[i]].second << endl;
//    }
//
//    table["5"].second++;
//    cout << endl << table["5"].first << " "
//            << table["5"].second << endl;
//
//
//   if (table.find("20") == table.end())
//    cout << "20 is not in the tree" << endl;
//
//    //Insert (100,0) in the table
//    cout << "(" << table["100"].first << ","
//         << table["100"].second << ")" << " has been inserted in the table" << endl;
//
//
//   /******************************************************
//   *PHASE 3: iterators                                   *
//   *******************************************************/
//    cout << "\n**TEST PHASE 3: iterators up and down"
//         << endl << endl;
//
//    cout << "\n\nTable sorted increasingly..."
//         << endl << endl;
//
//    BiIterator it = table.begin();
//
//    cout << "  \tKEY" << "\tCOUNTER" << endl;
//    cout << "==============================\n";
//    for( ; it != table.end(); it++)
//    {
//         cout << setw(10) << it->first
//              << setw(12) << it->second << endl;
//    }
//
//    cout << "\n\nTable sorted decreasingly..." << endl << endl;
//
//    it = table.find("8");
//
//    cout << "  \tKEY" << "\tCOUNTER" << endl;
//    cout << "==============================\n";
//    for( ; it != table.end(); it--)
//    {
//         cout << setw(10) << it->first
//              << setw(12) << it->second << endl;
//    }
//
//   /******************************************************
//   *PHASE 4: remove                                      *
//   *******************************************************/
//    cout << "\n**TEST PHASE 4: remove" << endl << endl;
//
//    table.remove("6");
//    table.remove("5");
//    table.remove("7");
//
//    cout << "\n\nTable sorted increasingly after removing 5, 6, and 7..."
//         << endl << endl;
//
//    it = table.begin();
//
//    cout << "  \tKEY" << "\tCOUNTER" << endl;
//    cout << "==============================\n";
//    for( ; it != table.end(); it++)
//    {
//         cout << setw(10) << it->first
//              << setw(12) << it->second << endl;
//    }
//
//    cout << "\nRemove all ..." << endl;
//
//    table.remove("2");
//    table.remove("4");
//    table.remove("8");
//    table.remove("100");
//
//    if (table.empty())
//        cout << "Table is empty!" << endl << endl;

    cout << "All tests passed successfully!!" << endl << endl;

    return 0;
}
