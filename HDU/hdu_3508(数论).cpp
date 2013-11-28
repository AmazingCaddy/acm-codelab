// 求解 小于n且与互素的数的乘积模上n的值
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;
typedef __int64 ll;
const int maxn = 34000;
int p[maxn>>1], vis[maxn], plen;
int fac[40], flen, num[40];

set<int> ans;

void prime( )
{
	int i, j, k;
	plen = 0;
	memset( vis, 0, sizeof( vis ) );
	for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[i] )
		{
			p[plen++] = i;
			if( k < maxn )
			for( j = k; j < maxn; j += i ) vis[j] = 1;
		}
	}
}

void Fac( int n )
{
	flen = 0;
	for( int i = 0; p[i] * p[i] <= n; i++ )
	{
		if( !( n % p[i] ) )
		{
			fac[flen] = 1;
			while( !( n % p[i] ) ) fac[flen] *= p[i], n /= p[i];
			flen++;
		}
	}
	if( n > 1 ) fac[flen++] = n;
}

void ex_gcd( int a, int b, int &d, int &x, int &y )
{
	if( !b ) { d = a; x = 1; y = 0; }
	else
	{
		ex_gcd( b, a % b, d, y, x );
		y -= x * ( a / b );
	}
}

bool merge( int m1, int c1, int m2, int c2, int & m, int & c, int & d )
{
	int x, y;
	ex_gcd( m1, m2, d, x, y );
	c = c2 - c1;
	if( c % d ) return false;
	c /= d;
	m = (ll) m1 * m2 / d;
	c = ( (ll)c * x * m1 + c1 ) % m;
	c = ( c + m ) % m;
	return true;
}

// x = 1 mod p, x = -1 mod q;
void add( int p, int q )
{
	int c1 = 1, c2 = -1;
	int m1 = p, m2 = q;
	int d, m, c;
	if( merge( m1, c1, m2, c2, m, c, d ) ) 
	{
		ans.insert( c );
		if( d == 2 )
			ans.insert( ( c + m ) % ( d * m ) );
	}
}

void dfs( int dep, int p, int q )
{
	if( dep == flen )
	{
		add( p, q );
		return;
	}
	if( fac[dep] % 2 == 0 && fac[dep] > 2 )
	{
		dfs( dep + 1, p * fac[dep] / 2, q * 2 );
		dfs( dep + 1, p * 2, q * fac[dep] / 2 );
	}
	dfs( dep + 1, p * fac[dep], q );
	dfs( dep + 1, p, q * fac[dep] );
}

int main(int argc, char *argv[])
{
	//freopen("data.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	prime( );
	while( scanf("%d",&n) != EOF )
	{
		ans.clear( );
		Fac( n );
		dfs( 0, 1, 1 );
		ll ret = 1;
		for( set<int>::iterator it = ans.begin(); it != ans.end(); it++ )
			ret = ret * ( *it ) % n;
		printf("%I64d\n",ret);
	}
	return 0;
}
