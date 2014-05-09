#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const double eps=1e-10,big=10000.0;
const int mn=20010;
struct point{ double x,y; };
struct line{ point a,b; };
struct polygon{ int n; point p[mn]; };
double at2[mn];
int ord[mn],dq[mn+1];
vector< line > ls;

inline int dblcmp( double x ){ return ( ( x < -eps ) ? -1 : x > eps ); }
inline double xmulit( point p0, point p1, point p2 )
{  
	return ( p1.x-p0.x )*( p2.y-p0.y )-( p1.y-p0.y )*( p2.x-p0.x );
}
//直线交点
point Intersection( point u1, point u2, point v1, point v2 )
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
		/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
// 按照象限排序
bool com( int x, int y )
{
	if( dblcmp( at2[x]-at2[y] ) == 0 )
		return dblcmp( xmulit( ls[y].a, ls[y].b, ls[x].b ) )>0;
	return at2[x]<at2[y];
}
// 判断半平面的交点是否在当前半平面的里面( 半平面左边 )
bool In_half_plane( int x, int y, int z )
{
	point pnt=Intersection( ls[x].a, ls[x].b, ls[y].a, ls[y].b );
	return dblcmp( xmulit( ls[z].a, ls[z].b, pnt ) )<0;
}
// 半平面交
polygon HalfPlaneIntersection( )
{
	//预处理
	int n=ls.size( ),tmpn,i;
	int top,bot;
	for( i=0; i<n; i++ )
	{
		at2[i]=atan2( ls[i].b.y-ls[i].a.y, ls[i].b.x-ls[i].a.x );
		ord[i]=i;
	}
	sort( ord, ord+n, com ); 
	for( tmpn=1, i=1; i<n; i++ )
		if( dblcmp( at2[ ord[i-1] ] - at2[ ord[i] ] )!=0 )
			ord[tmpn++] = ord[i];
	n=tmpn;
	bot=1, top=bot+1;
	dq[bot]=ord[0], dq[top]=ord[1];
	for( i=2; i<n; i++ )
	{
		while( bot<top && In_half_plane( dq[top-1], dq[top], ord[i] ) )top--;
		while( bot<top && In_half_plane( dq[bot+1], dq[bot], ord[i] ) )bot++;
		dq[++top]=ord[i];
	}
	while( bot<top && In_half_plane( dq[top-1], dq[top], dq[bot] ) )top--;
	while( bot<top && In_half_plane( dq[bot+1], dq[bot], dq[top] ) )bot++;
	dq[--bot]=dq[top];
	//求多边形
	polygon pg;
	pg.n=0;
	for( i=bot+1; i<=top; i++ )
		pg.p[pg.n++]=Intersection( ls[dq[i-1]].a, ls[dq[i-1]].b, ls[dq[i]].a, ls[dq[i]].b );
	return pg;
}
line tl;
polygon pg;
int main( ) 
{  
    int n,i; 
    scanf("%d",&n);ls.clear( ); 
    for( i=0; i<n; i++ ) 
	{  
        scanf("%lf%lf%lf%lf",&tl.a.x,&tl.a.y,&tl.b.x,&tl.b.y); 
		ls.push_back( tl ); 
    }  
	tl.a.x=0; tl.a.y=0; tl.b.x=big; tl.b.y=0; ls.push_back(tl); 
	tl.a.x=big; tl.a.y=0; tl.b.x=big; tl.b.y=big; ls.push_back(tl); 
	tl.a.x=big; tl.a.y=big; tl.b.x=0; tl.b.y=big; ls.push_back(tl); 
	tl.a.x=0; tl.a.y=big; tl.b.x=0; tl.b.y=0; ls.push_back(tl); 
    pg=HalfPlaneIntersection( ); 
    double area=0; 
    n=pg.n; 
    for( i=0; i<n; i++ )  
        area += pg.p[i].x * pg.p[(i+1)%n].y - pg.p[i].y * pg.p[(i+1)%n].x ; 
    area=fabs(area)/2.0; 
    printf("%.1lf\n",area); 
    return 0; 
}