/*
    author: AmazingCaddy
    time: 28/05/2011 13:02:59 
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

const int maxn = 14;

string g[ maxn ][ maxn ];
char buf[ 10000 ];

int main( int ac, char * av[ ] )
{
	int n, m, q, cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d%d%d", &n, &m, &q );
		getchar( );
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < m; j++ )
				cin >> g[ i ][ j ];
		printf( "Case %d:\n", t );
		for( int i = 0; i < q; i++ )
		{
			scanf( "%s", buf );
			int len = strlen( buf );
			for( int j = 0; j < len; j += 2 )
			{
				int a = buf[ j + 1 ] - '1';
				int b = buf[ j ] - 'A';
				cout << g[ a ][ b ];
			}
			printf( "\n" );
		}
	}
	return 0;
}
