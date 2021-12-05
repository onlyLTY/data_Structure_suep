//
// Created by lieying on 2021/10/17.
//

#include "stackByNodeList.h"

stackByNodeList::stackByNodeList() {
}

stackByNodeList::~stackByNodeList() {
}

int stackByNodeList::getTop() {
    int e = top->value;
    return e;
}

void stackByNodeList::push(int e) {
    if (0 == size){
        top = new node;
        top->value = e;
        size++;
    } else{
        node *temp = new node;
        temp->value = e;
        temp->next = top;
        top = temp;
        size++;
    }
}

int stackByNodeList::pop() {
    if (0 == size) {
        std::cout<<"空栈"<<std::endl;
        throw 1;
    }
    int e = top->value;
    node *temp = top;
    top = top->next;
    delete temp;
    size--;
    return e;
}

void stackByNodeList::emptyStack() {
    while (0 != size){
        node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }
}

bool stackByNodeList::isEmpty() {
    if (0 != size){
        return false;
    } else{
        return true;
    }
}

void stackByNodeList::print() {
    node *temp = top;
    int a = size;
    while (0 != a){
        std::cout<<temp->value<<std::endl;
        temp = temp->next;
        a--;
    }
}

int stackByNodeList::getSize() {
    return size;
}
