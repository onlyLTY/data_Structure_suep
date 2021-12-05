#include "stackByArray.h"
#include "stackByNodeList.h"
#include <cstring>

void conversion(int a){
    int size, temp = a;
    stackByNodeList stack;
    do {
        stack.push(temp % 2);
        temp = temp / 2;
    } while (0 != temp);
    size = stack.getSize();
    for (int i = 0; i < size; i++) {
        std::cout<<stack.pop();
    }
    temp = a;
    std::cout<<std::endl;
    do {
        stack.push(temp % 8);
        temp = temp / 8;
    } while (0 != temp);
    size = stack.getSize();
    for (int i = 0; i < size; i++) {
        std::cout<<stack.pop();
    }
}

int palindrome (char *s){
    int size = strlen(s);
    stackByNodeList stack;
    for (int i = 0; i < size/2; ++i) {
        stack.push((int)*(s+i));
    }
    for (int i = 0; i < size/2; ++i) {
        if (stack.pop() != (int)*(s+i+size/2+size%2))
            return 0;
    }
    return 1;
}

int main() {
    int e = 5,a;
    bool b;
    std::default_random_engine random(516541);
    std::uniform_int_distribution<int> random_int(0,100);
    std::cout<<"构造栈"<<std::endl;
    stackByArray stack(10);
    for (int i = 0; i < 5; i++) {
        a = random_int(random);
        stack.push(a);
    }
    stack.print();
    std::cout<<"获得栈顶元素栈"<<std::endl;
    a = stack.getTop();
    std::cout<<"栈顶元素: "<<a<<std::endl;
    std::cout<<"进栈（元素为5）"<<std::endl;
    stack.push(e);
    std::cout<<"出栈"<<std::endl;
    a = stack.pop();
    std::cout<<a<<std::endl;
    std::cout<<"清空栈"<<std::endl;
    stack.emptyStack();
    std::cout<<"判断栈空   ";
    b = stack.isEmpty();
    std::cout<<"栈是空的: "<<b<<std::endl;
    std::cout<<"判断栈满   ";
    b = stack.isFull();
    std::cout<<"栈是满的: "<<b<<std::endl;
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"构造栈"<<std::endl;
    stackByNodeList stack_by_node_list;
    for (int i = 0; i < 5; i++) {
        a = random_int(random);
        stack_by_node_list.push(a);
    }
    stack_by_node_list.print();
    std::cout<<"获得栈顶元素栈"<<std::endl;
    a = stack_by_node_list.getTop();
    std::cout<<"栈顶元素: "<<a<<std::endl;
    std::cout<<"进栈（元素为5）"<<std::endl;
    stack_by_node_list.push(e);
    std::cout<<"出栈"<<std::endl;
    a = stack_by_node_list.pop();
    std::cout<<a<<std::endl;
    std::cout<<"清空栈"<<std::endl;
    stack_by_node_list.emptyStack();
    std::cout<<"判断栈空   ";
    b = stack_by_node_list.isEmpty();
    std::cout<<"栈是空的: "<<b<<std::endl;

    e = 14964;
    conversion(e);
    std::cout<<std::endl;
    char *s = "adada";
    int result = palindrome(s);
    std::cout<<result;
    return 0;
}
