/*
	author: AmazingCaddy
	time:	2011-07-07 15:36:05 
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
	int time;
	int id;
};
int fen[ maxn ];
vector<node> stu[ 6 ];

bool cmp( const node &a, const node &b )
{
	return a.time < b.time;
}

int main(int argc, char *argv[])
{
	int n, t, hh, mm, ss;
	while( scanf( "%d", &n ) && n != -1 )
	{
		for( int i = 0; i <= 5; i++ )
			stu[ i ].clear( );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d %d:%d:%d", &t, &hh, &mm, &ss );
			node tmp;
			tmp.time = ( hh * 60 + mm ) * 60 + ss;
			tmp.id = i;
			stu[ t ].push_back( tmp );
		}
		for( int i = 0; i <= 5; i++ )
		{
			if( stu[ i ].size( ) == 0 ) continue;
			sort( stu[ i ].begin( ), stu[ i ].end( ), cmp );
			int sz = stu[ i ].size( );
			for( int j = 0; j < sz / 2; j++ )
			{
				fen[ stu[ i ][ j ].id ] = 55 + i * 10;
				if( fen[ stu[ i ][ j ].id ] == 105 ) fen[ stu[ i ][ j ].id ] -= 5;
				if( fen[ stu[ i ][ j ].id ] == 55 ) fen[ stu[ i ][ j ].id ] -= 5;
			}
			for( int j = sz / 2; j < sz; j++ )
			{
				fen[ stu[ i ][ j ].id ] = 50 + i * 10;
			}
		}
		for( int i = 0; i < n; i++ )
			printf( "%d\n", fen[ i ] );
		printf( "\n" );
	}	
	return 0;
}
