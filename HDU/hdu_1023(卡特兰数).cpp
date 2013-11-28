/*
Catalan���Ľⷨ
Catalan������Ϲ�ʽΪ Cn=C(2n,n) / (n+1);
�����ĵݹ鹫ʽΪ  h(n ) = h(n-1)*(4*n-2) / (n+1)
С����
����50���µ�С������˵��ʹ������Ϳ�����ɣ��������£�
*/
/*
#include<iostream>
using namespace std;
int main()
{
     long long  int a[101][101],i,j,n;
    for (i=0; i<101; i++)    //���������� Catalan��
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
	������
	���ڴ�����˵����Ӧ��ʹ������Ĵ����㷨��
	ʹ�õĹ�ʽΪ��h(n)  = h(n-1)*(4*n-2)/n+1;
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

void multiply(int a[],int Max,int b)  //�����˷�
{
    int i,array=0;
    for (i=Max-1; i>=0; i--)   
    {
        array+=b*a[i];
        a[i] = array%BASE;
        array /= BASE;   
    }
}
 
void divide(int a[], int Max, int b)  //��������
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
        divide(a[i],MAX,i+1);                  //h[i] /= ��i+1��;
    }
    while (cin>>n)   
    {
        for (i=0; i<MAX && a[n][i]==0; i++);  //ȥ������ǰΪ0�����֡�
        cout<<a[n][i++];             //�����һ����0��
        for (; i<MAX; i++)   
            printf("%04d",a[n][i]);       //��������������ÿλ������5λ����
        cout<<endl;
    }
    return 0;
}
