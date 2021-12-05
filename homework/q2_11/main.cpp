#include <iostream>
template <typename T>
void output(T *p,int n){
    for (int i = 0; i < n; i++) {
        std::cout<<*(p+i)<<" ";
    }
    std::cout<<"\n"<<"---------------"<<std::endl;
}

int main() {
    int a[] = {10, 464, 4646, 5465, 4564};
    output(a, sizeof(a)/sizeof(a[1]));
    return 0;
}


