#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 200020;
int st[maxn][20];
int D[maxn];
int base[maxn];
int n, k;
int max( int a, int b )
{
	return D[a] > D[b] ? a : b;
	//return a > b ? a : b;
}

void ST( int n )
{
	for( int i = 0; i <= n; i++ )
		st[i][0] = i;
		// st[i][0] = D[i];
	int now = 0 ;
	for( int i = 1 ; i <= n; i++ )
	{
		if( ( 1 << ( now + 1 ) ) <= i ) now++;
		base[i] = now;
	}
	for( int j = 1; ( 1 << j ) <= n; j++ )
		for( int i = 1; i + ( 1 << j ) - 1 <= n; i++ )
			st[i][j] = max( st[i][j-1], st[i+(1<<(j-1))][j-1] );
}

int RMQ( int l, int r )
{
	int k = base[r-l+1];
	int t = max( st[l][k], st[r-(1<<k)+1][k] );
	return t;
}

bool check( int x, int & ans )
{
	int len = n / x;
	int sum = 0;
	int l = 1, r = x;
	for( int i = 1; i <= len; i++ )
	{
		sum += D[RMQ( l, r )];
		if( sum > k )
		{
			ans = i;
			return true;
		}
		l = l + x,  r = r + x;
	}
	ans = len;
	return false;
}

int main( )
{
	int ans, i;
	while( scanf("%d%d",&n,&k) && ( n > 0 && k > 0 ) )
	{
		for( i = 1; i <= n; i++ )
		{
			scanf("%d",&D[i]);
		}
		ST( n );
		for( i = 1; i <= n;  )
		{
			if( check( n / i, ans ) )
			{
				break;
			}
			else i = ans + 1;
		}
		if( i == n + 1 )printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
