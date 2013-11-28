// 返回一组解，不是最优解
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 800;
const int maxm = 10;
const int maxt = 800*4;

int S[maxn], O[maxn]; // S[] 列链表中结点的总数  O[] 记录搜索结果
int L[maxt], R[maxt], U[maxt], D[maxt];  // 四个方向
int C[maxt], W[maxt];  // C[]列指针头  W[]行指针头
int mat[maxn][maxm];  // 稀疏矩阵
int ANS;
int ret[ 1000 ];
///*
void build( int n, int m ) {  // 邻接矩阵的build函数
	int i, j, t, tot = m, first;
	R[0] = 1; L[0] = m;
	for( i = 1; i <= m; i++ ) {
		L[i] = i - 1; R[i] = ( i + 1 ) % ( m + 1 );
		U[i] = D[i] = C[i] = i; S[i] = 0;
	}
	for( i = 1; i <= n; i++ ) {
		first = 0;
		for( j = 1; j <= mat[i][0]; j++ ) {
			tot++;
			t = mat[i][j];
			U[tot] = U[t]; D[tot] = t;
			D[U[t]] = tot; U[t] = tot;
			if( first == 0 ) first = L[tot] = R[tot] = tot;
			else {
				L[tot] = L[first]; R[tot] = first;
				R[L[first]] = tot; L[first] = tot;
			}
			W[tot] = i; C[tot] = t; S[t]++;
		}
	}
}

void remove( int c ) {
	int i, j;
	//remove column c and all row i that A[i][c] == 1
	L[R[c]] = L[c];
	R[L[c]] = R[c];
	//remove column c;
	for( i = D[c]; i != c; i = D[i] ) {
		//remove i that A[i][c] == 1
		for( j = R[i]; j != i; j = R[j] ) {
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			S[C[j]]--;
			//decrease the count of column C[j];
		}
	}
}

void resume( int c ) {
	int i, j;
	for( i = U[c]; i != c; i = U[i] ) {
		for( j = L[i]; j != i; j = L[j] ) {
			S[C[j]]++;
			U[D[j]] = j;
			D[U[j]] = j;
		}
	}
	L[R[c]] = c;
	R[L[c]] = c;
}

int cnt;
int dfs( int k ) {
	int i, j, t, m = maxn, mn;
	if( R[0] == 0 ) {
		//One of the answers has been found.
		ANS = k;
		cnt++;
		if( cnt == 2 ) {
			return 2;
		}
		else {
			for( i = 0; i < ANS; i++ )
				ret[ i ] = W[ O[ i ] ];
		}
		return 1;
	}
	for( t = R[0]; t != 0; t = R[t] )
		if( S[t] < m ) { m = S[t]; mn = t; }
	remove( mn );
	for( i = D[mn]; i != mn; i = D[i] ) {
		O[k] = i;//record the answer.
		for( j = R[i]; j != i; j = R[j] )
			remove( C[j] );
		int tmp = dfs( k + 1 );
		if( tmp == 2 ) return 2;
		for( j = L[i]; j != i; j = L[j] )
			resume( C[j] );
	}
	resume( mn );
	return 0;
}

int g[ 100 ][ 100 ];
int map[11][11],cec[11][11];
typedef pair <int ,int > dd;
void predo( ){
	bool tmp[ 22 ][ 22 ];
	memset( tmp, 0, sizeof( tmp ) );
	for( int i = 1; i <= 9; i++ ) {
		for( int j = 1; j <= 9; j++ ) {
			int x;
			//scanf("%d",&x);
            scanf( "%d", &x );
			if( x & 16 ) {
				tmp[ 2 * i - 1 ][ 2 * j ] = true;//up have wall
				x -= 16;
			}
			if( x & 32 ) {
				tmp[ 2 * i ][ 2 * j + 1 ] = true;//right have wall
				x -= 32;
			}
			if( x & 64 ) {
				tmp[ 2 * i + 1 ][ 2 * j ] = true;//down
				x -= 64;
			}
			if( x & 128 ) {
				tmp[ 2 * i ][ 2 * j - 1 ] = true;//left
				x -= 128;
			}
			map[ i ][ j ] = x;
		}
	}
    memset( cec, 255, sizeof( cec ) );
	int maxcolor = -1;
	while( 1 ) {	
		int sx = -1, sy = -1;
		maxcolor++;
		for( int i = 1; i <= 9; i++ ) {
			for( int j = 1; j <= 9; j++ ) {
				if( cec[ i ][ j ] == -1 ) {
					sx = i;
					sy = j;
					break;
				}
			}
		}
		if( sx == -1 ) {
			break;
		}
		queue <dd> q;
		q.push( dd( sx, sy ) );
		while( !q.empty( ) ) {
			int i,j;
			i = q.front( ).first;
			j = q.front( ).second;
			cec[ i ][ j ] = maxcolor;
			q.pop( );
			if( !tmp[ i * 2 - 1 ][ j * 2 ] && cec[ i - 1 ][ j ] == -1 ) { //up
				q.push( dd( i - 1, j ) );
			}
			if( !tmp[ i * 2 + 1 ][ j * 2 ] && cec[ i + 1 ][ j ] == -1 ) {//down
				q.push( dd( i + 1, j ) ); 
			}
			if( !tmp[ i * 2 ][ j * 2 - 1 ] && cec[ i ][ j - 1 ] == -1 ) { //left
				q.push( dd( i, j - 1 ) );
			}
			if( !tmp[ i * 2 ][ j * 2 + 1 ] && cec[ i ][ j + 1 ] == -1 ) {//right
				q.push( dd( i, j + 1 ) );
			}
		}
	}
}

int main( ) {
//	freopen("out.txt","w",stdout);
	int n, m, i, j, c, ii, jj, k, p, q;
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		memset( mat, 0, sizeof( mat ) );
		predo( );
		for( i = 1; i <= 9; i++ ) {
			for( j = 1; j <= 9; j++ ) {
				int ii = i - 1;
				int jj = j - 1;
				k = ii* 9 + jj;
				p = k * 9;
				if( map[ i ][ j ] == 0 ) {
					for( q = 1; q <= 9; q++ ) {
						mat[p+q][0] = 4;
						mat[p+q][1] = q + ii * 9; // Row
						mat[p+q][2] = 81 + q + jj * 9; // Column
						mat[p+q][3] = 162 + q + cec[i][j] * 9; // Block
						mat[p+q][4] = 243 + 1 + k; // Grid
					}
				}
				else {
					q = map[i][j];
					mat[p+q][0] = 4;
					mat[p+q][1] = q + ii * 9; // Row
					mat[p+q][2] = 81 + q + jj * 9; // Column
					mat[p+q][3] = 162 + q + cec[i][j] * 9; // Block
					mat[p+q][4] = 243 + 1 + k; // Grid
				}
			}
		}
		
		build( 729, 324 );
		printf( "Case %d:\n", t );
		cnt = 0;
		int ans = dfs( 0 );
		if( cnt == 1 ) {
			sort( ret, ret + ANS );
			for( i = 0; i < ANS; i++ ) {
				printf( "%d", ( ret[ i ] - 1 ) % 9 + 1 );
				if( i % 9 == 8 ) {
					printf( "\n" );
				}
			}
			continue;
		}
		if( cnt == 0 ) {
			printf( "No solution\n" );
			continue;
		}
		printf( "Multiple Solutions\n" );
	}
	return 0;
}
