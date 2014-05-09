/*
	author : AmazingCaddy
	time : 2011-06-02 19:58:35 
	求 A + A^2 + ... + A^k
	    | A, I |               | A^(k+1), I+A+A^2+...+A^k |
    B = |      |     B^(k+1) = |                          |
   	    | 0, I |               |    0   ,       I         |
   	
   	也就是求 B^(k+1) 
   	
   	| A, B |   | C, D |   | AC, AD+B |
    |      | * |      | = |          |
   	| 0, I |   | 0, I |   |  0,   I  |
   	可以定义矩阵乘法:
   	| A, B | * | C, D | = | AC, AD+B |
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
#define lowbit(x) ((x)&(-(x)))

const int maxn = 32;
const int inf = 0x3fffffff;

void print( int a[ ][ maxn << 1 ], int n )
{
	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < 2 * n; j++ )
			printf( "%d ", a[ i ][ j ] );
		printf( "\n" );
	}
}

void matrix_mul( int a[ ][ maxn << 1 ], int b[ ][ maxn << 1 ], int n, int p )
{
	int c[ maxn ][ maxn << 1 ];
	memset( c, 0, sizeof( c ) );
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			for( int k = 0; k < n; k++ )
				c[ i ][ j ] = ( c[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ] ) % p;
	for( int i = 0; i < n; i++ )
	{
		for( int j = n; j < 2 * n; j++ )
		{
			c[ i ][ j ] = ( c[ i ][ j ] + a[ i ][ j ] ) % p;
			for( int k = 0; k < n; k++ )
				c[ i ][ j ] = ( c[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ] ) % p;
		}
	}
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < 2 * n; j++ )
			a[ i ][ j ] = c[ i ][ j ];
}

void matrix_mod( int a[ ][ maxn << 1 ], int n, int b, int p )
{
	int I[ maxn ][ maxn << 1 ];
	memset( I, 0, sizeof( I ) );
	for( int i = 0; i < n; i++ )
		I[ i ][ i ] = 1;
	while( b )
	{
		if( b & 1 ) matrix_mul( I, a, n, p );
		matrix_mul( a, a, n, p );
		b >>= 1;
	}
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < 2 * n; j++ )
			a[ i ][ j ] = I[ i ][ j ];
}

int main(int argc, char *argv[])
{
	int a[ maxn ][ maxn << 1 ];
	int n, k, m;
	while( scanf( "%d%d%d", &n, &k, &m ) != EOF )
	{
		memset( a, 0, sizeof( a ) );
		for( int i = 0; i < n; i++ ) a[ i ][ i + n ] = 1;
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
				scanf( "%d", &a[ i ][ j ] );
		matrix_mod( a, n, k + 1, m );
		for( int i = 0; i < n; i++ )
		{
			a[ i ][ i + n ]--;
			if( a[ i ][ i + n ] < 0 ) a[ i ][ i + n ] += m;
		}
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				if( j ) printf( " " );
				printf( "%d", a[ i ][ j + n ] );
			}
			printf( "\n" );
		}
	}
	return 0;
}
