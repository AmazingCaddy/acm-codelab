#include<iostream>
using namespace std;
typedef __int64 ll;
int gcd( int a, int b ){ return b ? gcd( b, a % b ) : a ; }

ll pow( int a, int n )
{
	ll ans = 1, d = a;
	while( n )
	{
		if( n & 1 ) ans = ans * d;
		d = d * d;
		n >>= 1;
	}
	return ans;
}

ll polya( int n, int k )
{
	int i;
	ll sum = 0;
	if( n == 0 )return 0;
	for( i = 1; i <= n; i++ )
		sum += pow( k, gcd( n, i ) );
	if( n & 1 )	sum += n * pow( k, n / 2 + 1 );
	else
	{
		sum += n / 2 * pow( k, n / 2 + 1 );
		sum += n / 2 * pow( k, n / 2 );
	}
	return sum / n / 2;
}

int main( )
{
	int c, s;
	while( 1 )
	{
		scanf("%d%d",&c,&s);
		if( c == 0 && s == 0 )break;
		printf("%I64d\n",polya( s, c ));
	}
	return 0;
}