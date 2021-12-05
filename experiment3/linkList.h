//
// Created by lieying on 2021/10/3.
//

#ifndef EXPERIMENT3_LINKLIST_H
#define EXPERIMENT3_LINKLIST_H

#include <iostream>

class linkList {
    private:
        struct node{
            int value;
            node *next = nullptr;
        };
        node *head = new node;
        node *tail = nullptr;
        int length=0;

    public:
        linkList();
        linkList(int *a, int length);
        ~linkList();
        void creat(int a[],int length);
        bool insert(int i, int e);
        bool del(int i,int &e);
        void print();
        int getLength();
        bool isEmpty();
        int getElem(int i);
        void deleteAll();
        bool reverse();
        void sort();
        //void mergeTwoLists(linkList &La,int lengthA, linkList &Lb,int lengthB);
};


#endif //EXPERIMENT3_LINKLIST_H
