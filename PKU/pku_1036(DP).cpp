/*
    author: AmazingCaddy
    time: 18/05/2011 13:50:54 
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

const int maxn = 104;
const int inf = 100000000;
struct node
{
	int ti;
	int pi;
	int si;
};
node gan[ maxn ];
int dp[ maxn ];

bool cmp( const node &a, const node &b )
{
	return a.ti < b.ti;
}

int Max( int a, int b ) { return ( a > b ? a : b ); }

int main( int ac, char * av[ ] )
{
	int N, K, T;
	while( scanf( "%d%d%d", &N, &K, &T ) != EOF )
	{
		for( int i = 1; i <= N; i++ )
			scanf( "%d", &gan[ i ].ti );
		for( int i = 1; i <= N; i++ )
			scanf( "%d", &gan[ i ].pi );
		for( int i = 1; i <= N; i++ )
			scanf( "%d", &gan[ i ].si );
		gan[ 0 ].ti = 0;
		gan[ 0 ].pi = 0;
		gan[ 0 ].si = 0;
		sort( gan + 1, gan + N + 1, cmp );
		
		for( int i = 1; i <= N; i++ )
			dp[ i ] = -1;
		dp[ 0 ] = 0;
		for( int i = 1; i <= N; i++ )
		{
			int max = -1;
			for( int j = 0; j < i; j++ )
				if( dp[ j ] > max && 
				gan[ i ].ti - gan[ j ].ti >= abs( gan[ i ].si - gan[ j ].si ) ) 
					max = dp[ j ];
			if( max >= 0 ) dp[ i ] = max + gan[ i ].pi;
		}
		int ans = 0;
		for( int i = 1; i <= N; i++ )
			ans = Max( ans, dp[ i ] );
		printf( "%d\n", ans );
	}
	return 0;
}
