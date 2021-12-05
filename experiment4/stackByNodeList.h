//
// Created by lieying on 2021/10/17.
//

#ifndef EXPERIMENT4_STACKBYNODELIST_H
#define EXPERIMENT4_STACKBYNODELIST_H

#include <iostream>
#include <math.h>

class stackByNodeList {
private:
    struct node{
        int value = 0;
        node *next = nullptr;
    };
    node *top = nullptr;
    int size=0;

public:
    stackByNodeList();
    ~stackByNodeList();
    int getTop();
    void push(int e);
    int pop();
    void emptyStack();
    bool isEmpty();
    void print();
    int getSize();
};


#endif //EXPERIMENT4_STACKBYNODELIST_H
