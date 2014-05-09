// 最小路径覆盖 = N - 最大匹配
#include <cstdio>
#include <iostream>
#include <cstring>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 505;

struct node
{
	int time, a, b, c, d;
};
node car[ maxn ];
int g[ maxn ][ maxn ];
int vis[ maxn ], match[ maxn ];
int n, m;

int usedtime( int a, int b, int c, int d )
{
	return abs( a - c ) + abs( b - d );
}

int dfs( int from )
{
	for( int i = 0; i < n; i++ )
	{
		if( g[ from ][ i ] && !vis[ i ] )
		{
			vis[ i ] = 1;
			if( match[ i ] == -1 || dfs( match[ i ] ) )
			{
				match[ i ] = from;
				return 1;
			}
		}
	}
	return 0;
}

int Hungray( )
{
	int sum = 0;
	memset( match, -1, sizeof( match ) );
	for( int i = 0; i < n; i++ )
	{
		memset( vis, 0, sizeof( vis ) );
		if( dfs( i ) )
			sum++;
	}
	return sum;
}

void build( )
{
	int en, st;
	memset( g, 0, sizeof( g ) );
	for( int i = 0; i < n; i++ )
	{
		en = car[ i ].time + usedtime( car[i].a, car[i].b, car[i].c, car[i].d );
		for( int j = 0; j < n; j++ )
		{
			st = usedtime( car[i].c, car[i].d, car[j].a, car[j].b );
			if( en + st < car[j].time )
				g[ i ][ j ] = 1;
		}
	}
}

int main(int argc, char *argv[])
{
	int cas, a, b, c, d;
	int hour, minute;
	scanf("%d",&cas);
	while( cas-- )
	{
		scanf("%d",&n);
		for( int i = 0; i < n; i++ )
		{
			scanf("%2d:%2d%d%d%d%d",&hour,&minute,&car[i].a,&car[i].b,&car[i].c,&car[i].d);
			car[ i ].time = hour * 60 + minute;
		}
		build( );
		int ans = n - Hungray( );
		printf("%d\n",ans);
	}
	return 0;
}
