////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-03-10 19:27:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
typedef int LL;
void f( LL a[][2], LL b[][2], LL m )
{
	LL d1,d2,d3,d4,d5,d6,d7;
	d1=( a[0][0]+a[1][1] )*( b[0][0]+b[1][1] );
	d2=( a[1][0]+a[1][1] )*b[0][0];
	d3=a[0][0]*( b[0][1]-b[1][1] );
	d4=a[1][1]*( b[1][0]-b[0][0] );
	d5=( a[0][0]+a[0][1] )*b[1][1];
	d6=( a[1][0]-a[0][0] )*( b[0][0]+b[0][1] );
	d7=( a[0][1]-a[1][1] )*( b[1][0]+b[1][1] );
	a[0][0]=(d1+d4-d5+d7)%m;
	a[0][1]=(d3+d5)%m;
	a[1][0]=(d2+d4)%m;
	a[1][1]=(d1+d3-d2+d6)%m;
}

LL Fibonacci( LL t, LL a[][2], LL I[][2], LL m )
{
	if( t==-1 )return 0;
	while( 1 )
	{
		if( t & 1 )f( I, a, m );
		f( a, a, m );
		t>>=1;
		if( t==0 )break;
	}
	return 11*I[0][0]+7*I[0][1];
}
int main( )
{
	LL k,n;
	LL a[2][2],I[2][2];
	while( scanf("%d",&n) != EOF )
	{
		I[0][0]=1;I[0][1]=0;I[1][0]=0;I[1][1]=1;
		a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=0;
		if( n==0 || n==1 )printf("no\n");
		else 
		{
			k=Fibonacci( n-1, a, I, 3 );
			if( k%3==0 ) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}