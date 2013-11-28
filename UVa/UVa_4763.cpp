// 返回一组解，不是最优解
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 800;
const int maxm = 350;
const int maxt = 800*5;

int S[maxn], O[maxn]; // S[] 列链表中结点的总数  O[] 记录搜索结果
int L[maxt], R[maxt], U[maxt], D[maxt];  // 四个方向
int C[maxt], W[maxt];  // C[]列指针头  W[]行指针头
int mat[maxn][maxm];  // 稀疏矩阵
int ANS, ans;

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

void dfs( int k )
{
	int i, j, t, m = maxn, mn;
	if( R[0] == 0 )
	{
		//One of the answers has been found.
		ans++;
		return ;
	}
	for( t = R[0]; t != 0; t = R[t] )
		if( S[t] < m ) { m = S[t]; mn = t; }
	remove( mn );
	for( i = D[mn]; i != mn; i = D[i] )
	{
		O[k] = i;//record the answer.
		for( j = R[i]; j != i; j = R[j] )
			remove( C[j] );
		dfs( k + 1 );
		for( j = L[i]; j != i; j = L[j] )
			resume( C[j] );
	}
	resume( mn );
	//return 0;
}

int azmap[ 30 ];

int main( )
{
	//freopen("out.txt","w",stdout);
	int cas;
	int n, m, i, j, c, ii, jj, k, p, q;
	char ch[10][10];
	scanf( "%d", &cas );
	while( cas-- )
	{
		memset( mat, 0, sizeof( mat ) );
		for( i = 0; i < 9; i++ )
			scanf( "%s", ch[ i ] );
		memset( azmap, -1, sizeof( azmap ) );
		//top = 0;
		for( i = 0; i < 9; i++ )
		{
			for( j = 0; j < 9; j++ )
			{
				k = i * 9 + j;
				p = k * 9;
				if( ch[ i ][ j ] == '0' )
				{
					for( q = 1; q < 10; q++ )
					{
						//mat[p+q][] = 4;
						mat[p+q][q + i * 9] = 1; // Row
						mat[p+q][81 + q + j * 9] = 1; // Column
						mat[p+q][162 + q + ( i / 3 * 3 + j / 3 ) * 9] = 1; // Block
						mat[p+q][243 + 1 + k] = 1; // Grid
					}
				}
				else if( ch[ i ][ j ] == 'e' )
				{
					for( q = 2; q < 10; q += 2 )
					{
						//mat[p+q][0] = 4;
						mat[p+q][q + i * 9] = 1; // Row
						mat[p+q][81 + q + j * 9] = 1; // Column
						mat[p+q][162 + q + ( i / 3 * 3 + j / 3 ) * 9] = 1; // Block
						mat[p+q][243 + 1 + k] = 1; // Grid
					}
				}
				else if ( ch[ i ][ j ] == 'o' )
				{
					for( q = 1; q < 10; q += 2 )
					{
						//mat[p+q][0] = 4;
						mat[p+q][q + i * 9] = 1; // Row
						mat[p+q][81 + q + j * 9] = 1; // Column
						mat[p+q][162 + q + ( i / 3 * 3 + j / 3 ) * 9] = 1; // Block
						mat[p+q][243 + 1 + k] = 1; // Grid
					}
				}
				else if( ch[ i ][ j ] <= '9' && ch[ i ][ j ] >= '1' )
				{
					q = ch[i][j] - '0';
					mat[p+q][q + i * 9] = 1; // Row
					mat[p+q][81 + q + j * 9] = 1; // Column
					mat[p+q][162 + q + ( i / 3 * 3 + j / 3 ) * 9] = 1; // Block
					mat[p+q][243 + 1 + k] = 1; // Grid
				}
				else
				{
					int c = ch[ i ][ j ] - 'a';
					if( azmap[ c ] == -1 )
					{
						azmap[ c ] = p;
					}
					for( q = 1; q < 10; q++ )
					{
						p = azmap[ c ];
						mat[p+q][q + i * 9] = 1; // Row
						mat[p+q][81 + q + j * 9] = 1; // Column
						mat[p+q][162 + q + ( i / 3 * 3 + j / 3 ) * 9] = 1; // Block
						mat[p+q][243 + 1 + k] = 1; // Grid
					}
				}
			}
		}
		
		build( 729, 324 );
		ans = 0;
		dfs( 0 );
		printf( "%d\n", ans );
	}
	return 0;
}


/*
1 
040008007
000030408
006000200
301004000
008000002
000003000
200401005
600070000
800006003
*/