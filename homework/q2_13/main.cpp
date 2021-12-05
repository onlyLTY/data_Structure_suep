#include <iostream>
template <typename T>
int find(T *p,int n){
    int flag = -1;
    for (int i = 0; i < n; i++) {
        if (*(p+i) == n){
            flag = i;
            break;
        }
    }
    return flag;
}

int main() {
    int a[] = {10, 464, 4646, 5465, 4564};
    int location = find(a, 464);
    std::cout<<location<<std::endl;
    return 0;
}
