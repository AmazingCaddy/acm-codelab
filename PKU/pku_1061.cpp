/*
	author: AmazingCaddy
	time: 2011/3/29  17:18
	( x + m * t ) - ( y + n * t ) = L * a
	(m - n)*t = (y - x) ( mod L )
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
using namespace std;

typedef __int64 ll;

ll ex_gcd( ll a, ll b, ll &d, ll &x, ll &y )
{
	if( !b ) { d = a; x = 1; y = 0; }
	else 
	{
		ex_gcd( b, a % b, d, y, x );
		y -= x * ( a / b );
	}
}

int main(int argc, char *argv[])
{
	ll x, y, m, n, L, d, a, b;
	while( scanf( "%I64d %I64d %I64d %I64d %I64d", &x, &y, &m, &n, &L ) != EOF )
	{
		a = m - n;
		b = y - x;
		if( a < 0 ) a = -a, b = -b;
		ex_gcd( a, L, d, x, y );
		if( m == n || b % d ) printf( "Impossible\n" );
		else printf( "%I64d\n", ( ( b / d * x ) % L + L ) % L );
	}
	return 0;
}
