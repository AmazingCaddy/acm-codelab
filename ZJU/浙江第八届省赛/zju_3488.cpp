/*
	author: AmazingCaddy
	time: 2011/5/6  13:35
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
using namespace std;

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }
int main(int argc, char *argv[])
{
	double a, b, c, d, e, f;
	int cas;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f );
		if( D( a ) == 0 || D( c ) == 0 ) printf( "parabola\n" );
		else if( D( a ) * D( c ) < 0 ) printf( "hyperbola\n" );
		else if( D( a - c ) == 0 )printf( "circle\n" );
		else printf( "ellipse\n" );
	}
	return 0;
}
