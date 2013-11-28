#include<iostream>
using namespace std;
__int64 gcd( __int64 a, __int64 b )
{
	return ( b ? gcd( b, a%b ) : a );
}

int main( )
{
	int i,n;
	__int64 x,y,t,a[16];
	__int64 b[14][2];
	a[1]=1,a[2]=1;
	for( i=3; i<=15; i++ )
		a[i]=a[i-1]+a[i-2];
	b[1][0]=2,b[1][1]=1;
	for( i=2; i<=13; i++ )
	{
		x=b[i-1][0]*a[i+1]+a[i+2]*b[i-1][1];
		y=b[i-1][1]*a[i+1];
		t=gcd( x, y );
		b[i][0]=x/t;
		b[i][1]=y/t;
	}
	scanf("%d",&n);
	while( n-- )
	{
		scanf("%d",&i);
		printf("%I64d/%I64d\n",b[i][0],b[i][1]);
	}
	return 0;
}