#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstdio>
using namespace std;
typedef __int64 ll;

ll gcd( ll a, ll b ){ return b==0 ? a : gcd( b, a%b ); }

void gcd( ll a, ll b, ll &d, ll &x, ll &y )
{
	if( !b ){ d=a; x=1; y=0; }
	else 
	{
		gcd( b, a%b, d, y, x );
		y -= x * ( a / b );
	}
}

ll inv( ll a, ll n )
{
	ll d,x,y;
	gcd( a, n, d, x, y );
	return ( d==1 ? ( x % n + n ) % n : -1 );
}

ll pow_mod( ll a, ll n, ll p )
{
	ll ans = 1, d = a % p;
	do
	{
		if( n & 1 ) ans = ans * d % p;
		d = d * d % p;
	}while( n >>= 1 );
	return ans;
}

const int maxn = 131071;
int cnt;
struct HashItem
{
	int a,b;
	HashItem *next;
};

HashItem *Hash[maxn];
HashItem hash[80005];

void init_hash( )
{
	int i;
	for( i = 0; i < maxn; i++ ) Hash[i] = NULL;
	cnt = 0;
}

void insert_hash( int a, int b )
{
	int id = a % maxn;
	hash[cnt].a = a;
	hash[cnt].b = b;
	if( Hash[id] == NULL )
	{
		Hash[id] = &hash[cnt];
		hash[cnt++].next = NULL;
	}
	else 
	{
		hash[cnt].next = Hash[id];
		Hash[id] = &hash[cnt++];
	}
}

int get_hash( int a )
{
	int id = a % maxn;
	HashItem *p = Hash[id];
	while( p != NULL )
	{
		if( p->a == a ) return p->b;
		p = p->next;
	}
	return -1;
}

ll log_mod( ll a, ll b, ll n )
{
	ll m,v,e,i;
	init_hash( );
	m = ( ll )ceil( sqrt( 1.0 * n ) );
	v = inv( pow_mod( a, m, n ), n );
	e = 1;
	for( i=1; i<=m; i++ )
	{
		e = e * a % n;
		if( get_hash( b ) == -1 )
			insert_hash( e, i );
	}
	for( i=0; i<m; i++ )
	{
		if( ( e = get_hash( b ) ) != -1 ) return i * m + e;
		b = b * v % n;
	}
	return -1;
}

// 离散对数 a^x=b( mod n )，x返回大于0的值（有解时）
ll non_prime_log_mod( ll a, ll b, ll n )
{
	ll g, r=0;
	while( ( g = gcd( a, n ) ) != 1 )
	{
		if( b % g != 0 )return -1;
		n /= g;
		b /= g;
		b = b * inv( a / g, n ) % n;
		r++;
		if( b == 1%n )return r;
	}
	if( r != 0 && 1 % n == b )return r;
	if( ( g = log_mod( a, b, n ) ) == -1 )return -1;
	return g + r;
}

int main( )
{
	ll K, P, N, D;
	while( scanf( "%I64d %I64d %I64d", &K, &P, &N ) != EOF )
	{
		if( N >= P ) printf( "Orz,I can’t find D!\n" );
		else
		{
			ll D = non_prime_log_mod( K, N, P );
			if( D == -1 ) printf( "Orz,I can’t find D!\n" );
			else printf( "%I64d\n", D );
		}
	}
	return 0;
}