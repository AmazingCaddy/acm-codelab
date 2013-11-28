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
const double eps = 1e-8;
typedef complex<double> point;

double operator ^(point p0, point p1) {return imag(conj(p0) * p1);}
double operator&(point p0, point p1) {return real(conj(p0) * p1);}
int dcmp(double x) { return x < -eps ? -1 : x > eps; }
point prev( const point &a ) { return a*point(0,1)/abs(a);}

point in( )
{
	double x, y;
	scanf("%lf %lf",&x, &y);
	return point(x, y);
}

//求两条直线的交点
point intersection( const point &u1, const point &u2, const point &v1, const point &v2) {
	double t = v1 - u1^ v2 - u1;
	double s = v2 - u2^ v1 - u2;
	return u1 + (u2 - u1) * t / (t + s);
}

//求角aob
double angle(point a, point b, point o)
{
	return atan2(a - o ^ b - o, a - o & b - o);
}

//求直线和圆的交点,点存在p中
void line_circle_intersect(point &l1, point &l2, point &c, double &r, vector<point> & p)
{
	point q = intersection(c + prev(l1 - l2), c, l1, l2);
	if (dcmp( r - abs(q - c) ) == 0)
		p.push_back( q );
	else
		if( dcmp(r - abs(q - c) ) > 0)
		{
			double t = sqrt(r * r - norm(q - c) ) / abs(l1 - l2);
			p.push_back( q + (l2 - l1) * t );
			p.push_back( q - (l2 - l1) * t );
		}
}

//判断点是否在线段上,不包括端点
bool point_on_seg(point &a, point &b, point &c)
{
	return dcmp(a - b ^ a - c)==0 && dcmp(b - a & c - a) < 0;
}


//求线段和圆的交点,点存在p中
void seg_circle_intersect(point & l1, point & l2, point & c, double &r, vector<point> & p)
{
	line_circle_intersect(l1, l2, c, r, p);

	for(int i = 0; i < p.size(); i++)
		if(!point_on_seg( p[i], l1, l2) )
		{
			for(int j = i; j < p.size()-1; j++)
				p[j] = p[j+1];
			p.pop_back();
			i = -1;
		}

		if( dcmp( abs(l1 - c) - r) <= 0)p.push_back(l1);
		if( dcmp( abs(l2 - c) - r) <= 0)p.push_back(l2);
}

//求三角形和圆相交的面积.这里的三角形有一个顶点和圆心重合
double tri_circle_area(point & a, point & b, point & c, double & r)
{
	vector<point> p;
	seg_circle_intersect(a, b, c, r, p);
	double t = fabs( angle( a, b, c) );
	if(p.size() != 2)
	{
		return 0.5 * r * r * t;
	}
	else
	{
		double s = fabs( angle(p[0] ,p[1], c) );
		return 0.5 * fabs(p[0] - c ^ p[1] - c) + 0.5 * r * r * (t - s);
	}
}
//求任意多边形和圆相交的面积
double poly_circle_area(vector<point> poly, point c, double r)
{
	double area = 0; int sz = poly.size();
	for(int i = 0; i < sz; i++)
	{
		double pos = tri_circle_area(poly[i], poly[(i+1) % sz], c, r);
		if( ( poly[(i+1) % sz] - c ^ poly[i] - c) > 0)
			area += pos;
		else
			area -= pos;
	}
	return fabs(area);
}

int main() {
	point c; double r; 
	vector<point> poly;
	double x, y;
	while(scanf("%lf %lf", &x, &y) != EOF) {
		poly.resize(3);
		poly[0] = point(x, y);
		poly[1] = in();
		poly[2] = in();
		c = in();
		scanf("%lf",&r);
		printf("%.2f\n",poly_circle_area(poly, c, r) );
	}
	return 0;
}