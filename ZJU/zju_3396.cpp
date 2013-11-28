/*
	author: AmazingCaddy
	time: 2011/4/15  0:29
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn = 504;
const int maxm = 10004;
const int inf = 100000000;
struct node
{
	int u;
	int d;
	node( ) { }
	node( int _u, int _d ) : u( _u ), d( _d ) { }
};
vector< node > mat[ maxn ];
int in[ maxn ];
bool inque[ maxn ];
int dis1[ maxn ], dis2[ maxn ], dis3[ maxn ];

int Min( int a, int b ) { return ( a < b ? a : b ); }
bool SPFA( int st, int n, int dis[ ] )
{
	queue< int > que;
	memset( in, 0, sizeof( in ) );
	memset( inque, false, sizeof( inque ) );
	for( int i = 0; i < maxn; i++ )
		dis[ i ] = inf;
	que.push( st );
	dis[ st ] = 0;
	in[ st ]++;
	inque[ st ] = true;
	while( !que.empty( ) )
	{
		int x = que.front( );
		int t;
		que.pop( );
		inque[ x ] = false;
		for( int i = 0; i < mat[ x ].size( ); i++ )
		{
			if( dis[ x ] + mat[ x ][ i ].d < dis[ t = mat[ x ][ i ].u ] )
			{
				dis[ t ] = dis[ x ] + mat[ x ][ i ].d;
				if( !inque[ t ] )
				{
					que.push( t );
					++in[ t ];
					if( in[ t ] >= n ) return true;
					inque[ t ] = true;
				}
			}
		}
	}
	return false;
}
int tel[ maxm ];

int main(int argc, char *argv[])
{
	int n, m, l, q, k = 1;
	int x, y, z, u, v, val;
	while( scanf( "%d %d %d", &n, &m, &l ) != EOF )
	{
		for( int i = 1; i <= n; i++ )
			scanf( "%d", &tel[ i ] );
		for( int i = 0; i < maxn; i++ )
			mat[ i ].clear( );
		for( int i = 0; i < l; i++ )
		{
			scanf( "%d %d %d", &u, &v, &val );
			mat[ u ].push_back( node( v, val ) );
			mat[ v ].push_back( node( u, val ) );
		}
		scanf( "%d", &q );
		printf( "Case #%d\n", k++ );
		for( int t = 1; t <= q; t++ )
		{
			scanf( "%d %d %d", &x, &y, &z );
			SPFA( tel[ x ], m, dis1 );
			SPFA( tel[ y ], m, dis2 );
			SPFA( tel[ z ], m, dis3 );
			int ans = inf;
			for( int i = 1; i <= m; i++ )
				ans = Min( ans, dis1[ i ] + dis2[ i ] + dis3[ i ] );
			if( ans == inf )
				printf( "Line %d: Impossible to connect!\n", t );
			else printf( "Line %d: The minimum cost for this line is %d.\n", t, ans );
		}
	}
	return 0;
}
