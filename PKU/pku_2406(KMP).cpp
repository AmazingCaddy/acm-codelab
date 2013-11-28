/*
    author: AmazingCaddy
    time: 16/05/2011 13:12:58 
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
	fail[ 0 ] = -1;
	int j = 1, k;
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
	int len, ans;
    while( scanf( "%s", p ) && p[ 0 ] != '.' )
    {
    	len = strlen( p );
    	faillink( len );
    	if( len % ( len - fail[ len ] ) == 0 ) ans = len / ( len - fail[ len ] );
    	else ans = 1;
    	printf( "%d\n", ans );
    }
    return 0;
}
