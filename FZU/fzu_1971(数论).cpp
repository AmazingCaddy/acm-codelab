/* 
  I believe in AekdyCoin 
*/
#include <cstdio>
#include <iostream>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef __int64 ll;

const int maxn = 33;
const int maxm = 32010;

bool vis[ maxm ];
ll pp[ maxm ];
int plen, flen, cnt;

ll aa[ 65 ], bb[ 65 ];
ll buf[ 100000 ];

void prime( )
{
	ll i, j, k;
	plen = 0;
	memset( vis, false, sizeof( vis ) );
	for( i = 2, k = 4; i < maxm; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
		{
			pp[ plen++ ] = i;
			if( k < maxm ) for( j = k; j < maxm; j += i ) vis[ j ] = true;
		}
	}
}

void num_factor( ll n )   //在有素数表的前提下的素因数分解
{
	int i;
	flen = 0;
	for( i = 0; pp[ i ] * pp[ i ] <= n; i++ )
	{
		if( n % pp[ i ] == 0 )
		{
			for( bb[ flen ] = 0; n % pp[ flen ] == 0; ++bb[ flen ], n /= pp[ i ] );
			aa[ flen++ ] = pp[ i ];
		}
	}
	if( n > 1 ) bb[ flen ] = 1, aa[ flen++ ] = n;
}

ll mod( ll a, ll mod ){ return ( a % mod + mod ) % mod; }

ll pow_mod( ll a, ll b, ll mod )
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

void ex_gcd( ll a, ll b, ll & d, ll & x, ll & y )
{
	if( !b ) { d = a, x = 1, y = 0; }
	else
	{
		ex_gcd( b, a % b, d, y, x );
		y -= x * ( a / b );
	}
}

ll china ( ll a[ ], ll m[ ], ll n ) // X mod m[i]=a[i] ，求解 X ,m[i]两两互素 
{
	ll M = 1, d, y, x, X;
	for( int i = 0; i < n; i++ )
		M = M * m[ i ];
	X = 0;
	for( int i = 0; i < n; i++ )
	{
		ll w = M / m[ i ];
		ex_gcd( m[ i ], w, d, x, y );      // don 't care about others
		X = ( X + y * w * a[ i ] ) % M;      // accumulate e*的和a
	}
	return mod( X, M ) ? mod( X, M ) : M;                    // adjust to [0,M-1]
}

// A = 52 mod = 8  A % 2 == 0   ans = 2^(c-1)
// A = 53 mod = 0  ans = 0

ll b[ maxn ], p[ maxn ], c[ maxn ], g[ maxn ], PC[ maxn ];
ll B[ maxn ];
ll K, A, N, M, ans;

void DFS( int dep, ll tem )
{
	int i;
    if( dep == flen )
	{
		buf[ cnt++ ] = tem;
        return;
    }
    ll temp = 1;
    for( i = 0; i <= bb[ dep ]; i++ )
    {
        DFS( dep + 1, tem * temp );
        temp *= aa[ dep ];
    }
}

void find_g( )   // 暴力找原根
{
	for( int j = 0; j <= K; j++ )
	{
		if( p[ j ] == 2 ) continue;
		ll phi = PC[ j ] / p[ j ] * ( p[ j ] - 1 );
		cnt = 0;
		num_factor( phi );
		DFS( 0, 1 );
		for( int i = 2; ; i++ )
		{
			int k;
			for( k = 0; k < cnt; k++ )
			{
				if( buf[ k ] != phi && pow_mod( i, buf[ k ], PC[ j ] ) == 1 )
					break;
			}
			if( k == cnt ) 
			{
				g[ j ] = i;
				break;
			}
		}
	}
}

ll sum( ll q, ll n, ll P )
{
    if( n < 0 ) return 0;
    if( n == 0 ) return 1 % P;
    if( n == 1 ) return ( 1 + q ) % P;
    ll S;
    if( n & 1 )
	{
        S = sum( q, n >> 1, P );
        return ( S + S * pow_mod( q, n / 2 + 1, P ) % P ) % P;
    }
    S = sum( q, n - 1, P );
    return ( S + pow_mod( q, n, P ) ) % P;
}

int main(int argc, char *argv[])
{
	// freopen("out.out","w",stdout);
	int cas;
	prime( );
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		scanf("%I64d%I64d",&A,&K);
		M = 1;
		for( int i = 0; i <= K; i++ )
		{
			scanf("%I64d%I64d%I64d",&b[ i ],&p[ i ],&c[ i ]);
			PC[ i ] = 1;
			for( int j = 0; j < c[ i ]; j++ )
				PC[ i ] *= p[ i ];
			M *= PC[ i ];
		}
		N = china( b, PC, K + 1 );
		find_g( );
		ll seg_res, seg_ment, base;
		for( int i = 0; i <= K; i++ )
		{
 			if( p[ i ] == 2 )
			{
				if( c[ i ] == 1 ) base = 1;
				else base = ( A % 2 == 1 ? 0 : ( 1 << ( c[ i ] - 1 ) ) );
			}
			else 
			{
				base = pow_mod( g[ i ], A, PC[ i ] );
				base = sum( base, PC[ i ] / p[ i ] * ( p[ i ] - 1 ) - 1, PC[ i ] );
			}
			seg_ment = N / PC[ i ];
			seg_res = b[ i ];
			ans = base * seg_ment % PC[ i ];
			ll tmp = 0;
			for( int j = 1; j <= b[ i ]; j++ )
			{
				tmp = ( tmp + pow_mod( j, A, PC[ i ] ) ) % PC[ i ];
			}
			B[ i ] = ( ans + tmp ) % PC[ i ];
		}
		ans = china( B, PC, K + 1 );
		printf("Case %d: %I64d\n",t, ans % M );
	}
	return 0;
}
