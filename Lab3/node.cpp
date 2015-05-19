/**********************************************
* File: node.cpp                              *
* Author: Aida Nordman                        *
* Course: TND004, Lab 3                       *
* Date: VT2, 2014                             *
* Description: class Node                     *
***********************************************/

#include "node.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS


Node::Node(ELEMENT v, Node *l, Node *r)
 : value(v), left(l), right(r)
{
    l_thread = r_thread = false;
}


//Destructor
//recursively deletes the nodes in the left_subtree and right-subtree
Node::~Node()
{
    if(!this->l_thread)
    {
        delete this->left;
    }
    if(!this->r_thread)
    {
        delete this->right;
    }
}


//Insert v in the tree having as root this node
//Return true, if v was inserted
//Otherwise, return false --v already exists in the tree
bool Node::insert(ELEMENT v)
{
    //this = root of the subtree
    if(v.first < this->value.first)
    {
        if(this->l_thread)
        {
            Node *temp_parent = this->left;
            this->left = new Node(v, temp_parent, this);
            this->left->l_thread = this->left->r_thread = true;
            this->l_thread = false;
            return true;

        }
        else
        {
            return this->left->insert(v);
        }
    }
    else if(v.first > this->value.first)
    {
        if(this->r_thread)
        {
            Node *temp_parent = this->right;
            this->right = new Node(v, this, temp_parent);
            this->right->l_thread = this->right->r_thread = true;
            this->r_thread = false;
            return true;
        }
        else
        {
            return this->right->insert(v);
        }
    }
    else
    {
        return false;
    }
}



//Remove the key from the tree having as root this node
//Return true, if a node storing key was found and deleted
//Otherwise, return false -- there is no node storing key
//isRight==false: this node is left child of parent
//isRight==true: this node is right child of parent
bool Node::remove(string key, Node* parent, bool isRight)
{
    if(key < this->value.first)
    {
        if(this->l_thread)
        {
            return false;
        }
        else
        {
            return this->left->remove(key, this, false);
        }
    }
    else if(key > this->value.first)
    {
        if(this->r_thread)
        {
            return false;
        }
        else
        {
            return this->right->remove(key, this, true);
        }
    }
    else
    {
        if(!this->l_thread && !this->r_thread)
        {
            this->value = this->right->findMin()->value;
            return this->right->remove(value.first, this, true);
        }
        else
        {
            this->removeMe(parent, isRight);
            return true;
        }
    }


}



//Remove this node -- this node has at most one child
//isRight==false: this node is left child of parent
//isRight==true: this node is right child of parent
//Remove has 6 cases
//1a: a left child with only a right child
//1b: a left child with only a left child
//1c: a left child with no children
//2a: a right child with only a right child
//2b: a right child with only a left child
//2c: a right child with no children
void Node::removeMe(Node* parent, bool isRight)
{
   if(isRight) //this node is right child of parent
   {
       //right child with only a right child
       if(!this->r_thread)
       {
           //cout << "2a";
           parent->right = this->right;
           this->right->findMin()->left = parent;
           this->right = nullptr;
       }
       //right child with only a left child
       else if(!this->l_thread)
       {
           //cout << "2b";
           parent->right = this->left;
           this->left->findMax()->right = this->right;
           this->left = nullptr;
       }
       else
       {
           //cout << "2c";
           parent->r_thread = true;
           parent->right = this->right;
       }
   }
   else //this node is left child of parent
   {
       //left child with only a right child
       if(!this->r_thread)
       {
           //cout << "1a";
           parent->left = this->right;
           this->right->findMin()->left = this->left;
           this->right = nullptr;
       }
       //left child with only left child
       else if(!this->l_thread)
       {
           //cout << "1b";
           parent->left = this->left;
           this->left->findMax()->right = parent;
           this->left = nullptr;
       }
       //left child with no children
       else
       {
           //cout << "1c";
           parent->l_thread = true;
           parent->left = this->left;
       }

   }
   delete this;
}



//Return a pointer to the Node storing key
//key is possibly stored in one of the sub-trees of this node
//If there is no node storing key then return nullptr
Node* Node::find(string key)
{
    if(key < this->value.first)
    {
        //left
        if(this->l_thread)
        {
            return nullptr;
        }
        else
        {
            return this->left->find(key);
        }
    }
    else if(key > this->value.first)
    {
        //right
        if(!this->r_thread)
        {
            return this->right->find(key);
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        return this;
    }
}


//Return a pointer to the node storing the smalest value
//of the tree whose root is this node
Node* Node::findMin()
{
    Node* n = this;
    while(!n->l_thread)
        n = n->left;
    return n;
}


//Return a pointer to the node storing the largest value
//of the tree whose root is this node
Node* Node::findMax()
{
    Node* n = this;
    while(!n->r_thread)
        n = n->right;
    return n;
}



//Display in inorder all keys
//stored in the tree whose root is this node
//recursive function
//Used for debugging -- ONLY
void Node::display() const
{
    if ( !l_thread ) //display left sub-tree
        left->display();

    cout << value.first << " "; //display key stored in the node

    if ( !r_thread ) //display right sub-tree
        right->display();
}


#endif /* DOXYGEN_SHOULD_SKIP_THIS */
