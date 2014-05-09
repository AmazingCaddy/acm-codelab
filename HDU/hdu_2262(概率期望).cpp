/*
	author: AmazingCaddy
	time:   2011/10/28	0:06 
	solve:	
		Ex = ( Ey1 + Ey2 + ... + Eyn ) / n + 1
		y 是 x 能扩展到点
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
const int maxn = 20;
const double eps = 1e-10;
const int dx[ ] = { -1, 0, 0, 1 };
const int dy[ ] = { 0, -1, 1, 0 };
struct node {
	int x, y;
	node() {}
	node( int _x, int _y ) : x( _x ), y( _y ) { }
};
int vis[ maxn ][ maxn ], cnt[ maxn ][ maxn ];
char g[ maxn ][ maxn ];
int n, m;
void floodfill( int stx, int sty ) {
	queue<node> que;
	node tmp( stx, sty );
	que.push( tmp );
	memset( cnt, 0, sizeof( cnt ) );
	memset( vis, 0, sizeof( vis ) );
	vis[ stx ][ sty ] = 1;
	while( !que.empty( ) ) {
		tmp = que.front();
		que.pop();
		for( int i = 0; i < 4; i++ ) {
			int nx = tmp.x + dx[ i ], ny = tmp.y + dy[ i ];
			if( nx < n && nx >= 0 && ny < m && ny >= 0 ) {
				if( g[ nx ][ ny ] != '#' ) {
					cnt[ tmp.x ][ tmp.y ] ++;
					if( !vis[ nx ][ ny ] ) {
						que.push( node( nx, ny ) );
						vis[ nx ][ ny ] = 1;
					}
				}
			}
		}
	}
}
double a[ maxn * maxn ][ maxn * maxn ], b[ maxn * maxn ];
int gauss_cpivot( int n ) {
	int i, j, k, row;
	double maxp, t;
	for ( k = 0; k < n; k++ ) {
		for( maxp = 0, i = k; i < n; i++ ) {
			if( fabs( a[ i ][ k ] ) > fabs( maxp ) ) {
				maxp = a[ row = i ][ k ];
			}
		}
		if( fabs( maxp ) < eps ) {
			return 0;
		}
		if( row != k ) {
			for( j = k; j < n; j++ ) {
				t = a[ k ][ j ], a[ k ][ j ] = a[ row ][ j ], a[ row ][ j ] = t;
			}
			t = b[ k ], b[ k ] = b[ row ], b[ row ] = t;
		}
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
int num[ maxn * maxn ];
vector<node> cateen;
bool check( ) {
	for( int i = 0; i < cateen.size(); i++ ) {
		if( vis[ cateen[ i ].x ][ cateen[ i ].y ] ) {
			return true;
		}
	}
	return false;
}
int main(int argc, char *argv[]){
	int stx, sty;
	while( scanf( "%d%d", &n, &m ) != EOF ) {
		cateen.clear();
		for( int i = 0; i < n; i++ ) {
			scanf( "%s", g[ i ] );
			for( int j = 0; j < m; j++ ) {
				if( g[ i ][ j ] == '@' ) {
					stx = i, sty = j;
				}
				else if( g[ i ][ j ] == '$' ) {
					cateen.push_back( node( i, j ) );
				}
			}
		}
		floodfill( stx, sty );
		if( !check( ) ) {
			printf( "-1\n" );
			continue;
		}
		int len = 0;
		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < m; j++ ) {
				if( vis[ i ][ j ] ) {
					num[ i * m + j ] = len++;
				}
			}
		}
		memset( a, 0, sizeof( a ) );
		memset( b, 0, sizeof( b ) );
		len = 0;
		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < m; j++ ) {
				if( vis[ i ][ j ] ) {
					if( g[ i ][ j ] != '$' ) {
						a[ len ][ num[ i * m + j ] ] = 1;
						double total = cnt[ i ][ j ];
						for( int k = 0; k < 4; k++ ) {
							int nx = i + dx[ k ], ny = j + dy[ k ];
							if( nx < n && nx >= 0 && ny < m && ny >= 0 ) {
								if( vis[ nx ][ ny ] ) {
									a[ len ][ num[ nx * m + ny ] ] = -1 / total;
								}
							}
						}
						b[ len ] = 1;
					}
					else {
						a[ len ][ num[ i * m + j ] ] = 1;
						b[ len ] = 0;
					}
					len++;
				}
			}
		}
		gauss_cpivot( len );
		printf( "%.6lf\n", b[ num[ stx * m + sty ] ] );
	}
	return 0;
}