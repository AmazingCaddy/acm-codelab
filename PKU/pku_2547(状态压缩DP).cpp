/*
    author: AmazingCaddy
    time: 26/05/2011 17:44:59
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 1 << 20;
const int inf = 1000000000;

struct node
{
	int x;
	int val;
};
node bag[ 30 ];

int pre[ maxn ];
bool dp[ maxn ];
//int vis[ maxn ];
int liju[ maxn ][ 2 ];
int L, W, N;
int g[ 30 ];

int check( int n, int m )
{
	int sum1 = liju[ n ][ 0 ] - ( bag[ m ].x + 3 ) * bag[ m ].val;
	int sum2 = liju[ n ][ 1 ] - ( bag[ m ].x - 3 ) * bag[ m ].val;
	if( sum1 < 0 || sum2 > 0 ) return 0;
	int tmp = n | g[ m ];
	liju[ tmp ][ 0 ] = sum1;
	liju[ tmp ][ 1 ] = sum2;
	return 1;
}

void print( int n, int m )
{
	if( m == 0 )
	{
		//printf( "%d %d\n", bag[ n ].x / 2, bag[ n ].val );
		return ;
	}
	print( pre[ m ^ g[ n ] ], m ^ g[ n ] );
	printf( "%d %d\n", bag[ n ].x / 2, bag[ n ].val );
}

int main( int ac, char * av[ ] )
{
	int t = 1;
	for( int i = 0; i < 30; i++ )
		g[ i ] = 1 << i;
	while( 1 )
	{
		scanf( "%d%d%d", &L, &W, &N );
		if( L == 0 && W == 0 && N == 0 ) break;
		for( int i = 0; i < N; i++ )
		{
			scanf( "%d%d", &bag[ i ].x, &bag[ i ].val );
			bag[ i ].x *= 2;
		}
		W = W * 3;
		int len =  1 << N;
		memset( dp, false, sizeof( dp ) );
		memset( pre, -1, sizeof( pre ) );
		//memset( vis, -1, sizeof( vis ) );
		dp[ 0 ] = 1;
		liju[ 0 ][ 0 ] = W;
		liju[ 0 ][ 1 ] = -W;
		for( int i = 0; i < N; i++ )
		{
			liju[ 0 ][ 0 ] += ( bag[ i ].x + 3 ) * bag[ i ].val;
			liju[ 0 ][ 1 ] += ( bag[ i ].x - 3 ) * bag[ i ].val;
		}	
		for( int i = 0; i < len; i++ )
		{
			if( !dp[ i ] ) continue;
			for( int j = 0; j < N; j++ )
			{
				//if( dp[ i ] && !( i & ( 1 << j ) ) && check( i | ( 1 << j ) ) )
				if( !( i & g[ j ] ) && !dp[ i | g[ j ] ] )
				{
					if( check( i, j ) )
					{
						//dp[ i | ( 1 << j ) ] = 1;
						//pre[ i | ( 1 << j ) ] = j;
						int tmp = i | g[ j ];
						dp[ tmp ] = true;
						pre[ tmp ] = j;
					}
				}
			}
		}
		printf( "Case %d:\n", t++ );
		if( dp[ len - 1 ] ) print( pre[ len - 1 ], len - 1 );
		else printf( "Impossible\n" );
	}
	return 0;
}

