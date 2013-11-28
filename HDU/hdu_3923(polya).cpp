/*
    author: AmazingCaddy
    time:   2011/8/9  18:45
    polya
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
typedef long long ll;

const int maxn = 10004;
const int mod = 1000000007;

int vis[ maxn ], p[ maxn ];
int plen, flen;
int a[ 32 ], b[ 32 ];
int n, m;

void prime( )
{
    memset( vis, 0, sizeof( vis ) );
    plen = 0;
    for( int i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
    {
        if( !vis[ i ] )
        {
            p[ plen ++ ] = i;
            if( k < maxn ) for( int j = k; j < maxn; j += i ) vis[ j ] = 1;
        }
    }
}

int PHI( int n )
{
    int phi = n;
    for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
    {
        if( n % p[ i ] == 0 )
        {
            while( n % p[ i ] == 0 ) n /= p[ i ];
            phi -= phi / p[ i ];
        }
    }
    if( n > 1 ) phi -= phi / n;
    return phi;
}

void factor( int n )
{
    flen = 0;
    for( int i = 0; p[ i ] * p[ i ] <= n; i++ )
    {
        if( n % p[ i ] == 0 )
        {
            for( b[ flen ] = 0; n % p[ i ] == 0; ++ b[ flen ], n /= p[ i ] );
            a[ flen++ ] = p[ i ];
        }
    }
    if( n > 1 ) a[ flen ] = n, b[ flen++ ] = 1;
}

int pow_mod( int a, int b )
{
    ll ans = 1, d = a % mod;
    while( b )
    {
        if( b & 1 ) ans = ans * d % mod;
        d = d * d % mod;
        b >>= 1;
    }
    return ans;
}

int Inv( int n )
{
    return pow_mod( n, mod - 2 );
}

int sum;

void dfs( int dep, int t )
{
    if( dep == flen )
    {
        sum = ( sum + (ll)PHI( m / t ) * pow_mod( n, t ) ) % mod;
        return;
    }
    int tmp = 1;
    for( int i = 0; i <= b[ dep ]; i++ )
    {
        dfs( dep + 1, t * tmp );
        tmp *= a[ dep ];
    }
}

int main(int argc, char *argv[])
{
    int cas;
    prime( );
    scanf( "%d", &cas );
    for( int k = 1; k <= cas; k++ )
    {
        scanf( "%d%d", &n, &m );
        factor( m );
        sum = 0;
        dfs( 0, 1 );
        if( m % 2 == 0 )
        {
            sum = ( sum + (ll)( m / 2 ) * ( pow_mod( n, m / 2 + 1 ) + pow_mod( n, m / 2 ) ) ) % mod;
        }
        else
        {
            sum = ( sum + (ll)m * pow_mod( n, m / 2 + 1 ) ) % mod;
        }
        sum = ( ll )sum * Inv( 2 * m ) % mod;
        printf( "Case #%d: %d\n", k, sum );
    }    
    return 0;
}