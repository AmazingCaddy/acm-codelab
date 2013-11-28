/*
	author: AmazingCaddy
	time: 2011/4/13  13:33
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
const int maxn = 10004;
char buf[ maxn ];

int main(int argc, char *argv[])
{
	int cas;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%s", buf );
		int len = strlen( buf );
		int cnt = 1;
		for( int i = 1; i < len; i++ )
		{
			if( buf[ i ] != buf[ i - 1 ] )
			{
				if( cnt != 1 ) printf( "%d", cnt );
				printf( "%c", buf[ i - 1 ] );
				cnt = 1;
			}
			else cnt++;
		}
		if( cnt != 1 ) printf( "%d", cnt );
		printf( "%c\n", buf[ len - 1 ] );
	}
	return 0;
}
