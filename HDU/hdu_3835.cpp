#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
using namespace std;

const int maxn = 35000;
const int inf = 1000000000;

int num[ maxn ];
map< int, int > vis;

void init( )
{
    vis.clear( );
    for( int i = 0; i * i <= inf; i++ )
    {
        num[ i ] = i * i;
        vis[ num[ i ] ] = 1;
    }
    //for( int i = 0; i < 10; i++ )
    //    printf( "%d\n", num[ i ] );
}

int main()
{
    int n;
    init( );
    while( scanf( "%d", &n ) != EOF )
    {
        int ans = 0;
        for( int i = 0; num[ i ] <= n; i++ )
        {
            if( vis.find( n - num[ i ] ) != vis.end() )
                ans++;
        }
        ans *= 4;
        if( vis.find( n ) != vis.end( ) )
            ans -= 4;
        printf( "%d\n", ans );
    }
    return 0;
}
