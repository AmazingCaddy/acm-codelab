/*
    author: AmazingCaddy
    time:    2011-08-17 16:56:40 
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

const int maxn = 10004;
char buf[ maxn ];
int num[ maxn ];

int main(int argc, char *argv[]) {
    while( scanf( "%s", buf ) != EOF ) {
        int len = strlen( buf );
        int i = 0, j, cnt = 0;
        while( i < len ) {
            while( i < len && buf[ i ] == '5' ) i++;
            if( i >= len ) break;
            int tmp = 0;
            for( j = i; j < len && buf[ j ] != '5'; j++ ) {
                tmp = tmp * 10 + buf[ j ] - '0';
            }
            num[ cnt++ ] = tmp;
            i = j + 1;
        }
        sort( num, num + cnt );
        for( i = 0; i < cnt; i++ ) {
            if( i ) printf( " " );
            printf( "%d", num[ i ] );
        }
        printf( "\n" );
    }
    return 0;
}
