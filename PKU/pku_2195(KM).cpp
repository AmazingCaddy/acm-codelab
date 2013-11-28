#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <complex>

const int maxn = 102;
const int inf = 0x3fffffff;

int cx[ maxn ], cy[ maxn ], lx[ maxn ], ly[ maxn ], sx[ maxn ], sy[ maxn ];
int nx, ny, match, g[ maxn ][ maxn ];

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

void KuhnMunkres( int maxsum = 1 )
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
	//for( i = 1; i <= nx; i++ )
	//	printf("%d %d\n",cy[i], i);
	match = 0;
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
}

char m[ maxn ][ maxn ];
int Hou[ maxn ][ 2 ], Man[ maxn ][ 2 ];

int main(int argc, char *argv[])
{
	int N, M;
	while( 1 )
	{
		scanf("%d%d",&N,&M);
		if( N == 0 && M == 0 ) break;
		for( int i = 0; i < N; i++ )
			scanf("%s",m[i]);
		nx = ny = 0;
		for( int i = 0; i < N; i++ )
		{
			for( int j = 0; j < M; j++ )
			{
				if( m[ i ][ j ] == 'H' ) 
					Hou[ ++nx ][ 0 ] = i, Hou[ nx ][ 1 ] = j;
				if( m[ i ][ j ] == 'm' )
					Man[ ++ny ][ 0 ] = i, Man[ ny ][ 1 ] = j;
			}
		}
		for( int i = 1; i <= nx; i++ )
			for( int j = 1; j <= ny; j++ )
				g[ i ][ j ] = abs( Hou[ i ][ 0 ] - Man[ j ][ 0 ] ) + 
								abs( Hou[ i ][ 1 ] - Man[ j ][ 1 ] );
		//for( int i = 1; i <= nx; i++ )
		//{
		//	for( int j = 1; j <= ny; j++ )
		////		printf("%d ",g[i][j]);
		//	printf("\n");
		//}
		//printf("%d %d\n",nx, ny);
		KuhnMunkres( 0 );
		printf("%d\n",match);
	}
	return 0;
}
