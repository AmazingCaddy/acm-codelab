/*
    author: AmazingCaddy
    time: 26/05/2011 20:41:09 
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

const int maxn = 4004;
const int inf = 1000000000;

struct node
{
	int h, l, t;
};
node bg[ 40 ];

int dp[ maxn ];

int Max( int a, int b ) { return ( a > b ? a : b ); }

bool cmp( const node & a, const node & b )
{
	return a.t < b.t;
}

int main( int ac, char * av[ ] )
{
	int n;
	while( scanf( "%d", &n ) != EOF && n >= 0 )
	{
		//int m = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d%d%d", &bg[ i ].h, &bg[ i ].l, &bg[ i ].t );
			//if( bg[ i ].t < m ) m = bg[ i ].t;
		}
		sort( bg, bg + n, cmp );
		memset( dp, 0, sizeof( dp ) );
		for( int i = 0; i < n; i++ )
		{
			for( int j = bg[ i ].t; j >= bg[ i ].l; j-- )
			{
				dp[ j ] = Max( dp[ j ], dp[ j - bg[ i ].l ] + bg[ i ].h );
			}
		}
		int ans = 0;
		for( int i = 0; i <= bg[ n - 1 ].t; i++ )
			if( dp[ i ] > ans ) ans = dp[ i ];
		printf( "%d\n", ans );
	}
	return 0;
}
