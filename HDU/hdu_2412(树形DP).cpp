/*
	author: AmazingCaddy
	time: 2011/5/9  20:00
	dp[ 0 ][ i ] 表示不取第i个人, 得到的最大人数
	dp[ 1 ][ i ] 表示取了第i个人, 得到的最大人数
	dup[ 0 ][ i ] 表示不取第i个人是否唯一解
	dup[ 1 ][ i ] 表示取了第i个人是否唯一解
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

const int maxn = 240;
map<string, int> mm;
vector<int> g[ maxn ];
int dp[ 2 ][ maxn ];
int dup[ 2 ][ maxn ];

int Max( int a, int b ) { return ( a > b ? a : b ); }

void DFS( int u )
{
	int sz = g[ u ].size( );
	if( sz == 0 )
	{
		dp[ 0 ][ u ] = 0;
		dp[ 1 ][ u ] = 1;
		dup[ 0 ][ u ] = dup[ 1 ][ u ] = 1;
		return;
	}
	int sum0 = 0, sum1 = 0;
	int flag0 = 1, flag1 = 1;
	for( int i = 0; i < sz; i++ )
	{
		DFS( g[ u ][ i ] );
		sum0 += Max( dp[ 0 ][ g[ u ][ i ] ], dp[ 1 ][ g[ u ][ i ] ] );
		sum1 += dp[ 0 ][ g[ u ][ i ] ];
		if( dp[ 0 ][ g[ u ][ i ] ] > dp[ 1 ][ g[ u ][ i ] ] && dup[ 0 ][ g[ u ][ i ] ] == 0
			|| dp[ 1 ][ g[ u ][ i ] ] > dp[ 0 ][ g[ u ][ i ] ] && dup[ 1 ][ g[ u ][ i ] ] == 0 
			|| dp[ 0 ][ g[ u ][ i ] ] == dp[ 1 ][ g[ u ][ i ] ] ) flag0 = 0;
		if( dup[ 0 ][ g[ u ][ i ] ] == 0 ) flag1 = 0;
	}
	dp[ 0 ][ u ] = sum0;
	dp[ 1 ][ u ] = sum1 + 1;
	dup[ 0 ][ u ] = flag0;
	dup[ 1 ][ u ] = flag1;
}

int main(int argc, char *argv[])
{
	int n;
	char buf1[ maxn ], buf2[ maxn ];
	while( scanf( "%d", &n ) && n )
	{
		scanf( "%s", buf1 );
		for( int i = 1; i < maxn; i++ )
			g[ i ].clear( );
		mm.clear( );
		mm[ buf1 ] = 1;
		int len = 2;
		for( int i = 1; i < n; i++ )
		{
			scanf( "%s%s", buf1, buf2 );
			if( mm[ buf1 ] == 0 ) mm[ buf1 ] = len++;
			if( mm[ buf2 ] == 0 ) mm[ buf2 ] = len++;
			g[ mm[ buf2 ] ].push_back( mm[ buf1 ] );
		}
		DFS( 1 );
		
		int ans = Max( dp[ 0 ][ 1 ], dp[ 1 ][ 1 ] );
		printf( "%d ", ans );
		if( dp[ 1 ][ 1 ] > dp[ 0 ][ 1 ] && dup[ 1 ][ 1 ] == 0
			|| dp[ 0 ][ 1 ] > dp[ 1 ][ 1 ] && dup[ 0 ][ 1 ] == 0 
			|| dp[ 0 ][ 1 ] == dp[ 1 ][ 1 ] ) printf( "No\n" );
		else printf( "Yes\n" );
	}
	return 0;
}
