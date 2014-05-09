/*
	author:	AmazingCaddy
	time:	2011/10/29	2:26
	solve:	trie树构造状态转移
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 150;
const int inf = 0x3fffffff;
const double eps = 1e-12;

double a[ maxn ][ maxn ], b[ maxn ];
int gauss_cpivot( int n ) {
	int i, j, k, row;
	double maxp, t;
	for ( k = 0; k < n; k++ ) {
		if( a[ k ][ k ] == 0 ) {
			int flag = 1;
			for( i = k; i < n; i++ ) {
				if( a[ i ][ k ] != 0 ) {
					for( j = k; j < n; j++ ) {
						swap( a[ k ][ j ], a[ i ][ j ] );
					}
					swap( b[ k ], b[ i ] );
					flag = 0;
					break;
				}
			}
			if( flag ) {
				return 0;
			}
		}
		maxp = a[ k ][ k ];
		for( j = k + 1; j < n; j++ ) {
			a[ k ][ j ] /= maxp;
			for( i = k + 1; i < n; i++ ) {
				a[ i ][ j ] -= a[ i ][ k ] * a[ k ][ j ];
			}
		}
		b[ k ] /= maxp;
		for( i = k + 1; i < n; i++ ) {
			b[ i ] -= b[ k ] * a[ i ][ k ];
		}
	}
	for( i = n - 1; i >= 0; i-- ) {
		for( j = i + 1; j < n; j++ ) {
			b[ i ] -= a[ i ][ j ] * b[ j ];
		}
	}
	return 1;
}

struct node {
	node * next[ 10 ];
	node * pre, * father;
	int flag, c, id;
}trie[ maxn << 2 ];
int len, cnt;

void init( ) {
	len = 0;
	memset( trie[ len ].next, 0, sizeof( trie[ len ].next ) );
	trie[ len ].father = NULL;
	trie[ len ].flag = 0;
	trie[ len ].c = 0;
	trie[ len ].id = 0;
}

node * NewNode( node * f, int k ) {
	len++;
	memset( trie[ len ].next, 0, sizeof( trie[ len ].next ) );
	trie[ len ].pre = NULL;
	trie[ len ].father = f;
	trie[ len ].flag = 0;
	trie[ len ].c = k;
	trie[ len ].id = len;
	return &trie[ len ];
}

void insert( char str[ ] ) {
	node *root = trie;
	for( int i = 0; str[ i ]; i++ ) {
		int k = str[ i ] - 'A';
		if( root -> next[ k ] == NULL ) {
			root -> next[ k ] = NewNode( root, k );
		}
		root = root -> next[ k ];
	}
	root -> flag = 1;
}

node* que[ maxn ];
int vis[ maxn ], mat[ maxn ][ 10 ];
void get_pre( node * p ) {
	node *q = p -> father;
	if( q == trie ) {
		p -> pre = trie;
		return;
	}
	int c = p -> c;
	q = q -> pre;
	while( q != trie && q -> next[ c ] == NULL ) {
		q = q -> pre;
	}
	if( q -> next[ c ] == NULL ) {
		p -> pre = trie;
	}
	else {
		p -> pre = q -> next[ c ];
	}
}

void BFS( int n ) {
	node *p, q;
	int l, r;
	l = r = 0;
	que[ 0 ] = trie;
	trie -> pre = trie -> father = trie;
	while( l <= r ) {
		p = que[ l++ ];
		get_pre( p );
		for( int i = 0; i < n; i++ ) {
			if( p -> next[ i ] ) {
				que[ ++r ] = p -> next[ i ];
			}
		}
	}
	l = r = 0;
	que[ 0 ] = trie;
	while( l <= r ) {
		p = que[ l++ ];
		if( p -> pre -> flag || p -> father -> flag ) {
			p -> flag = 1;
		}
		for( int i = 0; i < n; i++ ) {
			if( p -> next[ i ] ) {
				que[ ++r ] = p -> next[ i ];
			}
		}
	}
	memset( vis, 0, sizeof( vis ) );
	l = r = cnt = 0;
	que[ 0 ] = trie;
	while( l <= r ) {
		p = que[ l++ ];
		p -> id = cnt++;
		if( p -> flag ) {
			vis[ p -> id ] = 1;
			continue;
		}
		for( int i = 0; i < n; i++ ) {
			if( p -> next[ i ] ) {
				que[ ++r ] = p -> next[ i ];
			}
		}
	}
	for( int i = 0; i < n; i++ ) {
		if( trie -> next[ i ] == NULL ) {
			trie -> next[ i ] = trie;
		}
	}
	for( l = 0; l <= r; l++ ) {
		p = que[ l ];
		if( p -> flag ) {
			continue;
		}
		else {
			for( int i = 0; i < n; i++ ) {
				if( p -> next[ i ] == NULL ) {
					p -> next[ i ] = p -> pre -> next[ i ];
				}
				mat[ p -> id ][ i ] = p -> next[ i ] -> id;
			}
		}
	}
}

double solve( int n ) {
	memset( a, 0, sizeof( a ) );
	memset( b, 0, sizeof( b ) );
	for( int i = 0; i < cnt; i++ ) {
		if( vis[ i ] ) {
			a[ i ][ i ] = 1;
			b[ i ] = 0;
			continue;
		}
		a[ i ][ i ] = b[ i ] = n;
		for( int j = 0; j < n; j++ ) {
			a[ i ][ mat[ i ][ j ] ] -= 1;
		}
	}
	//    if( gauss_tpivot( cnt ) ) {
	if( gauss_cpivot( cnt ) ) {
		return b[ 0 ];
	}
	return -1;
}
char buf[ maxn ];
int main(int argc, char *argv[]){
//	freopen( "input.txt", "r", stdin );
//	freopen( "out", "w", stdout );
	int cas, n, m;
	scanf( "%d", &cas );
	while( cas -- ) {
		scanf( "%d%d", &n, &m );
		init( );
		for( int i = 0; i < m; i++ ) {
			scanf( "%s", buf );
			insert( buf );
		}
		BFS( n );
		printf( "%.2lf\n", solve( n ) );
	}
	return 0;
}