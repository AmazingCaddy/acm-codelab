/*
	author: AmazingCaddy
	time: 2011/4/13  13:24
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
const int maxn = 1003;

int num[ maxn ];

int main(int argc, char *argv[])
{
	int n, m;
	while( scanf( "%d%d", &n, &m ) != EOF )
	{
		for( int i = 1; i < maxn; i++ )
		num[ i ] = i;
		m--;
		while( m-- )
		{
			next_permutation( num + 1, num + n + 1 );
		}
		for( int i = 1; i <= n; i++ )
		{
			if( i != 1 ) printf( " " );
			printf( "%d", num[ i ] );
		}
		printf( "\n" );
	}
	return 0;
}
