//叉积的应用判断位置关系，使用二分
#include<iostream>
#include<cmath>
#define eps 1e-8
#define MAXN 5005
#define INF 1e100
using namespace std;
struct point
{
	double x,y;
};
struct segment
{
	point a,b;
};
point p[MAXN];
segment L[MAXN];
int n,m,num[MAXN];
int dblcmp( double x )
{
	if( fabs(x)<eps )return 0;
	else if( x>eps )return 1;
	return -1;
}
double xmulti( const point &p0, const point &p1, const point &p2 )
{
	return ( ( p1.x-p0.x )*( p2.y-p0.y )-( p1.y-p0.y )*( p2.x-p0.x ) );
}
int find( point p )
{
	int l=0,r=n,mid;
	while( l<=r )
	{
		mid=(l+r)>>1;
		if( dblcmp( xmulti( L[mid].a, L[mid].b, p ) )==1 )r=mid-1;
		else l=mid+1;
	}
	return r;
}
int main( )
{
	int i,j;
	double x1,x2,y1,y2,x3,x4;
	point p;
	while( scanf("%d",&n) && n )
	{
		scanf("%d%lf%lf%lf%lf",&m,&x1,&y1,&x2,&y2);
		L[0].a.x=L[0].b.x=x1,L[0].a.y=y2,L[0].b.y=y1;
		for( i=1; i<=n; i++ )
		{
			scanf("%lf%lf",&x3,&x4);
			L[i].a.x=x4,L[i].a.y=y2;
			L[i].b.x=x3,L[i].b.y=y1;
		}
		memset( num, 0, sizeof(num) );
		for( i=0; i<m; i++ )
		{
			scanf("%lf%lf",&p.x,&p.y);
			j=find( p );
			num[j]++;
		}
		for( i=0; i<=n; i++ )
			printf("%d: %d\n",i,num[i]);
		printf("\n");
	}
	return 0;
}