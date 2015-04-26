#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "hashTable.h"

using namespace std;

unsigned word_hash(const string key, int table_size)
{
    unsigned int hash_val = 0;

    for(char ch : key)
    {
        hash_val = 37 * hash_val + ch;
    }
    return hash_val % table_size;
}

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
       letter == ';')
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

int main()
{
    const int TABLE_SIZE = 200;
    HashTable table(TABLE_SIZE, word_hash);

    string file;
    string word;
    int num_words = 0;

    cout << "What is the name of your file? ";
    cin >> file;
    //read file
    ifstream read_file;
    read_file.open(file);

    while(read_file >> word)
    {
        change_word(word);
        table[word]++;
        num_words++;
    }
    read_file.close();

    cout << endl << "Number of words in the file = " << num_words
         << endl << "Number unique words in the file = "
         << table.get_number_OF_items() << endl << endl
         << "Frequency table ..." << endl << endl << table;

    return 0;
}
