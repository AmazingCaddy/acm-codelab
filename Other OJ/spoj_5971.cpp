#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1010;
int p[maxn], vis[maxn], plen;
int num[40], fac[40], flen;
ll ans;
int phi[1000010];

void prime( )
{
	int i, j, k;
	plen = 0;
	memset( vis, 0, sizeof( vis ) );
	for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[i] )
		{
			p[plen++] = i;
			if( k < maxn ) for( j = k; j < maxn; j += i ) vis[j] = 1;
		}
	}
}

void all_phi( int n )
{
	int i, j;
	memset( phi, 0, sizeof( phi ) );
	phi[1] = 1;
	for( i = 2; i <= n; i++ )
	{
		if( !phi[i] )   //prime
			for( j = i; j <= n; j += i )  // for each multiple
			{
				if( !phi[j] ) phi[j] = j;  // first time , initialize
				phi[j] = phi[j] / i * ( i - 1 );
			}
	}
}

void init( )
{
	prime( );
	all_phi( 1000000 );
}

void dfs( int dep, int k )
{
	if( dep == flen )
	{
		ans += (ll)phi[k] * k / 2;
		return;
	}
	ll tmp = 1;
	for( int i = 0; i <= num[dep]; i++ )
	{
		dfs( dep + 1, k * tmp );
		tmp *= fac[dep];
	}
}

int main(int argc, char *argv[])
{
	int t, n, nn, i;
	init( );
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		nn = n;
		flen = 0;
		for( i = 0; p[i] * p[i] <= n; i++ )
		{
			if( !( n % p[i] ) )
			{
				for( num[flen] = 0; n % p[i] == 0; ++num[flen], n /= p[i] );
				fac[flen++] = p[i];
			}
		}
		if( n > 1 ) num[flen] = 1, fac[flen++] = n;
		ans = 0;
		dfs( 0, 1 );
		printf("%lld\n",(ans+1)*nn);
	}
	return 0;
}
