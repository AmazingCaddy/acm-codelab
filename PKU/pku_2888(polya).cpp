/*
	author: wwb
	time: 2011/2/26  22:40
	解法：polya  sum=sigma(Euler(n/i)*Gettr(i)){ i|n }
	主要是计算Gettr(i)的问题
	我们把m种颜色的关系画成一个无向图，而Gettr(i)就是长度为 i 的回路的个数
	把无向图表示成邻接矩阵 G[maxn][maxn]，
	Gettr(i)就是这个矩阵的 i 次幂的迹，也就是 Tr(G^i)
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 11;
const int maxm = 32000;
const int P = 9973;
int vis[ maxm ], p[ maxm ];
int plen, flen;
int aa[ 32 ], bb[ 32 ];
int n, m, ans;
int M[ 32 ][ maxn ][ maxn ];
void prime( )
{
	int i, j, k;
	plen = 0;
	memset( vis, 0, sizeof( vis ) );
	for( i = 2, k = 4; i < maxm; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
		{
			p[ plen++ ] = i;
			if( k < maxm ) for( j = k; j < maxm; j += i ) vis[ j ] = 1;
		}
	}
}

int pow_mod( int a, int b, int c )
{
	int ans = 1, d = a % c;
	while( b )
	{
		if( b & 1 ) ans = ans * d % c;
		d = d * d % c;
		b >>= 1;
	}
	return ans;
}

void matrix_mul( int a[ ][ maxn ], int b[ ][ maxn ], int p )
{
	int c[ maxn ][ maxn ];
	for( int i = 0; i < m; i++ )
	{
		for( int j = 0; j < m; j++ )
		{
			c[ i ][ j ] = 0;
			for( int k = 0; k < m; k++ )
				c[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];
		}
	}
	for( int i = 0; i < m; i++ )
		for( int j = 0; j < m; j++ )
			a[ i ][ j ] = c[ i ][ j ] % p;
}

int matrix_mod( int a[ ][ maxn ], int b, int c )
{
	int ans[ maxn ][ maxn ];
	memset( ans, 0, sizeof( ans ) );
	for( int i = 0; i < m; i++ ) ans[ i ][ i ] = 1;
	int j = 0;
	while( b )
	{
		if( b & 1 ) matrix_mul( ans, M[ j ], c );
		b >>= 1;
		j++;
	}
	int sum = 0;
	for( int i = 0; i < m; i++ )
		sum = ( sum + ans[ i ][ i ] ) % c;
	return sum;
}

void factor( int n )
{
	flen = 0;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			for( bb[ flen ] = 0; n % p[ i ] == 0; ++bb[ flen ], n /= p[ i ] );
			aa[ flen++ ] = p[ i ];
		}
	}
	if( n > 1 ) bb[ flen ] = 1, aa[ flen++ ] = n;
} 

int elur( int n )
{
	int phi = n;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			while( n % p[ i ] == 0 ) n /= p[ i ];
			phi -= phi / p[ i ];
		}
	}
	if( n > 1 ) phi -= phi / n;
	return phi;
}

int inv( int n, int p )
{
	return pow_mod( n, elur( p ) - 1, p );
}

int e[ maxn ][ maxn ], g[ maxn ][ maxn ];

void init( int c )
{
	for( int i = 0; i < m; i++ )
		for( int j = 0; j < m; j++ )
			M[ 0 ][ i ][ j ] = g[ i ][ j ];
	for( int i = 1; i < 32; i++ )
	{
		for( int j = 0; j < m; j++ )
		{
			for( int k = 0; k < m; k++ )
			{
				M[ i ][ j ][ k ] = 0;
				for( int l = 0; l < m; l++ )
					M[ i ][ j ][ k ] += M[ i - 1 ][ j ][ l ] * M[ i - 1 ][ l ][ k ];
				M[ i ][ j ][ k ] %= c;
			}
		}
	}
}

void DFS( int dep, int sum )
{
	if( dep == flen )
	{
		for( int i = 0; i < m; i++ )
			for( int j = 0; j < m; j++ )
				e[ i ][ j ] = g[ i ][ j ];
		ans = ( ans + elur( n / sum ) % P * matrix_mod( e, sum, P ) % P ) % P;
		return;
	}
	for( int tmp = 1, i = 0; i <= bb[ dep ]; tmp *= aa[ dep ], i++ )
		DFS( dep + 1, sum * tmp );
}

int main(int argc, char *argv[])
{
	int k, x, y, cas;
	prime( );
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d %d %d", &n, &m, &k );
		for( int i = 0; i < m; i++ )
			for( int j = 0; j < m; j++ )
				g[ i ][ j ] = 1;
		for( int i = 0; i < k; i++ )
		{
			scanf( "%d %d", &x, &y );
			g[ x - 1 ][ y - 1 ] = g[ y - 1 ][ x - 1 ] = 0;
		}
		init( P );
		factor( n );
		ans = 0;
		DFS( 0, 1 );
		ans = ans * inv( n, P ) % P;
		printf( "%d\n", ans ); 
	}
	return 0;
}
