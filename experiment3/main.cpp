#include <iostream>
#include "linkList.h"
#include "CLinkList.h"

void mergeTwoLists(linkList &La,int lengthA, linkList &Lb,int lengthB,linkList &Lc) {
    for (int i = 0; i < lengthA; i++) {
        Lc.insert(Lc.getLength(),La.getElem(i+1));
    }
    for (int i = 0; i < lengthB; i++) {
        Lc.insert(Lc.getLength(), Lb.getElem(i+1));
    }
    Lc.sort();

}

int main() {
    linkList a;

    int b2[] = {45,1526,465,46,4654,745,418,531,528};
    linkList a2(b2,9);
    std::cout<<"利用数组初始化带头结点的单链表构造函数，单链表a2";
    a2.print();

    int b[] = {16,56,564,446,4354,786,684,46,786};
    a.creat(b,9);
    std::cout<<"利用数组初始化带头结点的单链表，单链表a";
    a.print();

    a.insert(4,99);
    std::cout<<"在带头结点单链表的第i个位置前插入元素e，单链表a";
    a.print();

    int e;
    a.del(4,e);
    std::cout<<e<<std::endl;
    std::cout<<"在带头结点单链表中删除第i个元素，单链表a";
    a.print();

    std::cout<<"遍历单链表元素，单链表a";
    a.print();

    std::cout<<"求单链表表长，单链表a表长";
    std::cout<<a.getLength()<<std::endl;

    std::cout<<"判单链表表空，单链表a为空: ";
    std::cout<<std::boolalpha<<a.isEmpty()<<std::endl;

    std::cout<<"获得单链表中第i个结点的值且i合法(此时i为4)，值为： ";
    std::cout<<a.getElem(4)<<std::endl;
    std::cout<<"获得单链表中第i个结点的值且i不合法"<<std::endl;
    try {
        int elem;
        elem = a.getElem(100);
    }catch (int e){
        std::cout<<"i不合法"<<std::endl;
    }

    std::cout<<"删除链表 a2 中所有结点，打印a2  ";
    a2.deleteAll();
    a2.print();

    a.reverse();
    std::cout<<"实现单链表的就地逆置，单链表a";
    a.print();

    std::cout<<"下面是循环单链表"<<std::endl;

    CLinkList c = CLinkList(b, 9);
    std::cout<<"利用头插或尾插法创建带头结点的单循环链表，循环单链表c";
    c.print();

    c.insert(4,99);
    std::cout<<"在带头结点单链表的第i个位置前插入元素e，循环单链表c";
    c.print();

    c.del(4,e);
    std::cout<<e<<std::endl;
    std::cout<<"在带头结点循环单链表中删除第i个元素，循环单链表c";
    c.print();

    std::cout<<"遍历循环单链表元素，单链表c";
    c.print();

    std::cout<<"合并俩表";
    linkList La(b,9),Lb(b2,9),Lc;
    mergeTwoLists(La,9,Lb,9,Lc);
    Lc.print();

    return 0;
}
