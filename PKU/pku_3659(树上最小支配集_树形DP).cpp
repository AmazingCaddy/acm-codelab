/*
	author: AmazingCaddy
	time: 2011/5/10  14:43
	����: ����һ����(����ͼ),����������ѡ�����, 
	�����Ƿ�ΧΪ��ǰ������ڵĵ�,����С�����������е�
	
	����: �����ϵ���С֧�伯 ����DP
	dp[ i ][ 0 ], ��ʾ�õ㲻����, �ұ����Ƚ�㸲��
	dp[ i ][ 1 ], ��ʾ�õ㲻����, �������ȸ���
	dp[ i ][ 2 ], ����

	uΪi���ӽ��dp[ i ][ 0 ] = sum( min( dp[ u ][ 1 ], dp[ u ][ 2 ] ) );
	dp[ i ][ 2 ] = sum( min( dp[ u ][ 0 ], dp[ u ][ 2 ] ) ) + 1;
	dp[ i ][ 1 ] ������ӽڵ���������һ�����Ƿ���, ������ dp[ u ][ 2 ] <= dp[ u ][ 1 ] 
	��ô dp[ i ][ 1 ] = sum( min( dp[ u ][ 1 ], dp[ u ][ 2 ] ) );
	���� ö������һ���ӽ��, �ڸý�����( dp[ u ][ 2 ] ),�����Ա���dp[ u ][ 1 ]״̬
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
const int inf  = 10000000;

int vis[ maxn ], id[ maxn ], f[ maxn ], set[ maxn ];
int head[ maxn ], e[ maxn << 1 ], next[ maxn << 1 ];
int len;
int dp[ maxn ][ 3 ];

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

int Min( int a, int b ) { return ( a < b ? a : b ); }

void DFS( int u )
{
	vis[ u ] = 1;
	if( head[ u ] == 0 )
	{
		dp[ u ][ 0 ] = 0;
		dp[ u ][ 1 ] = inf;
		dp[ u ][ 2 ] = 1;
		return;
	}
	int sum[ 3 ] = { 0 }, off = inf;
	for( int i = head[ u ]; i ; i = next[ i ] )
	{
		int v = e[ i ];
		if( !vis[ v ] )
		{
			DFS( v );
			sum[ 0 ] += Min( dp[ v ][ 1 ], dp[ v ][ 2 ] );
			sum[ 2 ] += Min( dp[ v ][ 0 ], dp[ v ][ 2 ] );
			off = Min( off, dp[ v ][ 2 ] - dp[ v ][ 1 ] );
			// ���off <= 0 ����� dp[ v ][ 2 ] <= dp[ v ][ 1 ]
		}
	}
	dp[ u ][ 0 ] = sum[ 0 ];
	dp[ u ][ 1 ] = sum[ 0 ];
	dp[ u ][ 2 ] = sum[ 2 ] + 1;
	if( off > 0 ) dp[ u ][ 1 ] = sum[ 0 ] + off;
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
	DFS( 1 );
	printf( "%d\n", Min( dp[ 1 ][ 1 ], dp[ 1 ][ 2 ] ) );
	return 0;
}
