/*
	author: AmazingCaddy
	time: 2011/4/9  21:46
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
const int maxn = 100005;

int vis[ maxn ];
int mk[ maxn ];

int main(int argc, char *argv[])
{
	int n, cas, a, b, x;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d %d", &a, &b );
			vis[ a ] = b;
		}
		int cnt = 0;
		for( int i = 1; i <= n; i++ )
			if( vis[ i ] == i ) cnt++;
		printf( "%d\n", n - cnt );
		/*
		int cnt = n;
		memset( mk, 0, sizeof( mk ) );
		for( int i = 1; i <= n; i++ )
		{
			if( !mk[ i ] )
			{
				x = i;
				mk[ x ] = 1;
				if( x == vis[ x ] ) cnt--;
				else
				{
					while( 1 )
					{
						x = vis[ x ];
						if( mk[ x ] ) break;
						else mk[ x ] = 1;
					}
				}
			}
		}
		printf( "%d\n", cnt );
		*/
	}
	return 0;
}
