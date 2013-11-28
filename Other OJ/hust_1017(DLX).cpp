#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1010;
const int maxm = 1010;
const int maxt = 1010*110;

int S[maxm], O[maxn]; // S[] 列链表中结点的总数  O[] 记录搜索结果
int L[maxt], R[maxt], U[maxt], D[maxt];  // 四个方向
int C[maxt], W[maxt];  // C[]列指针头  W[]行指针头
int mat[maxn][110];  // 稀疏矩阵 邻接表的形式
int ANS;

void build( int n, int m )
{
	int i, j, t, tot = m, first;
	R[0] = 1; L[0] = m;
	for( i = 1; i <= m; i++ )
	{
		L[i] = i - 1; R[i] = ( i + 1 ) % ( m + 1 );
		U[i] = D[i] = C[i] = i; S[i] = 0;
	}
	for( i = 1; i <= n; i++ )
	{
		first = 0;
		for( j = 1; j <= mat[i][0]; j++ )
		{
			tot++;
			t = mat[i][j];
			U[tot] = U[t]; D[tot] = t;
			D[U[t]] = tot; U[t] = tot;
			if( first == 0 ) first = L[tot] = R[tot] = tot;
			else
			{
				L[tot] = L[first]; R[tot] = first;
				R[L[first]] = tot; L[first] = tot;
			}
			W[tot] = i; C[tot] = t; S[t]++;
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
		if( dfs( k + 1 ) )return 1;
		for( j = L[i]; j != i; j = L[j] )
			resume( C[j] );
	}
	resume( mn );
	return 0;
}

int main( )
{
	int n, m, i, j, c, t, k;
	while( scanf("%d %d",&n,&m) == 2 )
	{
		memset( mat, 0, sizeof( mat ) );
		for( i = 1; i <= n; i++ )
		{
			scanf("%d",&mat[i][0]);
			k = mat[i][0];
			for( j = 1; j <= k; j++ )
			{
				scanf("%d",&t);
				mat[i][j] = t;
			}
		}
		build( n, m );
		if( dfs( 0 ) == 0 ) puts("NO");
		else
		{
			printf("%d",ANS);
			for( i = 0; i < ANS; i++ )
				printf(" %d",W[O[i]]);
			putchar('\n');
		}
	}
	return 0;
}
