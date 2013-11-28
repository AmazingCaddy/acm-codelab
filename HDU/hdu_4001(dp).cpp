/*
    author: AmazingCaddy
    time:    2011-09-03 18:58:33 
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

struct node {
    int a, b, c, d;
    ll area;
} block[ maxn ];

ll dp[ maxn ];

bool cmp( const node &a, const node &b ) {
    if( a.a == b.a ) {
        if( a.b == b.b ) {
            return a.d > b.d;
        }
        return a.b < b.b;
    }
    return a.a < b.a;
}

int main(int argc, char *argv[]) {
    int n;
    while( scanf( "%d", &n ) && n ) {
        for( int i = 0; i < n; i++ ) {
            scanf( "%d%d%d%d", &block[ i ].a, &block[ i ].b, &block[ i ].c, &block[ i ].d );
            if( block[ i ].a < block[ i ].b ) {
                swap( block[ i ].a, block[ i ].b );
            }
            block[ i ].area = (ll) block[ i ].a * block[ i ].b;
        }
        sort( block, block + n, cmp );
        memset( dp, 0, sizeof( dp ) );
        for( int i = 0; i < n; i++ ) {
            ll maxheight = 0;
            for( int j = 0; j < i; j++ ) {
                switch( block[ i ].d ) {
                case 0:
                    if( block[ i ].a >= block[ j ].a && block[ i ].b >= block[ j ].b ){
                        if( dp[ j ] > maxheight ) {
                            maxheight = dp[ j ];
                        }
                    }
                    break;
                case 1:
                    if( block[ i ].a >= block[ j ].a && block[ i ].b >= block[ j ].b && 
                        block[ i ].area > block[ j ].area ) {
                        if( dp[ j ] > maxheight ) {
                            maxheight = dp[ j ];
                        }
                    }
                    break;
                case 2:
                    if( block[ i ].a > block[ j ].a && block[ i ].b > block[ j ].b ) {
                        if( dp[ j ] > maxheight ) {
                            maxheight = dp[ j ];
                        }
                    }
                    break;
                }
            }
            dp[ i ] = maxheight + block[ i ].c;
        }
        ll ans = 0;
        for( int i = 0; i < n; i++ ) {
            if( ans < dp[ i ] ) {
                ans = dp[ i ];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
