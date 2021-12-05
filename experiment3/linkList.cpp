//
// Created by lieying on 2021/10/3.
//

#include "linkList.h"

linkList::linkList() {
    tail = head;
    length = 0;
}

linkList::linkList(int a[], int length) {
    tail = head;
    this->length = 0;
    for (int i = 0; i < length; i++) {
        tail->next = new node;
        tail = tail->next;
        tail->value=*(a+i);
        this->length++;
    }
}

linkList::~linkList() {
    node *cache = head;
    node *temp = nullptr;
    for (int i = 0; cache != nullptr; i++) {
        temp = cache->next;
        delete cache;
        cache = temp;
    }
    this->tail = head;
    this->length = 0;
}

void linkList::creat(int *a,int length) {
    for (int i = 0; i < length; i++) {
        tail->next = new node;
        tail = tail->next;
        tail->value=*(a+i);
        this->length++;
    }
}

bool linkList::insert(int i, int e) {
    if(i > length) {
        return false;
    }
    if (head->next == nullptr) {
        head->next = new node;
        head->next->value = e;
        length++;
        return true;
    }
        node *temp = head->next;
        for (int j = 0; j < i-2; j++) {
            temp = temp->next;
        }
        node *cache = new node;
        cache->next = temp->next;
        temp->next = cache;
        cache->value = e;
        this->length++;
        return true;
}

bool linkList::del(int i,int &e) {
    if(i > length) {
        return false;
    }
    node *temp = head->next;
    for (int j = 0; j < i-1; j++) {
        temp = temp->next;
    }
    e = temp->value;
    node *cache = head->next;
    for (int j = 0; j < i-2; j++) {
        cache = cache->next;
    }
    cache->next = temp->next;
    delete temp;
    length--;
    return true;
}

void linkList::print() {
    if (0 == this->length) {
        std::cout<<"链表为空"<<std::endl;
        std::cout<<"---------------------"<<std::endl;
        return;
    }
    node *cache = head->next;
    std::cout<<"打印： ";
    for (int i = 0; cache != nullptr; i++) {
        std::cout<<cache->value<<" ";
        cache = cache->next;
    }
    std::cout<<std::endl;
    std::cout<<"---------------------"<<std::endl;
}

int linkList::getLength() {
    return length;
}

bool linkList::isEmpty() {
    if (0 != length){
        return false;
    }
    return true;
}

int linkList::getElem(int i) {
    if (i > length || i <= 0){
        throw 1;
    }
    node *cache = head->next;
    for (int j = 0; j < i-1; j++) {
        cache = cache->next;
    }
    return cache->value;
}

void linkList::deleteAll() {
    node *cache = head;
    node *temp;
    for (int i = 0; cache != nullptr; i++) {
        temp = cache->next;
        delete cache;
        cache = temp;
    }
    head = nullptr;
    tail = head;
    this->length = 0;
}

bool linkList::reverse() {
    node *cache = head->next;
    node *temp1 = nullptr;
    node *temp2 = cache->next;
    if (head->next == tail) return true;
    tail = head->next;
    while (true){
        cache->next = temp1;
        temp1 = temp2->next;
        temp2->next = cache;
        if (temp1 == nullptr){
            head->next = temp2;
            break;
        }
        cache = temp1->next;
        temp1->next = temp2;
        if (cache == nullptr){
            head->next = temp1;
            break;
        }
        temp2 = cache->next;
        if (temp2 == nullptr){
            head->next = cache;
            break;
        }
    }
}

void linkList::sort() {
    int *a,*b,temp;
    node *pb;
    pb = head->next;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length-1-i; j++) {
            a = &pb->value;
            b = &pb->next->value;
            if (*a > *b){
                temp = *b;
                *b = *a;
                *a = temp;
            }
            pb = pb->next;
        }
        pb = head->next;
    }
}
