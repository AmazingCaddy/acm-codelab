/*
    author: AmazingCaddy
    time: 16/05/2011 14:16:47 
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
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long ll;
const int maxn = 1000006;
int a[ maxn ];
int tree[ maxn ];
int len;

int Max( int a, int b ) { return ( a > b ? a : b ); }

int DFS( ll n )
{
	if( n < maxn && a[ n ] ) return a[ n ];
	int tmp;
	if( n % 2 == 1 ) tmp = DFS( 3 * n + 1 );
	else tmp = DFS( n / 2 );
	if( n < maxn ) a[ n ] = tmp + 1;
	return tmp + 1;
}

void init( )
{
	memset( a, 0, sizeof( a ) );
	a[ 1 ] = 1;
	for( int i = 2; i < maxn; i++ )
		if( !a[ i ] ) { a[ i ] = DFS( i ); }
}

void InitMax( )
{
	for( int i = 1; i < maxn; i++ )
	{
		tree[ i ] = a[ i ];
		for( int j = 1; j < lowbit( i ); j <<= 1 )
			tree[ i ] = Max( tree[ i ], tree[ i - j ] );
	}
}

int query( int l, int r )
{
	int ans = a[ r ];
	while( 1 )
	{
		ans = Max( ans, a[ r ] );
		if( r == l ) break;
		for( r -= 1; r - l >= lowbit( r ); r -= lowbit( r ) )
			ans = Max( ans, tree[ r ] );
	}
	return ans;
}

int main( int ac, char * av[ ] )
{
	int l, r, ans;
	init( );
	InitMax( );
	while( scanf( "%d%d", &l, &r ) != EOF )
	{
		ans = 0;
		printf( "%d %d", l, r );
		if( l > r ) swap( l, r );
		printf( " %d\n", query( l, r ) );
	}
    return 0;
}
