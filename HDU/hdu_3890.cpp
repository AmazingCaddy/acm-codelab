/*
	author: AmazingCaddy
	time:	2011/8/12  17:23
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
#define lowbit(x) ((x)&(-(x)))
typedef long long ll;

const int maxn = 1 << 16;

struct point { int x, y, val; };
point pnt[ maxn ];
struct node { int x, y; };
node quy[ maxn ];

map< int, int > xidx;
int pp[ maxn ], pq[ maxn ], anssum[ maxn ], anscnt[ maxn ];
int tsum[ maxn << 1 ], tcnt[ maxn << 1 ];
int n, m;

bool cmp_p( const int & l, const int & r ) {
	return pnt[ l ].y < pnt[ r ].y;
}

bool cmp_q( const int & l, const int & r ) {
	return quy[ l ].y < quy[ r ].y;
}

void update( int x, int val ) {
	for( ; x < 2 * maxn; x += lowbit( x ) ) {
		tsum[ x ] += val;
		tcnt[ x ] ++;
	}
}

void query( int x, int &sum, int &cnt ) {
	sum = cnt = 0;
	for( ; x > 0; x -= lowbit( x ) ) {
		sum += tsum[ x ];
		cnt += tcnt[ x ];
	}
}

int main(int argc, char *argv[])
{
//	freopen( "input.txt", "r", stdin );
//	freopen( "out", "w", stdout );
	double val;
	while( scanf( "%d%d", &n, &m ) != EOF ) {
		memset( tsum, 0, sizeof( tsum ) );
		memset( tcnt, 0, sizeof( tcnt ) );
		xidx.clear( );
		for( int i = 0; i < n; i++ ) {
			scanf( "%d%d%lf", &pnt[ i ].x, &pnt[ i ].y, &val );
			xidx[ pnt[ i ].x ] = 1;
			val *= 100;
			pnt[ i ].val = ( int )( val < 0 ? val - 0.1 : val + 0.1 );
			pp[ i ] = i;
		}
		for( int i = 0; i < m * 2; i += 2 ) {
			scanf( "%d%d%d%d", &quy[ i ].x, &quy[ i ].y, &quy[ i + 1 ].x, &quy[ i + 1 ].y );
			quy[ i ].x--;
			quy[ i ].y--;
			xidx[ quy[ i ].x ] = 1;
			xidx[ quy[ i + 1 ].x ] = 1;
			pq[ i ] = i;
			pq[ i + 1 ] = i + 1;
		}
		int id = 1;
		for( map< int, int >::iterator iter = xidx.begin( ); iter != xidx.end( ); iter++ ) {
			iter -> second = id++;
		}
		sort( pp, pp + n, cmp_p );
		sort( pq, pq + 2 * m, cmp_q );

		int sum1, sum2, cnt1, cnt2;
		for( int i = 0, j = 0; i < 2 * m; i++ ) {
			for( ; j < n && pnt[ pp[ j ] ].y <= quy[ pq[ i ] ].y; j++ ) {
				update( xidx[ pnt[ pp[ j ] ].x ], pnt[ pp[ j ] ].val );
			}
			int lx = ( pq[ i ] & 1 ) ? quy[ pq[ i ] ^ 1 ].x : quy[ pq[ i ] ].x;
			int rx = ( pq[ i ] & 1 ) ? quy[ pq[ i ] ].x : quy[ pq[ i ] ^ 1 ].x;
			query( xidx[ lx ], sum1, cnt1 );
			query( xidx[ rx ], sum2, cnt2 );
			anssum[ pq[ i ] ] = sum2 - sum1;
			anscnt[ pq[ i ] ] = cnt2 - cnt1;
		}
		for( int i = 0; i < 2 * m; i += 2 ) {
			printf( "%.2lf/%d\n", ( anssum[ i + 1 ] - anssum[ i ] ) / 100.0, anscnt[ i + 1 ] - anscnt[ i ] );
		}
	}
	return 0;
}
