/*
	author: AmazingCaddy
	time: 2011/4/2  10:54
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
const int maxn = 104;

int num[ maxn ];

int main(int argc, char *argv[])
{
	int n, x, y;
	while( scanf( "%d", &n ) && n )
	{
		scanf( "%d", &x );
		int sum = x * 6;
		y = x;
		for( int i = 1; i < n; i++ )
		{
			scanf( "%d", &x );
			if( x < y ) sum += ( y - x ) * 4;
			else sum += ( x - y ) * 6;
			y = x;
		}
		printf( "%d\n", sum + n * 5 );
	}
	return 0;
}
