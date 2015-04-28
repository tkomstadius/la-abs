#include <assert.h>
#include <iomanip>

#include "hashTable.h"

const double MAX_LOAD_FACTOR = 0.5;

//Test if a number is prime
bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}


//Return a prime number at least as large as n
int nextPrime( int n )
{
    if( n % 2 == 0 )
        n++;

    for(; !isPrime( n ); n += 2 );

    return n;
}


// Constructor
// IMPLEMENT
HashTable::HashTable(int table_size, HASH f)
    : size(nextPrime(table_size)), h(f), nItems(0)
{
    hTable = new Item*[size];
    empty_array(size);
}


//destructor
// IMPLEMENT
HashTable::~HashTable()
{
    for(int i = 0; i < size; i++)
    {
        delete hTable[i];
    }
    delete[] hTable;
}


//Return the load factor of the table
double HashTable::loadFactor() const
{
    return (double) nItems / size;
}


//Return the value associated with key
//If key does not exist in the table then NOT_FOUND is returned
// IMPLEMENT
int HashTable::find(string key) const
{
    int found = getIndex(key);
    if(found == NOT_FOUND)
    {
        return NOT_FOUND;
    }
    else
    {
        return hTable[found]->value;
    }
}


//Insert the Item (key, v) in the table
//If key already exists in the table then change the associated value to v
//Re-hash if the table becomes 50% full
// IMPLEMENT
void HashTable::insert(string key, int v)
{
    int index = h(key, size);
    bool inserted = false;
    while(!inserted)
    {
        if(!hTable[index] || hTable[index] == Deleted_Item::get_Item())
        {
            hTable[index] = new Item(key, v);
            nItems++;
            inserted = true;

            if(loadFactor() >= MAX_LOAD_FACTOR)
            {
                reHash();
            }
        }
        else if(hTable[index]->key == key)
        {
            hTable[index]->value = v;
            index = size;
            inserted = true;
        }
        index++;
        if(index == size)
        {
            index = 0;
        }
    }
}


//Remove Item with key
//If an Item with key belongs to the table then return true,
//otherwise, return false
// IMPLEMENT
bool HashTable::remove(string key)
{
    bool one_turn = false;
    int index = h(key, size);
    while(index < size)
    {
        if(!hTable[index])
        {
            return false;
        }
        else if(hTable[index]->key == key)
        {
            delete hTable[index];
            hTable[index] = Deleted_Item::get_Item();
            nItems--;
            return true;
        }
        index++;
        if(index == size && !one_turn)
        {
            index = 0;
            one_turn = true;
        }

    }
    return false; //to be deleted
}


void HashTable::display(ostream& os)
{
    if (!hTable) return;

    os << "-------------------------------\n";

    for (int i = 0; i < size; ++i)
    {
        os << setw(6) << i << ": ";

        if (!hTable[i])
        {
            os << "null" << endl;
        }
        else
        {
            string key = hTable[i]->key;

            os << "key = " << "\"" << key << "\""
               << setw(12) << "value = " << hTable[i]->value
               << "  (" << h(key,size) << ")" << endl;
        }
    }

    os << endl;
}


//Display the table to stream os
// IMPLEMENT
ostream& operator<<(ostream& os, const HashTable& T)
{
    if(!T.hTable)
    {
        return os;
    }

    for(int i = 0; i < T.size; i++)
    {
        if(T.hTable[i] && T.hTable[i] != Deleted_Item::get_Item())
        {
            os << "key = " << left << setw(20) << T.hTable[i]->key
            << left << "value = " << T.hTable[i]->value << endl;
        }
    }
    return os;
}

//Private member functions

//Rehashing function
// IMPLEMENT
void HashTable::reHash()
{
    cout << "Rehashing ..." << endl;

    Item** temp_table = new Item*[size];
    int old_size = size;
    save_values(temp_table, old_size);

    size = nextPrime(size*2);
    nItems = 0;
    hTable = new Item*[size];
    empty_array(size);

    for(int i = 0; i < old_size; i++)
    {
        if(temp_table[i] && temp_table[i] != Deleted_Item::get_Item())
        {
            insert(temp_table[i]->key, temp_table[i]->value);
        }
    }

    cout << "New size = " << size << endl;

}

void HashTable::empty_array(int e)
{
    for(int i = 0; i < e; i++)
    {
        hTable[i] = nullptr;
    }
}

void HashTable::save_values(Item** table, int s)
{
    for(int i = 0; i < s; i++)
    {
        table[i] = hTable[i];
    }
}

int HashTable::getIndex(string k) const
{
    int index = h(k, size);

    while(index < size)
    {
        if(!hTable[index])
        {
            return NOT_FOUND;
        }
        else if(hTable[index]->key == k)
        {
            return index;
        }
        index++;
        if(index == size)
        {
            index = 0;
        }
    }
    return NOT_FOUND;
}

int  &HashTable::operator[](string key)
{
    int place = getIndex(key);
    if(place == NOT_FOUND)
    {
        insert(key);
        place = getIndex(key);
    }
    return hTable[place]->value;
    //TODO: what if it is not in there?
}
