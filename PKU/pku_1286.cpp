#include<iostream>
using namespace std;
typedef __int64 ll;
int gcd( int a, int b ){ return b ? gcd( b, a % b ) : a; }
ll pow( ll a, ll n )
{
	ll ans = 1,  d = a;
	while( n )
	{
		if( n & 1 ) ans = ans * d;
		d *= d;
		n >>= 1;
	}
	return ans;
}

ll solve( int n )
{
	int i;
	ll sum = 0;
	if( n == 0 )return 0;
	for( i = 1; i <= n; i++ )
		sum += pow( 3, gcd( i, n ) );
	if( n % 2 == 0 )
	{
		sum += pow( 3, n / 2 ) * n / 2;
		sum += pow( 3, n / 2 + 1 ) * n / 2;
	}
	else sum += pow( 3, n / 2 + 1 ) * n; 
	return sum / n / 2;
}

int main( )
{
	int n;
	while( scanf("%d",&n) && n != -1 )
	{
		printf("%I64d\n",solve( n ));
	}
	return 0;
}