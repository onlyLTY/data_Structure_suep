//
// Created by lieying on 2021/9/27.
//

#ifndef MAIN_CPP_LINEARTABLE_1564_H
#define MAIN_CPP_LINEARTABLE_1564_H
#include <iostream>
using namespace std;

const int maxSize = 100;
template<class T>
class linearTable_1564
{
    private:
        T* data;	//存放顺序表中的元素
        int length;	//存放顺序表的长度
    public:
        linearTable_1564();
        linearTable_1564(T a[], int length);//构造函数
        ~linearTable_1564();		//析构函数
        void creatList(T a[], int n);		//由a数组中的元素构造顺序表
        void printList();		//打印顺序表
        int getLength();	//求顺序表的长度
        bool getElem(int i, T&e);	//取顺序表中某个位置的值
        int locate(T e);			//按元素查找位置
        bool insert(int i, T e);	//向顺序表中插入数据
        bool delElem(int i);		//在位置i上删除顺序表中的元素
        void sort(linearTable_1564<T> &a);
        bool isEmpty(linearTable_1564<T> a);
};

template<class T>
linearTable_1564<T>::linearTable_1564()
{
    data = new T[maxSize];
    length = 0;
}

template<class T>
linearTable_1564<T>::linearTable_1564(T a[], int length) {
    int i;
    for (i = 0; i < length; i++)
    {
        data[i] = a[i];
        length = i+1;
    }
}

template<class T>
linearTable_1564<T>::~linearTable_1564()
{
    delete[]data;
}

template<class T>
void linearTable_1564<T>::creatList(T a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        data[i] = a[i];
        length = i+1;
    }
}

template<class T>
void linearTable_1564<T>::printList()
{
    cout << "打印顺序表:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " " ;
    }
}

template<class T>
int linearTable_1564<T>::getLength()
{
    return length;
}

template<class T>
bool linearTable_1564<T>::getElem(int i, T &e)
{
    if (i<0 || i>length)
        return false;
    e = data[i];
    return true;
}

template<class T>
int linearTable_1564<T>::locate(T e)
{
    int i = 0;
    while (i < length && i != e)
        i++;
    if (i >= length)
        return 0;
    else
        return i + 1;
}

template<class T>
bool linearTable_1564<T>::insert(int i, T e)
{
    if (i<0 || i>length+1)
        return false;
    for(int j=length;j>i;j--)
    {

        data[j] = data[j - 1];
    }
    data[i] = e;
    length++;
    return true;
}

template<class T>
bool linearTable_1564<T>::delElem(int i)
{
    if (i<0 || i>length)
        return false;
    for (int j = i; j < length; j++)
    {
        data[j] = data[j + 1];
    }
    length--;
    return true;
}

template<class T>
void linearTable_1564<T>::sort(linearTable_1564<T> &a) {
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; ++j) {
            if (data[i] < data[j]){
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

template<class T>
bool linearTable_1564<T>::isEmpty(linearTable_1564<T> a) {
    if (length > 0){
        return false;
    }
    return true;
}

#endif //MAIN_CPP_LINEARTABLE_1564_H
