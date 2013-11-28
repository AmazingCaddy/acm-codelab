/*
	author: AmazingCaddy
	time: 2011/5/23  21:53
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

typedef __int64 ll;

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

int solve( double x )
{
	int n = 2;
	int sum = 0;
	while( x > 0 )
	{
		x -= 1.0 / n;
		n++;
		sum++;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	double length;
	while( scanf( "%lf", &length ) && length != 0.0 )
	{
		printf( "%d card(s)\n", solve( length ) );
	}
	return 0;
}
