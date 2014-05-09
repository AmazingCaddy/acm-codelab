#include<iostream>
#include<cmath>
typedef __int64 LL;
using namespace std;
const LL p = 1000003;

LL mod_mul( LL a, int n )
{
	LL g=1;
	while( n )
	{
		if( n & 1 ) g = ( g * a ) % p;
		a = ( a * a ) % p;
		n >>= 1;
	}
	return g;
}
int mod( int x, int n )  //可对负数进行调整
{
	return (x%n+n)%n;
}
// 扩展欧几里德算法
void Extend_Eulid( int a, int b, int &d, int &x, int &y )// ax+by=gcd(a,b);
{
	if( !b ){ d=a; x=1; y=0; }
	else { Extend_Eulid( b, a%b, d, y, x );	y-=x*(a/b); }
}
// 求a的逆元0～n-1之间
int inverse_a( int a, int n ) 
{
	int d,x,y;
	Extend_Eulid( a, n, d, x, y );
	return d==1 ? mod( x, n ) : -1;
}
int main( )
{
	int i,t,n,n1,rn,k=1;
	LL sum;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		rn = inverse_a( n, p );
		sum = 0;
		for( i = 0; i < n; i++ )
		{
			scanf("%d",&n1);
			sum += mod_mul( 2, n1 );
		}
		printf("Case %d:%I64d\n",k++,(sum*rn)%p);
	}
	return 0;
}