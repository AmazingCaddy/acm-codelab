#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lowbit( x ) ((x)&(-(x)))
const int maxn = 100003;

int h[maxn], v[maxn], hh[maxn];
int tree[maxn];

int max( int a, int b ) { return ( a > b ? a : b ); }
int cnt;

int bin_search( int k )
{
    int l = 1, r = cnt, mid;
    while( l <= r )
    {
        mid = ( l + r ) >> 1;
        if( hh[mid] < k ) l = mid + 1;
        else if( hh[mid] == k ) return mid;
        else r = mid - 1;
    }
    return -1;
}

void AddMax( int idx, int val )
{
    for( ; idx && idx <= cnt; idx += lowbit( idx ) )
        tree[idx] = max( tree[idx], val );
}

int query( int idx )
{
    int ans = 0;
    for( ; idx > 0; idx -= lowbit( idx ) )
        ans = max( ans, tree[idx] );
    return ans;
}

int main(int argc, char *argv[])
{
    int n;
    while( scanf("%d",&n) != EOF )
    {
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d%d",&h[i],&v[i]);
            hh[i] = h[i];
        }
        sort( hh + 1, hh + n + 1 );
        cnt = 1;
        for( int i = 2; i <= n; i++ )
            if( hh[i] != hh[i-1] )
                hh[++cnt] = hh[i];
        //printf("cnt = %d\n",cnt);
        for( int i = 1; i <= n; i++ )
            h[i] = bin_search( h[i] );
        //for( int i = 1; i <= n; i++ )
        //    printf("%d\n",h[i]);

        memset( tree, 0, sizeof( tree ) );
        int ans = 0, tmp;
        for( int i = 1; i <= n; i++ )
        {
            tmp = query( h[i] - 1 ) + v[i]; 
			// 查询[ 0, h[i]-1 ]的最大值加上v[i]
            if( tmp > ans ) ans = tmp;
            AddMax( h[i], tmp ); // 
        }
        printf("%d\n",ans);
    }
    return 0;
}
