#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 4;
const double eps = 1e-8;
const double pi = acos( -1.0 );

struct mat {
	double m[ maxn ][ maxn ];
	ll k;
	mat( ) { memset( m, 0, sizeof( m ) ); }
	mat( double x, double y, double z, double angle, ll _k, int flag ) {
		memset( m, 0, sizeof( m ) );
		if( _k == -1 ) {
			k = _k;
			if( flag == 0 ) {
				m[ 0 ][ 0 ] = m[ 1 ][ 1 ] = 1;
				m[ 2 ][ 2 ] = m[ 3 ][ 3 ] = 1;
				m[ 0 ][ 3 ] = x;
				m[ 1 ][ 3 ] = y;
				m[ 2 ][ 3 ] = z;
			}
			else if( flag == 1 ) {
				m[ 0 ][ 0 ] = x;
				m[ 1 ][ 1 ] = y;
				m[ 2 ][ 2 ] = z;
				m[ 3 ][ 3 ] = 1;
			}
			else {
				double len = sqrt( x * x + y * y + z * z );
				x /= len, y /= len, z /= len;
				double sina = sin( angle ), cosa = cos( angle );
				m[ 0 ][ 0 ] =      cosa + x * x * ( 1 - cosa );
				m[ 0 ][ 1 ] = -z * sina + x * y * ( 1 - cosa );
				m[ 0 ][ 2 ] =  y * sina + x * z * ( 1 - cosa );
				m[ 0 ][ 3 ] = 0;

				m[ 1 ][ 0 ] =  z * sina + x * y * ( 1 - cosa );
				m[ 1 ][ 1 ] =      cosa + y * y * ( 1 - cosa );
				m[ 1 ][ 2 ] = -x * sina + y * z * ( 1 - cosa );
				m[ 1 ][ 3 ] = 0;

				m[ 2 ][ 0 ] = -y * sina + x * z * ( 1 - cosa );
				m[ 2 ][ 1 ] =  x * sina + y * z * ( 1 - cosa );
				m[ 2 ][ 2 ] =      cosa + z * z * ( 1 - cosa );
				m[ 2 ][ 3 ] = 0;

				m[ 3 ][ 0 ] = 0;
				m[ 3 ][ 1 ] = 0;
				m[ 3 ][ 2 ] = 0;
				m[ 3 ][ 3 ] = 1;
			}
		}
		else {
			k = _k;
		}
	}
};

mat operator * ( const mat &a, const mat &b ) {
	mat c;
	memset( c.m, 0, sizeof( c.m ) );
	for( int i = 0; i < maxn; i++ ) {
		for( int j = 0; j < maxn; j++ ) {
			for( int k = 0; k < maxn; k++ ) {
				c.m[ i ][ j ] += a.m[ i ][ k ] * b.m[ k ][ j ];
			}
		}
	}
	return c;
}

mat matrix_pow( mat a, ll b ) {
	mat I, d = a;
	memset( I.m, 0, sizeof( I.m ) );
	for( int i = 0; i < maxn; i++ ) I.m[ i ][ i ] = 1;
	while( b ) {
		if( b & 1 ) {
			I = I * d;
		}
		d = d * d;
		b >>= 1;
	}
	return I;
}

char op[ 100 ];
char out[ 4 ][ 1000 ];

int main ( int argc, char* argv[] ) {
//	freopen( "in.txt", "r", stdin );
	int n;
	ll k;
	double x, y, z, angle;
	stack<mat> sta;
	mat I;
	while( scanf( "%d", &n ) && n ) {
		while( !sta.empty( ) ) {
			sta.pop();
		}
		sta.push( mat( 0, 0, 0, 0, 1, 0 ) );
		int cnt = 0;
		while( !sta.empty() ) {
			scanf( "%s", op );
			if( op[ 0 ] == 't' ) {
				scanf( "%lf%lf%lf", &x, &y, &z );
				sta.push( mat( x, y, z, 0, -1, 0 ) );
			}
			else if( op[ 0 ] == 's' ) {
				scanf( "%lf%lf%lf", &x, &y, &z );
				sta.push( mat( x, y, z, 0, -1, 1 ) );
			}
			else if( op[ 0 ] == 'r' ) {
				if( op[ 1 ] == 'o' ) {
					scanf( "%lf%lf%lf%lf", &x, &y, &z, &angle );
					angle = angle / 180 * pi;
					sta.push( mat( x, y, z, angle, -1, 2 ) );
				}
				else {
					cnt++;
					scanf( "%I64d", &k );
					sta.push( mat( 0, 0, 0, 0, k, 0 ) );
				}
			}
			else {
				cnt--;
				memset( I.m, 0, sizeof( I.m ) );
				for( int i = 0; i < maxn; i++ ) I.m[ i ][ i ] = 1;
				ll k;
				while( !sta.empty( ) ) {
					mat node = sta.top();
					sta.pop();
					if( node.k == -1 ) {
						I = I * node;
					}
					else {
						k = node.k;
						break;
					}
				}
				I = matrix_pow( I, k );
				I.k = -1;
				sta.push( I );
				if( cnt < 0 ) {
					break;
				}
			}
		}
		I = sta.top( );
		double p[ maxn ], ans[ maxn ];
		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < 3; j++ ){
				scanf( "%lf", &p[ j ] );
			}
			p[ 3 ] = 1;
			memset( ans, 0, sizeof( ans ) );
			for( int j = 0; j < maxn; j++ ) {
				for( int q = 0; q < maxn; q++ ) {
					ans[ j ] += I.m[ j ][ q ] * p[ q ];
				}
				sprintf( out[ j ], "%.2lf", ans[ j ] );
				if( strcmp( out[ j ], "-0.00" ) == 0 ) {
					sprintf( out[ j ], "0.00" );
				}
			}
			printf( "%s %s %s\n", out[ 0 ], out[ 1 ], out[ 2 ] );
		}
		printf( "\n" );
	}
	return 0;
}
