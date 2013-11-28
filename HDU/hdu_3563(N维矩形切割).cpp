#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef __int64 ll;
const ll p = 14121413;
const int maxn = 50005;
struct cube
{
	int s[10], e[10];
	cube( )
	{ 
		memset( s, 0, sizeof( s ) );
		memset( e, 0, sizeof( e ) );
	}
};
cube C[maxn], D[maxn];
cube t;
int n, m, clen, dlen;

bool check( const cube & p, const cube & q )
{
	for( int i = 0; i < m; i++ )
		if( p.s[i] >= q.e[i] || p.e[i] <= q.s[i] )return false;
	return true;
}

void ins( const cube & p )
{
	for( int i = 0; i < m; i++ )
		if( p.s[i] >= p.e[i] ) return;
	D[dlen++] = p;
}

void broke( const cube & p, const cube & q )
{
	cube tmp;
	t = p;
	for( int i = 0; i < m; i++ )
	{
		if( t.s[i] <= q.s[i] && q.s[i] <= t.e[i] )
		{
			tmp = t;
			tmp.e[i] = q.s[i];
			ins( tmp );
			t.s[i] = q.s[i];
		}
		if( t.s[i] <= q.e[i] && q.e[i] <= t.e[i] )
		{
			tmp = t;
			tmp.s[i] = q.e[i];
			ins( tmp );
			t.e[i] = q.e[i];
		}
	}
}

void insert( const cube & p )
{
	dlen = 0;
	for( int i = 0; i < clen; i++ )
		if( check( C[i], p ) ) broke( C[i], p );
		else D[dlen++] = C[i];
	clen = 0;
	C[clen++] = p;
	for( int i = 0; i < dlen; i++ )
		C[clen++] = D[i];
}

void solve( )
{
	cube tmp;
	clen = 0;
	dlen = 0;
	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < m; j++ )
			scanf("%d",&tmp.s[j]);
		for( int j = 0; j < m; j++ )
			scanf("%d",&tmp.e[j]);
		insert( tmp );
	}
	ll ans = 0;
	for( int i = 0; i < clen; i++ )
	{
		ll k = 1;
		for( int j = 0; j < m; j++ )
			k = k * (ll)( C[i].e[j] - C[i].s[j] ) % p;
		ans = ( ans + k ) % p;
	}
	printf("%I64d\n",ans);
}

int main(int argc, char *argv[])
{
	freopen("jesus.in","r",stdin);
	freopen("out.txt","w",stdout);
	while( scanf("%d%d",&n,&m) != EOF )
	{
		solve( );
	}
	return 0;
}
