/*
	author : AmazingCaddy
	time : 2011-07-06 20:32:35 
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
#define lowbit(x) ((x)&(-(x)))

const int maxn = 10004;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = 3.1415926;

int main(int argc, char *argv[])
{
	double x, y;
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%lf%lf", &x, &y );
		int ans = ceil( ( x * x + y * y ) * pi / 100 );
		printf( "Property %d: This property will begin eroding in year %d.\n", t, ans );
	}
	printf( "END OF OUTPUT.\n" );
	return 0;
}
