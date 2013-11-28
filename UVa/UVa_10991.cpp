/*
	author: AmazingCaddy
	time: 2011/5/22  14:29
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

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

double solve( double r1, double r2, double r3 )
{
	double a = r1 + r2, b = r2 + r3, c = r1 + r3;
	double angle1 = acos( ( a * a + c * c - b * b ) / ( 2 * a * c ) );
	double angle2 = acos( ( a * a + b * b - c * c ) / ( 2 * a * b ) );
	double angle3 = acos( ( b * b + c * c - a * a ) / ( 2 * b * c ) );
	double p = ( a + b + c ) / 2;
	return sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) ) 
		- 0.5 * ( angle1 * r1 * r1 + angle2 * r2 * r2 + angle3 * r3 * r3 );
}

int main(int argc, char *argv[])
{
	double r1, r2, r3;
	int cas;
	scanf( "%d", &cas );
	while( cas -- )
	{
		scanf( "%lf%lf%lf", &r1, &r2, &r3 );
		double ans = solve( r1, r2, r3 );
		printf( "%.6lf\n", ans );
	}
	return 0;
}
