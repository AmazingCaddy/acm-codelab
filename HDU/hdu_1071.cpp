/*
	author : AmazingCaddy
	time : 2011-05-31 21:40:18 
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
double a, c, d, b, k;

double f( double x )
{
	return a * x * x * x / 3 - ( a * d + k / 2 ) * x * x + ( a * d * d + c - b ) * x;
}


int main(int argc, char *argv[])
{
	double x[ 3 ], y[ 3 ];
	int cas;
	scanf( "%d", &cas );
	while( cas -- )
	{
		for( int i = 0; i < 3; i++ )
			scanf( "%lf%lf", &x[ i ], &y[ i ] );
		d = x[ 0 ], c = y[ 0 ];
		a = ( y[ 1 ] - c ) / ( x[ 1 ] - d ) / ( x[ 1 ] - d );
		k = ( y[ 2 ] - y[ 1 ] ) / ( x[ 2 ] - x[ 1 ] );
		b = y[ 1 ] - k * x[ 1 ];
		printf( "%.2lf\n", f( x[ 2 ] ) - f( x[ 1 ] ) );
	}
	return 0;
}
