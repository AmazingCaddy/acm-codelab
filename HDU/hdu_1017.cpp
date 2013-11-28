/*
	author: AmazingCaddy
	time: 2011/4/10  21:14
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	int cas, n, m;
	scanf( "%d", &cas );
	for( int t = 0; t < cas; t++ )
	{
		if( t ) printf( "\n" );
		int k = 1;
		while( 1 )
		{
			scanf( "%d%d", &n, &m );
			if( n == 0 && m == 0 ) break;
			int cnt = 0;
			for( int i = 1; i < n; i++ )
				for( int j = i + 1; j < n; j++ )
					if( ( i * i + j * j + m ) % ( i * j ) == 0 )
						cnt++;
			printf( "Case %d: %d\n", k++, cnt );
		}
	}
	return 0;
}
