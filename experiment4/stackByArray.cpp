//
// Created by lieying on 2021/10/16.
//

#include "stackByArray.h"

stackByArray::stackByArray(int maxSize) {
    stack = new int[maxSize];
    this->maxSize = maxSize;
    top = stack+maxSize;
}

stackByArray::~stackByArray() {

}

int stackByArray::getTop() {
    return *top;
}

void stackByArray::push(int e) {
    if (top == stack) {
        std::cout<<"栈满"<<std::endl;
        throw -1;
    }
    top--;
    *top = e;
    size++;
}

int stackByArray::pop() {
    if (top == stack+maxSize){
        std::cout<<"空栈"<<std::endl;
        throw -1.0;
    }
    int e = *top;
    top++;
    size--;
    return e;
}

void stackByArray::emptyStack() {
    delete stack;
    top = nullptr;
    maxSize = 0;
}

bool stackByArray::isEmpty() {
    if (0 == maxSize){
        return true;
    }
    return false;
}

bool stackByArray::isFull() {
    if (top == stack+0){
        return true;
    }
    return false;
}

void stackByArray::print() {
    int *temp = top;
    for (int i = 0; i < size; i++) {
        int e = *temp;
        std::cout<<e<<std::endl;
        temp++;
    }

}
