// poj 3020 Antenna Placement
// 对图进行重建，集合{'*'}到集合{'*'}的二分图
// ans=|{'*'}|-max/2;

#include<iostream>
#define MAXN 42 
#define MAXM 402
using namespace std;
struct node
{
	char ch;
	int num;
}M[MAXN][MAXN];
bool map[MAXM][MAXM],vis[MAXM];
int match[MAXM];
int N;

bool DFS( int from )
{
	int i;
	for( i=1; i<=N; i++ )
	{
		if( map[from][i] && !vis[i] )
		{
			vis[i]=true;
			if( match[i]==-1 || DFS( match[i] ) )
			{
				match[i]=from;
				return true;
			}
		}
	}
	return false;
}

int Hungray( )
{
	int i,sum;
	memset( match, -1, sizeof(match) );
	sum=0;
	for( i=1; i<=N; i++ )
	{
		memset( vis, false, sizeof(vis) );
		if( DFS(i) )sum++;
	}
	return sum;
}

int main( )
{
	int i,j,t,n,m;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&n,&m);
		N=0;
		for( i=1; i<=n; i++ )
		{
			for( j=1; j<=m; j++ )
			{
				cin>>M[i][j].ch;
				if( M[i][j].ch=='*' )
					M[i][j].num=++N;
			}
		}
		memset( map, false, sizeof(map) );
		for( i=1; i<=n; i++ )
		{
			for( j=1; j<=m; j++ )
				if( M[i][j].ch=='*' )
				{
					if( i-1>=1 && M[i-1][j].ch=='*' )
						map[M[i][j].num][M[i-1][j].num]=true;
					if( i+1<=n && M[i+1][j].ch=='*' )
						map[M[i][j].num][M[i+1][j].num]=true;
					if( j-1>=1 && M[i][j-1].ch=='*' )
						map[M[i][j].num][M[i][j-1].num]=true;
					if( j+1<=m && M[i][j+1].ch=='*' )
						map[M[i][j].num][M[i][j+1].num]=true;
				}
		}
		printf("%d\n",N-Hungray( )/2);
	}
	return 0;
}

////二分图最大匹配，匈牙利算法
////左边为”*“，右边为”*“
//#include <iostream>
//using namespace std;
//int n,m;
//struct Map
//{
//	char sig;
//	int count;
//} map[41][11];
//int ans[451][451];
//int check[451];
//int match[451];
//int dfs(int p) 
//{ 
//	int i,t; 
//	for(i=1;i<=m*n;i++) 
//		if(ans[i][p]&&!check[i]) 
//		{ 
//			check[i]=1; 
//			t=match[i]; 
//			match[i]=p; 
//			if(t==0||dfs(t)) return 1; 
//			match[i]=t; 
//		} 
//		return 0; 
//}
//
//int main()
//{
//	int cas;
//	int i,j;
//	scanf("%d",&cas);
//	while(scanf("%d%d",&n,&m)!=EOF)
//	{
//		memset(map,0,sizeof(map));
//		memset(match,0,sizeof(match));
//		int Count=0;
//		for(i=1;i<=n;++i)
//		{
//			for(j=1;j<=m;++j)
//			{
//				cin>>map[i][j].sig;
//				if(map[i][j].sig=='*')
//					map[i][j].count=++Count;
//			}
//		}
//		memset(ans,0,sizeof(ans));
//		for(i=1;i<=n;++i)
//		{
//			for(j=1;j<=m;++j)
//			{
//				//map[i][j]为第(9*i+j)个
//				if(map[i][j].sig=='*')
//				{
//					if(i-1>=1&&map[i-1][j].sig=='*')
//						ans[map[i][j].count][map[i-1][j].count]=1;
//					if(i+1<=n&&map[i+1][j].sig=='*')
//						ans[map[i][j].count][map[i+1][j].count]=1;
//					if(j-1>=1&&map[i][j-1].sig=='*')
//						ans[map[i][j].count][map[i][j-1].count]=1;
//					if(j+1<=m&&map[i][j+1].sig=='*')
//						ans[map[i][j].count][map[i][j+1].count]=1;
//				}
//			}
//		}
//		int max=0;
//		for(i=1;i<=Count;i++) 
//		{ 
//			memset(check,0,sizeof(check)); 
//			if(dfs(i)) max++; 
//		}
//		printf("%d\n",Count-max/2);//(Count-max)+max/2,其中(Count-max)表示有(Count-max)个点"*"没有找到“*”与其匹配，所以他们将与"O"匹配
//		cas--;
//		if(cas==0)break;
//	}
//	return 0;
//}