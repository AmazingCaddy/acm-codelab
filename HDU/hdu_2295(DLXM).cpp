#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 55;
const int maxm = 55;
const int maxt = 55*55;
const double inf = 1e4;
const double eps = 1e-7;

int S[maxm], O[maxn]; // S[] 列链表中结点的总数  O[] 记录搜索结果
int L[maxt], R[maxt], U[maxt], D[maxt];  // 四个方向
int C[maxt], W[maxt];  // C[]列指针头  W[]行指针头
int mat[maxn][maxm];  // 稀疏矩阵
int ANS;

struct point
{
	double x, y;
};
point pn[maxn], pm[maxm];

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
	int i, j, t, m = maxm, mn, flag;
	if( k + H( ) > lim ) return 0;
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
		remove( i );
		O[k] = i;  //record the answer.
		for( j = R[i]; j != i; j = R[j] )
			remove( j );
		if( dfs( k + 1, lim ) ) flag = 1;
		for( j = L[i]; j != i; j = L[j] )
			resume( j );
		resume( i );
		if( flag )return 1;
	}
	return 0;
	//return 0;
}

double dis( const point &p1, const point &p2 )
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y) );
}

double d[maxn][maxm];

int main( )
{
	//freopen("in.in","r",stdin);
    int n, m, i, j, k, cas;
	scanf("%d",&cas);
    while( cas-- )
    {
		scanf("%d%d%d",&m,&n,&k);
        for( i = 1; i <= m; i++ )
			scanf("%lf%lf",&pm[i].x,&pm[i].y);
		for( i = 1; i <= n; i++ )
			scanf("%lf%lf",&pn[i].x,&pn[i].y);
		for( i = 1; i <= n; i++ )
			for( j = 1; j <= m; j++ )
				d[i][j] = dis( pn[i], pm[j] );

		double l = 0, r = 1500, mid;
		while( r - l > eps )
		{
			mid = ( l + r ) / 2;
			memset( mat, 0, sizeof( mat ) );
			for( i = 1; i <= n; i++ )
				for( j = 1; j <= m; j++ )
					if( d[i][j] <= mid )
						mat[i][j] = 1;
			build( n, m );
			if( dfs( 0, k ) ) r = mid;
			else l = mid;
		}
        printf("%.6lf\n",mid);
    }
    return 0;
}
