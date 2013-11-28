#include <cstdio>
#include <iostream>
#include <cstring>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 20005;
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos( -1.0 );
const double g = 10.0;

struct node
{
	double angle1, angle2;
}ang[ maxn << 1 ];

int D( double x ) { return ( x < -eps ? -1 : x > eps ); }

bool cmp( const node & a, const node & b )
{
	if( D( a.angle1 - b.angle1 ) != 0 ) return a.angle1 < b.angle1;
	return D( a.angle2 - b.angle2 ) < 0;
}


//double y1[ maxn ], y2[ maxn ];
//double x[ maxn ];
 
int main(int argc, char *argv[])
{
	int cas, v0, n;
	double a, b, c, t, x, y1, y2, data;
	double angle1, angle2, angle3, angle4;
	scanf("%d",&cas);
	while( cas-- )
	{
		scanf("%lf%d",&v0,&n);
		int len = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf("%lf%lf%lf",&x,&y1,&y2);
			a = g * ( x / v0 ) * ( x / v0 ) / 2.0 ;
			b = -x;
			c = y1 + a;
			data = b * b - 4 * a * c ;
			if( D( data ) >= 0 )
			{
				if( data < 0 ) data = 0;
				t = sqrt( data );
				angle1 = ( -b - t ) / 2.0 / a ;
				angle2 = ( -b + t ) / 2.0 / a ;
			}
			else continue;
			a = g * ( x / v0 ) * ( x / v0 ) / 2.0 ;
			b = -x ;
			c = y2 + a ;
			data = b * b - 4 * a * c ;
			if( D( data ) >= 0 )
			{
				if( data < 0 ) data = 0;
				t = sqrt( data );
				angle3 = ( -b - t ) / 2.0 / a ;
				angle4 = ( -b + t ) / 2.0 / a ;
				ang[ len ].angle1 = angle1;
				ang[ len ].angle2 = angle3;
				len++;
				ang[ len ].angle1 = angle4;
				ang[ len ].angle2 = angle2;
				len++;
 			}
			else
			{
				ang[ len ].angle1 = angle1;
				ang[ len ].angle2 = angle2;
				len++;
			}

		}
		sort( ang, ang + len, cmp );
		double st = ang[ 0 ].angle1, ed = ang[ 0 ].angle2;
		int ans = 1, cnt = 0;
		for( int i = 1; i < len; i++ )
		{
			if( D( ang[ i ].angle1 - ed ) > 0 )
			{
				if( cnt > ans ) ans = cnt;
				st = ang[ i ].angle1, ed =ang[ i ].angle2;
			}
			else
			{
				cnt++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
