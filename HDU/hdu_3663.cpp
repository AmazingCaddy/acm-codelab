////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-09-29 21:16:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3663
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:3344KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef __int64 ll;

const int maxn = 2000;
const int maxm = 365;
const int maxt = 2000 * 365;

// int map[ 60 ][ 60 ];
int day[ 65 ][ 2 ];
int st[ maxn ][ 3 ];
int he[70];

struct node
{
	int y;
	int next;
} et[ 400 ];

int S[maxm], O[maxn]; // S[] 列链表中结点的总数  O[] 记录搜索结果
int L[maxt], R[maxt], U[maxt], D[maxt];  // 四个方向
int C[maxt], W[maxt];  // C[]列指针头  W[]行指针头
int mat[maxn][maxm];  // 稀疏矩阵
int ANS;

void build( int n, int m )  // 邻接矩阵的build函数
{
	int i, j, tot = m, first;
	R[0] = 1; L[0] = m;
	for( i = 1; i <= m; i++ )
	{
		L[i] = i - 1; R[i] = ( i + 1 ) % ( m + 1 );
		U[i] = D[i] = C[i] = i; S[i] = 0;
	}
	for( i = 1; i <= n; i++ )
	{
		first = 0;
		for( j = 1; j <= m; j++ )if( mat[i][j] )
		{
			tot++;
			U[tot] = U[j]; D[tot] = j;
			D[U[j]] = tot; U[j] = tot;
			if( first == 0 ) first = L[tot] = R[tot] = tot;
			else
			{
				L[tot] = L[first]; R[tot] = first;
				R[L[first]] = tot; L[first] = tot;
			}
			W[tot] = i; C[tot] = j; S[j]++;
		}
	}
}

void remove( int c )
{
	int i, j;
	//remove column c and all row i that A[i][c] == 1
	L[R[c]] = L[c];
	R[L[c]] = R[c];
	//remove column c;
	for( i = D[c]; i != c; i = D[i] )
	{
		//remove i that A[i][c] == 1
		for( j = R[i]; j != i; j = R[j] )
		{
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			S[C[j]]--;
			//decrease the count of column C[j];
		}
	}
}

void resume( int c )
{
	int i, j;
	for( i = U[c]; i != c; i = U[i] )
	{
		for( j = L[i]; j != i; j = L[j] )
		{
			S[C[j]]++;
			U[D[j]] = j;
			D[U[j]] = j;
		}
	}
	L[R[c]] = c;
	R[L[c]] = c;
}

int dfs( int k )
{
	int i, j, t, m = maxn, mn;
	if( R[0] == 0 )
	{
		//One of the answers has been found.
		ANS = k;
		return 1;
	}
	for( t = R[0]; t != 0; t = R[t] )
		if( S[t] < m ) { m = S[t]; mn = t; }
	remove( mn );
	for( i = D[mn]; i != mn; i = D[i] )
	{
		O[k] = i;//record the answer.
		for( j = R[i]; j != i; j = R[j] )
			remove( C[j] );
		if( dfs( k + 1 ) ) return 1;
		for( j = L[i]; j != i; j = L[j] )
			resume( C[j] );
	}
	resume( mn );
	return 0;
}

int ans[ 65 ][ 3 ];
int tot, top;
int main(int argc, char *argv[])
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i, j,n, m, d,k,x,y,u,v;
	while( scanf("%d%d%d",&n,&m,&d) != EOF )
	{
		tot=0;top=1;
		for(i=1;i<=n;i++)he[i]=-1;
		while(m--){
			scanf("%d%d",&u,&v);
			et[tot].y=v;
			et[tot].next=he[u];
			he[u]=tot++;

			et[tot].y=u;
			et[tot].next=he[v];
			he[v]=tot++;
		}
		/*for(i=1;i<=n;i++)
		{
			et[tot].y=i;
			et[tot].next=he[i];
			he[i]=tot++;
		}*/
		
		for( i = 1; i <= n; i++ )
		{
			scanf("%d%d",&day[ i ][ 0 ],&day[ i ][ 1 ]);
		}
		memset( mat, 0, sizeof( mat ) );
		for(k=1;k<=n;k++)
		{  
			mat[top][n*d+k]=1;
			st[top][0]=k;
			st[top][1]=0;
			st[top][2]=0;
			top++;
		    for(x=day[k][0];x<=day[k][1];x++)
			{
			    for(y=x;y<=day[k][1];y++)
			    {
					//mat[top][0]=0;
					st[top][0]=k;
					st[top][1]=x;
					st[top][2]=y;
					for(u=x;u<=y;u++)
					{
						for( j=he[k];j!=-1;j=et[j].next)
						{
							mat[top][(et[j].y-1)*d+u] = 1;
							//mat[top][++mat[top][0]]=(et[j].y-1)*d+u;		
						}
						mat[top][(k-1)*d+u]=1;
						//mat[top][++mat[top][0]]=(k-1)*d+u;
					}
					mat[top][n*d+k]=1;
					//mat[top][++mat[top][0]]=n*d+k;
					top++;
				}
			}
		}

		build( top - 1, n * ( d + 1 ) );
		ANS = 0;
		if( dfs( 0 ) == 0 ) { printf("No solution\n\n"); continue; }
		memset( ans, 0, sizeof( ans ) );
		int tmp;
		for( int i = 0; i < ANS; i++ )
		{
			tmp = W[ O[ i ] ];
			ans[ st[tmp][0] ][0] = 1;
			ans[ st[tmp][0] ][1] = st[tmp][1];
			ans[ st[tmp][0] ][2] = st[tmp][2];
		}
		for( int i = 1; i <= n; i++ )
		{
			if( ans[i][0] ) printf("%d %d\n",ans[i][1],ans[i][2]);
			else printf("0 0\n");
		}
		printf("\n");
	}
	return 0;
}
/*

3 3 2
1 2
2 3
3 1
1 1
2 2
1 2

*/
