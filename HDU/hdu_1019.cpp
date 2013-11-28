// Math Thoery
#include<iostream>
using namespace std;
typedef __int64 LL;

LL gcd( LL a, LL b ){ return ( b ? gcd( b ,a % b ) : a ); }
LL lcm( LL a, LL b ){ return a * b / gcd( a, b ); }

int main( )
{
	int i,n,t;
	LL a,b;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		if( n==1 ) scanf("%I64d",&a);
		else 
		{
			scanf("%I64d%I64d",&a,&b);
			a = lcm( a, b );
			for( i = 2; i < n; i++ )
			{
				scanf("%I64d",&b);
				a = lcm( a, b );
			}
		}
		printf("%I64d\n",a);
	}
	return 0;
}