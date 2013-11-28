/*
	author: AmazingCaddy
	time: 
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

const int maxn = 506;

double num[ maxn ];
int main(int argc, char *argv[])
{
	int cas, n;
	double ans;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
			scanf( "%lf", &num[ i ] );
		sort( num, num + n );
		if( n % 2 )
			ans = num[ n / 2 ];
		else ans = ( num[ n / 2 - 1 ] + num[ n / 2 ] ) / 2.0;
		printf( "%.3lf\n", ans );
	}
	return 0;
}
