/*
    author: AmazingCaddy
    time:	2011/8/30	18:51
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

const ll INF =   9223372036854775807LL;

const int maxn = 10000005;
bool vis[ maxn ];
ll p[ 670000 ];
int flen, plen;
ll a[ 64 ], b[ 64 ];

void prime( ) {
    memset( vis, false, sizeof( vis ) );
    plen = 0;
    for( ll i = 2, k = 4; i < maxn; ++i, k += i + i - 1 ) {
        if( !vis[ i ] ) {
            p[ plen ++ ] = i;
            if( k < maxn ) {
                for( ll j = k; j < maxn; j += i ) {
                    vis[ j ] = true;
                }
            }
        }
    }
}

void factor( ll n ) {
    flen = 0;
    for( int i = 0; i < plen && p[ i ] * p[ i ] <= n; i++ ) {
        if( n % p[ i ] == 0 ) {
            for( b[ flen ] = 0; n % p[ i ] == 0; ++b[ flen ], n /= p[ i ] );
            a[ flen++ ] = p[ i ];
        }
    }
    if( n > 1 ) {
        a[ flen ] = n;
        b[ flen ++ ] = 1;
    }
}

ll get_num( ll n, ll p ) {
    ll sum = 0;
    while( n ) {
        n /= p;
        sum += n;
    }
    return sum;
}

ll k, n;
int main(int argc, char *argv[]) {
    prime( );
    int cas;
    scanf( "%d", &cas );
    for( int t = 1; t <= cas; t++ ){
        cin >> n >> k;
        printf( "Case %d: ", t );
        if( k == 1 ) {
            printf( "inf\n" );
            continue;
        }
        factor( k );
        ll ans = INF;
        for( int i = 0; i < flen; i++ ) {
            ll tmp = get_num( n, a[ i ] );
            ans = min( ans, tmp / b[ i ] );
        }
        cout << ans << endl;
    }
    return 0;
}
