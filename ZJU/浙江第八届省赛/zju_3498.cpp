/*
	author: AmazingCaddy
	time: 2011/4/16  13:15
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

int solve( int n )
{
	int i = 0;
	while( n )
	{
		n >>= 1;
		i++;
	}
	return i;
}

int main(int argc, char *argv[])
{
	int cas, n;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		int ans = solve( n );
		printf( "%d\n", ans );
	}
	return 0;
}
