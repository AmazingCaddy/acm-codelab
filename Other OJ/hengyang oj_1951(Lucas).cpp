// C( A, B ) % P
// P = p1 * p2 * ... * pj
// B = mk * pj ^ k + mk-1 * pj ^ (k-1) + ... + m1 * pj + m0
// A = nk * pj ^ k + nk-1 * pj ^ (k-1) + ... + n1 * pj + n0

#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int P = 999911659;
const int maxn = 36000;
int b[5] = { 0, 0, 0, 0 };
int w[5] = { 2, 3, 4679, 35617 }; // 999911658 = 2 * 3 * 4679 * 35617 ;
int s[2][101];
int c[4][maxn];  // 用于保存 ( n! ) mod wi( i = 0, 1, 2, 3 )
int N, G;

void Extend_Eulid( int a, int b, int &d, int &x, int &y )// ax+by=gcd(a,b);
{
	if( !b ){ d = a; x = 1; y = 0; }
	else 
	{
		Extend_Eulid( b, a % b, d, y, x );
		y -= x * ( a / b );
	}
}

int china( int n , int a[], int m[] )// X mod m[i]=a[i] ，求解 X ,m[i]两两互素 
{
	int i, w;
	int M = 1, d, y, x;
	for( i = 0; i < n; i++ ) M = M * m[i];
	ll X = 0;
	for( i = 0; i < n; i++ )
	{
		w = M / m[i];
		Extend_Eulid( m[i], w, d, x, y );      // don 't care about others
		X = ( X + (ll)y * w * a[i] ) % M;      // accumulate e*的和a
	}
	return ( M + X % M ) % M; // adjust to [0,M-1]
}

// ans = a ^ b mod p ;
int pow_mod( ll a, int b, int p )
{
	ll ans = 1, d = a % p;
	while( b )
	{
		if( b & 1 ) ans = ans * d % p;
		d = d * d % p;
		b >>= 1;
	}
	return ans;
}

// c( n, k ) = n! / k! / (n-k)!
int cnk( int a, int b, int cur )
{
	int ans = c[cur][a], p = w[cur];
	ans = ans * pow_mod( c[cur][b], p - 2, p ) % p;    // 求 k! mod p 的逆元
	ans = ans * pow_mod( c[cur][a-b], p - 2, p ) % p;  // 求 (n-k)! mod p 的逆元
	return ans;
}

//  求  PI ( C( ni, mi ) ) % pj 
int C( int n, int k, int cur )
{
	int i, x, len[2] = { 0, 0 };
	int c = 0, p = w[cur];
	x = n;
	while( x ) s[0][len[0]++] = x % p, x /= p;
	x = k;
	while( x ) s[1][len[1]++] = x % p, x /= p;
	while( len[1] < len[0] ) s[1][len[1]++] = 0;
	for( i = 0; i < len[0]; i++ ) if( s[1][i] > s[0][i] ) return 0;
	int ans = 1;
	for( i = 0; i < len[0]; i++ ) ans = ans * cnk( s[0][i], s[1][i], cur ) % p;
	return ans;
}

int main(int argc, char *argv[])
{
	int i, j, x, ans;
	for( i = 0; i < 4; i++ )
	{
		c[i][0] = 1;
		for( j = 1; j < w[i]; j++ )
			c[i][j] = c[i][j-1] * j % w[i];
	}
	while( scanf("%d%d",&N,&G) != EOF )
	{
		if( G == P )
		{
			printf("0\n");
			continue;
		}
		G %= P;
		for( i = 1; i * i <= N; i++ )
		{
			if( N % i == 0 )
			{
				x = i;
				for( j = 0; j < 4; j++ )
					b[j] = ( b[j] + C( N, x, j ) ) % w[j];
				x = N / i;
				if( i * i != N )
					for( j = 0; j < 4; j++ )
						b[j] = ( b[j] + C( N, x, j ) ) % w[j];
			}
		}
		ans = pow_mod( G, china( 4, b, w ), P );
		printf("%d\n",ans);
	}
	return 0;
}
