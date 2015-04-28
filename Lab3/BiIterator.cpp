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
    //ADD CODE
}


//Member access operator
ELEMENT* BiIterator::operator->() const
{
    //ADD CODE
    return nullptr;
}


//Equality comparison operator
bool BiIterator::operator==(const BiIterator &it) const
{
    //ADD CODE
    return false;
}


//Inequality comparison operator
bool BiIterator::operator!=(const BiIterator &it) const
{
   //ADD CODE
    return false;
}


//Pre increment operator
BiIterator& BiIterator::operator++()
{
   //ADD CODE
    return *this;
}



//Pos increment operator: see page 277 and 278 of C++ direkt
BiIterator BiIterator::operator++(int)
{
   //ADD CODE
    return *this;
}

//Pre decrement operator
BiIterator& BiIterator::operator--()
{
   //ADD CODE
    return *this;
}

//Pos decrement operator
BiIterator BiIterator::operator--(int)
{
   //ADD CODE
    return *this;
}

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
