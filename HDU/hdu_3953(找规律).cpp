/*
	author: AmazingCaddy
	time:	2011-08-18 19:08:59 
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

const int maxn = 104;
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

char A[ maxn ], B[ maxn ];
int main(int argc, char *argv[]) {
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%s%s", A, B );
		int sum = 0;
		for( int i = 0; A[ i ]; i++ ) {
			sum += ( A[ i ] - '0' );
		}
		for( int i = 0; B[ i ]; i++ ) {
			sum += ( B[ i ] - '0' );
		}
		printf( "Case %d: %d\n", t, sum );
	}
	return 0;
}
