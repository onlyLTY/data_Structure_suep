#include <iostream>
#include "linearTable_1564.h"

template<typename T>
void unionA_and_B(linearTable_1564<T> &a,linearTable_1564<T> &b){

    for (int i=0;i< b.getLength(); i++) {
        int temp;
        b.getElem(i, temp);
        a.insert(a.getLength(), temp);
    }
    cout << "合并后";
    a.printList();
}

template<typename T>
void unionA_and_B_oder(linearTable_1564<T> &a,linearTable_1564<T> &b, linearTable_1564<T> &c){
    a.sort(a);
    b.sort(b);
    T temp;
    for (int l = 0; l < a.getLength(); ++l) {
        a.getElem(l, temp);
        c.insert(l, temp);
    }
    for (int l = 0; l < b.getLength(); ++l) {
        b.getElem(l, temp);
        orderlyInsert(c,temp);
    }
}

template<typename T>
bool orderlyInsert(linearTable_1564<T> &s,T e){
    T a,b;
    s.sort(s);
    for (int i = 1; i <= s.getLength(); i++) {
        s.getElem(i, a);
        s.getElem(i + 1, b);
        if (a <= e && b >= e){
            s.insert(i + 1, e);
            return true;
        }
    }
    s.insert(s.getLength(), e);
    return true;
}

int main() {
    linearTable_1564<int> linearTable1564;
    int array[8] = { 7,213,498,4,135,2,263 };
    linearTable1564.creatList(array, 7);	//创建顺序表
    linearTable1564.printList();
    cout << endl;
    linearTable1564.getLength();
    cout << "当前顺序表的长度为：" << linearTable1564.getLength() << endl;
    int a;
    linearTable1564.getElem(1, a);
    cout << "第二个数值为：" << a << endl;
    linearTable1564.insert(2, 5);
    cout << "插入后重新";
    linearTable1564.printList();
    cout << endl;
    linearTable1564.delElem(3);
    cout << "删除第4个位置后重新";
    linearTable1564.printList();
    cout << endl;

    int b[3] = {163,146,1};
    linearTable_1564<int> linearTable1564_b;
    linearTable1564_b.creatList(b, 3);
    unionA_and_B<int>(linearTable1564, linearTable1564_b);
    cout << endl;
    orderlyInsert(linearTable1564, 8);
    linearTable1564.printList();
    cout << endl;
    linearTable_1564<int> linearTable1564_c;
    unionA_and_B_oder(linearTable1564,linearTable1564_b,linearTable1564_c);
    linearTable1564_c.printList();
    return 0;
}


