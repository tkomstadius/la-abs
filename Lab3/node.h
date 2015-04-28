/**********************************************
* File: node.h                                *
* Author: Aida Nordman                        *
* Course: TND004, Lab 3                       *
* Date: VT2, 2014                             *
* Description: class Node                     *
***********************************************/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <utility> //to use pair template

using namespace std;

/** \brief Type ELEMENT is a pair storing a string and a counter.
*
*/
//A pair to store a string and a counter
typedef pair<string,int> ELEMENT;
//Nodes of the BSTs store ELEMENTs


/****************************
* Class: Node               *
*****************************/


/** \brief Class Node
 *
 * Nodes of threaded binary search trees
 */
class Node
{
public:

    /** \brief Constructor.
    *
    * \param v an ELEMENT.
    * \param l pointer to left sub-tree.
    * \param r pointer to right sub-tree.
    *
    */
    Node(ELEMENT v, Node *l = nullptr, Node *r = nullptr);


    /** \brief Destructor.
    *
    * Delete all nodes in the left-subtree and in the right-subtree of this node.
    *
    */
    //IMPLEMENT
    ~Node();

private:
    //key is the first component of the pair
    ELEMENT value; /**< Pair stored in the node: first component is the search key.*/

    //sub-trees
    Node *left;   /**< left sub-tree */
    Node *right;  /**< right sub-tree */

    //thread flags
    bool l_thread;  /**< left thread flag */
    bool r_thread;  /**< right thread flag */


    /*******************************************
    * Auxiliary functions                      *
    * called by BST_threaded member functions  *
    ********************************************/


    /** \brief Insert v in the tree T, where T is the sub-tree with root this node.
    *
    * \note If a node storing v.first already exists in T then T is not modified.
    * \param v Element to be inserted in T.
    * \return true, if no node stores the key v.first. Otherwise, return false.
    *
    */
    //Insert v in the tree having as root this node
    //Return true, if v was inserted
    //Otherwise, return false --v already exists in the tree
    //IMPLEMENT
    bool insert(ELEMENT v);


    /** \brief Remove the node storing key from the tree T, where T is the sub-tree with root this node.
    *
    * \param key string representing the value to be searched in T.
    * \param parent pointer to the parent node of this node.
    * \param isRight bool: isRight==false, if this node is left child of parent; isRight==true, if this node is right child of parent.
    * \return true, if a node was removed. Otherwise, return false.
    *
    */
    //Remove the key from the tree having as root this node
    //Return true, if a node storing key was found and deleted
    //Otherwise, return false -- there is no node storing key
    //isRight==false: this node is left child of parent
    //isRight==true: this node is right child of parent
    //IMPLEMENT
    bool remove(string key, Node* parent, bool isRight);



    /** \brief Remove this Node.
    *
    * \pre this node has at most one child, i.e. either left or right sub-tree.
    * \param parent pointer to the parent node of this node.
    * \param isRight bool: isRight==false, if this node is left child of parent; isRight==true, if this node is right child of parent.
    * \note Remove has 6 cases
    *
    * \note 1a: a left child with only a right child
    *
    * \note 1b: a left child with only a left child
    *
    * \note 1c: a left child with no children
    *
    * \note 2a: a right child with only a right child
    *
    * \note 2b: a right child with only a left child
    *
    * \note 2c: a right child with no children
    *
    * \return None.
    *
    */
    //Remove this node -- this node has at most one child
    //isRight==false: this node is left child of parent
    //isRight==true: this node is right child of parent
    //IMPLEMENT
    void removeMe(Node* parent, bool isRight);


    /** \brief Find the node in tree T storing key, where T is the sub-tree with root this node.
    *
    * \param key string representing the value to be searched in T.
    * \return Pointer to the node in T storing key, if it exists. Otherwise, return nullptr.
    *
    */
    //Return a pointer to the Node storing key
    //key is possibly stored in one of the sub-trees of this node
    //If there is no node storing key then return nullptr
    Node* find(string key);


    /** \brief Find the node storing the smallest key in tree T, where T is the sub-tree with root this node.
    *
    * \return Pointer to the node storing the smallest key in tree T.
    *
    */
    //Return a pointer to the node storing the smallest value
    //of the tree whose root is this node
    //IMPLEMENT
    Node* findMin();


    /** \brief Find the node storing the largest key in tree T, where T is the sub-tree with root this node.
    *
    * \return Pointer to the node storing the largest key in tree T.
    *
    */
    //Return a pointer to the node storing the largest value
    //of the tree whose root is this node
    //IMPLEMENT
    Node* findMax();



    /** \brief Display the key stored in each node, using inorder traversal of tree T, where T is the sub-tree with root this node.
    *
    * \note Inorder traversal is used, recursively.
    * \return None.
    *
    */
    //Display in inorder all keys stored in the tree whose root is this node
    //Recursive function
    //Used for debugging -- ONLY
    void display() const;

    //count number of elements stored in the tree
    int counter; /**< Number of keys stored in the tree. */


    /** \brief Disabled copy constructor.
    *
    */
    //Disable copy constructor
    Node(const Node &source);


    /** \brief Disabled assignment operator.
    *
    */
    //Disable assignment operator
    const Node& operator=(const Node &N);

    friend class BST_threaded;
    friend class BiIterator;
};

#endif
