/*
	author: AmazingCaddy
	time:  2011/4/11  13:55
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
#include <stack>
using namespace std;
const int maxn = 20;
char s1[ maxn ], s2[ maxn ];
int r[ maxn ], vis[ maxn ];
stack< char > sta;
int buf[ 100 ];
const char * str[ ] = { "in", "out" };

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d%s%s", &n, s1, s2 ) != EOF )
	{
		while( !sta.empty( ) ) sta.pop( );
		int i = 0, j = 0, k = 0;
		// 1 out 0 in
		while( i < n )
		{
			if( !sta.empty( ) && sta.top( ) == s2[ i ] )
			{
				sta.pop( );
				buf[ k++ ] = 1;
				i++;
			}
			else if( j < n )
			{
				sta.push( s1[ j ] );
				buf[ k++ ] = 0;
				j++;
			}
			else break;
		}
		if( !sta.empty( ) ) printf( "No.\nFINISH\n" );
		else
		{
			printf( "Yes.\n" );
			for( i = 0; i < k; i++ )
				printf( "%s\n", str[ buf[ i ] ] );
			printf( "FINISH\n" );
		}
	}
	return 0;
}
