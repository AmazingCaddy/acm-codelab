//#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct point3D
{
	double x, y, z;
	point3D( double a, double b, double c ) : x( a ), y( b ), z( c ) { }
	point3D( ){ }
};

point3D operator + ( point3D p1, point3D p2 ){ return point3D( p1.x + p2.x, p1.y + p2.y, p1.z + p2.z ); }
point3D operator - ( point3D p1, point3D p2 ){ return point3D( p1.x - p2.x, p1.y - p2.y, p1.z - p2.z ); }
point3D operator * ( point3D p1, double x )  { return point3D( p1.x * x, p1.y * x, p1.z * x ); }
point3D operator / ( point3D p1, double y )  { return point3D( p1.x / y, p1.y / y, p1.z / y ); }

// 三维叉积
point3D operator ^ ( point3D p1, point3D p2 )
{
	return point3D( p1.y * p2.z - p1.z * p2.y, p2.x * p1.z - p2.z * p1.x, p1.x * p2.y - p1.y * p2.x );
}
// 三维点积
double operator & ( point3D p1, point3D p2 )
{
	return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

double volume( point3D p1, point3D p2, point3D p3, point3D p4 )
{
	return ( p4 - p1 ) & ( p3 - p1 ^ p2 - p1 ) / 6;
}

int main( )
{
	int n, m;
	double x, y, z;
	point3D zero( 0, 0, 0 );
	vector<point3D> poly;
	while( scanf("%d",&n) && n )
	{
		double ans = 0;
		for( int i = 0; i < n; i++ )
		{
			poly.clear( );
			scanf("%d",&m);
			for( int j = 0; j < m; j++ )
			{
				scanf("%lf%lf%lf",&x,&y,&z);
				poly.push_back( point3D( x, y, z ));
			}
			for( int j = 0; j < m; j++ )
				ans = ans + volume( zero, poly[0], poly[j], poly[(j+1)%m]);
		}
		printf("%.4lf\n",fabs(ans));
	}
}
