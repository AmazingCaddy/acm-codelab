/*
	author:	AmazingCaddy
	time:	2011/3/14  20:12
	离散化，区间 [ a, b ) 左闭右开，segment_tree
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <vector>
#include <map>
using namespace std;

const int maxn = 4010;
struct INDEX
{
	int a, b;
	char str[ 2 ];
};
INDEX index[ maxn >> 1 ]; 
struct node
{
	int l, r;
	int left, right, maxlen;
	int minright, color;
};
node tree[ maxn << 2 ];
int lisan[ maxn ];

void make_tree( int v, int l, int r )
{
	int mid = ( l + r ) >> 1;
	tree[ v ].l = l, tree[ v ].r = r;
	tree[ v ].left = lisan[ l ];
	tree[ v ].right = lisan[ r ];
	tree[ v ].maxlen = tree[ v ].color = 0;
	tree[ v ].minright = lisan[ l ];
	if( l + 1 != r )
	{
		make_tree( v << 1, l, mid );
		make_tree( v << 1 | 1, mid, r );
	}
}

void push_down( int v, int s, int t )
{
	tree[ v ].left = t;
	tree[ v ].right = s;
	//tree[ v ].maxlen = t - s;
	tree[ v ].minright = t;
}

void update( int v, int s, int t, int color )
{
	if( tree[ v ].color && tree[ v ].l + 1 != tree[ v ].r )
	{
		tree[ v << 1 ].color = tree[ v << 1 | 1 ].color = tree[ v ].color;
		int mid = ( tree[ v ].l + tree[ v ].r ) >> 1;
		if( tree[ v ].color == 1 )
		{
			push_down( v << 1, lisan[ tree[ v ].l ], lisan[ mid ] );
			tree[ v << 1 ].maxlen = lisan[ mid ] - lisan[ tree[ v ].l ];
			push_down( v << 1 | 1, lisan[ mid ], lisan[ tree[ v ].r ] );
			tree[ v << 1 | 1 ].maxlen = lisan[ tree[ v ].r ] - lisan[ mid ];
		}
		else
		{
			push_down( v << 1, lisan[ mid ], lisan[ tree[ v ].l ] );
			tree[ v << 1 ].maxlen = 0;
			push_down( v << 1 | 1, lisan[ tree[ v ].r ], lisan[ mid ] );
			tree[ v << 1 | 1 ].maxlen = 0;
		}
		tree[ v ].color = 0;
	}

	if( lisan[ tree[ v ].l ] == s && lisan[ tree[ v ].r ] == t )
	{
		tree[ v ].color = color;
		if( color == 1 ) // white
		{
			push_down( v, s, t );
			//tree[ v ].left = t;
			//tree[ v ].right = s;
			tree[ v ].maxlen = t - s;
			//tree[ v ].minright = t;
		}
		else if( color == 2 ) // black
		{
			push_down( v, t, s );
			//tree[ v ].left = s;
			//tree[ v ].right = t;
			tree[ v ].maxlen = 0;
			//tree[ v ].minright = s;
		}
		return;
	}

	int mid = ( tree[ v ].l + tree[ v ].r ) >> 1;
	if( lisan[ mid ] >= t ) update( v << 1, s, t, color );
	else if( lisan[ mid ] <= s ) update( v << 1 | 1, s, t, color );
	else 
	{
		update( v << 1, s, lisan[ mid ], color );
		update( v << 1 | 1, lisan[ mid ], t, color );
	}

	// 更新左值 和 右值
	if( tree[ v << 1 ].left == lisan[ tree[ v << 1 ].r ] )
		tree[ v ].left = tree[ v << 1 | 1 ].left;
	else tree[ v ].left = tree[ v << 1 ].left;
	
	if( tree[ v << 1 | 1 ].right == lisan[ tree[ v << 1 | 1 ].l ] )
		tree[ v ].right = tree[ v << 1 ].right;
	else tree[ v ].right = tree[ v << 1 | 1 ].right;

	// 更新最大段及其最右值
	tree[ v ].maxlen = tree[ v << 1 ].maxlen;
	tree[ v ].minright = tree[ v << 1 ].minright;
	if( tree[ v ].maxlen < tree[ v << 1 | 1 ].left - tree[ v << 1 ].right )
	{
		tree[ v ].maxlen = tree[ v << 1 | 1 ].left - tree[ v << 1 ].right;
		tree[ v ].minright = tree[ v << 1 | 1 ].left;
	}
	if( tree[ v ].maxlen < tree[ v << 1 | 1 ].maxlen )
	{
		tree[ v ].maxlen = tree[ v << 1 | 1 ].maxlen;
		tree[ v ].minright = tree[ v << 1 | 1 ].minright;
	}
}

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) != EOF )
	{
		int len = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d %d %s", &index[ i ].a, &index[ i ].b, index[ i ].str );
			index[ i ].b++;
			lisan[ len++ ] = index[ i ].a;
			lisan[ len++ ] = index[ i ].b;
		}
		sort( lisan, lisan + n * 2 );
		len = unique( lisan, lisan + n * 2 ) - lisan;
		make_tree( 1, 0, len - 1 );

		for( int i = 0; i < n; i++ )
			update( 1, index[ i ].a, index[ i ].b, index[ i ].str[ 0 ] == 'w' ? 1 : 2 );
		int ans = tree[ 1 ].maxlen;
		if( ans == 0 ) printf( "Oh, my god\n" );
		else printf( "%d %d\n", tree[ 1 ].minright - ans, tree[ 1 ].minright - 1 );
	}
	return 0;
}

/*
4
1 11 w
1 4 w
3 5 b
8 11 w
*/
