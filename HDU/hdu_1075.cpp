/*
	author : AmazingCaddy
	time : 2011-06-01 16:03:58 
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
#define lowbit(x) ((x)&(-(x)))

const int maxn = 1000004;
const int inf = 0x3fffffff;

struct TIRE
{
	int id;
	TIRE * child[ 26 ];
};
TIRE tree[ maxn ];
int len;
TIRE * root;
char buf[ maxn ][ 15 ];

TIRE * NewNode( )
{
	++len;
	tree[ len ].id = -1;
	for( int i = 0; i < 26; i++ )
		tree[ len ].child[ i ] = NULL;
	return &tree[ len ];
}

void Insert( char str[ ], int id )
{
	TIRE *p = root;
	for( int i = 0; str[ i ]; i++ )
	{
		int tmp = str[ i ] - 'a';
		if( p -> child[ tmp ] == NULL )
		{
			p -> child[ tmp ] = NewNode( );
		}
		p = p -> child[ tmp ];
	}
	p -> id = id;
}

int find( char str[ ] )
{
	TIRE * p = root;
	for( int i = 0; str[ i ]; i++ )
	{
		int tmp = str[ i ] - 'a';
		if( p -> child[ tmp ] == NULL ) return -1;
		p = p -> child[ tmp ];
	}
	return p -> id;
}

char str[ 3010 ];
char ch[ 20 ];

int main(int argc, char *argv[])
{
	//freopen( "out.txt", "w", stdout );
	scanf( "%s", str );
	int id = 0;
	len = -1;
	root = NewNode( );
	while( scanf( "%s", str ) && strcmp( str, "END" ) )
	{
		strcpy( buf[ id ], str );
		scanf( "%s", str );
		Insert( str, id );
		id++;
	}
	scanf( "%s", str );
	getchar( );
	while( gets( str ) && strcmp( str, "END" ) )
	{
		int len = strlen( str );
		int top = 0;
		for( int i = 0; i < len; i++ )
		{
			if( str[ i ] < 'a' || str[ i ] > 'z' )
			{
				//int c = 0;
				if( top == 0 ) { printf( "%c", str[ i ] ); continue; }
				ch[ top ] = 0;
				top = 0;
				id = find( ch );
				if( id == -1 ) printf( "%s", ch );
				else printf( "%s", buf[ id ] );
				printf( "%c", str[ i ] );
			}
			else
			{
				ch[ top++ ] = str[ i ];
			}
		}
		printf( "\n" );
	}
	return 0;
}
