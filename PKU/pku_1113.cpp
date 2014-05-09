//#include<iostream>
//#include<cmath>
//#include<cstdlib>
//#define esp 1e-8
//#define MAXN 1005
//#define pi 3.1415926535897932
//using namespace std;
//
//struct point 
//{
//	double x,y;
//};
//point stack[MAXN],p[MAXN];
//int top;     //栈顶指针
//int dblcmp( double x )
//{
//	if( fabs(x)<esp )return 0;
//	return (x>0)?1:-1;
//}
//
//double Distance( const point & p1, const point & p2 )
//{
//	double x=p2.x-p1.x,y=p2.y-p1.y;
//	return sqrt(x*x+y*y);
//}
//
//double multi( const point & p0, const point & p1, const point & p2 )
//{
//	//大于0，Op1在Op2顺时针方向
//	return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
//}
//
//int convex_com( const void *a, const void *b )
//{
//	point c=*( point* )a;
//	point d=*( point* )b;
//	int k=dblcmp( multi( p[0], c, d ) );//k>0，oc在od顺时针方向，不用交换
//	return k==0?dblcmp( Distance( p[0], c )-Distance( p[0], d ) ):-k;
//}
//
//void graham( int n )//逆时针算法
//{
//	int i,k,d,index=0;
//	double miny=p[0].y;
//	point temp;
//	for( i=1; i<n; i++ )//找左下角顶点
//		if( dblcmp( miny-p[i].y ) == 1 ) miny=p[i].y,index=i;//找y坐标小的
//		else if( dblcmp( miny-p[i].y )==0 && dblcmp( p[i].x-p[index].x )==-1 )
//			index=i;
//		//y相等，找x坐标小的
//	temp=p[index];
//	p[index]=p[0];
//	p[0]=temp;
//	qsort( p+1, n-1, sizeof(point), convex_com );//p[1:n-1]按相对p[0]的极角从小到大排序
//	stack[0]=p[n-1];
//	stack[1]=p[0];
//	top=1;
//	k=1;
//	while( k<n )
//	{
//		d=dblcmp( multi( stack[top], stack[top-1], p[k] ) );
//		if( d!=1 )    //p[k]在当前边的顺时针方向压入栈中,不算共线的点
//			stack[++top]=p[k],k++;
//		else top--;   //否则弹出栈顶元素
//	}
//}
//	
//int main( )
//{
//	int n,l,i;
//	double sum;
//	while( scanf("%d%d",&n,&l) != EOF )
//	{
//		for( i=0; i<n; i++ )
//			scanf("%lf%lf",&p[i].x,&p[i].y);
//		graham( n );
//		sum=Distance( stack[top], stack[0] );
//		for( i=1; i<=top; i++ )
//			sum+=Distance( stack[i-1], stack[i] );
//		sum+=2*l*pi;
//		printf("%.lf\n",sum);
//	}
//	return 0;
//}

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
 
typedef long long int64;
typedef  long long unsigned  LLU;
const int maxint = 0x7FFFFFFF;  //2^31-1
const int64 maxint64 = 0x7FFFFFFFFFFFFFFFLL;  //2^63-1
#define pi 3.1415926535897932384626433832795
#define out(x) (cout << #x << ": " << x << endl;)
template <class T> void show(T a, int n) { for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl; }
template <class T> void show(T a, int r, int l) { for (int i = 0; i < r; ++i) show(a[i], l); cout << endl; }
 
 
 
#define maxn 10020
#define eps 1e-10
struct Point{double x, y;};
 
double Distance (Point a, Point b)
{
	return sqrt( (a.x -b.x)*(a.x -b.x) + (a.y -b.y)*(a.y -b.y) );
} 
 
double det(Point p0, Point p1, Point p2)
{
	return (p1.x-p0.x)* (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x); 
}
 
int dcmp(double x)
{
	if( x<-eps )return -1; 
	else return x>eps?1:0;
}
 
bool cmp( const Point &a, const Point &b )
{
	return dcmp(a.y-b.y)<0 || dcmp(a.y-b.y)==0 && dcmp(a.x-b.x)<0 ;
}
 
Point p[maxn], np[maxn];
int N, Ns;
 
void Convex_Hull( )   // N 要求大于2 
{ 
	int i,k;
	sort( p, p+N, cmp );
	Ns=0;
	for( i=0; i<N; ++i )
	{
		while( Ns>=2 && dcmp( det( np[Ns-2], np[Ns-1], p[i] ) ) <0 )
			Ns--;          //包括所有共线点，改为<=则只有极点
		np[Ns++]=p[i];
	}
	k=Ns;
	for( i=N-2; i>=0; i-- )
	{
		while( Ns > k && dcmp( det( np[Ns-2], np[Ns-1], p[i] ) ) <0 )
			Ns--;
		np[Ns++]=p[i];
	}
	Ns--;
}
int main( )
{ 
	int r,i;
	while( scanf("%d%d",&N,&r) != EOF )
	{
		for( i=0; i<N; i++ )
			scanf("%lf%lf",&p[i].x,&p[i].y);
		Convex_Hull( );
	    double ans=0;
		for( i=0; i<Ns; i++ )
			ans += Distance( np[i], np[(i+1)%Ns] );
		printf("%d\n" ,(int)(ans+2 * pi * r + 0.5) );
	}
}