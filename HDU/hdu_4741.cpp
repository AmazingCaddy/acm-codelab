/*
 *	time:	2013-12-18 19:28
 *	author:	AmazingCaddy
 *	solve:	几何模板题，解两条异面直线的公垂线段
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

const double eps = 1e-8;
int D (double x) {
	return x < -eps ? -1 : x > eps;
}

struct point3 {
	double x, y, z;
	point3 (double _x = 0, double _y = 0, double _z = 0) :x(_x), y(_y), z(_z) {
	}
	void input () {
		scanf ("%lf%lf%lf", &x, &y, &z);
	}
	double len2 () {
		return x * x + y * y + z * z;
	}
	double len () {
		return sqrt(len2());
	}
};

struct line {
	point3 p1, p2;
};

point3 operator + (const point3 &a, const point3 &b) {
	return point3(a.x + b.x, a.y + b.y, a.z + b.z);
}
point3 operator - (const point3 &a, const point3 &b) {
	return point3(a.x - b.x, a.y - b.y, a.z - b.z);
}
point3 operator * (const point3 &a, const double &b) {
	return point3(a.x * b, a.y * b, a.z * b);
}
point3 operator / (const point3 &a, const double &b) {
	return point3(a.x / b, a.y / b, a.z / b);
}
double operator & (const point3 &a, const point3 &b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
point3 operator ^ (const point3 &a, const point3 &b) {
	return point3(a.y * b.z - a.z * b.y, -(a.x * b.z - a.z * b.x), a.x * b.y - a.y * b.x);
}

double dis2 (const point3 &p) {
	return p.x * p.x + p.y * p.y + p.z * p.z;
}

double dis (const point3 &a, const point3 &b) {
	return sqrt (dis2 (a - b));
}

/*
void Intersection( Line x,Line y ){
    double t1 = ( (y.a-x.a)^(y.b-y.a) )*( (x.b-x.a)^(y.b-y.a) );
    double t2 = ( (y.a-x.a)^(x.b-x.a) )*( (x.b-x.a)^(y.b-y.a) );
    t1 /= dis2One( (x.b-x.a)^(y.b-y.a) );
    t2 /= dis2One( (x.b-x.a)^(y.b-y.a) );
    Mid1 = x.a+(x.b-x.a)*t1;
    Mid2 = y.a+(y.b-y.a)*t2;
    
    return ;
}
*/
line nearLL (const point3 &p1, const point3 &p2, const point3 &p3, const point3 &p4, double &ans) {
	line res;
    double t1 = ((p3 - p1) ^ (p4 - p3)) & ((p2 - p1) ^ (p4 - p3));
    double t2 = ((p3 - p1) ^ (p2 - p1)) & ((p2 - p1) ^ (p4 - p3));
    t1 /= ((p2 - p1) ^ (p4 - p3)).len2();
    t2 /= ((p2 - p1) ^ (p4 - p3)).len2();
	/*
	double d1 = p1 - p3 & p4 - p3;	//1343
	double d2 = p4 - p3 & p2 - p1;	//4321
	double d3 = p1 - p3 & p2 - p1;	//1321
	double d4 = p4 - p3 & p4 - p3;	//4343
	double d5 = p2 - p1 & p2 - p1;	//2121
	double ua = (d1 * d2 - d3 * d4) / (d5 * d4 - d2 * d2);
	double ub = (d1 + ua * d2) / d4;
	*/
	res.p1 = p1 + (p2 - p1) * t1;
	res.p2 = p3 + (p4 - p3) * t2;
	point3 n = p1 - p2 ^ p3 - p4;
	double tmp = (p1 - p3) & n;
	ans = fabs (tmp) / n.len();
	return res;
}

int main (int argc, char * argv[]) {
	//freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
	int cas;
	point3 a, b, c, d;
	scanf ("%d", &cas);
	for (int t = 0; t < cas; t ++) {
		a.input ();
		b.input ();
		c.input ();
		d.input ();
		double anslen = 0;
		line ans = nearLL (a, b, c, d, anslen);
		printf("%.6lf\n%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", anslen, ans.p1.x, ans.p1.y, ans.p1.z, ans.p2.x, ans.p2.y, ans.p2.z);
	}
	return 0;
}
