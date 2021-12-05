//
// Created by lieying on 2021/10/6.
//

#ifndef EXPERIMENT3_CLINKLIST_H
#define EXPERIMENT3_CLINKLIST_H

#include <iostream>

class CLinkList {
private:
    struct node{
        int value;
        node *next = nullptr;
    };
    node *head = new node;
    int length=0;

public:
    CLinkList(int *a, int length);
    ~CLinkList();
    bool insert(int i, int e);
    bool del(int i,int &e);
    void print();
};


#endif //EXPERIMENT3_CLINKLIST_H
