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
char a[ maxn ], b[ maxn ];

int main(int argc, char *argv[])
{
	int n, m;
	while( scanf("%s%s",&a,&b) != EOF )
	{
		n = strlen( a );
		m = strlen( b );
		int i = 0, j = 0;
		while( i < n )
		{
			if( j == m ) break;
			if( a[ i ] == b[ j ] ) i++;
			j++;
		}
		if( i == n ) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
