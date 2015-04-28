/**********************************************
* File: BiIterator.h                          *
* Author: Aida Nordman                        *
* Course: TND004, Lab 2                       *
* Date: VT2, 2014                             *
* Description: class biIterator               *
* Represents bidirectional iterators          *
***********************************************/

#ifndef BIITERATOR_H
#define BIITERATOR_H

#include <iostream>

#include "node.h"

using namespace std;


/** \brief Class to represent a bi-directional iterator for threaded BSTs.
 *
 * Bi-directional iterators can be moved in both directions, towards the first and towards the last node.
 */
//Class to represent a bi-directional iterator for threaded BSTs.
//Bi-directional iterators can be moved in both directions.
class BiIterator
{
    public:

        /** \brief Constructor.
        *
        * \param ptr pointer to the node to which the iterator should be pointing.
        *
        */
        // Constructor
        BiIterator(Node *ptr);


        /** \brief Dereferencing operator.
        *
        * \return Reference to the element stored by the node pointed by this iterator.
        *
        */
        //Dereferencing operator
        //IMPLEMENT
        ELEMENT& operator*() const;


        /** \brief Member access operator.
        *
        * \return Pointer to the element stored by the node pointed by this iterator.
        *
        */
        //Member access operator
        //IMPLEMENT
        ELEMENT* operator->() const;


        /** \brief Equality comparison operator.
        *
        * \param it reference to the rhs iterator of the comparison.
        * \return true, if this iterator and it point to the same node. Otherwise, return false.
        *
        */
        //Equality comparison operator
        //IMPLEMENT
        bool operator==(const BiIterator &it) const;


        /** \brief Inequality comparison operator.
        *
        * \param it reference to the rhs iterator of the comparison.
        * \return true, if this iterator and it point to different nodes. Otherwise, return false.
        *
        */
        //Inequality comparison operator
        //IMPLEMENT
        bool operator!=(const BiIterator &it) const;


        /** \brief Pre-increment operator.
        *
        * Advance the iterator to point to the next node in the inorder traversal.
        * \return This iterator, after advancing the internal pointer.
        *
        */
        //Pre increment operator
        //IMPLEMENT
        BiIterator& operator++();


        /** \brief Pos-increment operator.
        *
        * Advance the iterator to point to the next node in the inorder traversal.
        * \return (A copy of) this iterator, before advancing the internal pointer.
        *
        */
        //Pos increment operator: see page 277 and 278 of C++ direkt
        //IMPLEMENT
        BiIterator operator++(int);


        /** \brief Pre-decrement operator.
        *
        * Make the iterator to point to the previous node in the inorder traversal.
        * \return This iterator, after updating the internal pointer.
        *
        */
        //Pre decrement operator
        //IMPLEMENT
        BiIterator& operator--();


        /** \brief Pos-decrement operator.
        *
        * Make the iterator to point to the previous node in the inorder traversal.
        * \return (A copy of) this iterator, before updating the internal pointer.
        *
        */
        //Pos decrement operator
        //IMPLEMENT
        BiIterator operator--(int);

    private:
        Node* current;  /**< pointer to a Node of a threaded BST */

};

#endif
