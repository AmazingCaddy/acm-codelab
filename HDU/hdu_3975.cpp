/*
	author: AmazingCaddy
	time:	2011/9/5	13:53
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

typedef long long ll;

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;
const double g = 10.0;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

int main(int argc, char *argv[]) {
	double a, b, c, d, e, f;
	double x0, x1, x2;
	double v0, v1, v2;
	double angle0, angle1, angle2;
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%lf%lf%lf", &x0, &x1, &x2 );
		scanf( "%lf%lf%lf", &v0, &v1, &v2 );
		scanf( "%lf%lf%lf", &angle0, &angle1, &angle2 );
		printf( "Case #%d: ", t );
		if( D( v0 ) == 0 || D( v1 ) == 0 || D( v2 ) == 0 || 
			D( sin( angle0 ) ) == 0 || D( sin( angle1 ) ) == 0 || D( sin( angle2 ) ) == 0 ) {
			printf( "-1\n" );
			continue;
		}
		a = x1 - x0;
		b = v1 * cos( angle1 ) - v0 * cos( angle0 );
		c = v2 * sin( angle2 ) - v0 * sin( angle0 );
		d = x2 - x0;
		e = v2 * cos( angle2 ) - v0 * cos( angle0 );
		f = v1 * sin( angle1 ) - v0 * sin( angle0 );
		
		double v = b * c - e * f, u = d * f - a * c;
		if( D( v ) == 0 && D( u ) == 0 ) {
			printf( "Multiply answer\n" );
			continue;
		}
		if( D( v ) == 0 ) {
			printf( "-1\n" );
			continue;
		}
		double ans = u / v;
		double t = min( v0 * sin( angle0 ) / g, v1 * sin( angle1 ) / g );
		t = min( t, v2 * sin( angle2 ) / g );
		t *= 2;
		if( ans > 0 && D( ans - t ) <= 0 ) {
			printf( "%.4lf\n", ans );
		}
		else {
			printf( "-1\n" );
		}
	}
	return 0;
}
