/*
	author: AmazingCaddy
	time: 2011/5/18  23:25
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

int main(int argc, char *argv[])
{
	int n, u, d;
	while( 1 )
	{
		scanf( "%d%d%d", &n, &u, &d );
		if( n == 0 && u == 0 && d == 0 ) break;
		int cnt = 0;
		while( 1 )
		{
			n -= u;
			cnt++;
			if( n <= 0 ) break;
			n += d;
			cnt++;
		}
		printf( "%d\n", cnt );
	}
	return 0;
}
