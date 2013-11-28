/*
	author: AmazingCaddy
	time:	2011/7/30  15:43
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

//typedef __int64 ll;
typedef long long ll;

const int maxn = 1004;
const double eps = 1e-8;

double p[ maxn ][ maxn ][ 3 ];
double dp[ maxn ][ maxn ];

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

int main(int argc, char *argv[])
{
//	freopen( "data1.in", "r", stdin );
//	freopen( "out", "w", stdout );
	int R, C;
	while( scanf( "%d%d", &R, &C ) != EOF )
	{
		for( int i = 1; i <= R; i++ )
			for( int j = 1; j <= C; j++ )
				for( int k = 0; k < 3; k++ )
					scanf( "%lf", &p[ i ][ j ][ k ] );
		for( int i = R; i >= 1; i-- )
		{
			for( int j = C; j >= 1; j-- )
			{
				dp[ i ][ j ] = 0;
				if( i == R && j == C ) continue;
				if( j < C ) dp[ i ][ j ] += p[ i ][ j ][ 1 ] * dp[ i ][ j + 1 ];
				if( i < R ) dp[ i ][ j ] += p[ i ][ j ][ 2 ] * dp[ i + 1 ][ j ];
				dp[ i ][ j ] += 1;
				if( D( 1 - p[ i ][ j ][ 0 ] ) != 0 )
					dp[ i ][ j ] /= ( 1 - p[ i ][ j ][ 0 ] );
				else dp[ i ][ j ] = 1;
			}
		}
		printf( "%.3lf\n", dp[ 1 ][ 1 ] * 2 );
	}
	return 0;
}
