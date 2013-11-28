/*
	author: AmazingCaddy
	time: 2011/4/1  20:20
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
using namespace std;

const int maxn = 10004;
int num[ maxn ];
int buf[ maxn ];
int n;

void print( )
{
	int len = n / 2, flag = n % 2;
	int cnt = n - 1, k = 0;
	while( len-- )
	{
		buf[ k++ ] = num[ cnt ];
		buf[ k++ ] = num[ n - 1 - cnt ];
		cnt--;
	}
	if( flag ) buf[ k++ ] = num[ n / 2 ];
	for( int i = 0; i < k; i++ )
	{
		if( i ) printf( " " );
		printf( "%d", buf[ i ] );
	}
	printf( "\n" );
}

int main(int argc, char *argv[])
{
	while( scanf( "%d", &n ) != EOF )
	{
		for( int i = 0; i < n; i++ )
			scanf( "%d", &num[ i ] );
		sort( num, num + n );
		print( );
	}
	return 0;
}
