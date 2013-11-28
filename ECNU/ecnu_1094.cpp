#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
inline long long abs( long long a ) { return a < 0 ? -a : a; }
typedef unsigned long long ull;
#define MAX 0xffffffff
const int bits = 19, mask = ( 1 << bits ) - 1;

ull mul( ull x, ull y, ull M )
{
    if( x <= MAX && y <= MAX ) return x * y % M;
    ull r = y * ( x & mask ) % M;
    while( x >>= bits )
		r += ( y = ( y << bits ) % M ) * ( x & mask ), r %= M;
	return r;
}

int mt(ull n,ull a)
{
    ull s, t, mi = n - 1;
    int r;
    for( s = mi, r = 0; !( s & 1 ); s >>= 1, r++ );
    for( t = a; s >>= 1; )
    {
        a = mul( a, a, n );
		if( s & 1 ) t = mul( t, a, n );
    }
    if( t == 1 || t == mi ) return 1;
    while( --r ) if( ( t = mul( t, t, n ) ) == mi ) return 1;
    return 0;
}

int pr( ull n )
{
    if( n == 1 ) return 0;
    if( n < 29 ) 
		return n==2||n==3||n==5||n==7||n==11||n==13||n==17||n==19||n==23;
    if( !(n&1&&n%3&&n%5&&n%7&&n%11&&n%13&&n%17&&n%19&&n%23) ) return 0;
    return ( n == 17431 || mt( n, 34862 ) &&
		( n == 3281359 || mt( n, 574237825 ) ) );
}

int main( )
{
    ull n;
    while( scanf("%I64d", &n ) != EOF )
	{
		if( pr( n ) ) puts( "YES" );
		else puts( "NO" );
    }
	return 0;
}
