/*
	author: AmazingCaddy
	time: 2011/4/11  0:24  n! ~ (2*pi*n)^(0.5)*(n/e)^(n)
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
const double pi = acos( -1.0 );
const double e = 2.718281828459;
int len[ ] = { 0, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10 };
int main(int argc, char *argv[])
{
	int cas, n;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		if( n <= 13 ) printf( "%d\n", len[ n ] );
		else
		{
			int ans = 0.5 * log10( 2 * pi * n ) + n * log10( n / e );
			printf( "%d\n", ans + 1 );
		}
	}
	return 0;
}
