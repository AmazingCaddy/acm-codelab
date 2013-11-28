/*
    author: AmazingCaddy
    time: 27/05/2011 19:44:41 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 10004;
const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[ ] = { 1, 0, -1, 0, -1, 1, 1, -1 };

int main( int ac, char * av[ ] )
{
	double sum = 0;
	double x;
	int cnt = 0;
	while( scanf( "%lf", &x ) != EOF )
	{
		sum = x;
		for( int i = 0; i < 11; i++ )
		{
			scanf( "%lf", &x );
			sum += x;
		}
		printf( "$%.2lf\n", sum / 12 );
	}
	return 0;
}
