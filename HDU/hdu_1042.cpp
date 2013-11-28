/*
    author: AmazingCaddy
    time: 18/05/2011 16:00:36 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 10004;
int num[ maxn ];

int main( int ac, char * av[ ] )
{
	int n;
	while( scanf( "%d", &n ) != EOF )
	{
		memset( num, 0, sizeof( num ) );
		num[ 0 ] = 1;
		int len = 1;
		for( int i = 1; i <= n; i++ )
		{
			int carry = 0;
			for( int j = 0; j < len; j++ )
			{
				num[ j ] = num[ j ] * i + carry;
				carry = num[ j ] / 10000;
				num[ j ] %= 10000;
			}
			num[ len ] += carry;
			while( num[ len ] )
			{
				num[ len + 1 ] += num[ len ] / 10000;
				num[ len ] %= 10000;
				len++;
			}
		}
		printf( "%d", num[ len - 1 ] );
		for( int i = len - 2; i >= 0; i-- )
			printf( "%.4d", num[ i ] );
		printf( "\n" );
	}
	return 0;
}
