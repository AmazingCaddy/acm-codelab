////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-03-19 15:42:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
//#include<iostream>
//#include<cmath>
//using namespace std;
//typedef int LL;
//LL num[93]={ 0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,
//6765,1094,1771,2865,4636,7502,1213,1964,3178,5142,8320,1346,2178,3524,5702,9227,
//1493,2415,3908,6324,1023,1655,2679,4334,7014,1134,1836,2971,4807,7778,1258,2036,
//3295,5331,8626,1395,2258,3654,5912,9567,1548,2504,4052,6557,1061,1716,2777,4494,
//7272,1176,1903,3080,4984,8065,1304,2111,3416,5527,8944,1447,2341,3788,6130,9919,
//1605,2596,4201,6798,1100,1779,2880,4660,7540 };
//
//int main( )
//{
//	LL n;
//	double x,k=(1+sqrt(5.0))/2;
//	while( scanf("%d",&n) != EOF )
//	{
//		if( n<=92 )printf("%d\n",num[n]);
//		else 
//		{
//			x=n*log10(k)-0.5*log10(5.0);
//			x=x-(int)x;
//			x=pow( 10.0, x );
//			n=(int)(x*1000);
//			printf("%d\n",n);
//		}
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
typedef int LL;
void f( LL a[][2], LL b[][2] )
{
	LL d1,d2,d3,d4,d5,d6,d7;
	d1=( a[0][0]+a[1][1] )*( b[0][0]+b[1][1] );
	d2=( a[1][0]+a[1][1] )*b[0][0];
	d3=a[0][0]*( b[0][1]-b[1][1] );
	d4=a[1][1]*( b[1][0]-b[0][0] );
	d5=( a[0][0]+a[0][1] )*b[1][1];
	d6=( a[1][0]-a[0][0] )*( b[0][0]+b[0][1] );
	d7=( a[0][1]-a[1][1] )*( b[1][0]+b[1][1] );
	a[0][0]=(d1+d4-d5+d7)%7;
	a[0][1]=(d3+d5)%7;
	a[1][0]=(d2+d4)%7;
	a[1][1]=(d1+d3-d2+d6)%7;
}

LL Fibonacci( LL t, LL a[][2], LL I[][2] )
{
	while( 1 )
	{
		if( t & 1 )f( I, a );
		f( a, a );
		t>>=1;
		if( t==0 )break;
	}
	return (I[0][0]+I[0][1])%7;
}
int main( )
{
	LL k,n,A,B;
	LL a[2][2],I[2][2];
	int i=1;
	while( 1 )
	{
		scanf("%d%d%d",&A,&B,&n);
		if( A==0 && B==0 && n==0 )break;
		if( n==1 || n==2 )k=1;
		else
		{
			I[0][0]=1;I[0][1]=0;I[1][0]=0;I[1][1]=1;
			a[0][0]=A;a[0][1]=B;a[1][0]=1;a[1][1]=0;
			k=Fibonacci( n-2, a, I );
		}
		printf("%d\n",k);
	}
	return 0;
}