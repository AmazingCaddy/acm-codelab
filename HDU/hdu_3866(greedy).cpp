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

//typedef __int64 ll;
typedef long long ll;

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

struct node
{
	int id, a;
};
node peo[ maxn ];

int pay[ maxn ];

bool cmp( const node &a, const node &b )
{
	if( a.a != b.a ) return a.a < b.a;
	return a.id > b.id;
}

int main(int argc, char *argv[])
{
	int cas, n, p;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d%d", &p, &n );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d", &peo[ i ].a );
			peo[ i ].id = i;
		}
		sort( peo, peo + n, cmp );
		for( int i = 0; i < n; i++ )
		{
			pay[ peo[ i ].id ] = min( peo[ i ].a, p / ( n - i ) );
			p -= pay[ peo[ i ].id ];
		}
		if( p ) printf( "IMPOSSIBLE\n" );
		else 
		{
			for( int i = 0; i < n; i++ )
				printf( "%d%c", pay[ i ], ( i == n - 1 ? '\n' : ' ' ) );
		}
	}
	return 0;
}
