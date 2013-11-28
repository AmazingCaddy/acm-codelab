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

const int maxn = 1005;
const int maxm = maxn * 10;
struct node {
    int n, k, p, id;
    node( ) { };
    node( int _n, int _k, int _p ) : n( _n ), k( _k ), p( _p ) { }
    bool operator < ( const node & b ) const {
        return p < b.p;
    }
};
node input[ maxn * 100 ];
int ans[ maxn * 100 ];

int F[ maxm ], Inv[ maxm ];
int s[ 2 ][ 32 ];
int P;

int pow_mod( int a, int b ) {
    int ans = 1, d = a % P;
    while( b ) {
        if( b & 1 ) ans = ans * d % P;
        d = d * d % P;
        b >>= 1;
    }
    return ans;
}

void init( ) {
    F[ 0 ] = Inv[ 0 ] = 1;    
    for( int i = 1; i < P; i++ ) {
        F[ i ] = F[ i - 1 ] * i % P;
        Inv[ i ] = Inv[ i - 1 ] * pow_mod( i, P - 2 ) % P;
    }
}

int cnk( int n, int k ) {
    return (ll)F[ n ] * Inv[ k ] * Inv[ n - k ] % P;
}

int C( int n, int k ) {
    int i, x, len[ 2 ] = { 0, 0 };
    x = n;
    while( x ) s[ 0 ][ len[ 0 ] ++ ] = x % P, x /= P;
    x = k;
    while( x ) s[ 1 ][ len[ 1 ] ++ ] = x % P, x /= P;
    while( len[ 1 ] < len[ 0 ] ) s[ 1 ][ len[ 1 ] ++ ] = 0;
    for( i = 0; i < len[ 0 ]; i++ ) if( s[ 1 ][ i ] > s[ 0 ][ i ] ) return 0;
    int ans = 1;
    for( i = 0; i < len[ 0 ]; i++ ) ans = ans * cnk( s[ 0 ][ i ], s[ 1 ][ i ] ) % P;
    return ans;
}

int main(int argc, char *argv[]) {
    int cas = 1;
    int n, k;
    while( scanf("%d%d%d",&input[ cas ].n, &input[ cas ].k, &input[ cas ].p ) != EOF ) {
        input[ cas ].id = cas;
        cas++;
    }
    sort( input + 1, input + cas );
    input[ 0 ].p = -1;
    for( int i = 1; i < cas; i++ ) {
        if( input[ i ].p != input[ i - 1 ].p ) {
            P = input[ i ].p;
            init( );
        }
        k = input[ i ].k;
        n = input[ i ].n;
        if( k > n - k ) k = n - k;
        ans[ input[ i ].id ] = ( C( n + 1, k ) + ( n - k ) ) % P;
    }
    for( int i = 1; i < cas; i++ ) {
        printf( "Case #%d: %d\n", i, ans[ i ] );
    }
    return 0;
}
