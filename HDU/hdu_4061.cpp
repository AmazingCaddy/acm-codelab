#include <stdio.h>
#include <math.h>

#define N 110

const double eps = 1e-8;

int main ( void ) {
//    freopen ( "in.txt", "r", stdin );
    int T, t, n;
    scanf ( "%d", &T );
    for ( int cas = 1 ; cas <= T ; ++cas ) {
        scanf ( "%d", &n );
        int sum = 0, u;
        for ( int i = 0 ; i < n ; ++i ) {
            scanf ( "%d", &t );
            if ( i == 0 ) u = t;
            sum += t;
        }
        printf ( "Case %d: %.6lf\n", cas, u * 1.0 / sum );
    }
    return 0;
}