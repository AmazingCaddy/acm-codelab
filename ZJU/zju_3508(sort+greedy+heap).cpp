#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <complex>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

const int maxn = 2505;
const int maxm = 40010;

struct node
{
    int x, y;
    friend bool operator < ( const node & a, const node &b )
    {
        return a.y > b.y;
    }
};

priority_queue< node > heap;

node arm[ maxn ];
int weapon[ maxm ];

bool cmp( const node & a, const node & b )
{
    return ( a.x < b.x );
}

int cnt[ 1005 ];

int main( )
{
    int n, m;
    while( scanf( "%d%d", &n, &m ) != EOF )
    {
        memset( cnt, 0, sizeof( cnt ) );
        while( !heap.empty( ) ) heap.pop( );
        
        for( int i = 0; i < n; i++ )
            scanf( "%d%d", &arm[ i ].x, &arm[ i ].y );
        for( int i = 0; i < m; i++ )
        {
            scanf( "%d", &weapon[ i ] );
            cnt[ weapon[ i ] ] ++;
        }
        sort( arm, arm + n, cmp );
        int ans = 0, j = 0;
        for( int i = 1; i <= 1000; i++ )
        {
            while( j < n && arm[ j ].x == i ) { heap.push( arm[ j ] ); j++; }
            if( cnt[ i ] == 0 ) continue;
            int tmp = cnt[ i ];
            while( tmp && !heap.empty( ) )
            {
                if( heap.top( ).y < i ) heap.pop( );
                else
                {
                    heap.pop( );
                    tmp--;
                    ans++;
                }
            }
        }
        printf( "%d\n", ans );
    }
    return 0;
}
