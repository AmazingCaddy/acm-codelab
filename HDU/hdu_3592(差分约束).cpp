#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 1003;
const int maxm = 30005;
const int inf = 1000000000;
struct node
{
    int v, d;
    node *next;
}buf[ maxm ];
int len;
node * adj[maxn];
bool in[maxn];
int dis[maxn], cnt[maxn];

node * NewNode( )
{
    buf[len].next = NULL;
    return &buf[len++];
}

void AddEdge( int u, node * p )
{
    p -> next = adj[u];
    adj[u] = p;
}

bool SPFA( int s, int n )
{
    node * p;
    int u, v;
    queue<int> que;
    for( int i = 1; i <= n; i++ )
        dis[i] = inf, in[i] = false, cnt[i] = 0;
    que.push( s );
    dis[s] = 0, cnt[s] = 1, in[s] = true;
    while( !que.empty( ) )
    {
        u = que.front( );
        que.pop( );
        in[u] = false;
        p = adj[u];
        while( p )
        {
            //cout << "OO"<<endl;
            v = p -> v;
            if( dis[u] + p -> d < dis[v] )
            {
                dis[v] = dis[u] + p -> d;
                if( !in[v] )
                {
                    que.push( v );
                    cnt[v]++;
                    if( cnt[v] >= n ) return true; // 存在负环
                    in[v] = true;
                }
            }
            p = p -> next;
        }
    }
    return false;
}

int main( )
{
    int cas, n, a, b, c, x, y, z;
    bool flag;
    node *p;
    scanf("%d",&cas);
    while( cas-- )
    {
        len = 0;
        scanf("%d%d%d",&n,&a,&b);
        memset( adj, NULL, sizeof( adj ) );
        for( int i = 0; i < a; i++ )
        {
            scanf("%d%d%d",&x,&y,&z);
            p = NewNode( );
            p -> v = y;
            p -> d = z;
            AddEdge( x, p );  
        }
        for( int i = 0; i < b; i++ )
        {
            scanf("%d%d%d",&x,&y,&z);
            p = NewNode( );
            p -> v = x;
            p -> d = -z;
            AddEdge( y, p );
        }
        for( int i = 2; i <= n; i++ )
        {
            p = NewNode( );
            p -> v = i - 1;
            p -> d = 0;
            AddEdge( i, p );
        }
        int ans;
        flag = SPFA( 1, n );
        if( flag ) ans = -1;
        else 
        {
            if( dis[n] >= inf ) ans = -2;
            else ans = dis[n];
        }
        printf("%d\n",ans);
    }
    return 0;
}


//
/*
int len = 0;
int head[maxn], next[maxm], v[maxm], e[maxm];

// add <u,v,l>

void add_edge( int u , int v , int l ){
    ++len ; v[len] = v ; e[ len ] = l ; next[len] = head[u] ; head[u] = len ;
}

// u 
for( int _i = head[u] ; _i ; _i = next[_i] ){
    int v = v[ _i ] ;
    int l = e[ _i ] ;
    
        
} 

*/
