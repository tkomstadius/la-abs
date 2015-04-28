/********************************************************
* File: threaded_BST.h                                  *
* Author: Aida Nordman                                  *
* Course: TND004, Lab 3                                 *
* Date: VT2, 2014                                       *
* Description: class BST_threaded representing          *
*              a threaded binary search tree            *
*********************************************************/

#ifndef BST_THREADED_H
#define BST_THREADED_H


#include "node.h"
#include "BiIterator.h"

#include <iostream>

using namespace std;

/****************************
* Class: BST_threaded       *
****************************/

/** \brief Class to represent a threaded binary search tree (BST).
 *
 * Every node of the tree stores an ELEMENT that is a pair <word, counter>.
 * The word is the search key.
 */
 //Class to represent a threaded binary search tree (BST)
 //Every node of the tree stores an ELEMENT that is pair <word, counter>
class BST_threaded
{
    public:

    /** \brief Default constructor.
    *
    * Create an empty BST. An empty tree has always a dummy node.
    *
    */
    //Default Constructor: create an empty tree
    //Empty tree has one dummy node
    //IMPLEMENT
    BST_threaded();

    /** \brief Destructor.
    *
    * Delete all nodes in the BST, including the dummy node.
    *
    */
    //destructor
    //IMPLEMENT
    ~BST_threaded();


    /** \brief Test whether the BST is empty.
    *
    * \return true, if no keys are stored in the BST. Otherwise, return false.
    *
    */
    //Test if the tree is empty
     //IMPLEMENT
    bool empty() const;


    /** \brief Get number of keys (ELEMENTS) stored in the BST.
    *
    * \note Dummy node should not be counted.
    * \return Number of keys (ELEMENTS) stored in the BST.
    *
    */
    //Return mumber of keys (elements) stored in the tree
    //IMPLEMENT
    int size() const;


    /** \brief Insert element v in the BST.
    *
    * \note If a node storing v.first already exists in the BST then the tree is not modified.
    * \param v ELEMENT to be inserted.
    * \return None.
    *
    */
    //Insert v in the tree
    void insert(ELEMENT v);


    /** \brief Remove the node storing key from the BST.
    *
    * \param key string representing the value to be searched in the BST.
    * \return None.
    *
    */
    //Remove node with key from the tree
    //IMPLEMENT
    void remove(string key);


    /** \brief Subscript operator: search for the ELEMENT in the BST storing the index.
    *
    * If key does not match the key of any element in the container, then an ELEMENT (key,0) is inserted and a reference to it is returned.
    * \param key string to be used as index.
    * \return Reference to the ELEMENT storing the key.
    *
    */
    //If key matches the key of an element in the container,
    //then return a reference to the ELEMENT with the key
    //If key does not match the key of any element in the container,
    //then an ELEMENT (key,0) is inserted and a reference to it is returned
    //IMPLEMENT
    ELEMENT& operator[](string key);


    /** \brief Find the node in the BST storing key.
    *
    * \param key string representing the value to be searched.
    * \return A BiIterator referring to the node storing the key. Otherwise, return this->end().
    *
    */
    //Find the node in the BST storing key
    //Return a BiIterator referring to the node storing the key, if the key is found.
    //Otherwise, return this->end().
    //IMPLEMENT
    BiIterator find(string key) const;


    /** \brief Get a BiIterator referring to the first node in the inorder traversal of the BST.
    *
    * \return A BiIterator referring to the first node in the inorder traversal. If the tree is empty, return this->end().
    *
    */
    //Return an iterator referring to the first node in the inorder traversal of the BST
    //IMPLEMENT
    BiIterator begin() const;


    /** \brief Get a BiIterator referring to the past-the-end element in the BST.
    *
    * \return A BiIterator referring to the past-the-end element in the BST.
    *
    */
    //Return a BiIterator referring to the past-the-end element in the BST
    BiIterator end() const;


    /** \brief Display the key stored in each node, using inorder traversal of the BST.
    *
    * \return None.
    *
    */
    //Display all keys increasingly
    //To be used for debugging -- ONLY
    void display() const;

    private:

    //Pointer to the dummy root node of the tree
    Node *root; /**< Pointer to the dummy root node of the tree. */

    //count number of elements stored in the tree
    int counter; /**< Number of keys stored in the tree. */

    /** \brief Disabled copy constructor.
    *
    */
    //Disable copy constructor
    BST_threaded(const BST_threaded &source);


    /** \brief Disabled assignment operator.
    *
    */
    //Disable assignment operator
    const BST_threaded& operator=(const BST_threaded &T);

};


/** \brief Just a simpler name (alias) for BST_threaded
*
*\note A map container is usually implemented with a threaded binary search tree.
*
*/
typedef BST_threaded MAP; //just a simpler name for BST_threaded


#endif
