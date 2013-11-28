#include<iostream>
using namespace std;
const int maxn = 1000006;
int a[maxn];
int b[maxn];

int main( )
{
	int n, t, i, k, len = 0, ans, cnt;
	scanf("%d",&t);
	scanf("%d",&n);
	memset( b, 0, sizeof( b ) );
	for( ans = 0, i = 0; i < n; i++ )
	{
		scanf("%d",&a[i]);
		if( a[i] >= 0 )
		{
			ans += a[i];
			if( b[len] >= 0 )
				b[len] += a[i];
			else b[++len] = a[i];
		}
		else b[++len] = a[i];
	}
	for( cnt = 0, i = 0; i <= len; i++ )
		if( b[i] > 0 ) cnt++;
	printf("Case %d:\n%d %d\n",1, cnt, ans );
	for( k = 2; k <= t; k++ )
	{
		scanf("%d",&n);
		memset( b, 0, sizeof( b ) );
		for( len = 0, ans = 0, i = 0; i < n; i++ )
		{
			scanf("%d",&a[i]);
			if( a[i] >= 0 )
			{
				ans += a[i];
				if( b[len] >= 0 )
					b[len] += a[i];
				else b[++len] = a[i];
			}
			else b[++len] = a[i];
		}
		for( cnt = 0, i = 0; i <= len; i++ )
			if( b[i] > 0 ) cnt++;
		printf("\nCase %d:\n%d %d\n",k, cnt, ans );
	}
	return 0;
}