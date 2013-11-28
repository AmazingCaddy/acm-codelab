#include <cstdio>
#include <iostream>
#include <cstring>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef complex<double> point;

const int maxn = 90010;
int a[maxn], b[maxn];

int merge_sort( int l, int r )
{
	int c = 0;
	if( l < r )
	{
		int mid = ( l + r ) >> 1;
		c = merge_sort( l, mid ) + merge_sort( mid + 1, r );
		int i = l, j = mid + 1, k = l;
		while( i <= mid || j <= r )
		{
			if( i <= mid && ( j > r || a[i] <= a[j] ) )
			{
				b[k] = a[i];
				i++;
				c += j - mid - 1;
			}
			else 
			{
				b[k] = a[j];
				j++;
			}
			k++;
		}
		for( int i = l; i <= r; i++ )
			a[i] = b[i];
	}
	return c;
}

int main(int argc, char *argv[])
{
	int k, len, n;
	while( scanf("%d",&n) && n )
	{
		len = 0;  k = -1;
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				scanf("%d",&a[len]);
				if( a[len] == 0 ) k = i;
				else len++;
			}
		}
		//printf("len %d k %d\n",len, k);
		int cnt = merge_sort( 0, len - 1 );
		n -= k + 1;
		if( cnt % 2 == n % 2 ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
