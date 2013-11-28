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

typedef __int64 ll;

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

int main(int argc, char *argv[])
{
	printf( "n e\n" );
	printf( "- -----------\n" );
	printf( "0 1\n" );
	printf( "1 2\n" );
	printf( "2 2.5\n" );
	double e = 2.5;
	double ii = 2.0;
	for( int i = 3; i <= 9; i++ )
	{
		ii *= i;
		e += 1.0 / ii;
		printf( "%d %.9lf\n", i, e );
	}
	return 0;
}
