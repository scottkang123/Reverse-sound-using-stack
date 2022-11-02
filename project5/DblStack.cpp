// File name: DblStack.cpp
// Name: Scott Kang
// VUnetid: kangk
// Email: kyung.ho.kang@vanderbilt.edu
// Class:  CS 2201
// Assignment Number: #5
// Honor statement: I have not given or received unauthorized aid on this assignment
// Description:  Maintains a stack of ItemType.  Implements functions to
//     push, pop, retrieve top, and retrieve size of the stack.
// Last Changed: 2019 10/22

#include <cstddef>
#include <stdexcept>
#include "DblStack.h"


// TODO
// Define all the methods of the DblStack class here

// Class Constructor
// post: stack is created & initialized to be empty

DblStack :: DblStack(): myTop(nullptr), stackSize(0){

}

// Copy Constructor
// pre: parameter object, rhs, exists
// post: stack is created to be a copy of the parameter stack

DblStack :: DblStack(const DblStack& rhs): myTop(nullptr), stackSize(rhs.stackSize){

    if (rhs.myTop != nullptr) {
        myTop = new stack;
        myTop-> item = rhs.myTop-> item;
        myTop -> next = nullptr;

        stackNodePointer newPtr = myTop;

        //as long as the right stack does not reach the end, add a new node to the stack and copy the number

        for (stackNodePointer origPtr = rhs.myTop->next; origPtr != nullptr; origPtr = origPtr->next) {
            newPtr->next = new stack;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
            newPtr->next = nullptr;
        }
    }

}

// Class Deconstructor
// pre: the stack exists
// post: the stack is destroyed and any dynamic memory is returned to the system
DblStack :: ~DblStack(){

    stackSize = 0;

    // delete all the ItemType

    while (myTop != nullptr) {
        stackNodePointer temp = myTop;
        myTop = myTop->next;
        delete temp;
    }

}

// Assignment operator
// Assigns a stack to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const DblStack& DblStack :: operator= (const DblStack& rhs){

    if (this != &rhs) {
        DblStack temp(rhs);
        std::swap(myTop, temp.myTop);
        std::swap(stackSize, temp.stackSize);
    }

    return *this;

}

// isEmpty
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
bool DblStack :: isEmpty() const{

    if(stackSize == 0){
        return true;
    }
    return false;

}

// push
// Pushes an item on top of the stack.
// pre:  Stack exists and item is passed.
// post: the item is placed on top of the stack, and size is incremented.

void DblStack :: push(const ItemType& item){

    // create a new nodeptr to store the item

    stackNodePointer newPtr = new stack;
    newPtr -> item = item;

    // insert the new node to the beginning of the linked list

    stackNodePointer cur = myTop;
    myTop = newPtr;
    newPtr -> next = cur;
    stackSize++;

}

// pop
// Pops the top item off the stack.
// pre:  Stack exists.
// post: Removes item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
void DblStack :: pop(){

    if(isEmpty()){
        throw std::underflow_error("The stack is empty");
    }else{
        stackNodePointer temp = myTop;
        myTop = temp -> next;
        delete temp;
        stackSize--;
    }

}

// top
// Returns the top item of the stack without popping it.
// pre:  Stack exists.
// post: Returns item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
ItemType DblStack :: top() const{
    if(isEmpty()){
        throw std::underflow_error("The stack is empty");
    }else{
        return myTop -> item;
    }
}

// size
// Returns the number of items on the stack.
// post: Returns size from the private section of class.
size_t DblStack :: size() const{

    return stackSize;

}