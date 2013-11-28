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
typedef long long ll;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int main(int argc, char *argv[]) {
//	freopen( "in.txt", "r", stdin );
	double n, m, t, c;
	int cas;
	scanf( "%d", &cas );
	for( int i = 1; i <= cas; i++ ) {
		scanf( "%lf%lf%lf%lf", &n, &m, &t, &c );
		if( i > 1 ) {
			printf( "\n" );
		}
		double area  = n * m * t * t;
		double area1 = ( t - c ) * ( t - c ) * n * m + ( m + n ) * c * ( t - c ) + c * c;
		double area2 = ( m + n - 2 ) * c * c + ( 2 * m * n - n - m ) * c * ( t - c );
		double area3 = ( area - ( area1 + area2 ) ) * ( 1 - pi / 4 );
		double area4 = ( area - ( area1 + area2 ) ) * pi / 4;
		printf( "Case %d:\n", i );
		printf( "Probability of covering 1 tile  = %.4f%%\n", area1 / area * 100 );
		printf( "Probability of covering 2 tiles = %.4f%%\n", area2 / area * 100 );
		printf( "Probability of covering 3 tiles = %.4f%%\n", area3 / area * 100 );
		printf( "Probability of covering 4 tiles = %.4f%%\n", area4 / area * 100 );
	}
	return 0;
}
