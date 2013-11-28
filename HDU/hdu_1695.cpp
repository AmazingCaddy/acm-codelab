#include<iostream>
using namespace std;
typedef __int64 ll;
const int maxn = 1010;
int p[maxn], phi[maxn];
bool vis[maxn];
int len,cnt,d[]={-1,1};
int a[40],b[40];
ll min( ll a, ll b ){ return a > b ? b : a; }
void prime( )
{
	int i,j,k;
	len=0;
	memset( vis, false, sizeof( vis ) );
	for( i = 2, k = 4; i < maxn; ++i, k += i+i-1 )
	{
		if( !vis[i] )
		{
			p[len++]=i;
			if( k < maxn ) for( j = k; j < maxn; j += i ) vis[j] = true;
		}
	}
}
void factor( int n, int &j )
{
	int i;
	for( j = 0, i = 0; p[i] * p[i] <= n; i++ )
	{
		if( n % p[i] == 0 )
		{
			for( ; n % p[i] == 0; n /= p[i] );
			a[j++] = p[i];
		}
	}
	if( n > 1 ) a[j++] = n;
}
int compute( int c, int b )
{
	int i,q,j,k,m;
	int ans = 0, sum;
	factor( c, m );
	for( i = 1; i < ( 1<<m ); i++ )
	{
		q = i; j = 0; k = 0; sum = 1;
		while( q )
		{
			if( q & 1 ) sum *= a[k], j++;
			k++;
			q >>= 1;
		}
		ans = ans + d[j%2] * b / sum;
	}
	return b - ans;
}
ll solve( int b, int d, int k )
{
	int i, tmp;
	ll ans;
	if( k == 0 )return 0;
	b /= k, d /= k;
	if( b > d ) tmp = d, d = b, b = tmp;  // ʹ d > b
	ans = 0;
	for( i = 1; i <= d; i++ )
		ans += compute( i, min( i, b ) );
	return ans;
}
int main( )
{
	int t,i = 1;
	int a,b,c,d,k;
	ll ans;
	prime( );
	scanf("%d",&t);
	while( t-- )
	{ 
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		ans = solve( b, d, k );
		printf("Case %d: %I64d\n",i++,ans);
	}
	return 0;
}
