/*
	author: AmazingCaddy
	time: 2011/4/30  20:11
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
#define lowbit( x ) ((x)&(-(x)))
using namespace std;
const int maxn = 100004;
struct node
{
	int id;
	int tor;
	node( ) { }
	node( int _id, int _tor ) : id( _id ), tor( _tor ) { }
	bool operator < ( const node & b ) const
	{
		return tor > b.tor;
	}
};

priority_queue< node > heap;
map< int, int > mm;

int tree[ maxn ];
int que[ maxn ];
char buf[ 30 ];
int n;

void add( int idx, int val )
{
	for( ; idx <= n; idx += lowbit( idx ) )
		tree[ idx ] += val;
}

int query( int idx )
{
	int sum = 0;
	for( ; idx > 0; idx -= lowbit( idx ) )
		sum += tree[ idx ];
	return sum;
}

int main(int argc, char *argv[])
{
	int a, b, x, y, z, id;
	int head, tail, flag;
	node tmp;

	while( scanf( "%d", &n ) != EOF )
	{
		memset( tree, 0, sizeof( tree ) );
		mm.clear( );
		map< int, int >::iterator it;
		while( !heap.empty( ) ) heap.pop( );
		head = tail = 1;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%s", buf );
			switch( buf[ 0 ] )
			{
			case 'a':
				scanf( "%d%d", &a, &b );
				add( tail, 1 );
				heap.push( node( a, b ) );
				mm[ a ] = tail;
				que[ tail++ ] = a;
				break;

			case 'c':
				scanf( "%d%d", &x, &y );
				it = mm.find( x );
				if( it != mm.end( ) )
				{
					id = it -> second;
					z = query( id ) - 1;
					printf( "%d\n", z );
					if( z > y )
					{
						add( id, -1 );
						mm.erase( it );
					}
				}
				break;

			case 'l':
				while( !heap.empty( ) ) 
				{
					it = mm.find( heap.top( ).id );
					heap.pop( );
					if( it != mm.end( ) )
					{
						id = it -> second;
						add( id, -1 );
						mm.erase( it );
						break;
					}
				} 
				break;

			case 'p':
				while( head < tail && ( it = mm.find( que[ head ] ) ) == mm.end( ) ) head++;
				if( head < tail )
				{
					add( head, -1 );
					mm.erase( it );
					head++;
				}
				break;
			}
		}
	}
	return 0;
}
