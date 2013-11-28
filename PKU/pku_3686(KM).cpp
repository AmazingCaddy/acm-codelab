/*
	author: AmazingCaddy
	time:	2011/10/10	1:05
	solve:	KM
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

const int maxn = 60;
const int maxm = 3000;
const int inf = 0x3fffffff;

int cx[ maxn ], cy[ maxm ], lx[ maxn ], ly[ maxm ], sx[ maxn ], sy[ maxm ];
int nx, ny, match, g[ maxn ][ maxm ];

int path( int u ) {
	sx[ u ] = 1;
	for( int v = 1; v <= ny; v++ ) {
		if( g[ u ][ v ] == lx[ u ] + ly[ v ] && !sy[ v ] ){
			sy[ v ] = 1;
			if( !cy[ v ] || path( cy[ v ] ) ){
				cx[ u ] = v;
				cy[ v ] = u;
				return 1;
			}
		}
	}
	return 0;
}

// 0表示求最小值 默认是1 求最大值
void KuhnMunkres( int maxsum = 1 ) {
	int i, j, u, min;
	memset( cx, 0, sizeof( cx ) ); 
	memset( cy, 0, sizeof( cy ) );
	memset( ly, 0, sizeof( ly ) );
	if( !maxsum ) {
        for( i = 1; i <= nx; i++ ) {
            for( j = 1; j <= ny; j++ ) {
                g[ i ][ j ] = -g[ i ][ j ];
			}
		}
	}
	for( i = 1; i <= nx; i++ ) {
		lx[ i ] = -inf;
		for( j = 1; j <= ny; j++ ) {
			if( lx[ i ] < g[ i ][ j ] ) {
				lx[ i ] = g[ i ][ j ];
			}
		}
	}
	for( u = 1; u <= nx; u++ ) {
		if( !cx[ u ] ) {
			memset( sx, 0, sizeof( sx ) );
			memset( sy, 0, sizeof( sy ) );
			while( !path( u ) ) {
				min = inf;
				for( i = 1; i <= nx; i++ ) {
					if( sx[ i ] ) {
						for( j = 1; j <= ny; j++ ) {
							if( !sy[ j ] && lx[ i ] + ly[ j ] - g[ i ][ j ] < min ) {
								min = lx[ i ] + ly[ j ] - g[ i ][ j ];
							}
						}
					}
				}
				for( i = 1; i <= nx; i++ ) {
					if( sx[ i ] ) {
						lx[ i ] -= min; 
						sx[ i ] = 0; 
					
					}
				}
				for( j = 1; j <= ny; j++ ) {
					if( sy[ j ] ) { 
						ly[ j ] += min; 
						sy[ j ] = 0; 
					}
				}
			}
		}
	}
	match = 0;
	for( i = 1; i <= nx; i++ ) {
		match += g[ i ][ cx[ i ] ];
	}
	if( !maxsum ) {
        match = -match;
		/*
        for( i = 1; i <= nx; i++ )
            for( j = 1; j <= ny; j++ )
                g[ i ][ j ] = -g[ i ][ j ];
		*/
		// 如果需要保持 g[ ] [ ] 原来的值，这里需要将其还原
	}
}

int z[ maxn ][ maxn ];
int main(int argc, char *argv[]){
	int cas;
	scanf( "%d", &cas );
	while( cas-- ) {
		scanf( "%d%d", &nx, &ny );
		for( int i = 1; i <= nx; i++ ) {
			for( int j = 1; j <= ny; j++ ) {
				scanf( "%d", &z[ i ][ j ] );
			}
		}
		memset( g, 0, sizeof( g ) );
		for( int i = 1; i <= nx; i++ ) {
			for( int j = 1; j <= ny; j++ ) {
				for( int k = 1; k <= nx; k++ ) {
					g[ i ][ ( j - 1 ) * nx + k ] = k * z[ i ][ j ];
				}
			}
		}
		ny *= nx;
		KuhnMunkres( 0 );
		printf( "%.6f\n", 1.0 * match / nx );
	}
	return 0;
}
