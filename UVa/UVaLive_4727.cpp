/*
	author: AmazingCaddy
	time:	
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

const int maxn = 10004;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[ ] = { 0, -1, 0, 1, -1, -1, 1, 1 };

struct point {
	double x, y;
	point( ){ }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	int cas, n, m;
	scanf( "%d", &cas );
	while( cas -- ) {
		scanf( "%d%d", &n, &m );
		int s = 0;
		int t = 1 - ( s + m ) % 2;
		int vis[ 3 ] = { 0 };
		vis[ ( 0 + m ) % 3 ] = 1, vis[ ( 1 + m ) % 3 ] = 1;
		int r = -1;
		for( int i = 0; i < 3; i++ ) {
			if( !vis[ i ] ) {
				r = i;
				break;
			}
		}
		for( int i = 2; i <= n; i++ ) {
			s = ( s + m ) % i;
		}
		for( int i = 3; i <= n; i++ ) {
			t = ( t + m ) % i;
		}
		for( int i = 4; i <= n; i++ ) {
			r = ( r + m ) % i;
		}
		printf( "%d %d %d\n", r + 1, t + 1, s + 1 ); 
	}
	return 0;
}
