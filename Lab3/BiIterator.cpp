/**********************************************
* File: BiIterator.cpp                        *
* Author: Aida Nordman                        *
* Course: TND004, Lab 2                       *
* Date: VT2, 2014                             *
* Description: class biIterator               *
* Represents bidirectional iterators          *
***********************************************/


#include "BiIterator.h"


#ifndef DOXYGEN_SHOULD_SKIP_THIS


// Constructor
BiIterator::BiIterator(Node *ptr)
 : current(ptr)
 {

 }


//Dereferencing operator
ELEMENT& BiIterator::operator*() const
{
    return this->current->value;
}


//Member access operator
ELEMENT* BiIterator::operator->() const
{
    return &this->current->value;
}


//Equality comparison operator
bool BiIterator::operator==(const BiIterator &it) const
{
    if(this->current == it.current)
    {
        return true;
    }
    return false;
}


//Inequality comparison operator
bool BiIterator::operator!=(const BiIterator &it) const
{
    if(this->current != it.current)
    {
        return true;
    }
    return false;
}


//Pre increment operator
BiIterator& BiIterator::operator++()
{
    if(!this->current->r_thread) //then node has right subtree
    {
        //then current is leftmost of that right subtree
        this->current = this->current->right->findMin();
    }
    else
    {
        //follow the thread to the parent
        this->current = this->current->right;
    }
    return *this;
}



//Pos increment operator: see page 277 and 278 of C++ direkt
BiIterator BiIterator::operator++(int)
{
    BiIterator before(this->current);
    if(!this->current->r_thread) //if node has right subtree
    {
        //then next should be the leftmost of that right subtree
        this->current = this->current->right->findMin();
    }
    else
    {
        //else follow the thread to the parent
        this->current = this->current->right;
    }
    return before;
}

//Pre decrement operator
BiIterator& BiIterator::operator--()
{
    if(!this->current->l_thread) //if node has left subtree
    {
        //next node is the rightmost node of that subtree
        this->current = this->current->left->findMax();
    }
    else
    {
        //follow the left thread
        this->current = this->current->left;
    }
    return *this;
}

//Pos decrement operator
BiIterator BiIterator::operator--(int)
{
    BiIterator before(this->current);
    if(!this->current->l_thread) //if node has left subtree
    {
        //next node is the rightmost node of that subtree
        this->current = this->current->left->findMax();
    }
    else
    {
        //follow the left thread
        this->current = this->current->left;
    }
    return before;
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
