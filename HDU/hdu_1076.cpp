/*
	author : AmazingCaddy
	time : 2011-06-01 17:30:39 
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

int leapyear( int n )
{
	if( n % 4 == 0 )
	{
		if( n % 100 == 0 )
		{
			if( n % 400 == 0 ) return 1;
			return 0;
		}
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int cas, y, n;
	scanf( "%d", &cas );
	while( cas -- )
	{
		scanf( "%d%d", &y, &n );
		while( n )
		{
			if( leapyear( y ) ) n--;
			y++;
		}
		printf( "%d\n", y - 1 );
	}
	return 0;
}
