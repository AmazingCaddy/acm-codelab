/*
    author: AmazingCaddy
    time: 18/05/2011 15:56:49 
    dp[i] = dp[i-1] + dp[i-2]*2
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

int a[ 1002 ][ 505 ];

int main( int ac, char * av[ ] )
{
    int i, n, j, t;
//    memset(a,0,sizeof(a));
    a[ 1 ][ 0 ] = 0; a[ 2 ][ 0 ] = 1; a[ 3 ][ 0 ] = 1;
    for( i = 4; i <= 1000; i++ )
    {
        t = 0;
        for( j = 0; j <= 350; j++ )
    	{
            a[ i ][ j ] = a[ i - 1 ][ j ] + 2 * a[ i - 2 ][ j ] + t;
            t = a[ i ][ j ] / 10;
            a[ i ][ j ] = a[ i ][ j ] % 10;
        }
    }
    while( cin >> n )
    {
        if( n == 1 )
        {
            cout << "0" << endl;
            continue;
        }
	    int flag = 0;
        for( i = 350; i >= 0; i-- )
        {
            if( a[ n ][ i ] != 0 || flag )
            {
                cout << a[ n ][ i ];
                flag = 1;
	        }
        }
        cout << endl;   
    }
    return 0;
}

