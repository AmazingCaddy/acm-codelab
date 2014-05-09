/*
	author: AmazingCaddy
	time: 2011/6/4  16:00
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

const int maxn = 30;
const int inf = 0xffff;

struct node
{
	int co, re;
};
node opp[ maxn ], tmp[ maxn ];

int dp[ 10 ];

int Min( int a, int b ) { return ( a < b ? a : b ); }

// 消耗体力升序排列
bool cmp1( const node &a, const node &b )
{
	return a.co < b.co;
}

// 恢复体力降序排列
bool cmp2( const node &a, const node &b )
{
	return a.re > b.re;
}

int main(int argc, char *argv[])
{
	int cas, n, s;
	int p1, p2, p3;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d%d", &n, &s );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d%d%d%d", &p1, &p2, &p3, &opp[ i ].re );
			opp[ i ].co = inf;
			for( int a = 0; a <= 3; a++ )
				for( int b = 0; b <= 4; b++ )
					for( int c = 0; c <= 8; c++ )
						if( a * 3 + b * 2 + c >= 7 )
							opp[ i ].co = Min( opp[ i ].co, p1 * a + p2 * b + p3 * c );
			//printf( "cost = %d, recover = %d\n", opp[ i ].co, opp[ i ].re );
		}
		int st = 0, ed = n;
		for( int i = 0; i < n; i++ )
		{
			if( opp[ i ].re >= opp[ i ].co )
				tmp[ st++ ] = opp[ i ];
			else tmp[ --ed ] = opp[ i ];
		}
		//printf( "st = %d, ed = %d\n", st, ed );
		sort( tmp, tmp + st, cmp1 );
		sort( tmp + ed, tmp + n, cmp2 );
		int ans = s, flag = 0;
		for( int i = 0; i < n; i++ )
		{
			//printf( "cost = %d, recover = %d\n", opp[ i ].co, opp[ i ].re );
			if( tmp[ i ].co >= ans )
			{
				flag = 1;
				break;
			}
			ans += tmp[ i ].re - tmp[ i ].co;
		}
		if( flag ) printf( "no\n" );
		else printf( "%d\n", ans );
	}
	return 0;
}
