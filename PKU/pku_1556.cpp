#include<iostream>
#include<cmath>
#define eps 1e-8
#define MAXN 100
using namespace std;
const double INF=1e10;
struct point
{
	double x,y;
};
struct segment
{
	point up,down;
};
segment seg[MAXN];
double map[MAXN][MAXN];
point P[MAXN];
int n;
int dblcmp( double x )
{
	if( fabs(x)<eps )return 0;
	return ( x > eps ? 1 : -1 );
}
double xmulti( point p0, point p1, point p2 )
{
	return ( p1.x-p0.x )*( p2.y-p0.y )-( p2.x-p0.x )*( p1.y-p0.y );
}
double dmulti( point p0, point p1, point p2 )
{
	return ( p1.x-p0.x )*( p2.x-p0.x )+( p2.y-p0.y )*( p1.y-p0.y );
}
double Distance( point p1, point p2 )
{
	return sqrt( ( p1.x-p2.x )*( p1.x-p2.x )+( p1.y-p2.y )*( p1.y-p2.y ) );
}
bool seg_cross( point p1, point p2, point p3, point p4 )
{
	if( ( dblcmp( xmulti( p1, p2, p3 ) )^dblcmp( xmulti( p1, p2, p4 ) ) )==-2 &&
		( dblcmp( xmulti( p3, p4, p1 ) )^dblcmp( xmulti( p3, p4, p2 ) ) )==-2 )
		return true;
	return false;
}
bool check( point p1, point p2, int m )
{
	int i;
	for( i=0; i<m; i++ )
		if( seg_cross( p1, p2, seg[i].down, seg[i].up ) )
			return false;
	return true;
}
double dijkstra( int pn )
{
	int i,k,j;
	double dis[MAXN],min;
	bool vis[MAXN];
	for( i=0; i<=pn; i++ )
	{
		dis[i]=map[0][i];
		vis[i]=false;
	}
	vis[0]=true;
	for( i=1; i<=pn; i++ )
	{
		min=INF;
		k=0;
		for( j=0; j<=pn; j++ )
		{
			if( !vis[j] && dis[j]<min )
			{
				min=dis[j];
				k=j;
			}
		}
		if( k==0 )continue;
		vis[k]=true;
		for( j=0; j<=pn; j++ )
		{
			if( !vis[j] && dis[k]+map[k][j]<dis[j] )
				dis[j]=dis[k]+map[k][j];
		}
	}
	return dis[pn];
}
int main( )
{
	int i,j,k,pn,sn,tpn,tsn;
	double x,y1,y2,y3,y4;
	while( scanf("%d",&n) && n!=-1 )
	{
		for( i=0; i<4*n+2; i++ )
		{
			map[i][i]=0.0;
			for( j=i+1; j<4*n+2; j++ )
			{
				map[i][j]=INF;
				map[j][i]=INF;
			}
		}
		P[0].x=0,P[0].y=5;
		for( i=1,pn=1,sn=0; i<=n; i++ )
		{
			scanf("%lf%lf%lf%lf%lf",&x,&y1,&y2,&y3,&y4);
			tpn=pn;
			tsn=sn;
			P[pn].x=x,P[pn++].y=y1;
			P[pn].x=x,P[pn++].y=y2;
			P[pn].x=x,P[pn++].y=y3;
			P[pn].x=x,P[pn++].y=y4;
			seg[sn].down.x=x,seg[sn].down.y=0,seg[sn].up.x=x,seg[sn++].up.y=y1;
			seg[sn].down.x=x,seg[sn].down.y=y2,seg[sn].up.x=x,seg[sn++].up.y=y3;
			seg[sn].down.x=x,seg[sn].down.y=y4,seg[sn].up.x=x,seg[sn++].up.y=10;
			for( k=pn-1; k>=pn-4; k-- )
				for( j=0; j<tpn; j++ )
					if( check( P[k], P[j], tsn ) )
						map[k][j]=map[j][k]=Distance( P[k], P[j] );
		}
		tpn=pn;
		P[pn].x=10,P[pn].y=5;
		for( i=0; i<tpn; i++ )
			if( check( P[pn], P[i], sn ) )
				map[pn][i]=map[i][pn]=Distance( P[pn], P[i] );
		printf("%.2lf\n",dijkstra( pn ));
	}
	return 0;
}