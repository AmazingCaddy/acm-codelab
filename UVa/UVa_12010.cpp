/*
	author: AmazingCaddy
	time: 2011/5/16  0:22
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

const int maxn = 10000;

struct node
{
	int id;
	int col;
	node * lchild, *rchild;
};
node buf[ maxn ];
node *root;
int len;

node * NewNode( int n )
{
	buf[ len ].id = n;
	buf[ len ].col = 0;
	buf[ len ].lchild = buf[ len ].rchild = NULL;
	return &buf[ len++ ];
}

void Insert( int n )
{
	if( root == NULL )
	{
		root = NewNode( n );
		return;
	}
	node *p = NewNode( n ), *q = root, *r;
	while( q )
	{
		r = q;
		if( q -> id < n ) q = q -> rchild;
		else if( q -> id > n ) q = q -> lchild;
		else return;
	}
	if( r -> id < n ) r -> rchild = p;
	else r -> lchild = p;
}

char str[ 1000 ][ 100 ];
int col, DEP;

void DFS( node * p, int dep )
{
	if( DEP < dep ) DEP = dep;
	if( p )
	{
		DFS( p -> lchild, dep + 1 );
		p -> col = ++col;
		int tmp = dep << 1;
		str[ tmp ][ col ] = '+';
		str[ tmp + 1 ][ col ] = '|';
		str[ tmp + 2 ][ col ] = 'o';
		if( p -> lchild )
			for( int i = p -> lchild -> col + 1; i < p -> col; i++ )
				str[ tmp + 2 ][ i ] = '-';
		DFS( p -> rchild, dep + 1 );
		if( p -> rchild )
			for( int i = p -> col + 1; i < p -> rchild -> col; i++ )
				str[ tmp + 2 ][ i ] = '-';
	}
}

int main(int argc, char *argv[])
{
	int cas, n, x;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d", &n );
		len = 0;
		root = NULL;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d", &x );
			Insert( x );
		}
		memset( str, ' ', sizeof( str ) );
		DEP = -1;
		col = -1;
		DFS( root, 0 );
		printf( "Case #%d:\n", t );
		int row = DEP * 2;
		for( int i = 2; i <= row; i++ )
		{
			int tmp = -1;
			for( int j = 99; j >= 0; j-- )
			{
				if( str[ i ][ j ] != ' ' )
				{
					tmp = j;
					break;
				}
			}
			str[ i ][ tmp + 1 ] = '\0';
			printf( "%s\n", str[ i ] );
		}
	}
	return 0;
}
