// 费马降阶法  《数论概论》 P123
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef __int64 ll;

ll pow_mod( ll a, ll b, ll p )
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

int main(int argc, char *argv[])
{
	//freopen("data1.in","r",stdin);
	//freopen("out.txt","w",stdout);
	ll p, a, b, m, A, B, M, x, y, u, v;
	srand( (unsigned)time( 0 ) );
	while( scanf("%I64d",&p) != EOF )
	{
		if( p % 4 == 3 )printf("Illegal\n");
		else
		{
			printf("Legal ");
			while( 1 )
			{
				x = rand( ) % ( p - 1 ) + 1;
				y = pow_mod( x, ( p - 1 ) / 4, p );
				if( y * y % p == p - 1 )break;
			}
			A = y, B = 1;
			M = ( A * A + B * B ) / p;
			while( M != 1 )
			{
				u = A % M;
				v = B % M;
				if( u > M / 2 ) u -= M;
				if( v > M / 2 ) v -= M; 
				a = ( u * A + v * B ) / M;
				b = ( v * A - u * B ) / M;
				if( a < 0 ) a = -a;
				if( b < 0 ) b = -b;
				M = ( a * a + b * b ) / p;
				A = a, B = b;
			}
			if( A > B ) swap( A, B );
			printf("%I64d %I64d\n",A,B);
		}
	}
	return 0;
}
