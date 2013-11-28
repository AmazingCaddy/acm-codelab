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

int num[ ][ 20 ] = {
{ 2, 3, 6 },
{ 2, 4, 6, 12 },
{ 2, 5, 6, 12, 20 },
{ 2, 4, 8, 16, 24, 48 },
{ 2, 6, 7, 12, 20, 30, 42 },
{ 2, 6, 8, 12, 20, 30, 42, 56 },
{ 2, 6, 9, 12, 20, 30, 42, 56, 72 },
{ 2, 6, 10, 12, 20, 30, 42, 56, 72, 90 },
{ 2, 6, 11, 12, 20, 30, 42, 56, 72, 90, 110 },
{ 2, 6, 8, 20, 24, 30, 42, 56, 72, 90, 110, 132 },
{ 2, 6, 12, 13, 20, 30, 42, 56, 72, 90, 110, 132, 156 },
{ 2, 6, 12, 14, 20, 30, 42, 56, 72, 90, 110, 132, 156, 182 },
{ 2, 6, 12, 15, 20, 30, 42, 56, 72, 90, 110, 132, 156, 182, 210 },
{ 2, 6, 12, 16, 20, 30, 42, 56, 72, 90, 110, 132, 156, 182, 210, 240 },
{ 2, 6, 12, 17, 20, 30, 42, 56, 72, 90, 110, 132, 156, 182, 210, 240, 272 },
{ 2, 6, 12, 18, 20, 30, 42, 56, 72, 90, 110, 132, 156, 182, 210, 240, 272, 306 } };

int main( int ac, char * av[ ] )
{
    int n;
    //freopen( "ans.txt", "w", stdout );
    //init( );
    int ans[ 20 ];
    for( int i = 0; i < 16; i++ )
    {
        for( int j = 0; j < i + 3; j++ )
        {
            if( j ) printf( " " );
            printf( "%d", num[ i ][ j ] );            
        }
        printf( "\n" );
    }
    return 0;
}
