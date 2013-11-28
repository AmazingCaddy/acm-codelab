//�������ε����Բ��Բ����O�����A��������ABC�������ڽǣ���AD��ֱBC��D��
//����AO���ӳ���ԲO��E������BE��Ȼ��֤��������ABE��������ADC���ƣ�
//��AB:AE=AD:AC,��AD=��AB*AC)/AE,��S=1/2BC*AD,AE=2R������S=1/2BC*��AB*AC)/AE= abc/4R
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

int main( )
{
	triangle tr;
	double r,C;
	while( scanf("%lf%lf%lf%lf%lf%lf", &tr.p[0].x, &tr.p[0].y,
		&tr.p[1].x, &tr.p[1].y, &tr.p[2].x, &tr.p[2].y) != EOF )
	{
		r=circle_R( tr );
		C=2*pi*r;
		printf("%.2lf\n",C);
	}
	return 0;
}