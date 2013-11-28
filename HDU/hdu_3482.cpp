#include<iostream>
#include<cmath>
using namespace std;
typedef __int64 ll;
const ll p = 987654321;

ll pow_mod( ll a, ll b )
{
	ll ans = 1, d = a % p;
	while( b )
	{
		if( b & 1 ) ans = ans * d % p;
		d = d * d % p;
		b >>= 1;
	}
	return ans;
}

int main( )
{
	ll n, m, ans;
	while( 1 )
	{
		scanf("%I64d%I64d",&n,&m);
		if( n < 0 && m < 0 ) break;
		if( m == 1 ) ans = 1;
		else if( m == 2 )
		{
			ans = pow_mod( 2, n );
		}
		else 
		{
			if( n >= m )
			{
				ans = 1;
				for( int i = m; i > 1; i-- )
					ans = ans * i % p;
				ans = ( ans + m ) % p;
			}
			else
			{
				ans = pow_mod( m, n );
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
