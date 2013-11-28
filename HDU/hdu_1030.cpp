/*
	author: AmazingCaddy
	time: 2011/4/29  21:31
	Èý±ß×ø±ê
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

int main(int argc, char *argv[])
{
	int n, m;
	while( scanf( "%d%d", &n, &m ) != EOF )
	{
		int cn = ceil( sqrt( 1.0 * n ) );
		int cm = ceil( sqrt( 1.0 * m ) );

		int xn = ( n - ( cn - 1 ) * ( cn - 1 ) - 1 ) / 2 + 1;
		int yn = ( cn * cn - n ) / 2 + 1;

		int xm = ( m - ( cm - 1 ) * ( cm - 1 ) - 1 ) / 2 + 1;
		int ym = ( cm * cm - m ) / 2 + 1;

		int ans = abs( cm - cn ) + abs( xm - xn ) + abs( ym - yn );

		printf( "%d\n", ans );
	}
	return 0;
}
