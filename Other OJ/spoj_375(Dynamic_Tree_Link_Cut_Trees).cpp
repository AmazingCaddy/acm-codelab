//Qtree_dynamic_tree_link_cut_trees
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;
const int maxn = 10010 ;
const int minc = -2147483647 ;

int cost[ maxn ], maxcost[ maxn ];
int nodetype[ maxn ];
int pre[ maxn ];
int ch[ maxn ][ 2 ];

int dest[ maxn << 1 ], Next[ maxn << 1 ], val[ maxn << 1 ];
int start[ maxn ];
int bottom[ maxn ];

void dfs( int node )
{
	int i = start[ node ];
	while( i )
	{
		if( dest[i] != pre[ node ] )
		{
			bottom[ (i+1)>>1 ] = dest[i] ;
			pre[ dest[ i ] ] = node;
			memset( ch[ dest[ i ] ], 0, sizeof( ch[ dest[ i ] ] ) );
			nodetype[ dest[ i ] ] = 2;
			cost[ dest[ i ] ] = val[ i ];
			maxcost[ dest[ i ] ] = val[ i ];
			dfs( dest[i] );
		}
		i = Next[i];
	}
}

void update( int root )
{
	int x = maxcost[ ch[ root ][ 0 ] ], y = maxcost[ ch[ root ][ 1 ] ];
	maxcost[ root ] = cost[ root ];
	if( x < y ) x = y;
	if( x > maxcost[ root ] ) maxcost[ root ] = x;
}

void Rotate( int node, int x )
{
	int pare = pre[ node ];
	int y = nodetype[ pare ];
	pre[ node ] = pre[ pare ];
	nodetype[ node ] = y;
	if( y != 2 ) ch[ pre[ pare ] ][ y ] = node;
	y = 1 - x;
	pre[ ch[ node ][ y ] ] = pare;
	nodetype[ ch[ node ][ y ] ] = x;
	ch[ pare ][ x ] = ch[ node ][ y ];
	pre[ pare ] = node;
	nodetype[ pare ] = y;
	ch[ node ][ y ] = pare;
	update( pare );
}

void Splay( int z )
{
	int y;
	int a, b;
	do{
		a = nodetype[ z ];
		if( a == 2 ) break;
		y = pre[ z ];
		b = nodetype[ y ];
		if( a == b ) Rotate( y, a );
		else Rotate( z, a );
		if( b == 2 )break;
		Rotate( z, b );
	}while( true );
	update( z );
}

int query( int a, int b )
{
	int i, ret ;
	i = 0;
	while( a )
	{
		Splay( a );
		nodetype[ ch[ a ][ 1 ] ] = 2;
		ch[ a ][ 1 ] = i;
		nodetype[ ch[ a ][ 1 ] ] = 1;
		update( a );
		i = a;
		a = pre[ a ]; 
	}
	i = 0 ;
	while( b )
	{
		Splay( b ) ;
		if( pre[ b ] == 0 )
		{
			ret = maxcost[ ch[ b ][ 1 ] ];
			if( maxcost[ i ] > ret ) ret = maxcost[ i ];
		}
		nodetype[ ch[ b ][ 1 ] ] = 2;
		ch[ b ][ 1 ] = i;
		nodetype[ ch[ b ][ 1 ] ] = 1;
		update( b );
		i = b;
		b = pre[ b ]; 
	}
	return ret;
}

int main( )
{
	int t, k, n, i, j, a, b, c;
	scanf("%d",&t);
	for( k = 1; k <= t; k ++ )
	{
		scanf("%d",&n);
		for( i = 1; i <= n; i ++ )
			start[ i ] = 0;
		j = 0;
		for( i = 2; i <= n; i ++ )
		{
			scanf("%d%d%d",&a,&b,&c);
			++ j;
			dest[ j ] = b;
			val[ j ] = c;
			Next[ j ] = start[ a ];
			start[ a ] = j;
			++ j;
			dest[ j ] = a;
			val[ j ] = c;
			Next[ j ] = start[ b ];
			start[ b ] = j;
		}
		memset( ch[ 0 ], 0, sizeof( ch[ 0 ] ) );
		pre[ 0 ] = 0;
		cost[ 0 ] = minc;
		maxcost[ 0 ] = minc;
		nodetype[ 0 ] = 2;
		memset( ch[ 0 ], 0, sizeof( ch[ 0 ] ) );
		pre[ 1 ] = 0;
		cost[ 1 ] = minc;
		maxcost[ 1 ] = minc;
		nodetype[ 1 ] = 2;
		dfs( 1 );

		char d[10];
		do{
			scanf("%s",d);
			if( d[0] == 'C' )
			{
				scanf( "%d%d",&i,&c);
				cost[ bottom[i] ] = c;
				Splay( bottom[i] );
			}
			else if( d[0] == 'Q' )
			{
				scanf("%d%d",&a,&b);
				printf("%d\n",query( a , b ) );
			}
			else break;
		}while( true );
	}
}
