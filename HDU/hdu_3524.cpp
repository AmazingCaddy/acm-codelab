#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
const int mod = 10007;
const int maxn = 3;

void matrix_mul( int a[][maxn], int b[][maxn] )
{
	int c[maxn][maxn];
	memset( c, 0, sizeof( c ) );
	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 2; j++ )
			for( int k = 0; k < 2; k++ )
				c[i][j] = ( c[i][j] + a[i][k] * b[k][j] ) % mod;
	for( int i = 0; i < 2; i++ )
		for( int j = 0; j < 2; j++ )
			a[i][j] = c[i][j] % mod;
}

int matrix_mod( int a[][maxn], int vec[maxn], int b )
{
	int I[maxn][maxn];
	I[0][0] = I[1][1] = 1; I[0][1] = I[1][0] = 0;
	while( b )
	{
		if( b & 1 ) matrix_mul( I, a );
		matrix_mul( a, a );
		b >>= 1;
	}
	return ( ( I[0][0] * vec[0] + I[0][1] * vec[1] ) % mod + mod ) % mod;
}

int main(int argc, char *argv[])
{
	int t, n, ans, k = 1;
	int a[maxn][maxn], vec[maxn];
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		if( n == 1 ) ans = 2;
		else if( n == 2 ) ans = 2;
		else if( n == 3 ) ans = 3;
		else
		{
			a[0][0] = 4, a[0][1] = 1, a[1][0] = 0, a[1][1] = 1;
			if( n % 2 )
			{
				vec[0] = 3, vec[1] = -5;
				ans = matrix_mod( a, vec, ( n - 3 ) / 2 );
			}
			else
			{
				vec[0] = 2, vec[1] = -4;
				ans = matrix_mod( a, vec, ( n - 2 ) / 2 );
			}
		}
		printf("Case #%d: %d\n",k++,ans);
	} 
	return 0;
}
