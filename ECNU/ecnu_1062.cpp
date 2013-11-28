#include<iostream>
#include<cmath>
#define precision 1e-6
using namespace std;
struct point
{
	double x,y;
};

int dblcmp( double d )
{
	if( fabs(d)<precision )return 0;
	return (d>0)?1:-1;
}

double det( double x1, double y1, double x2, double y2 )
{
	return x1*y2-x2*y1;
}

double cross( point a, point b, point c )
{
	return det( b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y );
}

double dotdet( double x1, double y1, double x2, double y2 )
{
	return x1*x2+y1*y2;
}

double dot( point a, point b, point c )
{
	return dotdet( b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y );
}

int betweencmp( point a, point b, point c )
{
	return dblcmp( dot( a, b, c ) );
}

bool segcross( point a, point b, point c, point d )
{
	int d1,d2,d3,d4;
	d1=dblcmp( cross(a,b,c) );
	d2=dblcmp( cross(a,b,d) );
	d3=dblcmp( cross(c,d,a) );
	d4=dblcmp( cross(c,d,b) );

	if( ( d1^d2 )==-2 && ( d3^d4 )==-2 )return true;
	if( d1==0 && betweencmp( c, a, b )<=0 ||
		d2==0 && betweencmp( d, a, b )<=0 ||
		d3==0 && betweencmp( a, c, d )<=0 ||
		d4==0 && betweencmp( b, c, d )<=0 )
		return true;
	return false;
}

int main()
{
	point a,b,c,d;
	while( scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y) != EOF )
	{
		if( segcross(a,b,c,d) )printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}