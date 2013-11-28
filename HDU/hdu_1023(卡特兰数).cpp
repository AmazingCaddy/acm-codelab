/*
Catalan数的解法
Catalan数的组合公式为 Cn=C(2n,n) / (n+1);
此数的递归公式为  h(n ) = h(n-1)*(4*n-2) / (n+1)
小数解
对于50以下的小数解来说，使用数组就可以完成，代码如下：
*/
/*
#include<iostream>
using namespace std;
int main()
{
     long long  int a[101][101],i,j,n;
    for (i=0; i<101; i++)    //利用数组求 Catalan数
        a[i][0] = 1;
    for (i=1; i<101; i++)                    
    {
        for (j=1; j<=i; j++)   
            a[i][j] = a[i][j-1] + a[i-1][j];   
    }
    while (cin>>n)   
    {     
        cout<<a[n][n]<<endl;
    }
    return 0;
}
*/
/*
	author: AmazingCaddy
	time: 2011/4/13  13:52
	大数解
	对于大数来说，就应该使用下面的大数算法。
	使用的公式为：h(n)  = h(n-1)*(4*n-2)/n+1;
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
using namespace std;
const int MAX = 100;
const int BASE = 10000;

void multiply(int a[],int Max,int b)  //大数乘法
{
    int i,array=0;
    for (i=Max-1; i>=0; i--)   
    {
        array+=b*a[i];
        a[i] = array%BASE;
        array /= BASE;   
    }
}
 
void divide(int a[], int Max, int b)  //大数除法
{
    int i,div=0;
    for (i=0;i<Max; i++)   
    {
        div = div*BASE + a[i];
        a[i] = div / b;
        div %= b;
    }
}
int main()
{
    int a[101][MAX],i,j,n;
    memset(a[1],0,MAX*sizeof(int));
    for (i=2,a[1][MAX-1]=1; i<101; i++)
    {
        memcpy(a[i],a[i-1],MAX*sizeof(int));      //h[I] = h[i-1];  
        multiply(a[i],MAX,4*i-2);               //h[i] *= (4*i-2);
        divide(a[i],MAX,i+1);                  //h[i] /= （i+1）;
    }
    while (cin>>n)   
    {
        for (i=0; i<MAX && a[n][i]==0; i++);  //去掉数组前为0的数字。
        cout<<a[n][i++];             //输出第一个非0数
        for (; i<MAX; i++)   
            printf("%04d",a[n][i]);       //输出后面的数，并每位都保持5位长度
        cout<<endl;
    }
    return 0;
}
