#include <iostream>
using namespace std;

template<typename T>
void swap1(T *p1,T *p2)   
{
  T p;
  p=*p1;
  *p1=*p2;
  *p2=p;
}

int main()
{
 int n1,n2,n3;
 cout<<"请输入三个整数：\n";
 cin>>n1>>n2>>n3;
 if (n1<n2)  swap1(&n1,&n2);     
 if (n1<n3)  swap1(&n1,&n3);
 if (n2<n3)  swap1(&n2,&n3);
cout<<"排序后为："<<n1<<"  "<<n2<<"  "<<n3<<endl;
 float e1,e2,e3;
 cout<<"请输入三个浮点数：\n";
 cin>>e1>>e2>>e3;
 if (e1<e2)  swap1(&e1,&e2);
 if (e1<e3)  swap1(&e1,&e3);
 if (e2<e3)  swap1(&e2,&e3);
cout<<"排序后为："<<e1<<"  "<<e2<<"  "<<e3<<endl;
system("pause");
return 0;
}