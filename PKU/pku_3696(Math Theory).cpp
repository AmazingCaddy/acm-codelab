/*
8*10^0+8*10^1+8*10^2+8*10^3+8*10^4+.....+8*10^(n-1) = 8*(10^n-1)/9
由题意有 8 * ( 10^n - 1 ) / 9 = 0 ( mod L ) 求最小的 n
-------> 8 * ( 10^n - 1 ) = 0 ( mod 9 * L )
-------> ( 10^n - 1 ) = 0 ( mod ( 9 * L / gcd( L, 8 ) ) )
-------> 10^n = 1 ( mod( 9 * L / gcd( L, 8 ) ) )
设 m = 9 * L / gcd( L, 8 ) 
根据欧拉定理：( 10, m ) != 1 时 方程无解
当 ( 10, m ) == 1 是 phi( m ) 必然是一个解，但是不一定是最小的，故可以
从小到大枚举 phi( m ) 的所有因数
*/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

typedef __int64 ll;
const int maxn = 100006;

int vis[ maxn ], p[ maxn ];
int plen, flen;
int a[ 64 ], b[ 64 ];

ll gcd( ll a, ll b ) { return b ? gcd( b, a % b ) : a; }

void prime( )
{
    ll i, j, k;
    plen = 0;
    memset( vis, 0, sizeof( vis ) );
    for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
    {
        if( !vis[ i ] )
        {
            p[ plen++ ] = i;
            if( k < maxn ) for( j = k; j < maxn; j += i ) vis[ j ] = 1;
        }
    }
}

ll mul_mod( ll a, ll b, ll c )
{
	ll ans = 0, d = a % c;
	while( b )
	{
		if( b & 1 )if( ( ans += d ) >= c ) ans -= c;
		if( ( d <<= 1 ) >= c ) d -= c;
		b >>= 1;
	}
	return ans ;
}

ll pow_mod( ll a, ll b, ll c )
{
	ll ans = 1, d = a % c;
	while( b )
	{
		if( b & 1 ) ans = mul_mod( ans, d, c );
		d = mul_mod( d, d, c );
		b >>= 1;
	}
	return ans;
}

void number_factor( ll n )
{
	flen = 1;
	for( int i = 0; (ll) p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			for( b[ flen ] = 0; n % p[ i ] == 0; ++b[ flen ], n /= p[ i ] );
			a[ flen++ ] = p[ i ];
		}
	}
	if( n > 1 ) a[ flen ] = n, b[ flen++ ] = 1;
}

ll PHI( ll n )
{
	ll phi = n;
	for( int i = 0; (ll) p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			while( !( n % p[ i ] ) )
				n /= p[ i ];
			phi = phi / p[ i ] * ( p[ i ] - 1 );
		}
	}
	if( n > 1 ) phi = phi / n * ( n - 1 );
	return phi;
}

ll buf[ maxn ], cnt;

void DFS( int dep, ll tmp )
{
	if( dep == flen )
	{
		buf[ cnt++ ] = tmp;
		return;
	}
	int temp = 1;
	for( int i = 0; i <= b[ dep ]; i++ )
	{
		DFS( dep + 1, tmp * temp );
		temp *= a[ dep ];
	}
}

int main(int argc, char *argv[])
{
	ll L;
	int k = 1;
	prime( );
	while( scanf( "%I64d", &L ) && L )
	{
		ll m = 9 * L / gcd( L, 8 );
		if( gcd( 10, m ) != 1 )
		{
			printf( "Case %d: 0\n", k++ );
			continue;
		}
		number_factor( PHI( m ) );
		cnt = 0;
		DFS( 0, 1 );
		sort( buf, buf + cnt );
		ll ans = 0;
		for( int i = 0; i < cnt; i++ )
		{
			if( pow_mod( 10, buf[ i ], m ) == 1 )
			{
				ans = buf[ i ];
				break;
			}
		}
		printf( "Case %d: %I64d\n", k++, ans );
	}
	return 0;
}
