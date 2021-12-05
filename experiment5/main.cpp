
#include "CircularQueue1564.h"

int main() {
    CircularQueue1564<int> circularQueue(10);
    int a[] = {51,485,45,4156,156,485,11,45,78,46,64};
    std::cout<<"入队"<<std::endl;
    for (int i = 0; i < 11; i++) {
        circularQueue.insert(a[i]);
    }
    circularQueue.print();
    std::cout<<"求元素个数"<<std::endl;
    int length = circularQueue.length();
    std::cout<< length <<std::endl;
    std::cout<<"出队列操作"<<std::endl;
    int temp = circularQueue.pop();
    std::cout<<temp<<std::endl;
    std::cout<<"遍历"<<std::endl;
    circularQueue.print();
    std::cout<<"清空"<<std::endl;
    //circularQueue.clear();
    std::cout<<"获得表头"<<std::endl;
    temp = circularQueue.getHead();
    std::cout<<temp<<std::endl;
    return 0;
}
