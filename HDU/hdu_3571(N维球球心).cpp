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

const ll p =   1000000000000000003LL;
const int maxn = 60;
const ll inf = 100000000000000000LL;

ll mod( ll a, ll n ) { return ( a % n + n ) % n; }

ll mul_mod ( ll a, ll b )
{ 
	ll ret = 0, tmp = a % p;
	while( b )
	{     
		if( b & 1 )
			if( ( ret += tmp ) >= p ) 
				ret -= p;     
		if( ( tmp <<= 1 ) >= p ) tmp -= p;  
		b >>= 1;   
	}  
	return ret;
}

void gcd( ll a, ll b, ll & d, ll & x, ll & y )
{
	if( ! b ) { d = a; x = 1; y = 0; }
	else
	{
		gcd( b, a % b, d, y, x );
		y -= x * ( a / b );
	}
}

ll inv( ll a, ll n ) 
{
	ll d, x, y;
	gcd( a, p, d, x, y );
	return d == 1 ? mod( x, p ) : -1;
}

ll ABS( ll a ) { return ( a < 0 ? -a : a ); }

int Gauss( int n, ll a[][maxn], ll b[] )
{
	int i, j, k, row;
	ll maxp, t;
	for( k = 0; k < n; k++ )
	{
		for( maxp = 0, i = k; i < n; i++ )
			if( ABS( a[i][k] ) > ABS( maxp ) )
				maxp = a[row=i][k];
		if( maxp == 0 ) return 0;
		if( row != k )
		{
			for( j = k; j < n; j++ )
				t = a[k][j], a[k][j] = a[row][j], a[row][j] = t;
			t = b[k], b[k] = b[row], b[row] = t;
		}
		ll INV = inv( maxp, p );
		for( j = k + 1; j < n; j++ )
		{
			a[k][j] = mul_mod( a[k][j], INV );
			for( i = k + 1; i < n; i++ )
				a[i][j] = mod( a[i][j] - mul_mod( a[i][k], a[k][j] ), p );
		}
		b[k] = mul_mod( b[k], INV );
		for( i = k + 1; i < n; i++ )
			b[i] = mod( b[i] - mul_mod( b[k], a[i][k] ), p );
	}
	for( i = n - 1; i >= 0; i-- )
		for( j = i + 1; j < n; j++ )
			b[i] = mod( b[i] - mul_mod( a[i][j], b[j] ), p );
	return 1;
}

int main(int argc, char *argv[])
{
	int cas, n;
	ll a[maxn][maxn], b[maxn], c[maxn][maxn], d[maxn];
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		scanf("%d",&n);
		for( int i = 0; i <= n; i++ )
		{
			b[i] = 0;
			for( int j = 0; j < n ; j++ )
			{
				scanf("%I64d",&a[i][j]);
				a[i][j] += inf;
				b[i] = ( b[i] + mul_mod( a[i][j], a[i][j] ) ) % p;
				a[i][j] = ( a[i][j] + a[i][j] ) % p;
			}
		}
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
				c[i][j] = mod( a[i][j] - a[n][j], p );
			d[i] = mod( b[i] - b[n], p );
		}
		Gauss( n, c, d );
		//gauss_cpivot( n, c, d );
		printf("Case %d:\n",t);
		printf("%I64d",d[0]-inf);
		for( int i = 1; i < n; i++ )
			printf(" %I64d",d[i]-inf);
		printf("\n");
	}
	return 0;
}
