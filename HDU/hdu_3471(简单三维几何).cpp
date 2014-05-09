#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct point
{
	double x, y, z;
	point( double a, double b, double c ) : x(a), y(b), z(c){ }
	point( ){ x = 0, y = 0, z = 0; }
};
const double eps = 1e-8;
point operator ^ ( point a, point b )
{
	return point( b.z * a.y - b.y * a.z, b.x * a.z - a.x * b.z, a.x * b.y - b.x * a.y );
}
double operator & ( point a, point b )
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
point operator + ( point a, point b )
{
	return point( a.x + b.x, a.y + b.y, a.z + b.z );
}
point operator - ( point a, point b )
{
	return point( a.x - b.x, a.y - b.y, a.z - b.z );
}
point operator * ( point p, double x )
{
	return point( p.x * x, p.y * x, p.z * x );
}
point operator / ( point p, double x )
{
	return point( p.x / x, p.y / x, p.z / x );
}
double dis( point p1 )
{
	return sqrt(p1.x*p1.x+p1.y*p1.y+p1.z*p1.z);
}
int dblcmp( double x ) { return x < -eps ? -1 : x >eps ; }
int main(int argc, char *argv[])
{
	int t;
	//freopen("eg.in","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&t);
	point v, s, p[8];
	for( int q = 1; q <= t; q++ )
	{
		bool flag;
		scanf("%lf%lf%lf",&s.x,&s.y,&s.z);
		scanf("%lf%lf%lf",&v.x,&v.y,&v.z);
		for( int i = 0; i < 8; i++ )
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
		// 平面ABCD的法向量
		point n = p[4] - p[0];
		if( dblcmp( v & n ) <= 0 )
			printf("Case %d: Intelligent Larrionda!!!\n",q);
		else
		{
			double nlen = dis( n ); 
			double h1 = ( ( p[0] - s ) & n ) / nlen;
			double h2 = ( v & n ) / nlen;
			point t;
			if( dblcmp( h1 ) > 0 ) t = s + v * h1 / h2;
			else t = s;
			flag = true;
			for( int i = 0; i < 4; i++ )
			{
				point c = p[(i+1)%4] - p[i];
				point d = t - p[i];
				point e = p[i] - t;
				point f = p[(i+1)%4] - t;
				if( ( dblcmp( dis( c ^ d ) ) == 0 ) && dblcmp( e & f ) <= 0 )
					flag = false;
			}
			if( !flag )
			{
				printf("Case %d: Intelligent Larrionda!!!\n",q);
				continue;
			}
			point g = p[2] - p[3];
			point h = p[0] - p[3];
			point tt = t - p[3];
			point j = p[0] - p[1];
			point k = p[2] - p[1];
			point ss = t - p[1];
			//double hlen = dis( p[0] - p[3] ), glen = dis( p[2] - p[3] );
			//double Hlen, Glen;
			if( ( dblcmp( tt & h ) > 0 && dblcmp( tt & g ) > 0 ) &&
				( dblcmp( ss & j ) > 0 && dblcmp( ss & k ) > 0 ) )
				printf("Case %d: Stupid Larrionda!!!\n",q);
			else printf("Case %d: Intelligent Larrionda!!!\n",q);
 		}
	}
	return 0;
}



/*
10
-438.943786 -12.040495 251.440297
405.327817 18.162952 -267.545264
7.809129 -50.068625 -8.389828
-34.834707 -50.068625 -57.445951
-68.643837 46.000000 -28.056123
-26.000000 46.000000 21.000000
79.629042 -5.693708 -70.821926
36.985205 -5.693708 -119.878048
3.176076 90.374917 -90.488220
45.819913 90.374917 -41.432098
*/
