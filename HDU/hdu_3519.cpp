#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>

using namespace std;
const int mod = 10007;
const int maxn = 5;
void matrix_mul( int a[][maxn], int b[][maxn] )
{
	int c[maxn][maxn];
	memset( c, 0, sizeof( c ) );
	for( int i = 0; i < 4; i++ )
		for( int j = 0; j < 4; j++ )
			for( int k = 0; k < 4; k++ )
				c[i][j] = ( c[i][j] + a[i][k] * b[k][j] ) % mod;
	for( int i = 0; i < 4; i++ )
		for( int j = 0; j < 4; j++ )
			a[i][j] = c[i][j] % mod;
}

int matrix_mod( int a[][maxn], int b )
{
	int I[maxn][maxn];
	for( int i = 0 ; i < 4; i++ )
	{
		I[i][i] = 1;
		for( int j = i + 1; j < 4; j++ )
			I[i][j] = I[j][i] = 0;
	}
	while( b )
	{
		if( b & 1 ) matrix_mul( I, a );
		matrix_mul( a, a );
		b >>= 1;
	}
	int ans = 0;
	int vec[maxn];
	vec[0] = vec[3] = vec[1] = vec[2] = 1;
	for( int i = 0; i < 4; i++ )
	{
		for( int j = 0; j < 4; j++ )
			ans += vec[j] * I[i][j];
		ans %= mod;
	}
	return ans % mod;
}

int pow_mod( int a, int b )
{
	int ans = 1, d = a % mod;
	while( b )
	{
		if( b & 1 ) ans = ans * d % mod;
		d = d * d % mod;
		b >>= 1;
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int n, ans;
	int a[maxn][maxn];
	while( scanf("%d",&n) != EOF )
	{
		if( n <= 2 ) ans = 0;
		else
		{
			ans = pow_mod( 2, n );
			memset( a, 0, sizeof( a ) );
			a[0][2] = a[1][0] = a[1][2] = a[2][1] = a[2][3] = a[3][1] = 1;
			ans = ans - matrix_mod( a, n - 2 );
			ans = ( ans % mod + mod ) % mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
