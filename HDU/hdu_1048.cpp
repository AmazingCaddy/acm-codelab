/*
	author: AmazingCaddy
	time: 
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
#include <queue>
using namespace std;

typedef __int64 ll;

const int maxn = 10004;

const char ch[ ] = { 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F',
	'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U' };
char buf[ maxn ];

int main(int argc, char *argv[])
{
	char c;
	while( gets( buf ) )
	{
		if( strcmp( buf, "ENDOFINPUT" ) == 0 ) break;
		while( ( c = getchar( ) ) != '\n' )
		{
			if( c <= 'Z' && c >= 'A' ) printf( "%c", ch[ c - 'A' ] );
			else printf( "%c", c );
		}
		printf( "\n" );
		gets( buf );
	}
	return 0;
}
