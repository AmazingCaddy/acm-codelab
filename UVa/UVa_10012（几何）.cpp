/*
author: AmazingCaddy
time: 2011/5/22  15:50
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

const int maxn = 10;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

int id[ maxn ];
double r[ maxn ];
double Dis[ maxn ];

double getlength( int n )
{
	if( n == 1 ) return 2 * r[ id[ 0 ] ];
	//if( n == 2 ) return r[ id[ 0 ] ] + r[ id[ 1 ] ] + 2 * sqrt( r[ id[ 0 ] ] * r[ id[ 1 ] ] );
	Dis[ 0 ] = 0;
	for( int i = 1; i < n; i++ )
	{
		double MaxX = 0;
		for( int j = 0; j < i; j++ )
		{
			double t = Dis[ j ] + 2 * sqrt( r[ id[ j ] ] * r[ id[ i ] ] );
			if( t > MaxX ) MaxX = t;
		}
		Dis[ i ] = MaxX;
	}
	double L = inf, R = -inf;
	for( int i = 0; i < n; i++ )
	{
		if( L > Dis[ i ] - r[ id[ i ] ] )
			L = Dis[ i ] - r[ id[ i ] ];
		if( R < Dis[ i ] + r[ id[ i ] ] )
			R = Dis[ i ] + r[ id[ i ] ];
	}
	return R - L;
	/*
	double ans = r[ id[ 0 ] ] + r[ id[ n - 1 ] ];
	for( int i = 1; i < n; i++ )
		ans += 2 * sqrt( r[ id[ i ] ] * r[ id[ i - 1 ] ] );

	return ans;
	*/
}

int main(int argc, char *argv[])
{
	int cas, m;
	//freopen( "B_in.txt", "r", stdin );
	//freopen( "out.txt", "w", stdout );
	scanf( "%d", &cas );
	while( cas -- )
	{
		scanf( "%d", &m );
		double Maxr = 0;
		for( int i = 0; i < m; i++ )
		{
			scanf( "%lf", &r[ i ] );
			if( r[ i ] > Maxr ) Maxr = r[ i ];
		}
		//printf( "MaxR = %lf\n", Maxr );
		for( int i = 0; i < m; i++ )
			id[ i ] = i;
		double ans = inf;
		//ans = getlength( m );
		do
		{
			double tmp = getlength( m );
			//printf( "%lf\n", tmp );
			ans = ( ans < tmp ? ans : tmp );
			//for( int i = 0; i < m; i++ )
			//	printf( "%d ", id[ i ] );
			//printf( "\n" );
		}while( next_permutation( id, id + m ) );
		printf( "%.3lf\n", ans );
	}
	return 0;
}

/*
1
3 0.196 0.009 0.735
*/
