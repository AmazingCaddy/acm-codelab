#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef __int64 ll;
// ans = C( m + n, m ) - C( m + n, m - 1 ) ( mod 20100501 )
// C( m + n, m ) - C( m + n, m - 1 ) = (m+n)! /( m!*(n+1)! )*(n-m+1)
// 由于20100501不是square-free-number，不能使用Lucas定理
// n 并不是很大，故可以使用分解质因数的办法来做。
const int maxn = 2000003;
const int P = 20100501;
int p[maxn], vis[maxn];
int len;
int cnt[maxn];

void prime( )
{
	ll i, j, k;
	memset( vis, 0, sizeof( vis ) );
	for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[i] )
		{
			p[len++] = i;
			if( k < maxn )
			{
				for( j = k; j < maxn; j += i )
					vis[j] = 1;
			}
		}    
	}
}

ll pow_mod( ll a, int b )
{
	ll ans = 1, d = a % P;
	while( b )
	{
		if( b & 1 ) ans = ans * d % P;
		d = d * d % P;
		b >>= 1;
	}
	return ans;
}

void f1( int n )
{
	for( int i = 0; i < len && p[i] <= n; i++ )
	{
		int t = n;
		while( t )
		{
			t /= p[i];
			cnt[i] += t;
		}
	}
}

void f2( int n )
{
	for( int i = 0; i < len && p[i] <= n; i++ )
	{
		int t = n;
		while( t )
		{
			t /= p[i];
			cnt[i] -= t;
		}
	}
}

int solve( int n, int m )
{
	//int nn = n, mm = m;
	ll ans1, ans2;
	memset( cnt, 0, sizeof( cnt ) );
	f1( n + m );
	f2( n + 1 );
	f2( m );
	int tmp = n + 1 - m;
	for( int i = 0; tmp > 1 && i < len && p[i] <= tmp; i ++)
		while(tmp > 1 && tmp % p[i] == 0)
			cnt[i]++, tmp /= p[i];
	ans1 = 1;
	for( int i = 0; i < len; i++ )
		ans1 = ans1 * pow_mod( p[i], cnt[i] ) % P;
	return ans1;
}

int main(int argc, char *argv[])
{
	int n, m, t;
	len = 0;
	prime( );
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&n,&m);
		int ans = solve( n, m );
		printf("%d\n",ans);
	}
	return 0;
}
