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

const char * song[ ] = { "Yu Jian", "Tin O O", "I Missed", "Stefanie", "The Same", 
"About", "Honey Honey", "Unfinished", "Hey Jude", "When Winter Fades" };

int main( int ac, char * av[ ] )
{
    int n, cas;
    scanf( "%d", &cas );
    printf( "Best wishes to Stefanie\n\n" );
    while( cas-- )
    {
        scanf( "%d", &n );
        n--;
        n %= 14;
        if( n >= 7 ) printf( "%s\n", song[ n - 2 ] );
        else printf( "%s\n", song[ n ] );
    }
    return 0;
}
