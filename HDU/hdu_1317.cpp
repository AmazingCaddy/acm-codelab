#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 103;
int mk[maxn], inque[maxn], e[maxn], dis[maxn], in[maxn];
int g[maxn][maxn];
int n, m;

bool SPFA( int src )
{
    queue<int> que;
    memset( inque, 0, sizeof( inque ) );
    memset( in, 0, sizeof( in ) );
    memset( dis, 0, sizeof( dis ) );
    dis[src] = 100;
    que.push( src );
    inque[src] = 1;
    in[src]++;
    while( !que.empty( ) )
    {
        int x = que.front( );
        que.pop( );
        inque[x] = 0;
        if( in[x] >= n ) return true; // 存在正环
        for( int i = 1; i <= n; i++ )
        {
            if( g[x][i] && dis[x] + e[i] > dis[i] )
            {
                dis[i] = dis[x] + e[i];
                if( !inque[i] )
                {
                    que.push( i );
                    in[i]++;
                    inque[i] = 1;
                }
            }
        }    
    }
    return false;
}

void Floyd( )
{
    int i, j, k;
    for( k = 1; k <= n; k++ )
        for( i = 1; i <= n; i++ )
            for( j = 1; j <= n; j++ )
                if( g[i][k] && g[k][j] )
                    g[i][j] = 1;
}

void solve( )
{
    int i;
    SPFA( 1 ); 
    Floyd( );
    if( dis[n] ) printf("winnable\n");
    else
    {
        for( i = 1; i <= n; i++ )
            if( in[i] >= n && g[i][n] )
            {
                printf("winnable\n");
                break;
            }
        if( i > n ) printf("hopeless\n");
    }
}

bool readdate( )
{
    int i, j, y;
    scanf("%d",&n);
    if( n == -1 ) return false;
    memset( g, 0, sizeof( g ) );
    for( i = 1; i <= n; i++ )
    {
        scanf("%d%d",&e[i],&m);
        for( j = 1; j <= m; j++ )
        {
            scanf("%d",&y);
            g[i][y] = 1;
        }
    }
    return true;
}

int main( )
{
    while( readdate( ) )
    {
        solve( );
    }
    return 0;
}
