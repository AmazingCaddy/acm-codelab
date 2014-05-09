/*
	author: AmazingCaddy
	time: 2011/4/2  0:07 ~ 0:51
	设当前的时间为 H:M:S, 其中 0 <= H < 12, 0 <= M < 60, 0 <= S < 60, H,M皆为整数, S为实数
	于是时针、分针、秒针相对于时刻 0:0:0 的转角分别为
	A(H) = 30H + M/2 + S/120;
	A(M) = 6M + S/10;
	A(S) = 6S;
	(1) D <= | A(H) - A(M) | <= 360-D;
	(2) D <= | A(H) - A(S) | <= 360-D;
	(3) D <= | A(M) - A(S) | <= 360-D; 

		D <= | pS - q | <= 360-D
	[ (q+D)/p, (q+360-D)/p ] 并 [ (q+D-360)/p, (q-D)/p ]
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
const double eps = 1e-8;
int D;

struct seg
{
	double x, y;
	int flag;
	seg( ){ }
	seg( double _x, double _y ) : x( _x ), y( _y ) { flag = x < y; }
};

seg operator *( const seg &a, const seg &b )
{
	double x = max( a.x, b.x );
	double y = min( a.y, b.y );
	return seg( x, y );
}

seg make_seg1( double x, double y )
{
	double xx = ( D + y ) / x;
	double yy = ( 360 - D + y ) / x;
	if( xx < 0.0 ) xx = 0.0;
	if( yy > 60.0 ) yy = 60.0;
	return seg( xx, yy );
}

seg make_seg2( double x, double y )
{
	double xx = ( D - 360 + y ) / x;
	double yy = ( y - D ) / x;
	if( xx < 0.0 ) xx = 0.0;
	if( yy > 60.0 ) yy = 60.0;
	return seg( xx, yy );
}

double merge( seg s[ ][ 2 ] )
{
	double sum = 0;
	seg tmp;
	for( int i = 0; i < 2; i++ )
	{
		for( int j = 0; j < 2; j++ )
		{
			for( int k = 0; k < 2; k++ )
			{
				tmp = s[ 0 ][ i ] * s[ 1 ][ j ] * s[ 2 ][ k ];
				sum += ( tmp.flag ? tmp.y - tmp.x : 0 );
			}
		}
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int H = 12, M = 60;
	double p, q;
	while( scanf( "%d", &D ) && D != -1 )
	{
		double len = 0;
		for( int i = 0; i < H; i++ )
		{
			for( int j = 0; j < M; j++ )
			{
				seg s[ 3 ][ 2 ];
				p = 11.0 / 120.0; q = 30.0 * i - 5.5 * j;
				s[ 0 ][ 0 ] = make_seg1( p, q );
				s[ 0 ][ 1 ] = make_seg2( p, q );
				p = 5.9; q = 6.0 * j;
				s[ 1 ][ 0 ] = make_seg1( p, q );
				s[ 1 ][ 1 ] = make_seg2( p, q );
				p = 719.0 / 120.0; q = 30 * i + 0.5 * j;
				s[ 2 ][ 0 ] = make_seg1( p, q );
				s[ 2 ][ 1 ] = make_seg2( p, q );
				len += merge( s );
			}
		}
		printf( "%.3lf\n", len * 100 / 43200 );
	}
	return 0;
}
