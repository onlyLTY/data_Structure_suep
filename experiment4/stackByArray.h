//
// Created by lieying on 2021/10/16.
//

#ifndef EXPERIMENT4_STACKBYARRAY_H
#define EXPERIMENT4_STACKBYARRAY_H

#include <iostream>
#include <random>

class stackByArray {

private:
    int *stack=nullptr, *top=nullptr;
    int size=0, maxSize=0;
public:
    stackByArray(int maxSize);
    ~stackByArray();
    int getTop();
    void push(int e);
    int pop();
    void emptyStack();
    bool isEmpty();
    bool isFull();
    void print();
};


#endif //EXPERIMENT4_STACKBYARRAY_H
