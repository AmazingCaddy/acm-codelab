/*
	author: AmazingCaddy
	time: 2011/4/2  1:19
	最近点对
*/ 
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
#define sqr(x) ((x)*(x))
using namespace std;

const int maxn = 100005;
struct point{ double x, y; } pt[ maxn ];
int n, o[ maxn ], on;

const double eps = 1e-9;
int D(double x){return x < -eps ? -1 : x > eps;}

bool cmp(const point& a,const point& b){ return D(a.x-b.x)<0;}

bool cmp2(const int& a,const int& b){ return D(pt[a].y-pt[b].y)<0;}

double dis(point a,point b){ return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}

double min(double a,double b){ return a<b?a:b;}

double search(int s,int t)
{
	int mid=(s+t)/2,i,j;
	double ret(1e300);
	if (s>=t) return ret;
	for (i=mid;i>=s&&!D(pt[i].x-pt[mid].x);i--); ret=search(s,i);
	for (i=mid;i<=t&&!D(pt[i].x-pt[mid].x);i++);
	ret=min(ret,search(i,t));  on=0;
	for(i=mid;i>=s&&D(pt[mid].x-pt[i].x-ret)<=0;i--) o[++on]=i;
	for(i=mid+1;i<=t&&D(pt[i].x-pt[mid].x-ret)<=0;i++) o[++on]=i;
	sort(o+1,o+on+1,cmp2);
	for(i=1;i<=on;i++)
		for(j=1;j<=10;j++)
			if(i+j<=on)
				ret=min(ret,dis(pt[o[i]],pt[o[i+j]]));
	return ret;
}

int main(int argc, char *argv[])
{
	while( scanf( "%d", &n ) && n )
	{
		for( int i = 0; i < n; i++ )
			scanf( "%lf %lf", &pt[ i ].x, &pt[ i ].y );
		sort( pt, pt + n, cmp );
		printf( "%.2lf\n", search( 0, n - 1 ) / 2 );
	}
	return 0;
}
