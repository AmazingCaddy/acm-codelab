#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 103;
char str[ maxn ];

int main(int argc, char *argv[])
{
	while( scanf("%s",str) != EOF )
	{
		int len = strlen( str );
		for( int i = 0; i < len / 2; i++ )
			swap( str[ i ], str[ len - i - 1 ] );
		int i, j, a, b, c;
		for( a = 0, i = 0; i < len && str[ i ] != '='; i++ )
			a = a * 10 + str[ i ] - '0';
		for( b = 0, j = i + 1; j < len && str[ j ] != '+'; j++ )
			b = b * 10 + str[ j ] - '0';
		for( c = 0, i = j + 1; i < len; i++ )
			c = c * 10 + str[ i ] - '0';
		if( a == b + c ) printf("True\n");
		else printf("False\n");
	}
	return 0;
}
