/*
	author: AmazingCaddy
	time:	2011-08-18 19:08:18 
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
	int cas, n, k;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d%d", &n, &k );
		printf( "Case %d: ", t );
		if( k == 1 ) {
			if( n % 2 == 1 ) {
				puts( "first" );
			}
			else {
				puts( "second" );
			}
		}
		else
		{
			if( k < n ) {
				puts( "second" );
			}
			else {
				puts( "first" );
			}
		}
	}
	return 0;
}
