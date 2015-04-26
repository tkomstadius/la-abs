/*
  Name: hashTable.h
  Author: Aida Nordman
  Course: TND004, Lab 2
  Description: class HashTable represents an open addressing hash table
              (also known as closed_hashing) with linear probing
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "item.h"

#include <iostream>

using namespace std;

const int NOT_FOUND = -1;


/** \brief Class to represent an open addressing hash table using linear probing to resolve collisions
 *
 * Internally the table is represented as an array of pointers to Items
 */
//Class to represent a linear probing hash table
class HashTable
{
public:

    /** \brief Pointer to an hash function
     *
    */
    typedef unsigned (*HASH)(string, int); //new type HASH: pointer to a hash function


    /** \brief Constructor to create a hash table
     *
     * \param table_size number of slots in the table (note: next prime number can be used)
     * \param f hash function
     *
    */
    // Constructor
    // IMPLEMENT
    HashTable(int table_size, HASH f);


    /** \brief Destructor
     *
     * Deallocate all memory used for the table
     *
    */
    //destructor
    // IMPLEMENT
    ~HashTable();


     /** \brief Calculate load factor of the table, i.e. percentage of slots in use
      *
      * \return load factor of the table
      *
    */
    //Return the load factor of the table
    double loadFactor() const;


    /** \brief Get the number of items stored in the table
      *
      * \return number of items stored in the table
      *
    */
    //return number of items stored in the table
    int get_number_OF_items() const
    {
        return nItems;
    }



    /** \brief Search an item in the table
      *
      * \param key of the item to be found
      * \return The value associated with key.
      * If the key is not found in the table then the constant NOT_FOUND is returned
      *
    */
    //Return the value associated with key
    //If key does not exist in the table then NOT_FOUND is returned
    // IMPLEMENT
    int find(string key) const;



    /** \brief Insert an item in the table
      *
      * \param key of the item to be inserted
      * \param v value associated with key
      *
    */
    //Insert the Item (key, v) in the table
    //If key already exists in the table then change the associated value to v
    //Re-hash if the table becomes 50% full
    // IMPLEMENT
    void insert(string key, int v = 0);


    /** \brief Remove an item from the table
      *
      * \param key of the item to be removed
      * \return true if an item with key was found.
      * Otherwise, return false
      *
    */
    //Remove Item with key
    //If an Item with key belongs to the table then return true,
    //otherwise, return false
    // IMPLEMENT
    bool remove(string key);

    int &operator[](string key);


    /** \brief Display all items in the table T
      *
      * \param os output stream where the table is displayed
      * \param T hash table
      *
    */
    //Display the table to stream os
    // IMPLEMENT
    friend ostream& operator<<(ostream& os, const HashTable& T);


    /** \brief Display all entries in the table
      *
      * This function is used for debugging and testing purposes
      * Thus, empty and deleted entries are also displayed
      * \param os output stream where the table is displayed
      *
    */
    //Display the table for debug and testing purposes
    void display(ostream& os);


private:
    //is okej to create private member functions
    //data members

    //number of slots in the table
    int size; /**< number of slots in the table, a prime number */

    //hash function
    const HASH h; /**< hash function */

    //number of items stored in the table
    int nItems; /**< number of items stored in the table */


    //Each slot of the table stores a pointer to an Item =(key, value)
    Item** hTable; /**< table is an array of pointers to Items */


     /** \brief Re-hash function
      *
      * This function is called when the load factor of the table gets to 50%
      *
    */
    //Rehashing function
    // IMPLEMENT
    void reHash();


    //disable copy constructor
    HashTable(const HashTable &);


    //disable assignment operator
    const HashTable& operator=(const HashTable &);

    //make nullptr
    void empty_array(int end);

    //save values for rehashing
    void save_values(Item** table, int s);

    //if the item is found, return the index
    int getIndex(string k) const;

};

#endif
