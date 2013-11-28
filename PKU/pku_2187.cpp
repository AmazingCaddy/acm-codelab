//#include<iostream>
//#include<cstdlib>
//#include<cmath>
////#define esp 1e-8
//#define MAXN 50005
//using namespace std;
//struct point
//{
//	int x,y;
//};
//point p[MAXN],stack[MAXN];
//int top;
//int dis( point p1, point p2 )
//{
//	int x=p1.x-p2.x;
//	int y=p1.y-p2.y;
//	return x*x+y*y;
//}
//
//int multi( point p0, point p1, point p2 )
//{
//	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
//}
//
//int convex_com( const void * a, const void *b )
//{
//	point c=*(point *)a;
//	point d=*(point *)b;
//	int k=multi( p[0], c, d );
//	return k==0?(dis( c, p[0] )-dis( d, p[0] )):-k;
//}
//int graham( int n )
//{
//	int i,k,index=0;
//	point temp;
//	for( i=1; i<n; i++ )
//		if( p[i].y<p[index].y || p[i].y==p[index].y && p[i].x<p[index].x )
//			index=i;
//	temp=p[index];
//	p[index]=p[0];
//	p[0]=temp;
//	qsort( p+1, n-1, sizeof(point), convex_com );
//	stack[0]=p[n-1];
//	stack[1]=p[0];
//	k=top=1;
//	while( k<n && top )
//	{
//		if( multi( stack[top], stack[top-1], p[k] )>0 )top--;
//		else top++,stack[top]=p[k],k++;
//	}
//	return top;
//}
//
//int main( )
//{
//	int n,i,ans,j;
//	while( scanf("%d",&n) != EOF )
//	{
//		for( i=0; i<n; i++ )
//			scanf("%d%d",&p[i].x,&p[i].y);
//		if( graham( n ) )
//		{
//			ans=0;
//			for( i=1; i<top; i++ )
//				for( j=i+1; j<=top; j++ )
//					if( dis( stack[i], stack[j] ) > ans )
//						ans=dis( stack[i], stack[j] );
//		}
//		else ans=dis( stack[1],stack[0] ); 
//		printf("%d\n",ans);
//	}
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<cmath>
#define maxn 50005
#define eps 1e-10
using namespace std;
struct Point{double x, y;};
 
double Distance ( Point a, Point b )
{
	return sqrt( (a.x -b.x)*(a.x -b.x) + (a.y -b.y)*(a.y -b.y) );
} 
 
double det(Point p0, Point p1, Point p2)
{
	return (p1.x-p0.x)* (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x); 
}
 
int dcmp( double x )
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
		while( Ns>=2 && dcmp( det( np[Ns-2], np[Ns-1], p[i] ) ) <=0 )
			Ns--;          //包括所有共线点，改为<=则只有极点
		np[Ns++]=p[i];
	}
	k=Ns;
	for( i=N-2; i>=0; i-- )
	{
		while( Ns > k && dcmp( det( np[Ns-2], np[Ns-1], p[i] ) ) <=0 )
			Ns--;
		np[Ns++]=p[i];
	}
	Ns--;
}
int main( )
{ 
	int i,j;
	double ans,t;
	while( scanf("%d",&N) != EOF )
	{
		for( i=0; i<N; i++ )
			scanf("%lf%lf",&p[i].x,&p[i].y);
		if( N==2 )printf("%.lf\n",Distance( p[0], p[1])*Distance( p[0], p[1]));
		else 
		{
			Convex_Hull( );
			ans=0;
			for( i=0; i<Ns-1; i++ )
				for( j=i+1; j<Ns; j++ )
					if( dcmp((t=Distance( np[i], np[j]))-ans)==1 )
						ans=t;
			printf("%.lf\n",ans*ans);
		}
	}
}