/*
	author: AmazingCaddy
	time: 2011/6/13  15:47
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int maxn = 10004;
int dp[ maxn ];
int bag[ maxn ];
int len;

void getbag( int n, int val )
{
	int m = n, tmp = 1;
	while( m >= tmp )
	{
		bag[ len++ ] = tmp * val;
		m -= tmp;
		tmp <<= 1;
	}
	if( m ) bag[ len++ ] = m * val;
}

int main(int argc, char *argv[])
{
	int num1, num2, num5;
	while( 1 )
	{
		scanf( "%d%d%d", &num1, &num2, &num5 );
		if( num1 == 0 && num2 == 0 && num5 == 0 ) break;
		len = 0;
		getbag( num1, 1 );
		getbag( num2, 2 );
		getbag( num5, 5 );
		int total = num1 + num2 * 2 + num5 * 5;
		memset( dp, 0, sizeof( dp ) );
		dp[ 0 ] = 1;
		for( int i = 0; i < len; i++ )
			for( int j = total; j >= bag[ i ]; j-- )
				if( dp[ j - bag[ i ] ] ) dp[ j ] = 1;
		for( int i = 1; i <= total + 1; i++ )
			if( !dp[ i ] ) { printf( "%d\n", i ); break; }
	}
	return 0;
}
