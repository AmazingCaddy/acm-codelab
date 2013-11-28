/*
	author: AmazingCaddy
	time: 2011/2/28  20:01
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef __int64 ll;

int main(int argc, char *argv[])
{
	int n, t;
	scanf( "%d", &t );
	while( t-- )
	{
		scanf( "%d", &n );
		int sum = n;
		while( n > 2 )
		{
			sum += n / 3;
			n = n / 3 + n % 3;
		}
		printf( "%d\n", sum );
	}
	return 0;
}
