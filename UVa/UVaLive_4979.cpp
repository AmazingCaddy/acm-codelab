/*
	author: AmazingCaddy
	time:	2011-07-15 12:48:49 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;

const int maxn = 10;
char g[ maxn ][ maxn ];

int solve( char ch )
{
	int flag = 0;
	for( int i = 0; i < 5; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			if( g[ i ][ j ] == ch && g[ i ][ j + 1 ] == ch && g[ i ][ j + 2 ] == ch )
				return 1;
		}
	}
	for( int i = 0; i < 5; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			if( g[ j ][ i ] == ch && g[ j + 1 ][ i ] == ch && g[ j + 2 ][ i ] == ch )
				return 1;
		}
	}
	for( int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			if( g[ i ][ j ] == ch && g[ i + 1 ][ j + 1 ] == ch && g[ i + 2 ][ j + 2 ] == ch )
				return 1;
		}
	}
	for( int i = 0; i < 3; i++ )
	{
		for( int j = 2; j < 5; j++ )
		{
			if( g[ i ][ j ] == ch && g[ i + 1 ][ j - 1 ] == ch && g[ i + 2 ][ j - 2 ] == ch )
				return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int cas;
	scanf( "%d", &cas );
	while( cas-- )
	{
		for( int i = 0; i < 5; i++ )
			scanf( "%s", g[ i ] );
		int ans1 = solve( 'A' ), ans2 = solve( 'B' );
		if( ( ans1 ^ ans2 ) == 0 ) printf( "draw\n" );
		else 
		{
			if( ans1 > ans2 ) printf( "A wins\n" );
			else printf( "B wins\n" );
		}
	}
	return 0;
}
