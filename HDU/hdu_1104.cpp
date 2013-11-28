/*
    author: AmazingCaddy
    time:    2011-07-14 17:57:28 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;

//const int maxn = 1005;
int mod( int a, int b ) { return ( a % b + b ) % b; }

//int vis[ maxn * maxn ];
const char ch[ ] = "+-*%";

void BFS( int n, int m, int k )
{
    queue< pair< int, string > > que;
    map< int, int > vis;
    int st = n, nn, final = mod( n + 1, k );
    string step;
    vis[ st ] = 1;
    que.push( make_pair( st, "" ) );
    int flag = 0;
    while( !que.empty( ) )
    {
        pair< int, string > tmp = que.front( );
        que.pop( );
        st = tmp.first;
        step = tmp.second;
        if( mod( st, k ) == final ) { flag = 1; break; }
        
        nn = mod( st + m, k * m );
        if( vis.find( nn ) == vis.end( ) )
        {
            vis[ nn ] = 1;
            que.push( make_pair( nn, step + "0" ) );
        }
        
        nn = mod( st - m, k * m );
        if( vis.find( nn ) == vis.end( ) )
        {
            vis[ nn ] = 1;
            que.push( make_pair( nn, step + "1" ) );
        }
        
        nn = mod( st * m, k * m );
        if( vis.find( nn ) == vis.end( ) )
        {
            vis[ nn ] = 1;
            que.push( make_pair( nn, step + "2" ) );
        }
        
        nn = mod( st, m ) % ( k * m );
        if( vis.find( nn ) == vis.end( ) )
        {
            vis[ nn ] = 1;
            que.push( make_pair( nn, step + "3" ) );
        }
    }
    if( !flag || step == "" )
    {
        printf( "0\n" );
        return;
    }
    int ans = step.size( );
    printf( "%d\n", ans );
    for( int i = 0; i < ans; i++ )
        step[ i ] = ch[ step[ i ] - '0' ];
     cout << step << endl;
}

int main(int argc, char *argv[])
{
    int n, m, k;
    while( 1 )
    {
        scanf( "%d%d%d", &n, &k, &m );
        if( n == 0  && m == 0 && k == 0 ) break;
        BFS( n, m, k );
    }
    return 0;
}
