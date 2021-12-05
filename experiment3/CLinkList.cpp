//
// Created by lieying on 2021/10/6.
//

#include "CLinkList.h"

CLinkList::CLinkList(int a[], int length) {
    head->next = new node;
    node *temp = head;
    this->length = 0;
    for (int i = 0; i < length; i++) {
        temp->next = new node;
        temp = temp->next;
        temp->value=*(a+i);
        this->length++;
    }
    temp->next = head;
}

CLinkList::~CLinkList() {
    node *cache = head->next;
    delete head;
    head = nullptr;
    node *temp = nullptr;
    for (int i = 0; i<length; i++) {
        temp = cache->next;
        delete cache;
        cache = temp;
    }
    this->length = 0;
}

bool CLinkList::insert(int i, int e) {
    if(i > length){
        return false;
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

bool CLinkList::del(int i, int &e) {
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

void CLinkList::print() {
    if (0 == this->length) {
        std::cout<<"链表为空"<<std::endl;
        std::cout<<"---------------------"<<std::endl;
        return;
    }
    node *cache = head->next;
    std::cout<<"打印： ";
    while (cache != head) {
        std::cout<<cache->value<<" ";
        cache = cache->next;
    }
    std::cout<<std::endl;
    std::cout<<"---------------------"<<std::endl;
}
