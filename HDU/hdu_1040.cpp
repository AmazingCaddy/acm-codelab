/*
    author: AmazingCaddy
    time: 
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
int num[ maxn ];

int main( int ac, char * av[ ] )
{
	int cas, n;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		for( int i = 0; i < n; i++ )
			scanf( "%d", &num[ i ] );
		sort( num, num + n );
		for( int i = 0; i < n; i++ )
		{
			if( i ) printf( " " );
			printf( "%d", num[ i ] );
		}
		printf( "\n" );
	}
	return 0;
}
