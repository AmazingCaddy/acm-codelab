/*
	author: AmazingCaddy
	time: 2011/4/10  18:51
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
const int maxn = 30;

int target, flag, slen, k;
int vis[ maxn ];
int buf[ maxn ];
char str[ maxn ];

bool cmp( const char a, const char b )
{
	return a > b;
}

int get( int a, int n )
{
	int tmp = 1;
	for( int i = 0; i < n; i++ )
		tmp *= a;
	return tmp;
}

void DFS( int dep, int sum )
{
	if( flag ) return;
	if( dep == 5 )
	{
		if( sum == target )
		{
			for( int i = 0; i < dep; i++ )
				printf( "%c", str[ buf[ i ] ] );
			printf( "\n" );
			flag = 1;
		}
		return;
	}
	for( int i = 0; i < slen; i++ )
	{
		if( vis[ i ] ) continue;
		int tmp = get( str[ i ] - 'A' + 1, dep + 1 );
		vis[ i ] = 1;
		buf[k++] = i;
		DFS( dep + 1, sum + ( dep % 2 ? -1 : 1 ) * tmp );
		vis[ i ] = 0;
		k--;
	}
}

int main(int argc, char *argv[])
{
	while( scanf( "%d%s", &target, str ) != EOF )
	{
		if( target == 0 && strcmp( str, "END" ) == 0 ) break;
		flag = 0;
		slen = strlen( str );
		sort( str, str + slen, cmp );
		memset( vis, 0, sizeof( vis ) );
		k = 0;
		DFS( 0, 0 );
		if( !flag ) printf( "no solution\n" );
	}
	return 0;
}
