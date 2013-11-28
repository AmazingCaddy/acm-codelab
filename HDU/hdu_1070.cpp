/*
	author : AmazingCaddy
	time : 2011-05-31 19:08:00 
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
typedef long long ll;

const int maxn = 104;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[ ] = { 0, -1, 0, 1, -1, -1, 1, 1 };

struct point
{
	double x, y;
	point( ){ }
	point( double _x, double _y ) : x( _x ), y( _y ) { }
	void input( ) { scanf( "%lf%lf", &x, &y ); }
};

char buf[ maxn ];
char ans[ maxn ];

int main(int argc, char *argv[])
{
	int cas, P, V, D;
	int p, v, n, d;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d", &n );
		p = inf, d = 1, v = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%s%d%d", buf, &P, &V );
			D = V / 200;
			if( D == 0 ) continue;
			if( D > 5 ) D = 5;
			if( ( ll )P * d < ( ll )D * p || ( ll )P * d == ( ll )D * p && V > v )
			{
			 	strcpy( ans, buf );
			 	p = P;
			 	v = V;
			 	d = D;
		 	}
		}
		printf( "%s\n", ans );
	}
	return 0;
}
