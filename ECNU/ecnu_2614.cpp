// 求给定图的次小生成树。
// 次小生成树可以由最小生成树变换一边得到。
// 首先，我们用prim算法求出图的最小生成树，在这个过程中记录每条边是否用过，
// 以及两个点之间最短路径上的最大权值F[i,j]。F[i,j]可以如此求得，当加入点u的时候，
// 并且u的父结点是v,那么对于已经在生成树中的节点x，F[x,u]=max( F[x,v], weight[u][v] )
// 枚举添加每条不在MST上的边(u,v)，加上以后一定会形成一个环, 找到环上权值第二大的边
// (即除了(u,v)以外的权值最大的边), 把它删掉, 计算当前生成树的权值之和。取所有枚举
// 修改的生成树权值之和的最小值, 就是次小生成树。枚举的复杂度是O(m), 总复杂度O(n^2) 
// 用use[i][j]表示边i,j是否用过，1：存在，但没用过，0：不存在，2：存在，且在MST中

#include<iostream>
#include<cstring>
#include<cmath>
#define EXIST 1
#define NOT_EXIST 0
#define USE 2
using namespace std;
const int MAXN=110;
const int INF=1000000000;
struct node
{
	int x,y;
};
int g[MAXN][MAXN];
int n,m;
int use[MAXN][MAXN];
int ans1,ans2,F[MAXN][MAXN];
int max( int a, int b )
{
	return ( a > b ? a : b );
}
void prim( int u )
{
	int dis[MAXN],pre[MAXN];
	int i,j,pos,tmp;
	for( i=1 ;i<=n; ++i )
	{
		dis[i]=g[u][i];
		pre[i]=u;
	}
	for( i=1; i<n; ++i )
	{
		tmp=INF;
		for( j=1; j<=n; ++j )
		{
			if( dis[j]!=0 && dis[j]<tmp )
			{
				tmp=dis[j];
				pos=j;
			}
		}
		use[pre[pos]][pos]=use[pos][pre[pos]]=USE;
		for( j=1; j<=n; ++j )
			if( dis[j]==0 )   //已经加入到生成树中
				F[j][pos]=max( F[j][pre[pos]], g[pre[pos]][pos] );
		ans1+=tmp;
		dis[pos]=0;
		for( j=1; j<=n; ++j )
		{
			if( g[pos][j] != 0 && g[pos][j]<dis[j] )
			{
				dis[j]=g[pos][j];
				pre[j]=pos;
			}
		}
	}
}
void Second_MST( )
{
	int i,j;
	ans2=INF;
	for( i=1; i<=n; ++i )
		for( j=1; j<=n; ++j )
			if( use[i][j] == EXIST )
				if( ans1+g[i][j]-F[i][j] < ans2 )
					ans2=ans1+g[i][j]-F[i][j];
}

int main( )
{
	int i,j;
	node v[MAXN];
	while( scanf("%d",&n)!=EOF )
	{
		for( i=1; i<=n; i++ )
			scanf("%d%d",&v[i].x,&v[i].y);
		memset( use, 0, sizeof( use ) );
		memset( F, 0, sizeof( F ) );
		for( i=1; i<=n; i++ )
		{
			for( j=i; j<=n; j++ )
			{
				use[i][j]=use[j][i]=EXIST;
				if( i==j )
				{
					g[j][i]=0;
					use[i][j]=NOT_EXIST;
				}
				else g[j][i]=g[i][j]=abs(v[i].x-v[j].x)+abs(v[i].y-v[j].y);
			}
		}
		ans1=ans2=0;
		prim( 1 );
		Second_MST( );
		printf("%d\n",ans1);
		if( ans1==ans2 )printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}





















//#include<iostream>
//#include<cstring>
//#include<cmath>
//#define EXIST 1
//#define NOT_EXIST 0
//#define USE 2
//using namespace std;
//const int MaxN = 110;
//const int Inf = 0x7fffffff;
//struct node
//{
//	int x,y;
//};
//int g[MaxN][MaxN];
//int N,M;
//char use[MaxN][MaxN];
//int ans1,ans2,F[MaxN][MaxN];
//int max( int a, int b )
//{
//	return (a>b?a:b);
//}
//int prim(){
//	int i,j;
//	int dis[MaxN];
//	bool vis[MaxN];
//	int pre[MaxN];
//	memset(pre,0xff,sizeof(pre));
//	memset(vis,false,sizeof(vis));
//	for( i = 0 ;i < MaxN; ++i)
//		dis[i] = Inf;
//	dis[1] = 0;
//	for( i = 1; i <= N; ++i){
//		int pos;
//		int tmp = Inf;
//		for( j = 1;j <= N; ++j){
//			if(!vis[j] && dis[j] < tmp){
//				tmp = dis[j];
//				pos = j;
//			}
//		}
//		if(pre[pos] != -1){	
//			use[pre[pos]][pos] = use[pos][pre[pos]] = USE;
//			for( j = 1;j <= N; ++j){
//				if(vis[j])
//					F[j][pos] = max(F[j][pre[pos]],g[pre[pos]][pos]);
//			}
//		}
//		vis[pos] = true;
//		ans1 += dis[pos];
//		for( j = 1;j <= N; ++j){
//			if(!vis[j] && g[pos][j]!= 0 && g[pos][j] < dis[j]){
//				dis[j] = g[pos][j];
//				pre[j] = pos;
//			}
//		}
//	}
//	return ans1;
//}
//int Second_MST(){
//	int i,j;
//	ans2 = Inf;
//	for( i = 1;i <= N; ++i){
//		for( j = 1;j <= N; ++j){
//			if(use[i][j] == EXIST){
//				if(ans1 + g[i][j] - F[i][j] < ans2)
//					ans2 = ans1 + g[i][j] - F[i][j];
//			}
//		}
//	}
//	return ans2;
//}
//
//int main( )
//{
//	int i,j;
//	node v[MaxN];
//	while( scanf("%d",&N)!=EOF )
//	{
//		for( i=1; i<=N; i++ )
//			scanf("%d%d",&v[i].x,&v[i].y);
//		memset( use, 0, sizeof( use ) );
//		memset( F, 0, sizeof( F ) );
//		for( i=1; i<=N; i++ )
//		{
//			for( j=i; j<=N; j++ )
//			{
//				use[i][j]=use[j][i]=EXIST;
//				if( i==j )
//				{
//					g[j][i]=0;
//					use[i][j]=NOT_EXIST;
//				}
//				else g[j][i]=g[i][j]=abs(v[i].x-v[j].x)+abs(v[i].y-v[j].y);
//			}
//		}
//		ans1=ans2=0;
//		prim( );
//		Second_MST( );
//		printf("%d\n",ans1);
//		if( ans1==ans2 )printf("Yes\n");
//		else printf("No\n");
//	}
//	return 0;
//}