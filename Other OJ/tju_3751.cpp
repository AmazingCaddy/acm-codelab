#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 203;
const double eps = 1e-8;
const double pi = acos( -1.0 );
const int inf = 0x3fffffff;

int cx[ maxn ], cy[ maxn ], lx[ maxn ], ly[ maxn ], sx[ maxn ], sy[ maxn ];
int nx, ny, g[ maxn ][ maxn ];

int path( int u )
{
	sx[ u ] = 1;
	for( int v = 1; v <= ny; v++ ) 
		if( g[ u ][ v ] == lx[ u ] + ly[ v ] && !sy[ v ] )
		{
			sy[ v ] = 1;
			if( !cy[ v ] || path( cy[ v ] ) )
			{
				cx[ u ] = v;
				cy[ v ] = u;
				return 1;
			}
		}
	return 0;
}

int KuhnMunkres( int maxsum = 1 ) // 1: maximum  0: minimum
{
	int i, j, u, min;
	memset( cx, 0, sizeof( cx ) ); memset( cy, 0, sizeof( cy ) );
	if( !maxsum )
        for( i = 1; i <= nx; i++ )
            for( j = 1; j <= ny; j++ )
                g[ i ][ j ] = -g[ i ][ j ];
	for( i = 1; i <= nx; i++ )
	{
		lx[ i ] = -inf; ly[ i ] = 0;
		for( j = 1; j <= ny; j++ )
			if( lx[ i ] < g[ i ][ j ] ) lx[ i ] = g[ i ][ j ];
	}
	for( u = 1; u <= nx; u++ ) if( !cx[ u ] )
	{
		memset( sx, 0, sizeof( sx ) );
		memset( sy, 0, sizeof( sy ) );
		while( !path( u ) )
		{
			min = inf;
			for( i = 1; i <= nx; i++ ) if( sx[ i ] )
			for( j = 1; j <= ny; j++ ) if( !sy[ j ] )
				if( lx[ i ] + ly[ j ] - g[ i ][ j ] < min )
					min = lx[ i ] + ly[ j ] - g[ i ][ j ];
			for( i = 1; i <= nx; i++ ) if( sx[ i ] ) { lx[ i ] -= min; sx[ i ] = 0; }
			for( j = 1; j <= ny; j++ ) if( sy[ j ] ) { ly[ j ] += min; sy[ j ] = 0; }
		}
	}
	int match = 0;
	for( i = 1; i <= nx; i++ )
		match += g[ i ][ cx[ i ] ];
	if( !maxsum )
    {
        match = -match;
		/*
        for( i = 1; i <= nx; i++ )
            for( j = 1; j <= ny; j++ )
                g[ i ][ j ] = -g[ i ][ j ];
		*/
		// 如果需要保持 g[ ] [ ] 原来的值，这里需要将其还原
	}
	return match;
}

char str[ 1002 ][ 1002 ];

int LCP( int a, int b )
{
	int na = strlen( str[ a ] );
	int nb = strlen( str[ b ] );
	int sum = 0;
	for( int i = na - 1, j = 0; i >= 0 && j < nb; i--, j++ )
	{
		if( str[ a ][ i ] == str[ b ][ j ] ) sum++;
		else break;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int n;
	while( scanf("%d",&n) != EOF )
	{
		for( int i = 0; i < n; i++ )
			scanf("%s",str[i]);
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				if( i == j ) g[ i + 1 ][ j + 1 ] = 0;
				else g[ i + 1 ][ j + 1 ] = LCP( i, j );
			}
		}
		nx = ny = n;
		printf("%d\n",KuhnMunkres( ));
	}
	return 0;
}
