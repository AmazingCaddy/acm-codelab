#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf = 1000000000;
const int maxm = 1005;
const int maxn = 205;

int n, m, s, t, num, len, next[maxm], ev[maxm], ew[maxm];  // ev[i] 后继顶点  ew[i] 边( u, v )权值 
int value[maxn], mk[maxn], nbs[maxn], ps[maxn], heap[maxn];
// mk[i] 标记， nbs[i] 保存跟u邻接的定点在next[]中的下标， ps[i] 保存顶点i点在heap中的下标
void update( int r )   // 更新 向上调整
{
    int q = ps[r], p = q >> 1;
    while( p && value[heap[p]] > value[r] )
    {
        ps[heap[p]] = q;  heap[q] = heap[p];
        q = p;  p = q >> 1;
    }
    heap[q] = r;  ps[r] = q;
}

int getmin( )   // 获取最小值，并且调整堆
{
    int ret = heap[1], p = 1, q = 2, r = heap[len--];
    while( q <= len )
    {
        if( q < len && value[heap[q+1]] < value[heap[q]] ) q++;
        if( value[heap[q]] < value[r] )
        {
            ps[heap[q]] = p;  heap[p] = heap[q];
            p = q;  q = p << 1;
        }
        else break;    
    }
    heap[p] = r;  ps[r] = p;
    return ret;
}

void Dijkstra( int src, int dst )  // src 起点， dst 终点
{
    int i, j, u, v;
    for( i = 1 ; i <= n; i++ ) { value[i] = inf; mk[i] = ps[i] = 0; }
    value[src] = 0;  heap[len=1] = src;  ps[src] = 1;
    while( !mk[dst] )
    {
        if( len == 0 ) return ;
        u = getmin( );  mk[u] = 1;
        for( j = nbs[u]; j ; j = next[j] )
        {
            v = ev[j];  
            if( !mk[v] && value[u] + ew[j] < value[v] )
            {
                if( ps[v] == 0 ) { heap[++len] = v; ps[v] = len; }
                value[v] = value[u] + ew[j];
                update( v );
            }
        }
    }
}

void solve( )
{
    int i, u;
    num = 0;
    for( i = 1; i <= n; i++ ) nbs[i] = 0;
    for( i = 1; i <= n; i++ )
    {
        scanf("%d",&u);
        next[++num] = nbs[i];
        nbs[i] = num;
        ev[num] = i + u; ew[num] = 1;
        if( i - u > 0 )
        {
            next[++num] = nbs[i];
            nbs[i] = num;
            ev[num] = i - u; ew[num] = 1;
        }
    }
    Dijkstra( s, t );  // Minimum Distance saved at value[1..n]
    if( value[t] >= inf ) value[t] = -1;
    printf("%d\n",value[t]);
}

int main( )
{   
    while( scanf("%d%d%d",&n,&s,&t) && n )
    {
        solve( );     
    }
    return 0;
}
