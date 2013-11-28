/*
	author: AmazingCaddy
	time: 2011/4/8  15:42
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

const int maxn = 100005;
int vis[ maxn ];
int main(int argc, char *argv[])
{
	int step, mod, i, x;
	while( scanf( "%d %d", &step, &mod ) != EOF )
	{
		memset( vis, 0, sizeof( vis ) );
		x = 0;
		for( i = 0; i < mod; i++ )
		{
			if( !vis[ x ] )
			{
				vis[ x ] = 1;
				x = ( x + step ) % mod;
			}
			else break;
		}
		if( i == mod ) printf( "%10d%10d    Good Choice\n", step, mod );
		else printf( "%10d%10d    Bad Choice\n", step, mod );
		printf( "\n" );
	}
	return 0;
}
