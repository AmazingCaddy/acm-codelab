/*
	author: AmazingCaddy
	time:	2011/8/1  19:13
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

typedef long long ll;

const int maxn = 10004;

int pow_mod( int a, int b, int p )
{
	int ans = 1, d = a % p;
	while( b )
	{
		if( b & 1 ) ans = ans * d % p;
		d = d * d % p;
		b >>= 1;
	}
	return ans % p;
}

int solve( int a, int p )
{
	int cnt = 0;
	for( int i = 0; i < p; i++ )
		if( pow_mod( i, i, p ) == a )
			cnt++;
	return cnt;
}

char buf[ maxn ];

int main(int argc, char *argv[])
{
	int cas, p;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%s%d", buf, &p );
		int len = strlen( buf );
		//cout << len << endl;
		int ans = 0;
		for( int i = 0; i < len; i++ )
			ans = ( ans * 10 + buf[ i ] - '0' ) % p;
		//printf( "%d\n", ans );
		printf( "%d\n", solve( ans, p ) );
	}
	return 0;
}
