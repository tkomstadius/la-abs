/**********************************************
* File: main.cpp                              *
* Author: Aida Nordman                        *
* Course: TND004, Lab 3                       *
* Date: VT2, 2015                             *
* Description: frequency table                *
* DO NOT MODIFY                               *
***********************************************/

#include "threaded_BST.h"
#include "BiIterator.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//bool to check if a letter is capital
//numbers and apostrophe is ok
bool is_capital(char &letter)
{
    return true;
}

bool is_punctuation(char letter)
{
    if(letter == '.' || letter == ',' || letter == '!' ||
       letter == '?' || letter == ':' || letter == '\\' ||
       letter == '"' || letter == '(' || letter == ')' ||
       letter == ';' || letter == '\'')
    {
        return true;
    }
    return false;
}

void to_lower(char &letter)
{
    letter = tolower(letter);
}

void change_word(string &word)
{
    for_each(word.begin(), word.end(), to_lower);

    word.erase(
        remove_if(word.begin(), word.end(), is_punctuation), word.end());
}

/*******************************
* 2. Main function             *
********************************/


int main()
{
    MAP table;

    string name;
    string word;
    int counter = 0;

    /******************************************************
    * PHASE 0: Load the words in the text file            *
    *          into a the table                           *
    *******************************************************/

    cout << "File name? ";
    getline(cin, name);

    ifstream textFile(name);

    if (!textFile)
    {
        cerr << "Text file could not be opened!!" << endl;
        exit(1);
    }

    cout << "Loading the words from " << name << " ...\n" << endl;

    textFile >> word;
    change_word(word);
    ELEMENT e(word, 1);
    table.insert(e);
    while(textFile >> word)
    {
        change_word(word);
        table[word].second++;
        counter++;
    }
    textFile.close();

//    //Read words and load them in the table
//    while (textFile >> s)
//    {
//        //remove non-alphanumeric chars
//        s.erase(remove_if(s.begin(), s.end(), isNotAlnum), s.end());
//
//        //convert to lower-case letters
//        transform(s.begin(), s.end(), s.begin(), ::tolower);
//
//        if (!s.size()) continue; //skip numbers and punctuation signs
//
//        table[s].second++;  //if s is not in the table then it is inserted
//
//        count++;
//    }


    /******************************************************
    * PHASE 1: Display                                    *
    * - number of words in the text                       *
    * - number of unique words (occurring only once)      *
    * - frequency table                                   *
    *******************************************************/

    //ADD CODE
    cout << "Number of words in the file = " << counter << endl
         << "Number unique words in the file = " << table.size() << endl;

    cout << endl << endl << endl
         << "Frequency table sorted alphabetically..." << endl << endl;

    BiIterator it = table.begin();

    cout << "  \tKEY" << "\tCOUNTER" << endl;
    cout << "==============================\n";

    for( ; it != table.end(); it++)
    {
        cout << setw(15) << it->first
             << setw(12) << it->second << endl;
    }

    /******************************************************
    * PHASE 3: remove all words with counter 1            *
    *          and display table again                    *
    *******************************************************/
//    string wait;
//    getline(cin, wait);
    //ADD CODE
    vector<string> to_remove;

    BiIterator it_remove = table.begin();
    for( ; it_remove != table.end(); it_remove++)
    {
        if(it_remove->second == 1)
        {
            to_remove.push_back(it_remove->first);
        }
    }

    for(int i = 0; i < to_remove.size(); i++)
    {
        cout << to_remove.at(i) << endl;
        table.remove(to_remove.at(i));
    }

    cout << endl << endl << "Number of words after remove: " << table.size();

    cout << endl << endl << endl
         << "Frequency table sorted alphabetically..." << endl << endl;

    BiIterator it_new = table.begin();

    cout << "  \tKEY" << "\tCOUNTER" << endl;
    cout << "==============================\n";

    for( ; it_new != table.end(); it_new++)
    {
        cout << setw(15) << it_new->first
             << setw(12) << it_new->second << endl;
    }
    /***********************************************************
    * PHASE 4: request two words to the user w1 and w2         *
    *          then display all words in the interval [w1,w2]  *
    ************************************************************/

    //ADD CODE
    string w1, w2;
    cout << "Please give me a starting word: ";
    cin >> w1;
    if(table.find(w1) == table.end())
    {
        cout << "Does not exist";
        return 0;
    }
    cout << endl << "Please give me an ending word: ";
    cin >> w2;
    if(table.find(w2) == table.end())
    {
        cout << "Does not exist";
        return 0;
    }

    cout << endl << endl << endl
         << "Frequency table in [" << w1 << "," << w2 << "]" << endl << endl;

    BiIterator interval = table.find(w1);

    cout << "  \tKEY" << "\tCOUNTER" << endl;
    cout << "==============================\n";
    for( ; interval != table.find(w2); interval++)
    {
        cout << setw(15) << interval->first
             << setw(12) << interval->second << endl;
    }

    return 0;
}
