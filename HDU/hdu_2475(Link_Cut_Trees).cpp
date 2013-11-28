//Qtree_dynamic_tree_link_cut_trees
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;
const int maxn = 50010 ;
//const int minc = -2147483647 ;

// int cost[ maxn ], maxcost[ maxn ];
int nodetype[ maxn ];
int pre[ maxn ];
int ch[ maxn ][ 2 ];

//int dest[ maxn << 1 ], Next[ maxn << 1 ], val[ maxn << 1 ];
//int start[ maxn ];
//int bottom[ maxn ];

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
	//update( pare );
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
	//update( z );
}

void Access( int v )
{
	int u = v;
	v = 0;
	while( u )
	{
		Splay( u );
		nodetype[ ch[ u ][ 1 ] ] = 2;
		ch[ u ][ 1 ] = v;
		nodetype[ ch[ u ][ 1 ] ] = 1;
		// update( u );
		v = u;
		u = pre[ u ];
	}
}

int Find_root( int v )
{
	Access( v );
	Splay( v );
	while( ch[ v ][ 0 ] ) v = ch[ v ][ 0 ];
	Splay( v );
	return v;
}

void Cut( int v )
{
	Access( v );
	Splay( v );
	pre[ ch[ v ][ 0 ] ] = 0;
	nodetype[ ch[ v ][ 0 ] ] = 2;
	ch[ v ][ 0 ] = 0;
}

void Join( int v, int w )
{
	Access( v );
	pre[ v ] = w;
	//ch[ w ][ 1 ] = v;
	//nodetype[ v ] = 1;
	Access( v );
}

int getInt(){
    char c; while( (c=getchar())&&!isdigit(c) ) ;
    int ret = c - '0' ; while( (c = getchar()) && isdigit( c ) ) ret = ret*10 + c - '0' ;
    return ret;
}

int main( )
{
	int n, i, a, b, c, q, flag;
	//freopen("data.in","r",stdin);
	//freopen("out.out","w",stdout);
	int f = 0;
	while( scanf("%d",&n) != EOF )
	{
		if( f ) printf("\n");
		else f = 1;
		for( i = 1; i <= n; i++ )
		{
			//scanf("%d",&a);
			pre[ i ] = getInt( );
			nodetype[ i ] = 2;
		}
		memset( ch, 0, sizeof( ch ) );
		char d[10];
		scanf("%d",&q);
		for( i = 1; i <= q; i++ )
		{
			scanf("%s",d);
			if( d[0] == 'M' )
			{
				a = getInt( ), b = getInt( );
				//scanf("%d%d",&a,&b);
				if( a == b ) continue;

				if( b == 0 )
				{
					Cut( a );
					//Join( a, 0 );
				}
				else
				{
					Access( b );
					Splay( a );
					flag = 0;
					c = b;
					while( c )
					{
						if( c == a ){ flag = 1; break; }
						c = pre[ c ];
					}
					if( flag ) continue;
					Cut( a );
					Join( a, b );
				}
			}
			else if( d[0] == 'Q' )
			{
				c = getInt( );
				//scanf("%d",&c);
				printf("%d\n",Find_root( c ));
			}
		}
	}
}
