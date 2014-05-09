//作三角形的外接圆（圆心是O）设角A是三角形ABC中最大的内角，作AD垂直BC于D，
//连接AO并延长交圆O于E，连接BE，然后证明三角形ABE与三角形ADC相似，
//得AB:AE=AD:AC,即AD=（AB*AC)/AE,又S=1/2BC*AD,AE=2R，所以S=1/2BC*（AB*AC)/AE= abc/4R
#include<cmath>
#include<iostream>
#define pi 3.141592653589793
using namespace std;
const double eps = 1e-6;

struct point
{
	double x,y;
};

struct triangle
{
	point p[3];
};

struct circle
{
	point p;
	double r;
};

double Distance( const point &p1, const point &p2 )
{
	return sqrt( ( p1.x-p2.x )*( p1.x-p2.x )+( p1.y-p2.y )*( p1.y-p2.y ) );
}

double triangle_area( const triangle & tr )
{
	return fabs( tr.p[0].x*tr.p[1].y-tr.p[1].x*tr.p[0].y+tr.p[1].x*tr.p[2].y-
		tr.p[2].x*tr.p[1].y+tr.p[2].x*tr.p[0].y-tr.p[0].x*tr.p[2].y ) / 2 ;
}

double circle_R( const triangle & tr )
{
	double area,r,a,b,c;
	area=triangle_area( tr );
	a=Distance( tr.p[0], tr.p[1] );
	b=Distance( tr.p[1], tr.p[2] );
	c=Distance( tr.p[2], tr.p[0] );
	r=a*b*c/4/area;
	return r;
}

circle circumcircle_of_triangle( const triangle & tr )
{
	//三角形的外接圆
	circle tmp;
	double a, b, c;
	double c1, c2;
	double xA, yA, xB, yB, xC, yC;
	a = Distance( tr.p[0], tr.p[1] );
	b = Distance( tr.p[1], tr.p[2] );
	c = Distance( tr.p[2], tr.p[0] );
	//根据S = a * b * c / R / 4;求半径R 
	tmp.r = a * b * c / triangle_area(tr) / 4;
	
	xA = tr.p[0].x;  yA = tr.p[0].y;
	xB = tr.p[1].x;  yB = tr.p[1].y;
	xC = tr.p[2].x;  yC = tr.p[2].y;
	c1 = ( xA * xA + yA * yA - xB * xB - yB * yB ) / 2;
	c2 = ( xA * xA + yA * yA - xC * xC - yC * yC ) / 2;

	tmp.p.x = -( c1*( yA-yC )-c2*( yA-yB ) ) / ( ( xA-xB )*( yA-yC )-( xA-xC )*( yA-yB ) ); 
	tmp.p.y = -( c1*( xA-xC )-c2*( xA-xB ) ) / ( ( yA-yB )*( xA-xC )-( yA-yC )*( xA-xB ) ); 
	
	return tmp;
}

int main( )
{
	triangle tr;
	circle cir;
	double c, d, e;
	while( scanf("%lf%lf%lf%lf%lf%lf", &tr.p[0].x, &tr.p[0].y, 
		&tr.p[1].x, &tr.p[1].y, &tr.p[2].x, &tr.p[2].y) != EOF )
	{
		cir = circumcircle_of_triangle( tr );
		// printf("%lf %lf %lf\n", circle.centre.x, circle.centre.y, circle.r);

		if( fabs( cir.p.x ) < eps) printf("x^2");
		else if( cir.p.x < 0 ) printf("(x - %.3lf)^2 + ",-cir.p.x);
		else printf("(x + %.3lf)^2 + ", cir.p.x);
		if( fabs( cir.p.y ) < eps ) printf("y^2 = ");
		else if( cir.p.y < 0 ) printf("(y - %.3lf)^2 = ",-cir.p.y);
		else printf("(y + %.3lf)^2 = ", cir.p.y );
		printf("%.3lf^2\n", cir.r );
		c = 2 * cir.p.x;
		d = 2 * cir.p.y;
		e = cir.p.x * cir.p.x + cir.p.y * cir.p.y - cir.r * cir.r;
		printf("x^2 + y^2 ");
		//if(fabs(c) < eps) 
		if(c < 0) printf("- %.3lfx ", -c);
		else printf("+ %.3lfx ", c);
		if(d < 0) printf("- %.3lfy ", -d);
		else printf("+ %.3lfy ", d);
		if(e < 0) printf("- %.3lf = 0\n", -e);
		else printf("+ %.3lf = 0\n", e);
		printf("\n");
	}
	return 0;	
}