#include<iostream>
#include<cmath>
#define MAXN 350
using namespace std;
typedef unsigned __int64 llu;
typedef __int64 ll;
ll Mod[MAXN],ans[MAXN],f[MAXN][1600];
int visit[MAXN];
llu A, B, N;
ll C;

void init( )
{
	llu i,j,n;
	Mod[1] = 1; f[1][0] = 0;
	for( j = 2; j <= 300; j++ )
	{
		n = j;
		f[j][0] = 0, f[j][1] = 1;
		for( i = 2; ; i++ )
		{
			f[j][i] = ( f[j][i-1] + f[j][i-2] ) % n;
			if( f[j][i] == 1 && f[j][i-1] == 0 )
			{
				Mod[j] = i - 1;
				break;
			}
		}
	}
}

ll mul_mod( llu a, llu b, llu m ) //t有可能达到2m-1 所以 m < 2^63 
{
	ll t=0;
	a %= m, b %= m;
	while( b )
	{
		if( b & 1 ){ t += a; if( t>= m ) t -= m; }
		a += a; if( a >= m ) a -= m; b >>= 1;
	}
	return ll(t);
}

ll pow_mod( llu a, llu n, ll p )
{
	ll ans = 1, d = a % p;
	do{
		if( n & 1 ) ans = mul_mod( ans, d, p );
		d = mul_mod( d, d, p );
	}while( n >>= 1 );
	return ans;
}
//  寻找循环节  D^P = D^(T+P)( mod C );
void find_cycle( ll D, ll p, ll &T, ll &P )
{
	int vis[MAXN];
	ll i, x = 1;
	for( i = 0; i <= 300; i++ ) vis[i] = 0;
	for( vis[1] = 1, i = 2 ; ; vis[x] = i, i++ )
	{
		x = x * D % p;
		if( vis[x] )
		{
			T = i - vis[x];
			P = vis[x] - 1;
			return ;
		}
	}
}

void solve( ll &CYCLE, ll &Point )
{
	ll T, P, i, tem;
	memset( visit, 0, sizeof( visit ) );
	ans[1] = f[C][pow_mod( A, B, Mod[C])];
	visit[ans[1]] = 1;
	for( i = 2; ; visit[ans[i]] = i, i++ )
	{
		find_cycle( ans[i-1], C, T, P ); 

		// loop: (P+1)...(P+T)
		tem = ( f[T][pow_mod( A, B, Mod[T] )] - P % T + T ) % T;
		if( tem == 0 ) tem = T; 
		tem += P;
		ans[i] = pow_mod( ans[i-1], tem, C );
		if( visit[ans[i]] )
		{
			CYCLE = i - visit[ans[i]];
			Point = visit[ans[i]] - 1;
			return ;
		}
	}
}

int main( )
{
	init( );
	ll T, cas, CYCLE, Point;
	for(cin>>T, cas = 1; cas <= T; cas++ )
	{  
		scanf("%I64u%I64u%I64u%I64d",&A, &B, &N, &C);
		solve(CYCLE, Point);
		if( N > Point )
		{
			N -= Point;
			N %= CYCLE;
			if( N == 0 ) N = CYCLE;
			N += Point;
		}
		printf("Case %I64d: %I64d\n",cas,ans[N]);
	}
}
