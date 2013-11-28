/*
	author: AmazingCaddy
	time:	2011-08-11 11:45:26 
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

typedef long long ll;

const int maxn = 50004;
const int maxm = maxn << 2;
const int inf = 0x3fffffff;

struct node{
	int st, ed, id;
	bool operator < ( const node & b ) const {
		if( st == b.st ) return ed < b.ed;
		return st < b.st;
	}
};
node que[ maxm ];
ll tree[ maxn ];
ll ans[ maxm ];
int n, m;

void update( int x, int val ){
	for( ; x <= n; x += lowbit( x ) )
		tree[ x ] += val;
}

ll query( int x ){
	ll sum = 0;
	for( ; x > 0 ; x -= lowbit( x ) )
		sum += tree[ x ];
	return sum;
}

int num[ maxn ], head[ 1000005 ], next[ maxn ];

int main(int argc, char *argv[]) {
//	freopen( "in", "r", stdin );
//	freopen( "out1", "w", stdout );
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d", &n );
		int MaxNum = 0;
		for( int i = 1; i <= n; i++ ) {
			scanf( "%d", &num[ i ] );
			MaxNum = max( MaxNum, num[ i ] );
		}
		scanf( "%d", &m );
		for( int i = 0; i < m; i++ ) {
			scanf( "%d%d", &que[ i ].st, &que[ i ].ed );
			que[ i ].id = i;
		}
		memset( head, -1, sizeof( head ) );
		for( int i = n; i >= 1; i-- ) {
			next[ i ] = head[ num[ i ] ];
			head[ num[ i ] ] = i;
		}
		memset( tree, 0, sizeof( tree ) );
		for( int i = 0; i <= MaxNum; i++ ) {
			if( head[ i ] != -1 ) {
				update( head[ i ], i );
			}
		}
		sort( que, que + m );
		int now = 1;
		for( int i = 0; i < m; i++ ) {
			while( now < que[ i ].st ) {
				if( next[ now ] != -1 ) {
					update( next[ now ], num[ next[ now ] ] );
				}
				now++;
			}
			ans[ que[ i ].id ] = query( que[ i ].ed ) - query( que[ i ].st - 1 );
		}
		for( int i = 0; i < m; i++ ) {
			printf( "%I64d\n", ans[ i ] );
		}
	}
	return 0;
}
