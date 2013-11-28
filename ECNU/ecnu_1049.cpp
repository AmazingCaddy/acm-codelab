#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 100003;
int num[ maxn ];

int input( )
{
	char c;
	int sum = 0;
	while( '0' <= ( c = getchar( ) ) && c <= '9' )
		sum = sum * 10 + c - '0';
	return sum;
}

int main(int argc, char *argv[])
{
	int n, m, x;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		getchar( );
		for( int i = 0; i < n; i++ )
			num[ i ] = input( );
		sort( num, num + n );
		for( int i = 0; i < m; i++ )
		{
			x = input( );
			int ans = upper_bound( num, num + n, x ) - lower_bound( num, num + n, x );
			printf("%d\n",ans);
		}
	}
	return 0;
}
