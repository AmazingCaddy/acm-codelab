//acm.sgu.ru/problem.php?contest=0&problem=435
#include<iostream>
#include<complex>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 120;
//const double pi = acos( -1.0 );
const double eps = 1e-8;
struct point
{
	double x, y;
	point( ) { }
	point( double _x, double _y ) : x( _x ), y( _y ) { } 
};

struct circle
{
	point p;
	double r;
	circle( ){ }
	circle( point _p, double _r ) : p( _p ), r( _r ) { }
};

struct node
{
	double area;
	int flag;       // 标记圆弧是朝上还是朝下
	double y, y1, y2;
};

circle c[maxn];
vector<double> vec;
double ans1, ans2;

//计算 ab 和 ac 的叉积
double det(const point& a, const point& b, const point& c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

//计算 ab 和 ac 的点积
double dot(point a,point b,point c){
	return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}

double fix(double x){return x < -1 ? -1 : ( x > 1 ? 1 : x ); }

double dis(const point &a, const point &b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double dis2(const point &a, const point &b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }

//求直线ab和直线cd的交点
point cross(const point &a, const point &b, const point &c, const point &d)
{
	point ret = a;
	double t = ( ( c.x - a.x ) * ( d.y - c.y ) - ( c.y - a.y ) * ( d.x - c.x ) ) /
			   ( ( b.x - a.x ) * ( d.y - c.y ) - ( b.y - a.y ) * ( d.x - c.x ) );
	ret.x += ( b.x - a.x ) * t;
	ret.y += ( b.y - a.y ) * t;
	return ret;
}

//计算直线与圆的交点,保证直线与圆有交点
void cross( const circle & b, const point &l1, const point &l2, point& p1, point& p2 )
{
	point p = b.p;
	double t;
	p.x += l1.y - l2.y;
	p.y += l2.x - l1.x;
	p = cross( p, b.p, l1, l2 );
	double tem = b.r * b.r - ( p.x - b.p.x ) * ( p.x - b.p.x )
						   - ( p.y - b.p.y ) * ( p.y - b.p.y );
	if( tem < 0 ) tem = 0;
	t = sqrt( tem ) / dis( l1, l2 );
	p2.x = p.x + ( l2.x - l1.x ) * t;
	p2.y = p.y + ( l2.y - l1.y ) * t;
	p1.x = p.x - ( l2.x - l1.x ) * t;
	p1.y = p.y - ( l2.y - l1.y ) * t;
}

//计算圆与圆的交点,保证圆与圆有交点,圆心不重合
void cross(const circle & a,const circle & b, point& p1, point& p2)
{
	point u, v;
	double t = ( 1 + ( a.r * a.r - b.r * b.r ) / dis2( a.p, b.p ) ) / 2;
	u.x = a.p.x + ( b.p.x - a.p.x ) * t;
	u.y = a.p.y + ( b.p.y - a.p.y ) * t;
	v.x = u.x + a.p.y - b.p.y;
	v.y = u.y - a.p.x + b.p.x;
	cross( a, u, v, p1, p2 );
}

bool cmp( const node & a, const node & b )
{
	return a.y > b.y;
}

void solve( double x1, double x2, const int & n )
{
	point p1, p2;
	double x = ( x1 + x2 ) / 2, t;
	vector<node> V;
	node up, down;  // up 上圆弧朝下， down 下圆弧朝上
	for( int i = 1; i <= n; i++ )
	{
		if( dblcmp( c[i].p.x - c[i].r - x2 ) >= 0 )continue;
		if( dblcmp( c[i].p.x + c[i].r - x1 ) <= 0 )continue;

		up.flag = 2; down.flag = 1;		// 2朝下，1朝上
		
		cross( c[i], point( x1, 0 ), point( x1, 1 ), p1, p2 );
		if( p1.y > p2.y ) swap( p1, p2 );
		up.y1 = p2.y, down.y1 = p1.y;
		
		cross( c[i], point( x2, 0 ), point( x2, 1 ), p1, p2 );
		if( p1.y > p2.y ) swap( p1, p2 );
		up.y2 = p2.y, down.y2 = p1.y;
		
		// y
		cross( c[i], point( x, 0 ), point( x, 1 ), p1, p2 );
		if( p1.y > p2.y ) swap( p1, p2 );
		up.y = p2.y, down.y = p1.y;
		
		p1 = point( x1, up.y1 ), p2 = point( x2, up.y2 );
		t = acos( fix( dot( c[i].p, p1, p2 ) / c[i].r / c[i].r ) );
		up.area = down.area = c[i].r * c[i].r * ( t - sin( t ) ) * 0.5;
		V.push_back( up );
		V.push_back( down );
	}

	sort( V.begin( ), V.end( ), cmp );
	int cnt = 0;
	for( int i = 0; i < V.size( ); i++)
	{
		double tem = 0;
		if( V[i].flag == 1 )
		{
			cnt--;
			tem -= V[i].area;
		}
		else
		{
			cnt++;
			tem += V[i].area;
		}
		if( cnt > 0 )
		{
			// 对于 下一个圆弧来说，弓形部分的取舍刚好与前面的相反
			if( V[i+1].flag == 1 ) tem += V[i+1].area;
			else tem -= V[i+1].area;
			tem += 0.5 * ( V[i].y1 - V[i+1].y1 + V[i].y2 - V[i+1].y2 ) * ( x2 - x1 );
			if( cnt % 2 ) ans1 += tem;
			else ans2 += tem;
		}
	}
}

void lisanhua( int n )
{
	point p1, p2;
	vec.clear( );
	for( int i = 1; i <= n; i++ )
	{
		vec.push_back( c[i].p.x + c[i].r );
		vec.push_back( c[i].p.x - c[i].r );
	}
	for( int i = 1; i <= n; i++ )
	{
		for( int j = i + 1; j <= n; j++ )
		{
			double d = dis( c[i].p, c[j].p );
			//if( samecircle( c[i], c[j] ) )continue;
			if( dblcmp( c[i].r + c[j].r - d ) < 0 ||
				dblcmp( fabs( c[i].r - c[j].r ) - d ) > 0 )continue;
			cross( c[i], c[j], p1, p2 );
			vec.push_back( p1.x );
			vec.push_back( p2.x );
		}
	}
	sort( vec.begin( ), vec.end( ) );
	ans1 = ans2 = 0;
	for( int i = 1; i < vec.size( ); i++ )
	{
		if( dblcmp( vec[i] - vec[i-1] ) == 0 )continue;
		solve( vec[i-1], vec[i], n );
	}
	printf("%.5lf %.5lf\n",ans1, ans2);
	//myunique( vec );
}

int main( )
{
	int n;
	//freopen("in.in","r",stdin);
	//freopen("out.txt","w",stdout);
	while( scanf("%d",&n) != EOF )
	{
		for( int i = 1; i <= n; i++ )
			scanf("%lf %lf %lf",&c[i].p.x,&c[i].p.y,&c[i].r);
		lisanhua( n );
	}
	return 0;
}
