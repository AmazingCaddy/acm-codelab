#include<cmath>
#include<cstdio>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 2050;
int lg[ maxn ];
void init( ) {
    lg[ 1 ] = 0;
    for( int i = 0; i <= 10; i++ ) {
        for( int j = ( 1 << i ) + 1; j <= ( 1 << ( i + 1 ) ); j++ ) {
            lg[ j ] = i + 1;
        }
    }
}

int main( ) {
//    freopen( "in.txt", "r", stdin );
    int cas, n, m, k;
    init();
    scanf( "%d", &cas );
    for( int t = 1; t <= cas; t++ ) {
        scanf( "%d%d%d", &n, &m, &k );
        printf( "Case #%d: %I64d %d\n",t, (ll)n*m*k-1, lg[n]+lg[m]+lg[k]);
    }
    return 0;
}