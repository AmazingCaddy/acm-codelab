/*
author: AmazingCaddy
time: 2011/4/16  13:51
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

const int maxn = 120;
char str[ maxn ];
int next[ maxn ];
char buf[ maxn ];
bool check( char ch )
{
	return ( ( ch <= '9' && ch >= '0' ) || ( ch <= 'Z' && ch >= 'A' ) || ( ch <= 'z' && ch >= 'a' ) );
}

int main(int argc, char *argv[])
{
	//freopen( "in.txt", "r", stdin );
	//freopen( "out2.txt", "w", stdout );
	int cas, n;
	scanf( "%d", &cas );
	while( cas-- )
	{
		memset( str, 0, sizeof( str ) );
		scanf( "%s%d", str + 1, &n );
		int len = strlen( str + 1 );
		for( int i = 1; i <= ( len + 1 ) / 2; i++ )
			swap( str[ i ], str[ len + 1 - i ] );
		memset( next, -1, sizeof( next ) );
		int p = 0;
		for( int i = 1; i <= len; i++ )
			if( check( str[ i ] ) )
				next[ p ] = i, p = i;

		int t = ( !p ? p + 2 : p + 1 );
		for( int i = t; i <= len; i++ )
		{
			buf[ i - t ] = str[ i ];
			str[ i ] = 0;
		}

		if( p == 0 ) next[ 0 ] = 1;

		int st = next[ 0 ];
		for( int i = 0; i < n; i++ )
		{
			str[ st ]++;
			int q = st, r;
			while( q != -1 )
			{
				if( str[ q ] == '9' + 1 )
				{
					str[ q ] = '0';
					r = next[ q ];
					if( r == -1 ) r = next[ q ] = q + 1;
					if( str[ r ] == 0 ) str[ r ] = '1';
					else str[ r ]++;
				}
				else if( str[ q ] == 'Z' + 1 )
				{
					str[ q ] = 'A';
					r = next[ q ];
					if( r == -1 ) r = next[ q ] = q + 1;
					if( str[ r ] == 0 ) str[ r ] = 'A';
					else str[ r ]++;
				}
				else if( str[ q ] == 'z' + 1 )
				{
					str[ q ] = 'a';
					r = next[ q ];
					if( r == -1 ) r = next[ q ] = q + 1;
					if( str[ r ] == 0 ) str[ r ] = 'a';
					else str[ r ]++;
				}
				else break;
				q = next[ q ];
			}
			int j;
			for( j = 1; str[ j ]; j++ );
			for( int k = len - t; k >= 0; k-- )
				printf( "%c", buf[ k ] );
			for( int k = j - 1; k >= 1; k-- )
				printf( "%c", str[ k ] );
			printf( "\n" );
		}
		printf( "\n" );
	}
	return 0;
}
