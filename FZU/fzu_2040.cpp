#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 70;
const ll p = 1000000007;
int n;

// A * B mod p
void matrix_mul( ll a[ ][ maxn ], ll b[ ][ maxn ] )
{
	ll c[ maxn ][ maxn ];
	memset( c, 0, sizeof( c ) );
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			for( int k = 0; k < n; k++ )
				c[ i ][ j ] = ( c[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ] ) % p;
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			a[ i ][ j ] = c[ i ][ j ];
}

// A^b mod p
void matrix_mod( ll a[ ][ maxn ], int b )
{
	ll I[ maxn ][ maxn ];
	memset( I, 0, sizeof( I ) );
	for( int i = 0; i < n; i++ )
		I[ i ][ i ] = 1;
	while( b )
	{
		if( b & 1 ) matrix_mul( I, a );
		matrix_mul( a, a );
		b >>= 1;
	}
	memcpy ( a, I, sizeof ( ll ) * maxn * maxn );
}

ll dp[ maxn ][ maxn ];

int A[ 10 ], B[ 10 ];

int cal ( int c, int d, int m ) {
	int a = c & d;
	int b = c ^ d;
	A[ 0 ] = 1;
	B[ 0 ] = 0;
	for ( int i = 0 ; i < m - 1 ; ++i ) {
		if ( a & ( 1 << i ) ) A[ i + 1 ] = 1;
		else A[ i + 1 ] = 0;
		if ( b & ( 1 << i ) ) B[ i + 1 ] = 1;
		else B[ i + 1 ] = 0;
	}
	A[ m ] = 1;
	B[ m ] = 0;
	int ans = 1;
	int  nu = 0;
	for ( int i = 1 ; i <= m ; ++i ) {
		if( B[ i ] == 1 ){
			nu++;
		}
		if ( A[ i ] == 1 ) {
			if( nu == 0 ) ans*=2;
			nu=0;
		}
		
	}
	return ans;
}

int main( int ac, char * av[ ] ) {
	int cas, n1, n2;
	scanf ( "%d", &cas );
	for ( int t = 1 ; t <= cas ; ++t ) {
		scanf ( "%d%d", &n, &n1 );
		n2 = n;
		int lim = 1 << ( n - 1 );
		n = lim;
		for ( int i = 0 ; i < ( lim ) ; ++i ) {
			for ( int j = 0 ; j < ( lim ) ; ++j ) {
				dp[ i ][ j ] = cal ( i, j, n2 );
				//printf ( "%lld ", dp[ i ][ j ] );
			}
			//puts ( "" );
		}
			
		matrix_mod( dp, n1 - 1 );
		
		long long ans = 0;
		for ( int i = 0 ; i < ( lim ) ; ++i ) {
			for ( int j = 0 ; j < ( lim ) ; ++j ) {
				//printf ( "%lld ", dp[ i ][ j ] );
				ans += dp[ i ][ j ];
				ans %= p;
			}
			//puts ( "" );
		}
		printf ( "Case %d: %lld\n", t, ans % p );
	}
	
	return 0;
}


