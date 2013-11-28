/*
	author: AmazingCaddy
	time:	2011/9/18	19:20
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 10005;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

struct rectangle {
	double x1, x2, y1, y2;
	rectangle( ) { }
	rectangle( double _x1, double _x2, double _y1, double _y2 ) {
		if( _x1 > _x2 ) {
			swap( _x1, _x2 );
		}
		if( _y1 > _y2 ) {
			swap( _y1, _y2 );
		}
		x1 = _x1, x2 = _x2;
		y1 = _y1, y2 = _y2;
	}
	rectangle( double x, double y, double a, double b, int t ) {
		if( t == 2 ) {
			swap( a, b );
		}
		a /= 2, b /= 2;
		x1 = x - a, x2 = x + a;
		y1 = y - b, y2 = y + b;
	}
	bool check( double W, double H ) {
		return ( D( 0 - x1 ) <= 0 && D( x1 - W ) <= 0 
			  && D( 0 - x2 ) <= 0 && D( x2 - W ) <= 0
			  && D( 0 - y1 ) <= 0 && D( y1 - H ) <= 0 
			  && D( 0 - y2 ) <= 0 && D( y2 - H ) <= 0 );
	}
};

double min_rec_rec( const rectangle & rec1, const rectangle & rec2 ) {
	double ans = 0;
	if( rec2.x2 < rec1.x1 ) {
		ans += ( rec1.x1 - rec2.x2 );
	}
	else if( rec1.x2 < rec2.x1 ) {
		ans += ( rec2.x1 - rec1.x2 );
	}
	if( rec2.y2 < rec1.y1 ) {
		ans += ( rec1.y1 - rec2.y2 );
	}
	else if( rec1.y2 < rec2.y1 ) {
		ans += ( rec2.y1 - rec1.y2 );
	}
	return ans;
}

int main(int argc, char *argv[]){
	double W, H, a, b;
	double x1, y1, x2, y2;
	int t1, t2;
	while( scanf( "%lf%lf%lf%lf", &W, &H, &a, &b ) != EOF ) {
		scanf( "%lf%lf%d%lf%lf%d", &x1, &y1, &t1, &x2, &y2, &t2 );
		rectangle rec1( x1, y1, a, b, t1 ), rec2( x2, y2, a, b, t2 );
		if( !rec1.check( W, H ) || !rec2.check( W, H ) ) {
			printf( "-1\n" );
			continue;
		}
		double ans = fabs( x1 - x2 ) + fabs( y1 - y2 );
		if( t1 == t2 ) {
			printf( "%.3lf\n", ans );
			continue;
		}
		if( W * W < a * a + b * b || H * H < a * a + b * b ) {
			printf( "-1\n" );
			continue;
		}
		double c = sqrt( a * a + b * b );
		rectangle squ( c / 2, W - c / 2, c / 2, H - c / 2);
		/*
		if( squ.x1 > squ.x2 || squ.y1 > squ.y2 ) {
			printf( "-1\n" );
			continue;
		}
		*/
		rectangle rec( x1, x2, y1, y2 );
		double dis = min_rec_rec( squ, rec );
		ans += dis * 2;
		printf( "%.3lf\n", ans );
	}
	return 0;
}
