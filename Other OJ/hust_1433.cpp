/*
	author: AmazingCaddy
	time: 2011/4/9  17:53
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
using namespace std;
#define lowbit( x ) ((x)&(-(x)))
//typedef __int64 ll;
typedef long long ll;
const int maxn = 100005;
int tree[ maxn ];
//int L[ maxn ], R[ maxn ]; // 左边比i大的个数，右边比i小的个数
int n;

void addtree( int x, int val )
{
	for( ; x && x <= n; x += lowbit( x ) )
		tree[ x ] += val;
}

int query( int x )
{
	int sum = 0;
	for( ; x > 0 ; x -= lowbit( x ) )
		sum += tree[ x ];
	return sum;
}

int main(int argc, char *argv[])
{
	int x, L, R;
	while( scanf( "%d", &n ) != EOF )
	{
		memset( tree, 0, sizeof( tree ) );
		ll cnt = 0;
		for( int i = 0; i < n - 1; i++ )
		{
			scanf( "%d", &x );
			int tmp = query( x );
			L = i - tmp + 1;
			R = x - tmp;
			cnt += R - L;
			if( i ) printf( " " );
			printf( "%lld", cnt );
			//L[ i ] = i - tmp + 1;
			//R[ i ] = x - tmp;
			addtree( x, 1 );
		}
		scanf( "%d", &x );
		printf( "\n" );
		/*
		ll cnt = R[ 0 ] - L[ 0 ];
		printf( "%lld", cnt );
		for( int i = 1; i < n - 1; i++ )
		{
			cnt += R[ i ] - L[ i ];
			printf( " %lld", cnt );
		}
		printf( "\n" );
		*/
	}
	return 0;
}
