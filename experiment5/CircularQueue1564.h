//
// Created by lieyi on 2021/11/14.
//

#ifndef EXPERIMENT5_CIRCULARQUEUE1564_H
#define EXPERIMENT5_CIRCULARQUEUE1564_H

#include <iostream>

template<typename T>
class CircularQueue1564 {
    private:
        int size, flag = 0;
        T *head, *tail, *base, *end;
    public:
        CircularQueue1564(int size);
        ~CircularQueue1564();
        void insert(T a);
        int length();
        T pop();
        void print();
        void clear();
        bool isEmpty();
        T getHead();
};

template<typename T>
CircularQueue1564<T>::CircularQueue1564(int size) {
    this->size = size;
    base = new T[size];
    end = base + (size-1);
    head = base;
    tail = base;
}

template<typename T>
CircularQueue1564<T>::~CircularQueue1564() {

}

template<typename T>
void CircularQueue1564<T>::insert(T a) {
    if(tail == end+1) {
        tail = base;
        if (tail == head) head++;
    }
    *tail = a;
    tail++;
    flag++;
    if (flag > size) flag = size;
}

template<typename T>
int CircularQueue1564<T>::length() {
    return this->flag;
}

template<typename T>
T CircularQueue1564<T>::pop() {
    T temp = *head;
    head++;
    flag--;
    return temp;
}

template<typename T>
void CircularQueue1564<T>::print() {
    if (0 == flag){
        throw "queue is empty";
    }
    T *temp = head;
    for (int i = 0; i < flag; i++) {
        if(temp == end+1){
            temp = base;
        }
        std::cout<< *temp << " ";
        temp++;
    }
    std::cout<<std::endl;
}

template<typename T>
void CircularQueue1564<T>::clear() {
    for (int i = 0; i < size; i++) {
        head = base;
        base++;
        delete head;
    }
    head = tail = base = end =nullptr;
    flag = 0;
}

template<typename T>
bool CircularQueue1564<T>::isEmpty() {
    if (0 == flag){
        return true;
    } else {
        return false;
    }
}

template<typename T>
T CircularQueue1564<T>::getHead() {
    if (flag < 1) throw "queue is null";
    return *head;
}

#endif //EXPERIMENT5_CIRCULARQUEUE1564_H
