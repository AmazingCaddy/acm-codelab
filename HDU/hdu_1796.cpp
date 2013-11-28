#include<iostream>
using namespace std;
typedef __int64 ll;
int num[20],d[]={-1,1};
ll gcd( ll a, ll b ){ return b ? gcd( b, a % b ): a; }
ll lcm( ll a, ll b ){ return a * b / gcd( a, b ); }
ll rongchi( int n, int m )
{
	int i,j,p,q,len = 1 << m;
	ll sum = 0, k;
	for( i = 1; i < len; i++ )
	{
		q = i; j = 0; k = 1; p = 0;
		while( q )
		{
			if( q & 1 ){ k = lcm( k, num[j] ); p++; }
			j++;
			q >>= 1;
		}
		sum = sum + d[p%2] * n / k;
	}
	return sum;
}
int main( )
{
	int i,j,n,m,ans;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		for( i = 0; i < m; i++ )
			scanf("%d",&num[i]);
		for( j = 0, i = 0; i < m; i++ )
			if( num[i] ) num[j++] = num[i];
		//ans = dfs( 0, n, j, 1 );
		ans = rongchi( n - 1, j );
		printf("%d\n",ans);
	}
	return 0;
}