#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 250;
const int maxm = 250;
const int maxt = 250*100;

int dx[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
int dy[] = { 1, 0, 0, -1, -1, -1, 1, 1 };

int S[maxm], O[maxn]; // S[] 列链表中结点的总数  O[] 记录搜索结果
int L[maxt], R[maxt], U[maxt], D[maxt];  // 四个方向
int C[maxt], W[maxt];  // C[]列指针头  W[]行指针头
int mat[maxn][maxm];  // 稀疏矩阵
int ANS;

char map[20][20];
int num[400];

void build( int n, int m )
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
    //remove column c;
    for( i = D[c]; i != c; i = D[i] )
    {
        L[R[i]] = L[i];
        R[L[i]] = R[i];
        S[C[i]]--;
    }
}

void resume( int c )
{
    int i, j;
    for( i = U[c]; i != c; i = U[i] )
    {
        S[C[i]]++;
        L[R[i]] = i;
        R[L[i]] = i;
    }
}

int H( )
{
    bool hash[51] = { 0 };
    int i, j, c, r = 0;
    for( c = R[0]; c != 0; c = R[c] )
        if( !hash[c] )
        {
            r++;
            hash[c] = true;
            for( i = D[c]; i != c; i = D[i] )
                for( j = R[i]; j != i; j = R[j] )
                    hash[C[j]] = true;
        }
    return r;
}

int dfs( int k, int lim )
{
    int i, j, t, m = maxn, mn, flag = 0;
    if( k + H( ) > lim ) return 0;
    // if( k + H( ) > ANS ) return 0;
    if( R[0] == 0 )
    {    
        //One of the answers has been found.
        //ANS = k;
        return 1;
    }
    for( t = R[0]; t != 0; t = R[t] )
        if( S[t] < m ) { m = S[t]; mn = t; }
    flag = 0;
    for( i = D[mn]; i != mn; i = D[i] )
    {
        //if( flag ) break;
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

int main( )
{
	//freopen("in.in","r",stdin);
    int n, m, i, j, k, r, ii, jj, x, y, cnt1, cnt2;
    while( scanf("%d %d",&n,&m) == 2 )
    {
        for( i = 0; i < n; i++ )
            scanf("%s",map[i]);
        cnt1 = 0, cnt2 = 0;
        for( i = 0; i < n; i++ )
        {
            for( j = 0; j < m; j++ )
            {
                if( map[i][j] == '.' ) num[i*m+j] = ++cnt1;
                else if( map[i][j] == '#' ) num[i*m+j] = ++cnt2;
            }
        }
        memset( mat, 0, sizeof( mat ) );
        for( i = 0; i < n; i++ )
        {
            for( j = 0; j < m; j++ )
            {
                if( map[i][j] == '.' )
                {
                    r = num[i*m+j];
                    for( k = 0; k < 4; k++ )
                    {
                        ii = i, jj = j;
                        x = dx[k], y = dy[k];
                        while( 1 )
                        {
                            ii += x; jj += y;
                            if( map[ii][jj] == '#' )
                            {
                                mat[r][num[ii*m+jj]] = 1;
                                break;
                            }
                            else if( map[ii][jj] == '*' )
                                break;
                        }
                    }
                }
            }
        }
        build( cnt1, cnt2 );
        int ll = 0, rr = cnt1, mid;
        while( ll <= rr )
        {
            mid = ( ll + rr ) >> 1;
            if( dfs( 0, mid ) ) ANS = mid, rr = mid - 1;
            else ll = mid + 1;
        }
        printf("%d\n",ANS);
    }
    return 0;
}
