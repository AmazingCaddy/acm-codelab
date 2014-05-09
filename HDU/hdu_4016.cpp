// 得到最优解，但是效率较低，可以加二分优化
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxn = 50;
const int maxm = 70;
const int maxt = 50 * 70;

int S[maxm], O[maxn]; // S[] 列链表中结点的总数  O[] 记录搜索结果
int L[maxt], R[maxt], U[maxt], D[maxt];  // 四个方向
int C[maxt], W[maxt];  // C[]列指针头  W[]行指针头
int mat[maxn][maxm];  // 稀疏矩阵
int ANS;

void build( int n, int m ) {
	int i, j, tot = m, first;
	R[0] = 1; L[0] = m;
	for( i = 1; i <= m; i++ ) {
		L[i] = i - 1; R[i] = ( i + 1 ) % ( m + 1 );
		U[i] = D[i] = C[i] = i; S[i] = 0;
	}
	for( i = 1; i <= n; i++ ) {
		first = 0;
		for( j = 1; j <= m; j++ )if( mat[i][j] ) {
			tot++;
			U[tot] = U[j]; D[tot] = j;
			D[U[j]] = tot; U[j] = tot;
			if( first == 0 ) first = L[tot] = R[tot] = tot;
			else {
				L[tot] = L[first]; R[tot] = first;
				R[L[first]] = tot; L[first] = tot;
			}
			W[tot] = i; C[tot] = j; S[j]++;
		}
	}
}

void remove( int c ) {
	int i, j;
	//remove column c;
	for( i = D[c]; i != c; i = D[i] ) {
		L[R[i]] = L[i];
		R[L[i]] = R[i];
		S[C[i]]--;
	}
}

void resume( int c ) {
	int i, j;
	for( i = U[c]; i != c; i = U[i] ) {
		S[C[i]]++;
		L[R[i]] = i;
		R[L[i]] = i;
	}
}

int H( ) {
	bool hash[maxm] = { 0 };
	int i, j, c, r = 0;
	for( c = R[0]; c != 0; c = R[c] ) {
		if( !hash[c] ) {
			r++;
			hash[c] = true;
			for( i = D[c]; i != c; i = D[i] )
				for( j = R[i]; j != i; j = R[j] )
					hash[C[j]] = true;
		}
	}
	return r;
}

int dfs( int k, int lim ) {
    int i, j, t, m = maxn, mn, flag = 0;
    if( k + H( ) > lim ) return 0;
    // if( k + H( ) > ANS ) return 0;
    if( R[0] == 0 ) {
        //One of the answers has been found.
        //ANS = k;
        return 1;
    }
    for( t = R[0]; t != 0; t = R[t] )
        if( S[t] < m ) { m = S[t]; mn = t; }
    flag = 0;
    for( i = D[mn]; i != mn; i = D[i] ) {
        remove( i );
        O[k] = i; //record the answer.
        for( j = R[i]; j != i; j = R[j] )
            remove( j );
        if( dfs( k + 1, lim ) ) flag = 1;
        for( j = L[i]; j != i; j = L[j] )
            resume( j );
        resume( i );
		if( flag ) return 1;
    }
    return 0;
}

int map[ maxn ][ maxm ];
int vis[ maxm ];
ll num[ maxn ];

void get_num( int x, ll n ) {
	for( int i = 60; i >= 1; i-- ) {
		if( ( n & 1 ) == 0 ) {
			map[ x ][ i ] = 1;
		}
		n >>= 1;
	}
}

int main( ) {
//	freopen( "out", "w", stdout );
	int cas, n, k;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d%d", &n, &k );
		memset( map, 0, sizeof( map ) );
		for( int i = 1; i <= n; i++ ) {
			cin >> num[ i ];
			get_num( i, num[ i ] );
		}
		/*
		for( int i = 1; i <= n; i++ ) {
			for( int j = 1; j <= 60; j++ ) {
				printf( "%d ", map[ i ][ j ] );
			}
			printf( "\n" );
		}
		*/
		memset( vis, 0, sizeof( vis ) );
		int len = 1;
		for( int j = 1; j <= 60; j++ ) {
			int flag = 0;
			for( int i = 1; i <= n; i++ ) {
				if( !map[ i ][ j ] ) {
					flag = 1;
					break;
				}
			}
			if( !flag ) {
				continue;
			}
			for( int i = 1; i <= n; i++ ) {
				mat[ i ][ len ] = map[ i ][ j ];
			}
			build( n, len );
			if( dfs( 0, k ) ) {
				len++;
				continue;
			}
			vis[ j ] = 1;
		}
		ll ans = 0;
		for( int i = 1; i <= 60; i++ ) {
			ans = ( ans << 1 ) + vis[ i ];
		}
		printf( "Case #%d: ", t );
		cout << ans << endl;
	}
	return 0;
}