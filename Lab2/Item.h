/*
  Name: hashTable.h
  Author: Aida Nordman
  Course: TND004, Lab 2
  Description: class Item
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <new>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class HashTable;


/** \brief Class to represent an item stored in the hash table
 *
 * item = (key,value)
 */
class Item
{
protected:

    /** \brief Constructor to create an item
    *
    * \param k item's key
    * \param v value associated with key k
    *
    */
    //Constructor to create an item given a key k and a value v
    explicit Item(string k, int v = 0)
        : key(k) , value(v) {  };

    //data members
    const string key; /**< key */
    int value;       /**< value associated with the key, e.g. counter */

    friend class HashTable;
    friend ostream& operator<<(ostream& os, const HashTable& T);
};



/** \brief Class to represent a deleted item
 *
 * An instance of this class is used to mark deleted slots of the hash table
 */
class Deleted_Item: public Item
{
public:

    /** \brief Get the item used to mark delete slots
     *
     * \return Pointer to a the item used to mark deleted entries in the table
     *
    */
    static Deleted_Item *get_Item();

private:

    static Deleted_Item *entry; /**< Only one instance of the class is needed to mark deleted slots of the table*/


    /** \brief Default constructor
    *
    * Creates an item = (key = "", value = -1)
    *
    */
    //Constructor
    Deleted_Item() //only member functions can create class instances
        : Item("", -1) { };

};

#endif
