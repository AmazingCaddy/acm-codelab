/*
	author: AmazingCaddy
	time: 2011/4/10  14:10
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
const int maxn = 1000006;

struct node
{
	int cnt;
	node * child[ 26 ];
}tree[ maxn ];
int len;

void init( )
{
	tree[ 0 ].cnt = 0;
	for( int i = 0; i < 26; i++ )
		tree[ 0 ].child[ i ] = NULL;
	len = 1;
}

node * NewNode( )
{
	tree[ len ].cnt = 0;
	for( int i = 0; i < 26; i++ )
		tree[ len ].child[ i ] = NULL;
	return & tree[ len++ ];
}

void insert( char str[ ] )
{
	int len = strlen( str );
	node *p = &tree[ 0 ];
	for( int i = 0; i < len; i++ )
	{
		int tmp = str[ i ] - 'a';
		if( p -> child[ tmp ] == NULL ) p -> child[ tmp ] = NewNode( );
		p = p -> child[ tmp ];
	}
	p -> cnt++;
}

int find( char str[ ] )
{
	int len = strlen( str );
	node *p = &tree[ 0 ];
	for( int i = 0; i < len; i++ )
	{
		int tmp = str[ i ] - 'a';
		if( p -> child[ tmp ] == NULL ) return 0;
		p = p -> child[ tmp ];
	}
	return p -> cnt;
}

char str[ 50005 ][ 20 ];

int main(int argc, char *argv[])
{
	int len = 0;
	char s1[ 32 ], s2[ 32 ];
	init( );
	while( scanf( "%s", str[ len ] ) != EOF )
	{
		insert( str[ len ] );
		len++;
	}
	for( int i = 0; i < len; i++ )
	{
		int slen = strlen( str[ i ] );
		for( int j = 0; j < slen - 1; j++ )
		{
			for( int k = 0; k <= j; k++ )
				s1[ k ] = str[ i ][ k ];
			s1[ j + 1 ] = 0;
			for( int k = j + 1; k < slen; k++ )
				s2[ k - j - 1 ] = str[ i ][ k ];
			s2[ slen - j - 1 ] = 0;
			if( find( s1 ) && find( s2 ) )
			{
				printf( "%s\n", str[ i ] );
				break;
			}
		}
	}
	return 0;
}
