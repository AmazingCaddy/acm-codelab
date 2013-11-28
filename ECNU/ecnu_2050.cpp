/*
	author: AmazingCaddy
	time: 2011/2/28  20:05
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	double n, m;
	while( scanf( "%lf%lf", &n, &m ) != EOF )
	{
		printf( "%.3lf\n", m / n );
	}
	return 0;
}
