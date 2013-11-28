#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef __int64 LL;
LL gcd( LL a, LL b ){ return ( b ? gcd( b, a % b ) : a ); }
LL lcm( LL a, LL b ){ return a * b / gcd( a, b ); }

int main( int argc, char *argv[] )
{
	LL I,a,ans;
	LL num[13];
	while( 1 )
	{
		scanf("%I64d%I64d",&I,&a);
		if( I == 0 && a == 0 )break;
		for( LL i = 0; i < I; i++ )
			scanf("%I64d",&num[i]);
		ans = 1;
		for( LL i = 0; i < I; i++ )
			ans = lcm( ans, num[i] );
		printf("%I64d\n",ans-a);
	}
	return 0;
}

