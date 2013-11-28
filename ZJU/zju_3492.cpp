/*
	author: AmazingCaddy
	time: 2011/4/16  13:15
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

const int maxn = 104;
char str[ maxn ][ 23 ];
char buf[ 23 ];

int main(int argc, char *argv[])
{
	int cas, n;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d%s", &n, buf );
		int k = -1;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%s", str[ i ] );
			if( strcmp( buf, str[ i ] ) == 0 )
				 k = i;
		}
		printf( "%s\n", str[ ( k + n / 2 ) % n ] );
	}
	return 0;
}
