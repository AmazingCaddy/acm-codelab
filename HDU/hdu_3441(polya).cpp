/*
	author: AmazingCaddy
	time: 2011/3/5  14:09
	这题的设计还是很巧妙的，用了2次burnside，这题的关键在于 a 很大，
	不能直接枚举 b ，但其中b * b = a * a - 1，转化为分解(a + 1)和(a - 1)
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef __int64 ll;
const int maxn = 32000;
const ll P = 1000000007;
int vis[ maxn ], p[ maxn ];
int a[ 64 ], b[ 64 ];
int a1[ 32 ], a2[ 32 ], b1[ 32 ], b2[ 32 ];
int plen, flen, flen1, flen2;

void prime( )
{
	int i, j, k;
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

void factor( int n, int &x, int c[ ], int d[ ] )
{
	x = 0;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			for( d[ x ] = 0; n % p[ i ] == 0; ++d[ x ], n /= p[ i ] );
			c[ x++ ] = p[ i ];
		}
	}
	if( n > 1 ) d[ x ] = 1, c[ x++ ] = n;
}

ll elur( ll n )
{
	for( int i = 0; i < flen; i++ )
		if( b[ i ] ) n -= n / a[ i ];
	return n;
}

/*
ll elur( ll n )
{
	ll phi = n;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			while( n % p[ i ] == 0 ) n /= p[ i ];
			phi -= phi / p[ i ];
		}
	}
	if( n > 1 ) phi -= phi / n;
}
*/

ll pow_mod( ll a, ll b, ll c )
{
	ll ans = 1, d = a % c;
	while( b )
	{
		if( b & 1 ) ans = ans * d % c;
		d = d * d % c;
		b >>= 1;
	}
	return ans;
}

ll inv( ll n )
{
	return pow_mod( n, P - 2, P );
}

ll ans, ANS, num, K, AA;
int A, C;

void dfs( int dep, ll t )
{
	if( dep == flen )
	{
		ans = ( ans + elur( K / t ) % P * pow_mod( num, t, P ) % P ) % P;
		return;
	}
	ll tmp = 1;
	for( int i = 0; i <= b[ dep ]; tmp *= a[ dep ], i++ )
	{
		b[ dep ] -= i;
		dfs( dep + 1, t * tmp );
		b[ dep ] += i;
	}
}

void DFS( int dep, ll B )
{
	if( dep == flen )
	{
		ll BB = B * B;
		num = pow_mod( C, BB, P );
		num = ( num + pow_mod( C, ( BB + 3 ) / 4, P ) * 2 ) % P;
		num = ( num + pow_mod( C, ( BB + 1 ) / 2, P ) ) % P;
		num = num * inv( 4 ) % P;
		K = AA / BB;
		ans = 0;
		dfs( 0, 1 );
		ans = ans * inv( K % P ) % P * C % P;
		ANS = ( ANS + ans ) % P;
		return;
	}
	ll tmp = 1;
	for( int i = 0; ( i << 1 ) <= b[ dep ]; tmp *= a[ dep ], i++ )
	{
		b[ dep ] -= ( i << 1 );
		DFS( dep + 1, B * tmp );
		b[ dep ] += ( i << 1 );
	}
}

int main(int argc, char *argv[])
{
	int cas, flag;
	//freopen( "in", "r", stdin );
	//freopen( "out.txt", "w", stdout );
	prime( );
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d %d", &A, &C );
		printf( "Case %d: ", t );
		if( A == 1 )
		{
			printf( "%d\n", C );
			continue;
		}
		factor( A + 1, flen1, a1, b1 );
		factor( A - 1, flen2, a2, b2 );
		flen = flen2;
		for( int i = 0; i < flen; i++ )
			b[ i ] = b2[ i ], a[ i ] = a2[ i ];
		for( int i = 0; i < flen1; i++ )
		{
			flag = 0;
			for( int j = 0; j < flen2; j++ )
			{
				if( a1[ i ] == a2[ j ] )
				{
					b[ j ] += b1[ i ];
					flag = 1;
					break;
				}
			}
			if( !flag )
			{
				a[ flen ] = a1[ i ];
				b[ flen++ ] = b1[ i ];
			}
		}
		ANS = 0;
		AA = ( ll )A * A - 1;
		DFS( 0, 1 );
		printf( "%I64d\n", ANS );
	}
	return 0;
}
