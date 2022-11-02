// Name: Scott Kang
// Email: kyung.ho.kang@vanderbilt.edu
// VUnetid: kangk
// Class: CS2201
// Date: 2019 10/22
// Honor statement: I have not given or received unauthorized aid on this assignment
// Description:  This program tests the DblStack class.

#include <iostream>
#include <string>
#include <cstdlib>
#include "DblStack.h"

int main()
{
    std:: cout << "test Dblstack" << std::endl;

    // check if initial stack has size == 0 and is empty

    DblStack test1;
    if(test1.size() != 0){
        std::cout << "size does not work" << std:: endl;
    }

    if(test1.isEmpty()){
        std::cout << "isEmpty does not work" << std:: endl;
    }

    // test pushing one item into the stack
    // check if top works

    test1.push(33.0);

    if(test1.size() != 1){
        std::cout << "failed to push" << std:: endl;
    }

    if(test1.top() != 33.0){
        std::cout << "failed to top" << std:: endl;
    }

    // test pushing another item into the stack

    test1.push(45.0);
    if(test1.size() != 2){
        std::cout << "failed to push" << std:: endl;
    }

    if(test1.top() != 45.0){
        std::cout << "failed to top" << std:: endl;
    }

    // test copy constructor

    DblStack test2(test1);

    DblStack test3;
    test3 = test2;

    if(test2.top() != 45.0){
        std::cout << "failed copy constructor " << std:: endl;
    }

    test2.pop();

    if(test2.top() != 33.0){
        std::cout << "failed copy constructor" << std:: endl;
    }

    if(test2.size() != 1){
        std::cout << "failed to pop" << std:: endl;
    }

    // test assignment operator

    if(test3.top() != 45.0){
        std::cout << "failed copy constructor " << std:: endl;
    }

    test3.pop();

    if(test3.top() != 33.0){
        std::cout << "failed copy constructor" << std:: endl;
    }

    if(test3.size() != 1){
        std::cout << "failed to pop" << std:: endl;
    }

    std:: cout << "test done" << std::endl;

    test3.pop();

    // test pushing multiple items into the stack

    test3.push(1);
    test3.push(2);
    test3.push(3);
    test3.push(4);

    if(test3.top() != 4){
        std::cout << "failed to top" << std:: endl;
    }

    if(test3.size() != 4){
        std::cout << "failed to push correctly" << std:: endl;
    }

    test3.pop();

    if(test3.top() != 3){
        std::cout << "failed to top" << std:: endl;
    }

    test3.pop();

    if(test3.top() != 2){
        std::cout << "failed to top" << std:: endl;
    }

}