/*
	author: wwb
	time: 2011/2/27  17:38
	�ⷨ��polya  sum=sigma(Euler(n/i)*Gettr(i)){ i|n }
	��Ҫ�Ǽ���Gettr(i)������
	���ǰ�m����ɫ�Ĺ�ϵ����һ������ͼ����Gettr(i)���ǳ���Ϊ i �Ļ�·�ĸ���
	������ͼ��ʾ���ڽӾ��� G[maxn][maxn]��
	Gettr(i)������������ i ���ݵļ���Ҳ���� Tr(G^i)
	����������ɫ��ͬ�����ڽ���GΪ�Խ�����Ԫ��ȫΪ0������Ԫ��ȫΪ1��
	Trace(G^n)=(p-1)^n+(-1)^n*(p-1)
	����p��G�Ľ�����Ҳ����K-1
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef __int64 ll;
const ll P = 1000000007;
const int maxn = 32000;

int vis[ maxn ], p[ maxn ];
int a[ 32 ], b[ 32 ];
int plen, flen;
int N, K;
ll ANS;

void prime( )
{
	int i, j, k;
	plen = 0;
	memset( vis, 0, sizeof( vis ) );
	for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
		{
			p[ plen++ ] = i;
			if( k < maxn ) for( j = k; j < maxn; j += i ) vis[ j ] = 1;
		}
	}
}

int elur( int n )
{
	int phi = n;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			while( n % p[ i ] == 0 ) n /= p[ i ];
			phi -= phi / p[ i ];
		}
	}
	if( n > 1 ) phi -= phi / n;
	return phi;
}

void factor( int n )
{
	flen = 0;
	for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			for( b[ flen ] = 0; n % p[ i ] == 0; ++b[ flen ], n /= p[ i ] );
			a[ flen++ ] = p[ i ];
		}
	}
	if( n > 1 ) b[ flen ] = 1, a[ flen++ ] = n;
}

ll pow_mod( ll a, ll b, ll c )
{
	ll ans = 1, d = a % c;
	while( b )
	{
		if( b & 1 ) ans = ans * d % c;
		d = d * d % c;
		b >>= 1;
	}
	return ans;
}

ll Mod( ll a, ll b )
{
	return ( a % b + b ) % b;
}

ll inv( ll n )
{
	return pow_mod( n, P - 2, P );
}

ll Trace( int n, int col_num )
{
	ll a = col_num - 1;
	return Mod( pow_mod( a, n, P ) + ( n % 2 ? -1 : 1 ) * a, P );
}

void DFS( int dep, int t )
{
	if( dep == flen )
	{
		ANS = ( ANS + (ll)elur( N / t ) * Trace( t, K - 1 ) % P ) % P;
		return;
	}
	for( int tmp = 1, i = 0; i <= b[ dep ]; tmp *= a[ dep ], i++ )
		DFS( dep + 1, t * tmp );
}

int main(int argc, char *argv[])
{
	prime( );
	while( scanf( "%d%d", &N, &K ) != EOF )
	{
		factor( N );
		ANS = 0;
		DFS( 0, 1 );
		ANS = ANS * inv( N ) % P;
		ANS = ANS * K % P;
		printf( "%I64d\n", ANS );
	}
	return 0;
}
