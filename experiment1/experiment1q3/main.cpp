#include <iostream>

using namespace std;
template<class T>

class calculation{
    private:
        int n = 10;
        T *a;
    public:
        T sumOperation(T *p,int n=10){
            T sum = 0;
            for (int i = 0; i < n; i++) {
                sum += p[i];
            }
            return sum;
        }

        T maxOperation(T *p,int n=10){
            T max;
            for (int i = 0; i < n; i++) {
                if (p[i] > max){
                    max = p[i];
                }
            }
            return max;
        }
};

int main(){
    cout<<"请输入十个整型数据"<<endl;
    calculation<int> InteagerTest;
    int *a = new int[10];
    for (int i = 0; i < 10; i++) {
        cin>>a[i];
    }
    int max = InteagerTest.maxOperation(a);
    int sum = InteagerTest.sumOperation(a);
    cout<<"sum="<<sum<<"  max="<<max<<endl;

    cout<<"请输入十个浮点数据"<<endl;
    calculation<double> DouberTest;
    double *b = new double[10];
    for (int i = 0; i < 10; i++) {
        cin>>b[i];
    }
    double max_D = DouberTest.maxOperation(b);
    double sum_D = DouberTest.sumOperation(b);
    cout<<"sum="<<sum_D<<"  max="<<max_D<<endl;
}