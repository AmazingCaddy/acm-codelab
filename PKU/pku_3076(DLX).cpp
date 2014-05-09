// 返回一组解，不是最优解
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 4100;
const int maxm = 5;
const int maxt = maxn * maxm;

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
	char ch[ 20 ][ 20 ];
	int Hang[ 20 ][ 20 ], Lie[ 20 ][ 20 ], Jiu[ 20 ][ 20 ];
	int st[ maxn ];
	while( scanf( "%s", ch[ 0 ] ) != EOF )
	{
		memset( mat, 0, sizeof( mat ) );
		memset( Hang, 0, sizeof( Hang ) );
		memset( Lie, 0, sizeof( Lie ) );
		memset( Jiu, 0, sizeof( Jiu ) );
		for( i = 1; i < 16; i++ )
			scanf( "%s", ch[ i ] );
		for( i = 0; i < 16; i++ )
		{
			for( j = 0; j < 16; j++ )
			{
				if( ch[ i ][ j ] != '-' )
				{
					int tmp = ch[ i ][ j ] - 'A';
					Hang[ i ][ tmp ] = 1;
					Lie[ tmp ][ j ] = 1;
					Jiu[ i / 4 * 4 + j / 4 ][ tmp ] = 1;
				}
			}
		}
		int top = 0;
		for( i = 0; i < 16; i++ )
		{
			for( j = 0; j < 16; j++ )
			{
				k = i * 16 + j;
				p = k * 16;
				if( ch[i][j] == '-' )
				{
					for( q = 1; q < 17; q++ )
					{
						int tmp = q - 1;
						if( Hang[ i ][ tmp ] || Lie[ tmp ][ j ] || Jiu[ i / 4 * 4 + j / 4 ][ tmp ] )
							continue;
						top++;
						mat[top][0] = 4;
						mat[top][1] = q + i * 16; // Row
						mat[top][2] = 256 + q + j * 16; // Column
						mat[top][3] = 512 + q + ( i / 4 * 4 + j / 4 ) * 16; // Block
						mat[top][4] = 768 + 1 + k; // Grid
						st[top]=p+q;
					}
				}
				else
				{
					top++;
					q = ch[i][j] - 'A' + 1;
					mat[top][0] = 4;
					mat[top][1] = q + i * 16; // Row
					mat[top][2] = 256 + q + j * 16; // Column
					mat[top][3] = 512 + q + ( i / 4 * 4 + j / 4 ) * 16; // Block
					mat[top][4] = 768 + 1 + k; // Grid
					st[top]=p+q;
				}
			}
		}
		
		build( top, 1024 );
		dfs( 0 );
		int ret[ 1000 ];
		for( int i = 0; i < ANS; i++ )
			ret[ i ] = st[ W[ O[ i ] ] ];
		sort( ret, ret + ANS );
		for( int i = 0; i < 16; i++ )
		{
			for( int j = 0; j < 16; j++ )
				printf( "%c", ( ret[ i * 16 + j ] - 1 ) % 16 + 'A' );
			printf("\n");
		}
		printf( "\n" );
		/*
		sort( O, O + ANS );
		for( i = 0; i < ANS; i++ )
			printf("%d",(W[O[i]]-1)%9+1);
		*/
		//putchar('\n');
	}
	return 0;
}
