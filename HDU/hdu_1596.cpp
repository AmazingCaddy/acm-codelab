#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 1003;
const double eps = 1e-8;
int inque[maxn], in[maxn]; 
double dis[maxn];
double g[maxn][maxn];
int s, t, n, m;
int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }

double SPFA( int src, int dst )
{
    queue<int> que;
    memset( in, 0, sizeof( in ) );
    memset( inque, 0, sizeof( inque ) );
    for( int i = 1; i <= n; i++ ) dis[i] = 0;
    que.push( src );
    inque[src] = 1;
    in[src]++;
    dis[src] = 1.0;
    while( !que.empty( ) )
    {
        int u = que.front( );
        que.pop( );
        inque[u] = 0;
        for( int i = 1; i <= n; i++ )
        {   
            double d = g[u][i];
            if( dis[u] * d > dis[i] )
            {
                dis[i] = dis[u] * d;
                if( !inque[i] )
                {
                    que.push( i );
                    in[i]++;
                    inque[i] = 1;               
                }
            }
        }   
    }
    return dis[dst];
}

int main( )
{   
    double ans;
    while( scanf("%d",&n) != EOF )
    {
        for( int i = 1; i <= n; i++ )
            for( int j = 1; j <= n; j++ )
                scanf("%lf",&g[i][j]);
        scanf("%d",&m);
        for( int i = 0; i < m; i++ )
        {
            scanf("%d%d",&s,&t);
            ans = SPFA( s, t );
            if( dblcmp( ans ) == 0 ) printf("What a pity!\n");
            else printf("%.3lf\n",ans);
        }   
    }
    return 0;
}
