/*
    author: AmazingCaddy
    time: 17/05/2011 20:35:34 
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
	int h1, h2, h3;
	while( scanf( "%d%d%d", &h1, &h2, &h3 ) != EOF )
	{
		if( h1 >= 168 && h2 >= 168 && h3 >= 168 )
			printf( "NO CRASH\n" );
		else
		{
			if( h1 < 168 ) 
			{
				printf( "CRASH %d\n", h1 );
				continue;
			}
			if( h2 < 168 )
			{
				printf( "CRASH %d\n", h2 );
				continue;
			}
			printf( "CRASH %d\n", h3 );
		}
	}
	return 0;
}
