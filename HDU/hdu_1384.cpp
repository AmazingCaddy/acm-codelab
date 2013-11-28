#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 50010;
const int inf = 1000000000;
struct edge
{
    int s, e, v;
};
edge E[maxn];
int nmin, nmax, n, m;
int dis[maxn];

int BellmanFord( )
{
    int i, j;
    bool flag;
    memset( dis, -1, sizeof( dis ) );
    dis[nmin] = 0;
    for( i = nmin; i < nmax; i++ )
    {
        flag = false;
        for( j = 0; j < n; j++ )
            if( dis[E[j].s] != -1 && dis[E[j].s] + E[j].v > dis[E[j].e] )
                dis[E[j].e] = dis[E[j].s] + E[j].v, flag = true;
        for( j = nmin; j < nmax; j++ )
            if( dis[j] != -1 && dis[j] > dis[j+1] )
                dis[j+1] = dis[j], flag = true;
        s
        for( j = nmax; j > nmin; j-- )
            if( dis[j] != -1 && dis[j] - 1 > dis[j-1] )
                dis[j-1] = dis[j] - 1, flag = true;
        
        if( !flag ) break;
    }
    return dis[nmax];
}

int main( )
{
    int i;
    while( scanf("%d",&n) != EOF )
    {
        nmin = inf, nmax = -1;
        for( i = 0; i < n; i++ )
        {
            scanf("%d%d%d",&E[i].s,&E[i].e,&E[i].v);
            E[i].e++;  // important
            if( E[i].s < nmin ) nmin = E[i].s;
            if( E[i].e > nmax ) nmax = E[i].e;
        }
        //printf("hello\n\n");
        printf("%d\n",BellmanFord( ));
    }
    return 0;
}
