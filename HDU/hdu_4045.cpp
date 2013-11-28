/*
    author: AmazingCaddy
    time:    2011-09-18 13:29:49 
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

const int maxn = 1004;
const int mod = 1000000007;

int C[ maxn ][ maxn ];// ???
int S[ maxn ][ maxn ];// ????
int n, r, k, m;

void init( ) {
    C[ 0 ][ 0 ] = 1;
    C[ 1 ][ 0 ] = C[ 1 ][ 1 ] = 1;
    S[ 1 ][ 1 ] = 1;
    for( int i = 2; i < maxn; i++ ) {
        C[ i ][ 0 ] = C[ i ][ i ] = 1;
        S[ i ][ 1 ] = S[ i ][ i ] = 1;
        for( int j = 1; j < i; j++ ) {
            C[ i ][ j ] = ( C[ i - 1 ][ j - 1 ] + C[ i - 1 ][ j ] ) % mod;
            S[ i ][ j ] = ( (ll)S[ i - 1 ][ j - 1 ] + (ll)j * S[ i - 1 ][ j ] ) % mod;
        }
    }
    /*
    for( int i = 1; i <= 10; i++ ) {
        for( int j = 1; j <= i; j++ ) {
            printf( "%d ", S[ i ][ j ] );
        }
        printf( "\n" );
    }
    */
}

void solve( ) {
    int tmp = n - ( r - 1 ) * ( k - 1 );
    if( tmp < r ) {
        printf( "0\n" );
        return;
    }
    int Min = min( r, m );
    ll sum = 0;
    for( int i = 1; i <= Min; i++ ) {
        sum += S[ r ][ i ];
        sum %= mod;
    }
    int ans = sum * C[ tmp ][ r ] % mod;
    printf( "%d\n", ans );
}

int main(int argc, char *argv[]) {
    init( );
    while( scanf( "%d%d%d%d", &n, &r, &k, &m ) != EOF ) {
        solve( );
    }
    return 0;
}