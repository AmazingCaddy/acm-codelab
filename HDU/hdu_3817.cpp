/*
    author: AmazingCaddy
    time: 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 10004;
const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[ ] = { 1, 0, -1, 0, -1, 1, 1, -1 };

int main( int ac, char * av[ ] )
{
    int a[4];
    int cas;
    scanf( "%d", &cas );
    for( int t = 1; t <= cas; t++ )
    {
        scanf( "%d%d%d", &a[0], &a[1], &a[2] );
        sort( a, a + 3 );
        printf( "Case %d: ", t );
        if( a[ 0 ] * a[ 0 ] + a[ 1 ] * a[ 1 ] > a[ 2 ] * a[ 2 ] )
            printf( "Acute triangle\n" );
        else if( a[ 0 ] * a[ 0 ] + a[ 1 ] * a[ 1 ] == a[ 2 ] * a[ 2 ] )
            printf( "Right triangle\n" );
        else printf( "Obtuse triangle\n" );
    }
    return 0;
}
