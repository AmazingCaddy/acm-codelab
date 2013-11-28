#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int DAY_A_MONTH = 31, MONTH_A_YEAR = 12;
const int isPrimeDay[ DAY_A_MONTH + 1 ] = 
{
0, // 0
0, // 1
1,
1,
0,
1,
0,
1,
0,
0,
0,
1,
0,
1,
0,
0,
0,
1,
0,
1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
1,
0,
1 // 31
};

const int isPrimeMonth[ MONTH_A_YEAR + 1 ] = 
{
0, // 0
0, // 1
1,
1,
0,
1,
0,
1,
0,
0,
0,
1,
0 // 12
};

const int totDays[ MONTH_A_YEAR + 1 ] = 
{
0,
31, // 1
28,
31,
30,
31,
30,
31,
31,
30,
31,
30,
31
};

inline int isLeapYear( int y ) {
        return ( y % 400 == 0 ) || ( ( y % 4 == 0 ) && ( y % 100 != 0 ) );
}

inline int getInDay( int m, int d ) {
        return ( isPrimeMonth[ m ] && isPrimeDay[ d ] ) ? 1 : 0;
}

const int MIN_YEAR = 1000, MAX_YEAR = 2999;
int totYearMonthDay[ MAX_YEAR + 1 ][ MONTH_A_YEAR + 1 ][ DAY_A_MONTH + 1 ];
void init( void ) {
        memset( totYearMonthDay, 0, sizeof( totYearMonthDay ) );
        int y, m, d, days, tot = 0;
        for ( y = MIN_YEAR; y <= MAX_YEAR; ++y ) {
                for ( m = 1; m <= MONTH_A_YEAR; ++m ) {
                        days = totDays[ m ];
                        if ( ( m == 2 ) && isLeapYear( y ) ) {
                                ++days;
                        }
                        for ( d = 1; d <= days; ++d ) {
                                tot += getInDay( m, d );
                                totYearMonthDay[ y ][ m ][ d ] = tot;
                        }
                }
        }
}

int main() {
        int td, y1, m1, d1, y2, m2, d2, ans;
        init();
        scanf( "%d", &td );
        while ( td-- ) {
                scanf( "%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2 );
                ans = totYearMonthDay[ y2 ][ m2 ][ d2 ] - totYearMonthDay[ y1 ][ m1 ][ d1 ] + getInDay( m1, d1 );
                printf( "%d\n", ans );
        }
        return 0;
}
