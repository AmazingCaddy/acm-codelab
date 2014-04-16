/*
	author: AmazingCaddy
	time: 2011/3/12  15:57
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
#include <queue>
using namespace std;

struct node
{
	int num;
	int step;
};
const int maxn = 10005;
int vis[ maxn ], p[ maxn ];

void prime( )
{
	int i, j, k;
	memset( p, 0, sizeof( p ) );
	for( p[ 0 ] = vis[ 1 ] = 1, i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
		if( !p[ i ] && k < maxn )
			for( j = k; j < maxn; j += i ) p[ j ] = 1;
}

int BFS( int st, int ed )
{
	int step, nst, t, tt;
	queue<node> que;
	node tmp;
	memset( vis, 0, sizeof( vis ) );
	vis[ st ] = 1;
	tmp.num = st;
	tmp.step = 0;
	que.push( tmp );

	while( !que.empty( ) )
	{
		tmp = que.front( );
		que.pop( );
		step = tmp.step;
		t = tmp.num;
		if( t == ed ) return step;
		vis[ t ] = 1;
		tt = t - t % 10;
		for( int i = 1; i < 10; i += 2 ) // 个位
		{
			nst = tt + i;
			if( !vis[ nst ] && !p[ nst ] )
			{
				tmp.num = nst;
				tmp.step = step + 1;
				que.push( tmp );
			}
		}

		tt = t - t % 100 + t % 10;
		for( int i = 0; i < 10; i++ ) // 十位
		{
			nst = tt + i * 10;
			if( !vis[ nst ] && !p[ nst ] )
			{
				tmp.num = nst;
				tmp.step = step + 1;
				que.push( tmp );
			}
		}

		tt = t - t % 1000 + t % 100;
		for( int i = 0; i < 10; i++ )
		{
			nst = tt + i * 100;
			if( !vis[ nst ] && !p[ nst ] )
			{
				tmp.num = nst;
				tmp.step = step + 1;
				que.push( tmp );
			}
		}

		tt = t % 1000;
		for( int i = 1; i < 10; i++ )
		{
			nst = tt + i * 1000;
			if( !vis[ nst ] && !p[ nst ] )
			{
				tmp.num = nst;
				tmp.step = step + 1;
				que.push( tmp );
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int st, ed, cas, ans;
	prime( );
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d%d", &st, &ed );
		ans = BFS( st, ed );
		if( ans == -1 )printf( "Impossible\n" );
		else printf( "%d\n", ans );
	}
	return 0;
}
