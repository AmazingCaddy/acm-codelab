/*
	author: AmazingCaddy
	time:	2011-07-07 12:37:21 
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

const int maxn = 104;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

struct node
{
	int r, c;
}matrix[ maxn ];

char buf[ maxn * maxn * 10 ];

int main(int argc, char *argv[])
{
	int n;
	char ch[ 5 ];
 	scanf( "%d", &n );
	for( int i = 0; i < n; i++ )
	{
		scanf( "%s", ch );
		int tmp = ch[ 0 ] - 'A';
		scanf( "%d%d", &matrix[ i ].r, &matrix[ i ].c );
	}
	stack<node> sta;
	while( scanf( "%s", buf ) != EOF )
	{
		while( !sta.empty( ) ) sta.pop( );
		int len = strlen( buf );
		int flag = 0;
		int ans = 0;
		for( int i = 0; i < len; i++ )
		{
			if( buf[ i ] == ')' )
			{
				node m1 = sta.top( ); sta.pop( );
				node m2 = sta.top( ); sta.pop( );
				if( m1.r != m2.c ) { flag = 1; break; }
				else 
				{
					ans += m2.r * m2.c * m1.c;
					m2.c = m1.c;
					sta.push( m2 );
				}
			}
			else if( buf[ i ] != '(' )
			{
				int tmp = buf[ i ] - 'A';
				node m;
				m.r = matrix[ tmp ].r, m.c = matrix[ tmp ].c;
				sta.push( m );
			}
		}
		if( flag ) printf( "error\n" );
		else printf( "%d\n", ans );
	}
	return 0;
}
