#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1003;
int len, n, d[maxn], a[maxn];
int bin_search( int k )
{
	int l = 1, r= len - 1, mid;
	while( l <= r )
	{
		mid = ( l + r ) >> 1;
		if( d[mid] < k ) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

void LIS( )
{
	len = 1;
	d[len] = a[0];
	for( int i = 1; i < n; i++ )
	{
		if( a[i] > d[len] ) d[++len] = a[i];
		else
		{
			int t = bin_search( a[i] );
			d[t] = a[i];
		}
	}
}

int main(int argc, char *argv[])
{
	while( scanf("%d",&n) != EOF )
	{
		for( int i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		LIS( );
		printf("%d\n",len);
	}
	return 0;
}
