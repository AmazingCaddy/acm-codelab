#include<iostream>
#include<cmath>
#define MAXN 201
#define INF 1e20
#define EPS 1e-6
#define S 0
#define T 1
typedef double elem_t; 
using namespace std;
struct node
{
	int x,y;
};
node stone[MAXN];
elem_t cost[MAXN][MAXN];
int n;

bool Dijkstra ( double mid )
{
	bool vis[MAXN];
	elem_t min,dist[MAXN];
	int i,j,k;
	for( i=0; i<n; i++ )
	{
		dist[i]=INF;
		vis[i]=false;
	}
	dist[S]=0;
	for( i=0; i<n; i++ )
	{
		for( min=INF,k=j=0; j<n; j++ )
		{
			if( !vis[j] && dist[j]<min )
			{
				min=dist[j];
				k=j;
			}
		}
		vis[k]=true;
		for( j=0; j<n; j++ )
			if( !vis[j] && cost[k][j]<=mid && dist[k]+cost[k][j]<dist[j] )
				dist[j]=dist[k]+cost[k][j];
	}
	return vis[T];
}

int main( )
{
	int i,j,k;
	elem_t res,mid,low,up;
	k=1;
	while( scanf("%d",&n) && n )
	{
		for( i=0; i<n; i++ )
		{
			scanf("%d%d",&stone[i].x,&stone[i].y);
			cost[i][i]=0;
		}
		for( i=0; i<n; i++ )
			for( j=i+1; j<n; j++ )
				cost[j][i]=cost[i][j]=sqrt(1.0*(stone[i].x-stone[j].x)*(stone[i].x-stone[j].x)+1.0*(stone[i].y-stone[j].y)*(stone[i].y-stone[j].y));
		res=INF;low=0;up=1000*sqrt(2.0);
		while ( fabs(up-low)>=EPS )
		{
			mid=( low+up )/2;
			if ( Dijkstra( mid ) )
				res=up=mid;
			else low=mid;
		}
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",k++,res);
	}
	return 0;
}


//#include<iostream>
//#include<cmath>
//using namespace std;
//
//#define MAXN 256
//#define EPS 1e-6
//#define INF 1e20
//#define S 0
//#define T 1
//
//double mat[MAXN][MAXN];
//int px[MAXN],py[MAXN],N;
//
//bool dijkstra ( double lim )
//{
//	double dist[MAXN];
//	bool vis[MAXN];
//	int i,j,k;
//	double Min;
//	for ( i=0 ; i<N ; i++ )
//		vis[i]=false,dist[i]=INF;
//	dist[S]=0;
//	for ( i=0 ; i<N ; i++ )
//	{
//		for ( Min=INF,k=j=0 ; j<N ; j++ )
//			if ( Min>dist[j] && !vis[j] )
//			{
//				Min=dist[j];
//				k=j;
//			}
//		vis[k]=true;
//		for ( j=0 ; j<N ; j++ )
//			if ( !vis[j] && mat[k][j]<=lim && dist[k]+mat[k][j]<dist[j] )
//				dist[j]=dist[k]+mat[k][j];
//	}
//	return vis[T];
//}
//
//void build ( )
//{
//	int i,j;
//	for ( i=0 ; i<N ; i++ )
//	{
//		scanf("%d%d",&px[i],&py[i]);
//		mat[i][i]=0;
//	}
//	for ( i=0 ; i<N ; i++ )
//		for ( j=i+1 ; j<N ; j++ )
//			mat[i][j]=mat[j][i]=sqrt(1.0*(px[i]-px[j])*(px[i]-px[j])+1.0*(py[i]-py[j])*(py[i]-py[j]));
//}
//
//double solve ( )
//{
//	double res=INF,mid,low=0,up=1000*sqrt(2.0);
//	while ( fabs(up-low)>=EPS )
//	{
//		mid=(low+up)/2;
//		if ( dijkstra(mid) )
//		{
//			res=mid;
//			up=mid;
//		}
//		else
//			low=mid;
//	}
//	return res;
//}
//
//int main ( )
//{
//	int cnt=1;
//	while ( scanf("%d",&N)!=EOF && N )
//	{
//		build();
//		double res=solve();
//		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cnt++,res);
//	}
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//
//#define MAXN 256
//#define EPS 1e-6
//#define INF 1e20
//#define S 0
//#define T 1
//
//double mat[MAXN][MAXN];
//int px[MAXN],py[MAXN],N;
//double dijkstra ( )
//{
//	double dist[MAXN];
//	bool vis[MAXN];
//	int i,j,k;
//	double Min;
//	for ( i=0 ; i<N ; i++ )
//		vis[i]=false,dist[i]=INF;
//	dist[S]=0;
//	for ( i=0 ; i<N ; i++ )
//	{
//		for ( Min=INF,k=j=0 ; j<N ; j++ )
//			if ( Min>dist[j] && !vis[j] )
//			{
//				Min=dist[j];
//				k=j;
//			}
//		vis[k]=true;
//		for ( j=0 ; j<N ; j++ )
//			if ( !vis[j] && ( dist[j]>max(dist[k],mat[k][j]) ) )
//				dist[j]=max(dist[k],mat[k][j]);
//	}
//	return dist[T];
//}
//
//void build ( )
//{
//	int i,j;
//	for ( i=0 ; i<N ; i++ )
//	{
//		scanf("%d%d",&px[i],&py[i]);
//		mat[i][i]=0;
//	}
//	for ( i=0 ; i<N ; i++ )
//		for ( j=i+1 ; j<N ; j++ )
//			mat[i][j]=mat[j][i]=sqrt(1.0*(px[i]-px[j])*(px[i]-px[j])+1.0*(py[i]-py[j])*(py[i]-py[j]));
//}
//
//int main ( )
//{
//	int i,j,k,cnt=1;
//	while ( scanf("%d",&N)!=EOF && N )
//	{
//		build();
//		double res=dijkstra();
//		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cnt++,res);
//
//	}
//
//}
