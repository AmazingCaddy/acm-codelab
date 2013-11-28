#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1003;

int len;
double d[maxn], a[maxn];
int dp1[maxn], dp2[maxn];

int bin_search1( double k )
{
	int l = 1, r = len, mid;
	while( l <= r )
	{
		mid = ( l + r ) >> 1;
		if( d[mid] < k ) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

void LIS1( int n, int b[] )
{
	len = 1;
	d[len] = a[1];
	b[1] = 1;
	for( int i = 2; i <= n; i++ )
	{
		if( a[i] > d[len] ) d[++len] = a[i], b[i] = len;
		else
		{
			int t = bin_search1( a[i] );
			d[t] = a[i];
			b[i] = t;
		}
	}
}

void LIS2( int n, int b[] )
{
	len = 1;
	d[len] = a[n];
	b[n] = 1;
	for( int i = n - 1; i >= 1; i-- )
	{
		if( a[i] > d[len] ) d[++len] = a[i], b[i] = len;
		else
		{
			int t = bin_search1( a[i] );
			d[t] = a[i];
			b[i] = t;
		}
	}
}

int main(int argc, char *argv[])
{
	int n;
	while( scanf("%d",&n) != EOF )
	{
		for( int i = 1; i <= n; i++ )
			scanf("%lf",&a[i]);
		memset( dp1, 0, sizeof( dp1 ) );
		memset( dp2, 0, sizeof( dp2 ) );
		LIS1( n, dp1 );
		LIS2( n, dp2 );
		n++;
		dp1[0] = 0; dp1[n] = dp1[n-1];
		dp2[0] = dp2[1];   dp2[n] = 0;

		int max = 0;
		for( int i = 1; i <= n; i++ )
			for( int j = i + 1; j <= n; j++ )
				if( a[i] >= a[j] && dp1[i] + dp2[j] > max )
					max = dp1[i] + dp2[j];
		printf("%d\n",n - max - 1);
	}
	return 0;
}
