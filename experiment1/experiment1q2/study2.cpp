#include <iostream>
using namespace std;
template <typename T>
void sort(T *a, int n)  /*选择法排序,从小到大*/
{
    int i,j,k; T p;
    for (i=0; i<n-1; i++)
    {
        k=i;
        for (j=i+1; j<n; j++)
        {
            if (a[k] > a[j])
                k=j;
        }
        if(k!=i)
        {
            p=a[i];
            a[i]=a[k];
            a[k]=p;
        }

    }
}
//试分析sort的时间复杂度：
int main()
{   int n;  //数组大小变量
    cout<<"请输入动态数组的大小："<<endl;
    cin>>n;
    int *a = new int[n];  //申请动态数组存储空间
    cout<<"\n请输入数组中的"<<n<<"个数据：\n";
    for(int i=0;i<n;i++)
        cin >> a[i];//从键盘读入数据
    sort(a, n); //对数组中的数据进行排序
    cout<<"排序后数组中的数据：\n";
    for(int j=0;j<n;j++)
        cout<<a[j]<<endl;    //输出数组中的数据
    delete a; //释放所申请的存储空间
}
