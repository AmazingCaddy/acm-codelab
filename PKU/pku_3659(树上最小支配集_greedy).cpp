/*
	author: AmazingCaddy
	time: 2011/5/10  14:43
	����: ����һ����(����ͼ),����������ѡ�����, 
	�����Ƿ�ΧΪ��ǰ������ڵĵ�,����С�����������е�
	
	����: �����ϵ���С֧�伯
	��ǰ�����һ�ζԽ����б�־,Ȼ���n��1����O(n)̰��.
	ÿ��ѡȡ��û���ǵĵ�,�ڸõ�ĸ��׽�����.
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

const int maxn = 10004;
int vis[ maxn ], id[ maxn ], f[ maxn ], set[ maxn ];
int head[ maxn ], e[ maxn << 1 ], next[ maxn << 1 ];
int len;

void init( )
{
	len = 0;
	memset( head, 0, sizeof( head ) );
}

void add( int u, int v )
{
	next[ ++len ] = head[ u ];
	head[ u ] = len;
	e[ len ] = v;
}

int num;

void DFS( int u )
{
	vis[ u ] = 1;
	id[ u ] = num++;
	for( int i = head[ u ]; i ; i = next[ i ] )
	{
		int v = e[ i ];
		if( !vis[ v ] )
		{
			DFS( v );
			f[ id[ v ] ] = id[ u ];
		}
	}
}

int main(int argc, char *argv[])
{
	int u, v, n;
	scanf( "%d", &n );
	init( );
	for( int i = 1; i < n; i++ )
	{
		scanf( "%d%d", &u, &v );
		add( u, v );
		add( v, u );
	}
	num = 1;
	memset( f, 0, sizeof( f ) );
	memset( vis, 0, sizeof( vis ) );
	DFS( 1 );
	memset( set, 0, sizeof( set ) );
	memset( vis, 0, sizeof( vis ) );

	int ans = 0;
	for( int i = n; i>= 1; i-- )
	{
		if( !vis[ i ] )
		{
			if( !set[ f[ i ] ] )
			{
				ans++;
				set[ f[ i ] ] = 1;
			}
			vis[ i ] = 1;
			vis[ f[ i ] ] = 1;
			vis[ f[ f[ i ] ] ] = 1;
		}
	}

	printf( "%d\n", ans );
	return 0;
}
