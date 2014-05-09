/*
    author: AmazingCaddy
    time:	2011/8/30	23:34
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
#include <deque>
using namespace std;

const double eps = 1e-8;
const double PI  = acos(-1.0);
typedef complex<double> point;

double operator ^(point p0, point p1) {return imag(conj(p0) * p1);}
double operator&(point p0, point p1) {return real(conj(p0) * p1);}
int dcmp(double x) { return x < -eps ? -1 : x > eps; }
point prev( const point &a ) { return a*point(0,1)/abs(a);}

struct line{
    point a, b;
    double angle;
    line(){}
    line(point u, point v):a(u), b(v){
        angle = arg( b - a );
    }
    bool operator<(const line & l)const{
        return dcmp( angle - l.angle) < 0 || 
            dcmp( angle - l.angle) == 0 && dcmp( b - a ^ l.b - a ) < 0; 
    }
};

deque<point> P;
deque<int> E;
vector<line> cut;
vector<point> pp;

bool onLeft(point p, line l){
    return dcmp(l.b - l.a ^ p - l.a) > 0;
}

point operator*(line l0, line l1){
    double t = l0.a - l1.a ^ l0.b - l1.a;
    double s = l0.b - l1.b ^ l0.a - l1.b;
    return l1.a + (l1.b - l1.a) * t / (t + s);
}

void MyUnique() {
    vector<line> tem;
    tem.push_back(cut[0]);
    for(int i = 1; i < cut.size(); i++) {
        if( dcmp(tem.back().angle - cut[i].angle) != 0 )
            tem.push_back(cut[i]);
    }
    cut = tem;
}

double solve(){
    sort(cut.begin(), cut.end());
    MyUnique();
    point last; bool ok = false; 
    for(int i = 0; i < cut.size(); i++) {
        int step = dcmp( cut[i].angle - cut[0].angle -  PI );
        if(ok && onLeft(last, cut[i]) )continue;
        
        while(!P.empty() && !onLeft(P.back(), cut[i]) )P.pop_back(), E.pop_back();
        
        if(step >= 0) {
            while(!P.empty() && !onLeft(P.front(), cut[i]) )P.pop_front(), E.pop_front();
            if( P.empty() )return 0;
        }
        
        if( !E.empty() )P.push_back( cut[ E.back() ] * cut[i] );
        E.push_back(i);
        
        if(step > 0)ok = true, last = cut[ E.front() ] * cut[ E.back() ];
    }
    P.push_back( last );
}

//求两条直线的交点
point intersection( const point &u1, const point &u2, const point &v1, const point &v2) {
    double t = v1 - u1 ^ v2 - u1;
    double s = v2 - u2 ^ v1 - u2;
    return u1 + (u2 - u1) * t / (t + s);
}

//求角aob
double angle( point a, point b, point o ) {
    return atan2(a - o ^ b - o, a - o & b - o);
}

//求直线和圆的交点,点存在p中
void line_circle_intersect(point &l1, point &l2, point &c, double &r, vector<point> & p) {
    point q = intersection( l1, l2, c + prev(l1 - l2), c );
//	if( !rapall( q, l1, l2 ) ) {
//		printf( "NO\n" );
//	}
    if (dcmp( r - abs(q - c) ) == 0) {
        p.push_back( q );
	}
    else {
        if( dcmp(r - abs(q - c) ) > 0) {
            double t = sqrt(r * r - norm(q - c) ) / abs(l1 - l2);
            p.push_back( q + (l2 - l1) * t );
            p.push_back( q - (l2 - l1) * t );
        }
	}
}

//判断点是否在线段上,不包括端点
bool point_on_seg(point &a, point &b, point &c) {
    return dcmp(b - a & c - a) < 0;
}

//求线段和圆的交点,点存在p中
void seg_circle_intersect(point & l1, point & l2, point & c, double &r, vector<point> & p)
{
	line_circle_intersect(l1, l2, c, r, p);

	for(int i = 0; i < p.size(); i++) {
	//	if( fabs( l1 - p[ i ] ^ l2 - p[ i ] ) > 1e-7 ) {
//			printf( "NO\n" );
	//	}
		if(!point_on_seg( p[i], l1, l2) )
		{
			for(int j = i; j < p.size()-1; j++)
				p[j] = p[j+1];
			p.pop_back();
			i = -1;
		}
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
        //printf( "%.4lf\n", pos );
        if( ( poly[(i+1) % sz] - c ^ poly[i] - c) > 0)
            area += pos;
        else
            area -= pos;
    }
    return fabs(area);
}

int main(int argc, char *argv[]) {
	freopen( "rowling.in", "r", stdin );
//	freopen( "in.txt", "r", stdin );
	freopen( "out", "w", stdout );
    int cas, n;
    double r, rr;
    double x1, y1, x2, y2;
    scanf( "%d", &cas );
    for( int t = 1; t <= cas; t++ ) {
        scanf( "%lf %d", &r, &n );
        cut.clear( );
        P.clear( );
        E.clear( );
        for( int i = 0; i < n; i++ ) {
            scanf( "%lf%lf%lf%lf", &x1, &y1, &x2, &y2 );
            cut.push_back( line( point( x1, y1 ), point( x2, y2 ) ) );
        }
        scanf( "%lf%lf", &x1, &y1 );
        point cherry = point( x1, y1 );
        for( int i = 0; i < cut.size( ); i++ ) {
            if( dcmp( cut[ i ].b - cut[ i ].a ^ cherry - cut[ i ].a ) < 0 ) {
                swap( cut[ i ].a, cut[ i ].b );
                cut[ i ].angle = arg( cut[ i ].b - cut[ i ].a );
            }
        }
        rr = r + 2;
        cut.push_back( line( point( -rr, -rr ), point( rr, -rr ) ) );
        cut.push_back( line( point( rr, -rr ), point( rr, rr ) ) );
        cut.push_back( line( point( rr, rr ), point( -rr, rr ) ) );
        cut.push_back( line( point( -rr, rr ), point( -rr, -rr ) ) );
        solve( );
        pp.clear( );
        for( int i = 0; i < P.size( ); i++ ) {
            pp.push_back( P[ i ] );
        }
        double area = poly_circle_area( pp, point( 0, 0 ), r );
        double ans =  area * 100 / ( r * r * PI ) ;
        if( ans < 0 ) ans = -ans;
        printf( "Case %d: %.5lf%%\n", t, ans );
    }
    return 0;
}
