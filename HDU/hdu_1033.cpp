/*
    author: AmazingCaddy
    time: 16/05/2011 18:29:31 
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

const int maxn = 205;
const int dx[ ] = { 10, 0, -10, 0 };
const int dy[ ] = { 0, 10, 0, -10 };

char buf[ maxn ];

int main( int ac, char * av[ ] )
{
	int x, y;
	while( scanf( "%s", buf ) != EOF )
	{
		printf( "300 420 moveto\n" );
		printf( "310 420 lineto\n" );
		x = 310, y = 420;
		int dir = 0;
		for( int i = 0; buf[ i ]; i++ )
		{
			if( buf[ i ] == 'A' ) dir = ( ( dir - 1 ) % 4 + 4 ) % 4;
			else dir = ( dir + 1 ) % 4;
			x = x + dx[ dir ], y = y + dy[ dir ];
			printf( "%d %d lineto\n", x, y );
		}
		printf( "stroke\n" );
		printf( "showpage\n" );
	}
    return 0;
}
