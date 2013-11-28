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

const int maxn = 500100;
int stone[ maxn ];
int L, n, m;

int check( int mid ) {
    if( stone[ 0 ] > mid || L - stone[ n - 1 ] > mid ) {
        return 0;
    }
    int last = 0;
    int cnt = 0;
    for( int i = 0; i < n && stone[ i ] < L; i++ ) {
        if( stone[ i ] - last > mid ) {
            if( last == stone[ i - 1 ] ) {
                return 0;
            }
            last = stone[ i - 1 ];
            i--;
            cnt++;
        }
    }
    cnt++;
    if( L - last > mid ) {
        cnt++;
    }
    return cnt <= m;
}

int main(int argc, char *argv[]) {
    while( scanf( "%d%d%d", &L, &n, &m ) != EOF ) {
        for( int i = 0; i < n; i++ ) {
            scanf( "%d", &stone[ i ] );
        }
        if( n == 0 ) {
            printf( "%d\n", L );
            continue;
        }
        sort( stone, stone + n );
        int l = 0, r = L + 1, mid;
        int ans = 0;
        while( l <= r ) {
            mid = ( l + r ) / 2;
            if( check( mid ) ) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        printf( "%d\n", ans );
    }
    return 0;
}