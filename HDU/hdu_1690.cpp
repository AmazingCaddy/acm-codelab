#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

const int maxn = 103;
const ll inf = 0x7fffffffffffff;

ll a[maxn][maxn], b[maxn][maxn];
int t, n, m, d[maxn];

void Floyd( )
{
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            b[i][j] = a[i][j];
    for( int k = 1; k <= n; k++ )
        for( int i = 1; i <= n; i++ )
            for( int j = 1; j <= n; j++ )
                if( b[i][k] + b[k][j] < b[i][j] )
                    b[i][j] = b[i][k] + b[k][j];
}

int main( )
{
    int l1, l2, l3, l4, c1, c2, c3, c4, p, q;
    scanf("%d",&t);
    for( int i = 1; i <= t; i++ )
    {
        scanf("%d%d%d%d%d%d%d%d",&l1,&l2,&l3,&l4,&c1,&c2,&c3,&c4);
        scanf("%d%d",&n,&m);
        for( int j = 1; j <= n; j++ )
            scanf("%d",&d[j]);
        for( int j = 1; j <= n; j++ )
        {
            a[j][j] = 0;
            for( int k = j + 1; k <= n; k++ )
            {
                int tmp = d[k] - d[j];
                if( tmp < 0 ) tmp = -tmp;
                if( tmp == 0 ) a[j][k] = a[k][j] = 0;
                else if( tmp <= l1 ) a[j][k] = a[k][j]= c1;
                else if( tmp <= l2 ) a[j][k] = a[k][j] = c2;
                else if( tmp <= l3 ) a[j][k] = a[k][j] = c3;
                else if( tmp <= l4 ) a[j][k] = a[k][j] = c4;
                else a[j][k] = a[k][j] = inf;
            }
        }
        Floyd( );
        printf("Case %d:\n",i);
        for( int j = 1; j <= m; j++ )
        {
            scanf("%d%d",&p,&q);
            if( b[p][q] < inf )
                printf("The minimum cost between station %d and station %d is %lld.\n",p,q,b[p][q]);
            else printf("Station %d and station %d are not attainable.\n",p,q);
        }
    }
    return 0;
}
