/*
	author: AmazingCaddy
	time: 2011/3/27  15:35
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 505;

int num[ maxn ], g[ maxn ][ maxn ];

int gcd( int a, int b )
{
	return b ? gcd( b, a % b ) : a;
}

void init( int n )
{
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			g[ i ][ j ] = gcd( num[ i ], num[ j ] );
}

int main(int argc, char *argv[])
{
	int n;
	scanf( "%d", &n );
	for( int i = 0; i < n; i++ )
		scanf( "%d", &num[ i ] );
	init( n );
	int ans = 0;
	for( int i = 0; i < n; i++ )
	{
		int a = 0, b = 0;
		for( int j = 0; j < n; j++ )
		{
			if( i == j )continue;
			if( g[ i ][ j ] == 1 ) a++;
			else b++;
		}
		ans += a * b;
	}
	printf( "%d\n", n*(n - 1)*(n - 2)/6-ans/2);
	return 0;
}
