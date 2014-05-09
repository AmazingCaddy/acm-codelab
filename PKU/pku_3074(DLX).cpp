// 返回一组解，不是最优解
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 800;
const int maxm = 10;
const int maxt = 800*4;

int S[maxn], O[maxn]; // S[] 列链表中结点的总数  O[] 记录搜索结果
int L[maxt], R[maxt], U[maxt], D[maxt];  // 四个方向
int C[maxt], W[maxt];  // C[]列指针头  W[]行指针头
int mat[maxn][maxm];  // 稀疏矩阵
int ANS;

///*
void build( int n, int m )  // 邻接矩阵的build函数
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
//*/

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

int main( )
{
	//freopen("out.txt","w",stdout);
	int n, m, i, j, c, ii, jj, k, p, q;
	char ch[100];
	while( 1 )
	{
		memset( mat, 0, sizeof( mat ) );
		scanf("%s",ch);
		if( ch[0] == 'e' )break;
		for( i = 0; i < 9; i++ )
		{
			for( j = 0; j < 9; j++ )
			{
				k = i * 9 + j;
				p = k * 9;
				if( ch[k] == '.' )
				{
					for( q = 1; q < 10; q++ )
					{
						mat[p+q][0] = 4;
						mat[p+q][1] = q + i * 9; // Row
						mat[p+q][2] = 81 + q + j * 9; // Column
						mat[p+q][3] = 162 + q + ( i / 3 * 3 + j / 3 ) * 9; // Block
						mat[p+q][4] = 243 + 1 + k; // Grid
					}
				}
				else
				{
					q = ch[k] - '0';
					mat[p+q][0] = 4;
					mat[p+q][1] = q + i * 9; // Row
					mat[p+q][2] = 81 + q + j * 9; // Column
					mat[p+q][3] = 162 + q + ( i / 3 * 3 + j / 3 ) * 9; // Block
					mat[p+q][4] = 243 + 1 + k; // Grid
				}
			}
		}
		
		build( 729, 324 );
		dfs( 0 );
		int ret[ 1000 ];
		for( int i = 0; i < ANS; i++ )
			ret[ i ] = W[ O[ i ] ];
		sort( ret, ret + ANS );
		for( int i = 0; i < ANS; i++ )
			printf( "%d", ( ret[ i ] - 1 ) % 9 + 1 );
		putchar('\n');
		/*
		sort( O, O + ANS );
		for( i = 0; i < ANS; i++ )
			printf("%d",(W[O[i]]-1)%9+1);
		*/
		//putchar('\n');
	}
	return 0;a
}
