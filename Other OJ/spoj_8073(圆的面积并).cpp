/*
	author: AmazingCaddy
	time: 2011/3/5  13:28
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps =  1e-8;
const double PI = acos( -1.0 );

int D( double x ){return x < -eps ? -1 : x > eps;}

struct point{
	double x, y;
	point(){}
	point(double x,double y):x(x),y(y){}
	double len2(){ return x*x + y*y;}

	point normal(double k)//将他视为向量，将模长变成 k 
	{
		double dist = sqrt(x*x + y*y);
		return point(x * k / dist, y * k / dist);
	}

	point turnLeft(){ return point(-y , x);}
	void in(){ scanf("%lf %lf",&x, &y); }
};

struct circle{
	point c;
	double r;	
};

point operator*(double k, const point& a){ return point(k * a.x, k * a.y); }
point operator/(const point& a, double k){ return point(a.x / k, a.y / k); }
point operator+(const point& a, const point& b){ return point(a.x+b.x, a.y+b.y); }
point operator-(const point& a, const point& b){ return point(a.x-b.x, a.y-b.y); }
double operator ^(const point& a, const point& b){ return a.x * b.y - b.x * a.y;  }
double operator&(const point& a, const point& b) { return a.x * b.x + a.y * b.y;  }

double dis(const point &a, const point &b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double dis2(const point &a, const point &b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double det( const point& a, const point& b, const point& c )
{
	return ( b.x - a.x ) * ( c.y - a.y ) - ( c.x - a.x ) * ( b.y - a.y );
}

//求直线ab和直线cd的交点
point cross(const point &a, const point &b, const point &c, const point &d)
{
	point ret = a;
	double t =  ((c.x - a.x)*(d.y - c.y) - (c.y - a.y)*(d.x - c.x))/
		((b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x));
	ret.x += (b.x - a.x) * t;
	ret.y += (b.y - a.y) * t;
	return ret;
}

//计算直线与圆的交点,保证直线与圆有交点
void cross(const circle & b,const point &l1,const point &l2,point& p1,point& p2){
	point p=b.c;
	double t;
	p.x+=l1.y-l2.y;
	p.y+=l2.x-l1.x;
	p=cross(p,b.c,l1,l2);
	t=sqrt(b.r*b.r-(p.x-b.c.x)*(p.x-b.c.x)-(p.y-b.c.y)*(p.y-b.c.y))/dis(l1,l2);
	p2.x=p.x + (l2.x - l1.x) * t;
	p2.y=p.y + (l2.y - l1.y) * t;
	p1.x=p.x - (l2.x - l1.x) * t;
	p1.y=p.y - (l2.y - l1.y) * t;
}

//计算圆与圆的交点,保证圆与圆有交点,圆心不重合
void cross(const circle & a,const circle & b, point& p1, point& p2){
	point u,v;
	double t;
	t=(1+(a.r*a.r-b.r*b.r)/dis(a.c,b.c)/dis(a.c,b.c))/2;
	u.x=a.c.x+(b.c.x-a.c.x)*t;
	u.y=a.c.y+(b.c.y-a.c.y)*t;
	v.x=u.x+a.c.y-b.c.y;
	v.y=u.y-a.c.x+b.c.x;
	cross(a,u,v,p1,p2);
}

/*==================圆的面积 交 & 并 =========================================*/
const int maxn = 1005;

struct Event{
	int in; // in  1 or out -1
	double a; point p;
	Event( ){ }
	Event( int in, double a, point p ):in(in),a(a),p(p){}
	bool operator<(const Event & e)const{
		return a < e.a;
	}
};
Event E[maxn << 1];
circle cir[maxn]; int n; 
int vis[ maxn ];

void myunique( )  // 用于去掉内含、内切、相同的圆
{
	double dd;
	memset( vis, 0, sizeof( vis ) );
	for( int i = 0; i < n; i++ )
	{
		for( int j = i + 1; j < n; j++ )
		{
			dd = dis( cir[ i ].c, cir[ j ].c );
			if( D( cir[ j ].r - cir[ i ].r - dd ) >= 0 )
			{
				vis[ i ] = 1;
				break;
			}
		}
	}
	int k = 0;
	for( int i = 0; i < n; i++ )
		if( !vis[ i ] ) cir[ k++ ] = cir[ i ];
	n = k;
}

//////面积并
double areaUnion()
{
	int i, j, k = 0, cnt; point p1, p2; double a, b, area = 0;
	myunique( );
	for(i = 0; i < n; i++)
	{
		for(cnt = 1, j = k = 0; j < n; j++)
		{
			a = dis(cir[i].c, cir[j].c);
			//外离或者外切或者自己或者圆i内含或者内切圆j
			if(i==j || D(a - cir[i].r - cir[j].r) >= 0||D(cir[i].r - cir[j].r - a) >= 0)continue;
			if(D(cir[j].r - a - cir[i].r) >= 0)goto end; //圆j内含或者内切圆i
			cross(cir[i], cir[j], p1, p2);
			if(det(cir[i].c, cir[j].c, p1) > 0)swap(p1, p2);
			a = atan2(p1.y - cir[i].c.y, p1.x - cir[i].c.x);
			b = atan2(p2.y - cir[i].c.y, p2.x - cir[i].c.x);
			E[k++] = Event(1, a, p1);
			E[k++] = Event(-1, b, p2);
			if(b < a) cnt++;
		}
		if(k == 0){
			area += 2 * PI * cir[i].r * cir[i].r;
			continue;
		}
		sort(E, E + k); E[k] = E[0];
		for(j = 0; j < k; j++)
		{
			cnt += E[j].in;
			if(cnt == 1){
				a = E[j+1].a - E[j].a; if(a < 0) a += 2*PI;
				area += cir[i].r * cir[i].r *( a - sin(a) );
				area += E[j].p.x * E[j+1].p.y - E[j].p.y * E[j+1].p.x;
			}
		}
		end:;
	}
	return area / 2;
}
/*==========================================================================*/

int main(int argc, char *argv[])
{
	while( scanf( "%d", &n ) != EOF )
	{
		for( int i = 0; i < n; i++ )
		{
			scanf( "%lf%lf%lf", &cir[ i ].c.x, &cir[ i ].c.y, &cir[ i ].r );
		}
		printf( "%.3lf\n", areaUnion( ) );
	}
	return 0;
}
