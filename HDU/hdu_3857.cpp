/*
	author: AmazingCaddy
	time:	2011/7/30  20:14
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

//typedef __int64 ll;
typedef long long ll;

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

int main(int argc, char *argv[])
{
	int n, ai;
	while( scanf( "%d", &n ) != EOF )
	{
		int flag = 0;
		for( int i = 1; i <= n; i++ )
		{
			scanf( "%d", &ai );
			if( ai == i )
			{
				if( flag ) printf( " " );
				else flag = 1;
				printf( "%d", i );
			}
		}
		if( !flag ) printf( "No Mistake" );
		printf( "\n" );
	}
	return 0;
}
