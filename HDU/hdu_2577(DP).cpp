/*
	author: AmazingCaddy
	time: 2011/4/10  16:21
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

const int maxn = 102;
char str[ maxn ];
int on[ maxn ], off[ maxn ];
int Min( int a, int b ) { return ( a < b ? a : b ); }

int main(int argc, char *argv[])
{
	int cas;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%s", str + 1 );
		int len = strlen( str + 1 );
		on[ 0 ] = 1, off[ 0 ] = 0;
		for( int i = 1; i <= len; i++ )
		{
			if( str[ i ] <= 'z' && str[ i ] >= 'a' )
			{
				on[ i ] = Min( on[ i - 1 ] + 2, off[ i - 1 ] + 2 );
				off[ i ] = Min( on[ i - 1 ] + 2, off[ i - 1 ] + 1 );
			}
			else
			{
				on[ i ] = Min( on[ i - 1 ] + 1, off[ i - 1 ] + 2 );
				off[ i ] = Min( on[ i - 1 ] + 2, off[ i - 1 ] + 2 );
			}
		}
		printf( "%d\n", Min( on[ len ] + 1, off[ len ] ) );
	}
	return 0;
}
