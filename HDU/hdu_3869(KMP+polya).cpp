/*
	author: AmazingCaddy
	time:	2011/8/10   21:11
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//typedef __int64 ll;
typedef long long ll;

const int mod = 1000000007;
const int maxn = 100004;

struct node
{
	int vec, edge;
	bool operator == ( const node & a ) const
	{
		return vec == a.vec && edge == a.edge;
	}
	bool operator != ( const node & a ) const
	{
		return !( *this == a );
	}
};
node pattern[ maxn ], text[ maxn << 1 ];

ll powC[ maxn ];
int fail[ maxn ], vis[ maxn ];
int N, C;

ll gcd( ll a, ll b ) { return ( b ? gcd( b, a % b ) : a ); }

ll pow_mod( ll a, ll b )
{
	ll ans = 1, d = a % mod;
	while( b )
	{
		if( b & 1 ) ans = ans * d % mod;
		d = d * d % mod;
		b >>= 1;
	}
	return ans;
}

ll Inv( ll n ) { return pow_mod( n, mod - 2 ); }

void init( )
{
	powC[ 0 ] = 1;
	for( int i = 1; i <= N; i++ )
		powC[ i ] = powC[ i - 1 ] * C % mod;
}

void faillink( )
{
	node * t = pattern;
	--t;
	for( int i = 1, j = 0; i <= N; i++, j++ )
	{
		fail[ i ] = j;
		while( j > 0 && t[ i ] != t[ j ] ) j = fail[ j ];
	}
	/*
	int j, k;
	flink[ 0 ] = -1;
	j = 1;
	while( j < N )
	{
		k = flink[ j - 1 ];
		while( k != -1 && pattern[ k ] != pattern[ j - 1 ] )
			k = flink[ k ];
		flink[ j ] = k + 1;
		j++;
	}
	*/
}

void kmp( )
{
	node *s = text, *t = pattern;
	--s, --t;
	for( int i = 1, j = 1; i <= 2 * N; i++, j++ )
	{
		while( j > 0 && s[ i ] != t[ j ] ) j = fail[ j ];
		if( j == N ) { vis[ i - N ] = 1; j = fail[ j ]; }
	}
	/*
	int i = 0, j = 0;
	while( i < N * 2 )
	{
		while( j != -1 && pattern[ j ] != text[ i ] )
			j = flink[ j ];
		if( j == N - 1 ) { vis[ i - N + 1 ] = 1; j = flink[ j ]; }
		i++;
		j++;
	}
	*/
}

int main(int argc, char *argv[])
{
//	freopen( "in", "r", stdin );
//	freopen( "out1", "w", stdout );
	int cas;
	scanf( "%d", &cas );
	while( cas -- )
	{
		scanf( "%d%d", &N, &C );
		init( );
		for( int i = 0; i < N; i++ )
			scanf( "%d", &pattern[ i ].vec );
		for( int i = 0; i < N; i++ )
			scanf( "%d", &pattern[ i ].edge );
		for( int i = 0; i < N; i++ )
			text[ i ] = text[ i + N ] = pattern[ i ];
		faillink( );
		memset( vis, 0, sizeof( vis ) );
		kmp( );
		ll ans = 0, cnt = 0;
		for( int i = 1; i <= N; i++ )
		{
			if( vis[ i ] )
			{
				cnt++;
				ans = ( ans + powC[ gcd( N, i ) ] ) % mod;
			}
		}
		ans = ans * Inv( cnt ) % mod;
		cout << ans << "\n";
	}
//	cerr << clock( ) << endl;
	return 0;
}
