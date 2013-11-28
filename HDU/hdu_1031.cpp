/*
	author: AmazingCaddy
	time: 2011/5/5  20:14
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

typedef __int64 ll;

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

struct node
{
	int id;
	double h;
};

node a[ maxn ];

bool cmp1( const node & a, const node & b )
{
	if( a.h == b.h ) return a.id < b.id;
	return a.h > b.h;
}

bool cmp2( const node & a, const node & b )
{
	return a.id > b.id;
}

int main(int argc, char *argv[])
{
	int n, m, k;
	double x;
	while( scanf( "%d%d%d", &n, &m, &k ) != EOF )
	{
		for( int i = 0; i < m; i++ )
			a[ i ].id = i + 1, a[ i ].h = 0;
		for( int j = 0; j < n; j++ )
		{
			for( int i = 0; i < m; i++ )
			{
				scanf( "%lf", &x );
				a[ i ].h += x;
			}
		}
		sort( a, a + m, cmp1 );
		sort( a, a + k, cmp2 );
		for( int i = 0; i < k; i++ )
		{
			if( i ) printf( " " );
			printf( "%d", a[ i ].id );
		}
		printf( "\n" );
	}
	return 0;
}
