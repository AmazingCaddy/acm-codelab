/*
    author: AmazingCaddy
    time: 2011/3/24  18:48
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

typedef long long ll;

const int maxn = 1001000;
map< ll, int > num;

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

int miller_rabin( ll n )
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

void DFS( ll n )
{
    if( miller_rabin( n ) ) 
    {
        num[ n ] ++;
        return ;
    }
    ll tmp = pollard_rho( n );
    DFS( tmp );
    DFS( n / tmp );
}

int main(int argc, char** argv)
{
    ll n;
    srand( (unsigned)time(NULL) );
    while( cin >> n  )
    {
        num.clear( );
           if( n < 2 ) 
        {
            printf( "is not a D_num\n" );
            continue;
        }
        DFS( n );
        if( num.size( ) == 1 && num.begin( )->second == 3 )
        {
            ll tmp = num.begin( )->first;
            cout << tmp << " "<< tmp * tmp << " "<< n << endl;
            continue;
        }
        if( num.size( ) == 2 )
        {
            map< ll, int >::iterator iter = num.begin( );
            int cnt1 = iter->second;
            ll q = iter->first;
            iter++;
            int cnt2 = iter->second;
            ll r = iter->first;
            if( cnt1 == 1 && cnt2 == 1 )
            {
                if( r < q ) swap( r, q );
                cout << q << " "<< r << " "<< n << endl;
                continue;
            }
        }
        cout << "is not a D_num" << endl;
    }
    return 0;
}
