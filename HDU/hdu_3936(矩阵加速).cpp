/*
	author: AmazingCaddy
	time:	2011/8/11  19:54
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int maxn = 3;

const ll gen[ maxn ][ maxn ] =  { 	{ 1, 1, 2 }, 
									{ 0, 2, 3 },
									{ 0, 3, 5 }	
								};
int vec[ maxn ] = { 2, 3, 5 };

void matrix_mul( ll a[ ][ maxn ], ll b[ ][ maxn ] )
{
	ll c[ maxn ][ maxn ];
	memset( c, 0, sizeof( c ) );
	for( int i = 0; i < maxn; i++ )
		for( int j = 0; j < maxn; j++ )
			for( int k = 0; k < maxn; k++ )
				c[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
	for( int i = 0; i < maxn; i++ )
		for( int j = 0; j < maxn; j++ )
			a[ i ][ j ] = c[ i ][ j ] % mod;
}

ll matrix_mod( ll a[ ][ maxn ], ll b )
{
//	cout << "b = " << b << endl;
	if( b < 0 ) return 0;
	ll I[ maxn ][ maxn ];
	memset( I, 0, sizeof( I ) );
	for( int i = 0; i < maxn; i++ ) I[ i ][ i ] = 1;
	while( b )
	{
		if( b & 1 ) matrix_mul( I, a );
		matrix_mul( a, a );
		b >>= 1;
	}
	ll ans = 0;
	for( int j = 0; j < maxn; j++ )
		ans += vec[ j ] * I[ 0 ][ j ];
	return ans % mod;
}

int main(int argc, char *argv[])
{
	int cas;
	ll L, R;
	ll a[ maxn ][ maxn ];
	scanf( "%d", &cas );
	while( cas -- ) {
		scanf( "%I64d%I64d", &L, &R );
//		scanf( "%lld%lld", &L, &R );
		memcpy( a, gen, maxn * maxn * sizeof( ll ) );
		ll ans1 = matrix_mod( a, R - 1 );
		memcpy( a, gen, maxn * maxn * sizeof( ll ) );
		ll ans2 = matrix_mod( a, L - 2 );
		printf( "%I64d\n", ( ( ans1 - ans2 ) % mod + mod ) % mod );
//		printf( "%lld\n", ( ( ans1 - ans2 ) % mod + mod ) % mod );
	}
	return 0;
}
