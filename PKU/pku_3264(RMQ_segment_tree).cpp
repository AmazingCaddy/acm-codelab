/*
	author: AmazingCaddy
	time: 2011/5/22  14:04
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
const int maxn = 50004;
struct node
{
	int l, r;
	int val;
};
node TreeMax[ maxn << 2 ], TreeMin[ maxn << 2 ];
int f[ maxn ];

int Max( int a, int b ) { return ( a > b ? a : b ); }
int Min( int a, int b ) { return ( a < b ? a : b ); }

void Make_MaxTree( int v, int l, int r )
{
	TreeMax[ v ].l = l;
	TreeMax[ v ].r = r;
	if( r != l + 1 )
	{
		int mid = ( l + r ) >> 1;
		Make_MaxTree( v << 1, l, mid );
		Make_MaxTree( v << 1 | 1, mid, r );
		TreeMax[ v ].val = Max( TreeMax[ v << 1 ].val, TreeMax[ v << 1 | 1 ].val );
	}
	else TreeMax[ v ].val = f[ l ];
}

void Make_MinTree( int v, int l, int r )
{
	TreeMin[ v ].l = l;
	TreeMin[ v ].r = r;
	if( r != l + 1 )
	{
		int mid = ( l + r ) >> 1;
		Make_MinTree( v << 1, l, mid );
		Make_MinTree( v << 1 | 1, mid, r );
		TreeMin[ v ].val = Min( TreeMin[ v << 1 ].val, TreeMin[ v << 1 | 1 ].val );
	}
	else TreeMin[ v ].val = f[ l ];
}

int Query_Max( int v, int l, int r )
{
	if( TreeMax[ v ].l == l && TreeMax[ v ].r == r )
	{
		return TreeMax[ v ].val;
	}
	int mid = ( TreeMax[ v ].l + TreeMax[ v ].r ) >> 1;
	if( r <= mid ) return Query_Max( v << 1, l, r );
	if( l >= mid ) return Query_Max( v << 1 | 1, l, r );
	return Max( Query_Max( v << 1, l, mid ), Query_Max( v << 1 | 1, mid, r ) ); 
}

int Query_Min( int v, int l, int r )
{
	if( TreeMin[ v ].l == l && TreeMin[ v ].r == r )
	{
		return TreeMin[ v ].val;
	}
	int mid = ( TreeMin[ v ].l + TreeMin[ v ].r ) >> 1;
	if( r <= mid ) return Query_Min( v << 1, l, r );
	if( l >= mid ) return Query_Min( v << 1 | 1, l, r );
	return Min( Query_Min( v << 1, l, mid ), Query_Min( v << 1 | 1, mid, r ) ); 
}

int main(int argc, char *argv[])
{
	int n, q, a, b;
	while( scanf( "%d%d", &n, &q ) != EOF )
	{
		for( int i = 0; i < n; i++ )
			scanf( "%d", &f[ i ] );
		Make_MaxTree( 1, 0, n );
		Make_MinTree( 1, 0, n );
		for( int i = 0; i < q; i++ )
		{
			scanf( "%d%d", &a, &b );
			int ans = Query_Max( 1, a - 1, b ) - Query_Min( 1, a - 1, b );
			printf( "%d\n", ans );
		}
	}
	return 0;
}



//#include<iostream>
//#include<cmath>
//#define MAXN 50005
//using namespace std;
//int a[MAXN],f1[MAXN*3],f2[MAXN*3];
//void buildtree( int m, int l, int r )
//{
//	int mid=(l+r)>>1;
//	if ( l!=r )
//	{
//		buildtree( m<<1, l, mid );
//		buildtree( (m<<1)+1, mid+1, r );
//		f1[m]=max( f1[m<<1], f1[(m<<1)+1] );
//		f2[m]=min( f2[m<<1], f2[(m<<1)+1] );
//	}
//	else
//	{
//		f1[m]=a[l];
//		f2[m]=a[l];
//	}
//}
//int find1( int q, int w, int l, int r, int m )
//{
//	int mid=(l+r)>>1;
//	if ( q==l && w==r )	return f1[m];
//	if ( w<=mid ) return find1( q, w, l, mid, m<<1 );
//	if ( q>mid ) return find1(q, w, mid+1, r, (m<<1)+1 );
//	return max( find1( q, mid, l, mid, m<<1 ), find1( mid+1, w, mid+1, r, (m<<1)+1) );
//}
//int find2( int q, int w, int l, int r, int m )
//{
//	int mid=(l+r)>>1;
//	if ( q==l && w==r ) return f2[m];
//	if ( w<=mid ) return find2( q, w, l, mid, m<<1 );
//	if ( q>mid ) return find2( q, w, mid+1, r, (m<<1)+1 );
//	return min( find2( q, mid, l, mid, m<<1 ), find2( mid+1, w, mid+1, r, (m<<1)+1 ) );
//}
//int main( )
//{
//	int q,i,j,k,n,z,x;
//	while( scanf("%d%d",&n,&q) != EOF )	
//	{
//		for ( i=1; i<=n; i++ )
//			scanf("%d",&a[i]);
//		buildtree( 1, 1, n );
//		for ( i=1; i<=q; i++ )
//		{
//			scanf("%d%d",&j,&k);
//			z=find1( j, k, 1, n, 1 );
//			x=find2( j, k, 1, n, 1 );
//			printf("%d\n",z-x);
//		}
//	}
//	return 0;
//}