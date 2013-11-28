#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100;
struct node
{
	int x, y, z;
	bool operator<( const node & b )
	{
		return y * z < b.y * b.z ;
	}
};
node b[maxn];
int dp[maxn];
int main( )
{
	int n, i, j, k = 1, ans, x, y, z, t1, t2, t3;
	while( scanf("%d",&n) && n )
	{
		t1 = 0, t2 = 1, t3 = 2;
		for( i = 0; i < n; i++ )
		{
			scanf("%d%d%d",&x,&y,&z);
			b[t1].x = x, b[t1].y = y, b[t1].z = z;
			b[t2].x = y, b[t2].y = x, b[t2].z = z;
			b[t3].x = z, b[t3].y = y, b[t3].z = x;
			t1 += 3,     t2 += 3,     t3 += 3;
		}
		n = n * 3;
		sort( b, b + n );
		memset( dp, 0, sizeof( dp ) );
		dp[0] = b[0].x;
		for( i = 1; i < n; i++ )
		{
			for( j = 0; j < i; j++ )
				if( b[j].y < b[i].y && b[j].z < b[i].z || b[j].z < b[i].y && b[j].y < b[i].z )
					if( dp[j] > dp[i] ) dp[i] = dp[j];
			dp[i] += b[i].x;
		}
		for( ans = 0, i = 0; i < n; i++ )
			if( dp[i] > ans )
				ans = dp[i];
		printf("Case %d: maximum height = %d\n",k++, ans);
	}
	return 0;
}