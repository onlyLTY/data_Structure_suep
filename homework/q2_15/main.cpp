#include <iostream>
template <typename T>
T * reverse(T *p, int size){
    T *reverse_a = new T[size];
    for (int i = 0; i < size; i++) {
        *(reverse_a+i) = *(p+size-i-1);
    }
    return reverse_a;
}

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
    int *b;
    output(a, sizeof(a)/sizeof(a[1]));
    b = reverse(a, sizeof(a)/sizeof(a[1]));
    output(b, sizeof(a)/sizeof(a[1]));
    return 0;
}