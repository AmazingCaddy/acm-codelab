/*
    author: AmazingCaddy
    time: 21/05/2011 12:18:41 
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

const int maxn = 100004;
const int inf = 1000000000;

char buf[ maxn << 1 ], sum[ maxn << 1 ];
int Max( int a, int b ) { return ( a > b ? a : b ); }

int main( int ac, char * av[ ] )
{
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%s", buf );
		int n = strlen( buf );
		int cnt = 0;
		for( int i = 0; i < n; i++ )
			cnt = cnt + ( buf[ i ] == 'A' );
		int cnta = 0;
		for( int i = 0; i < cnt; i++ )
			cnta = cnta + ( buf[ i ] == 'A' );
		int ans = cnta;
		for( int i = 0; i < n; i++ )
		{
			cnta = cnta - ( buf[ i ] == 'A' ) + ( buf[ ( i + cnt ) % n ] == 'A' );
			ans = Max( ans, cnta );
		}
		printf( "Case %d: %d\n", t, cnt - ans );
	}
	return 0;
}
