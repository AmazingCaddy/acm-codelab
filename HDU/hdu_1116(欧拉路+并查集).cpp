/*
	author: AmazingCaddy
	time: 2011/4/2 1:22
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

const int maxn = 1004;
int f[ 30 ], r[ 30 ];

void init( )
{
	for( int i = 0; i < 30; i++ )
		f[ i ] = i, r[ i ] = 1;
}

int find_root( int n )
{
	if( f[ n ] == n ) return n;
	return f[ n ] = find_root( f[ n ] );
}

void union_set( int x, int y )
{
	x = find_root( x );
	y = find_root( y );
	if( x != y )
	{
		if( r[ x ] > r[ y ] )
		{
			f[ y ] = x;
			r[ x ] += r[ y ];
		}
		else 
		{
			f[ x ] = y;
			r[ y ] += r[ x ];
		}
	}
}

char buf[ maxn ];
int a[ 30 ], b[ 30 ];
int main(int argc, char *argv[])
{
	int cas, n, x, y;
	scanf( "%d", &cas );
	while( cas -- )
	{
		scanf( "%d", &n );
		init( );
		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%s", buf );
			x = buf[ 0 ] - 'a';
			y = buf[ strlen( buf ) - 1 ] - 'a';
			union_set( x, y );
			a[ x ]++;
			b[ y ]++;
		}
		int m = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for( int i = 0; i < 26; i++ )
		{
			if( a[ i ] == 0 && b[ i ] == 0 ) continue;
			m++;
			if( abs( a[ i ] - b[ i ] ) == 1 ) cnt1++;
			if( a[ i ] == b[ i ] ) cnt2++;
			if( find_root( i ) == i ) cnt3++;
		}
		if( cnt3 == 1 && ( cnt1 == 2 && cnt2 == m - 2 || cnt2 == m ) )
			printf( "Ordering is possible.\n" );
		else printf( "The door cannot be opened.\n" );
	}
	return 0;
}
