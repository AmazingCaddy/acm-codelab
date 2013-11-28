/*
    author: AmazingCaddy
    time:    
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;
//typedef long long ll;
typedef __int64 ll;
const int maxn = 10004;

int vis[ maxn ], p[ maxn ];
int plen, flen1, flen2, flen;
ll a[ 100 ], b[ 100 ], a1[ 100 ], b1[ 100 ], a2[ 100 ], b2[ 100 ];

void prime( )
{
    memset( vis, 0, sizeof( vis ) );
    plen = 0;
    for( int i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
    {
        if( !vis[ i ] ) 
        {
            p[ plen++ ] = i;
            if( k < maxn ) for( int j = k; j < maxn; j += i ) vis[ j ] = 1;
        }
    }
}

ll mul_mod( ll a, ll b, ll c )
{
    ll ans = 0, d = a % c;
    while( b )
    {
        if( b & 1 )if( ( ans += d ) >= c ) ans -= c;
        if( ( d <<= 1 ) >= c ) d -= c;
        b >>= 1;
    }
    return ans ;
}

ll pow_mod( ll m, ll n )
{
    ll a, ans = 1;
    rand( ); a = rand( ); a *= rand( ) % ( n - 1 );
    a *= rand( ) % ( n - 1 ); a = a % ( n - 1 ) + 1;
    while( m )
    {
        if( m & 1 ) ans = mul_mod( ans, a, n );
        m >>= 1;
        a = mul_mod( a, a, n );
    }
    return ans;
}

ll miller_rabin( ll n )
{
    if( n == 2 ) return 1;
    if( n < 2 || !( n & 1 ) )return 0;
    ll m = n - 1, s = 0, a, i, j;
    while( !( m & 1 ) ) { m >>= 1; s++; }
    for( i = 1; i <= 10; i++ )
    {
        a = pow_mod( m, n );
        if( a == 1 ) continue;
        for( j = 1; j <= s; j++ )
        {
            if( a == n - 1 ) break;
            a = mul_mod( a, a, n );
        }
        if( j > s ) return 0;
    }
    return 1;
}

ll gcd( ll a, ll b )
{
    return b ? gcd( b, a % b ) : a;
}

ll f( ll x, ll n )
{
    return ( mul_mod( x, x, n ) + 1 ) % n;
}

ll pollard_rho( ll n )
{
    if( n < 2 ) return 0;
    if( !( n & 1 ) ) return 2;
    ll x, y, i, d;
    for( i = 1; i <= 10; i++ )
    {
        rand( );
        x = rand( ) % n; y = f( x, n );
        d = gcd( ( y - x + n ) % n, n );
        while( d == 1 )
        {
            x = f( x, n ); y = f( f( y, n ), n );
            d = gcd( ( y - x + n ) % n, n ) % n;
        }
        if( d ) return d;
    }
    return 0;
}

void factor( ll a[ ], ll b[ ], int &len, ll n )
{
    len = 0;
    for( int i = 0; i < plen && p[ i ] * p[ i ] <= n; i++ )
    {
        if( n % p[ i ] == 0 )
        {
            for( b[ len ] = 0; n % p[ i ] == 0; ++b[ len ], n /= p[ i ] );
            a[ len++ ] = p[ i ];
        }
    }
    if( n > 1 ) 
    {
        if( miller_rabin( n ) )
        {
            a[ len ] = n;
            b[ len++ ] = 1;
            return;
        }
        ll p = pollard_rho( n );
        ll q = n / p;
        if( p == q )
        {
            a[ len ] = n;
            b[ len++ ] = 2;
            return;
        }
        a[ len ] = p, b[ len++ ] = 1;
        a[ len ] = q, b[ len++ ] = 1;
    }
}

ll elur( ll n )
{
    for( int i = 0; i < flen; i++ )
        if( b[ i ] ) n -= n / a[ i ];
    return n;
}

ll ans1, ans2;
ll P, PP, N;
void dfs( int dep, ll t )
{
    if( dep == flen )
    {
        ll x = N / t;
        ll phix = elur( x );
        // lcm n*sigma(d*phi(d)/2)
        ans1 = ( ans1 + ( phix % PP * x % PP ) ) % PP;
        // gcd sigma(d*phi(n/d)){d|n}
        ans2 = ( ans2 + ( phix % P * t % P ) ) % P;
        return;
    }
    ll tmp = 1;
    for( int i = 0; i <= b[ dep ]; tmp *= a[ dep ], i++ )
    {
        b[ dep ] -= i;
        dfs( dep + 1, t * tmp );
        b[ dep ] += i;
    }
}

int main(int argc, char *argv[])
{
    int cas;
    ll n, c;
//    freopen("in.txt", "r", stdin );
//    freopen("out1.txt", "w", stdout );
    srand( (unsigned) time( NULL ) );
    prime( );
    scanf( "%d", &cas );
    while( cas -- )
    {
//        scanf( "%lld%lld", &n, &c );
        scanf( "%I64d%I64d", &n, &c );
        //printf( "%I64d %I64d\n", n, c );
        factor( a, b, flen, n );
        
        
        //for( int i = 0; i < flen; i++ )
        //    cout << a[ i ] << " " << b[ i ] << endl;
        
        ans1 = 0, ans2 = 0;
        P = c, PP = 2 * c;
        N = n;
        dfs( 0, 1 );
        ans1 = ( N % PP *( ans1 + 1 ) % PP ) / 2;
        //ans = ( ( ans + n ) % c + c ) % c;
//        printf( "%I64d\n", ans  );
        if( ans1 == ans2 ) printf( "yes\n" );
        else printf( "no\n" );
    }
//    cerr << clock( ) << endl;
    return 0;
}
