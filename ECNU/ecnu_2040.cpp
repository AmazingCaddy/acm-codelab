/*
ID: ecnuwbw1
PROG: 
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 203;
const double inf = 1e10;

double x[ maxn ], y[ maxn ];
double k[ maxn * maxn ];

int main(int argc, char *argv[])
{
	int n;
	scanf( "%d", &n );
	for( int i = 0; i < n; i++ )
		scanf( "%lf%lf", &x[ i ], &y[ i ] );
	int len = 0;
	for( int i = 0; i < n; i++ )
	{
		for( int j = i + 1; j < n; j++ )
		{
			if( x[ i ] == x[ j ] ) k[ len++ ] = inf;
			else k[ len++ ] = ( y[ i ] - y[ j ] ) / ( x[ i ] - x[ j ] );
		}
	}
	sort( k, k + len );
	int ans = unique( k, k + len ) - k;
	printf( "%d\n", ans);
	return 0;
}
