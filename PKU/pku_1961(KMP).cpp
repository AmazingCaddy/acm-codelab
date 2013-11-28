/*
    author: AmazingCaddy
    time: 16/05/2011 14:02:02 
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

const int maxn = 1000006;

char p[ maxn ];
int fail[ maxn ];

void faillink( int n )
{
	int j = 1, k;
	fail[ 0 ] = -1;
	while( j <= n )
	{
		k = fail[ j - 1 ];
		while( k != -1 && p[ k ] != p[ j - 1 ] )
			k = fail[ k ];
		fail[ j ] = k + 1;
		j++;
	}
}

int main( int ac, char * av[ ] )
{
	int n, t = 1;
	while( scanf( "%d", &n ) && n )
	{
		scanf( "%s", p );
		faillink( n );
		printf( "Test case #%d\n", t++ );
		for( int i = 2; i <= n; i++ )
		{
			int tmp = i - fail[ i ];
			if( i % tmp == 0 && i / tmp > 1 )
				printf( "%d %d\n", i, i / tmp );
		}
		printf( "\n" );
	}
    return 0;
}
