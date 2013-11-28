#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
using namespace std;

typedef __int64 ll;
const int maxn = 60;

int x, y;
ll n, m;
ll C[maxn][maxn], vec[maxn];
ll I[maxn][maxn];

void init( )
{
	for( int i = 1; i < maxn; i++ )
	{
		for( int j = 0; j <= i; j++ )
			if( j == 0 || j == i ) C[i][j] = 1 % m;
			else C[i][j] = ( C[i-1][j] + C[i-1][j-1] ) % m;
	}
}

void matrix_multi( ll a[][maxn], ll b[][maxn] )
{
	ll c[maxn][maxn];
	memset( c, 0, sizeof( c ) );
	for( int i = 0; i < y; i++ )
		for( int j = 0; j < y; j++ )
			for( int k = 0; k < y; k++ )
				c[i][j] = ( c[i][j] + a[i][k] * b[k][j] ) % m;
	for( int i = 0; i < y; i++ )
		for( int j = 0; j < y; j++ )
			a[i][j] = c[i][j];
}

void matrix_pow( ll a[][maxn], ll b )
{
	memset( I, 0, sizeof( I ) );
	for( int i = 0; i < y; i++ )
		I[i][i] = 1;
	while( b )
	{
		if( b & 1 ) matrix_multi( I, a );
		matrix_multi( a, a );
		b >>= 1;
	}
}

int main(int argc, char *argv[])
{
	//freopen("simple.in","r",stdin);
	//freopen("out.txt","w",stdout);
	ll a[maxn][maxn];
	while( 1 )
	{
		scanf("%I64d%d%I64d",&n,&x,&m);
		if( n == -1 && x == -1 && m == -1 ) break;
		init( );
		memset( a, 0, sizeof( a ) );
		a[0][0] = x % m; a[0][x+1] = 1;
		y = x + 2;
		for( int i = 1; i <= x; i++ )
		{
			a[i][i] = x % m;
			for( int j = 0; j < i; j++ )
			{
				for( int k = 0; k < y; k++ )
				{
					a[i][k] += a[j][k] * C[i][j] * ( ( i - j ) % 2 ? 1 : -1 );
					a[i][k] %= m;
					a[i][k] += m;
					a[i][k] %= m;
				}
			}
		}
		a[y-1][y-1] = 1;
		matrix_pow( a, n - 1 );
		for( int i = 0; i < y; i++ )
			vec[i] = x % m;
		ll ans = 0;
		for( int i = 0; i < y; i++ )
			ans = ( ans + I[x][i] * vec[i] ) % m;
		printf("%I64d\n",ans);
	}
	return 0;
}
