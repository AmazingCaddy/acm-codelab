#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int L = 100009, MM = 9901;

class TreeArray
{
public : 
        TreeArray( int num = 10 ) {
                init( num );
        }
        void init( int num ) {
                n = num;
                for ( int i = 1; i <= n; ++i ) {
                        a[ i ] = 0;
                }
        }
        void plus( int index, int value ) {
                while ( index <= n ) {
                        a[ index ] += value;
                        a[ index ] %= MM;
                        index += lowBit( index );
                }
        }
        int sum( int endIndex ) {
                int ans = 0;
                while ( endIndex > 0 ) {
                        ans += a[ endIndex ];
                        ans %= MM;
                        endIndex -= lowBit( endIndex );
                }
                return ans;
        }

private : 
        int lowBit( int x ) {
                return x & ( -x );
        }
        int a[ L ], n;
};

pair<int,int> data[ L ]; // first value, second index
int index[ L ];          // index[ data[ i ].second ] == i
TreeArray sum;           // map data

bool findHigh( int low, int high, int x, int & index ) {
        int mid, l = low;
        index = low - 1;
        while ( low <= high ) {
                mid = ( low + high ) / 2;
                if ( data[ mid ].first <= x ) {
                        low = mid + 1;
                        if ( mid > index ) {
                                index = mid;
                        }
                }
                else {
                        high = mid - 1;
                }
        }
        return index >= l;
}

bool findLow( int low, int high, int x, int & index ) {
        int mid, h = high;
        index = high + 1;
        while ( low <= high ) {
                mid = ( low + high ) / 2;
                if ( data[ mid ].first >= x ) {
                        high = mid - 1;
                        if ( mid < index ) {
                                index = mid;
                        }
                }
                else {
                        low = mid + 1;
                }
        }
        return index <= h;
}

int main() {
        int n, d, i, low, high, ans, delta;
        while ( scanf( "%d%d", &n, &d ) != EOF ) {
                for ( i = 0; i < n; ++i ) {
                        scanf( "%d", &(data[ i ].first) );
                        data[ i ].second = i;
                }
                sort( data, data + n );
                for ( i = 0; i < n; ++i ) {
                        index[ data[ i ].second ] = i;
                }
                sum.init( n );
                sum.plus( index[ 0 ] + 1, 1 );
                ans = 0;
                for ( i = 1; i < n; ++i ) {
                        if ( ( findLow( 0, n - 1, data[ index[ i ] ].first - d, low ) ) && 
                             ( findHigh( 0, n - 1, data[ index[ i ] ].first + d, high ) ) 
                           ) {
                           delta = ( sum.sum( high + 1 ) + MM - sum.sum( low ) ) % MM;
                           ans = ( ans + delta ) % MM;
                           sum.plus( index[ i ] + 1, delta + 1 );
                        }
                }
                printf( "%d\n", ans );
        }
        return 0;
}
