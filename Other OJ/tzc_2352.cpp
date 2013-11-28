#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;
typedef __int64 ll;

const int maxn = 66000;
bool vis[ maxn ];
ll p[ maxn ];
int plen, flen;
int a[ 65 ], b[ 65 ];

void prime( )
{
	ll i, j, k;
	plen = 0;
	memset( vis, false, sizeof( vis ) );
	for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[i] )
		{
			p[ plen++ ] = i;
			if( k < maxn ) for( j = k; j < maxn; j += i ) vis[ j ] = true;
		}
	}
}

void num_factor( ll n )   //在有素数表的前提下的素因数分解
{
	int i;
	flen = 0;
	for( i = 0; p[ i ] * p[ i ] <= n; i++ )
	{
		if( n % p[ i ] == 0 )
		{
			for( b[ flen ] = 0; n % p[ i ] == 0; ++b[ flen ], n /= p[ i ] );
			a[ flen++ ] = p[ i ];
		}
	}
	if( n > 1 ) b[ flen ] = 1, a[ flen++ ] = n;
}

int factor( ll n, ll p )
{
	int sum = 0;
	while( n )
	{
		n /= p;
		sum += n;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	ll n, m;
	prime( );
	while( scanf("%I64d %I64d",&n,&m) != EOF )
	{
		if( m == 0 )
		{
			printf("0 does not divide %I64d!\n",n);
			continue;
		}
		num_factor( m );
		int flag = 0;
		for( int i = 0; i < flen; i++ )
		{
			int tmp = factor( n, a[ i ] );
			if( tmp < b[ i ] ) { flag = 1; break; }
		}
		if( flag ) printf("%I64d does not divide %I64d!\n",m,n);
		else printf("%I64d divides %I64d!\n",m,n);
	}
	return 0;
}
