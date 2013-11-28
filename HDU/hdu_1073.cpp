/*
	author : AmazingCaddy
	time : 2011-06-01 14:52:33 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;
#define lowbit(x) ((x)&(-(x)))

const int maxn = 10004;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

char str1[ maxn ], str2[ maxn ], buf[ maxn ];

void fun( char str[ ] )
{
	int len = strlen( str );
	int j = 0;
	for( int i = 0; i < len; i++ )
	{
		if( str[ i ] != ' ' && str[ i ] != '\t' && str[ i ] )
		{
			str[ j++ ] = str[ i ];
		}
	}
	str[ j ] = 0;
}

int main(int argc, char *argv[])
{
	int cas;
	scanf( "%d", &cas );
	while( cas -- )
	{
		while( gets( buf ) && strcmp( buf, "START" ) );
		gets( str1 );
		while( gets( buf ) && strcmp( buf, "END" ) )
		{
			if( strcmp( buf, "" ) == 0 ) strcat( str1, " " );
			else strncat( str1, buf, strlen( buf ) );
		}
		
		while( gets( buf ) && strcmp( buf, "START" ) );
		gets( str2 );
		while( gets( buf ) && strcmp( buf, "END" ) )
		{
			if( strcmp( buf, "" ) == 0 ) strcat( str2, " " );
			else strncat( str2, buf, strlen( buf ) );
		}
		
		if( strcmp( str1, str2 ) == 0 )	printf( "Accepted\n" );
		else 
		{
			fun( str1 );
			fun( str2 );
			if( strcmp( str1, str2 ) == 0 ) printf( "Presentation Error\n" );
			else printf( "Wrong Answer\n" );
		}
	}
	return 0;
}
