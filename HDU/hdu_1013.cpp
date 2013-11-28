/*
	author: AmazingCaddy
	time: 2011/4/8  15:21
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
const int maxn = 1005;
char str[ maxn ];
int main(int argc, char *argv[])
{
	while( 1 )
	{
		scanf( "%s", str );
		int len = strlen( str );
		if( len == 1 && str[ 0 ] == '0' ) break;
		int sum = 0;
		for( int i = 0; i < len; i++ )
			sum += str[ i ] - '0';
		printf( "%d\n", sum % 9 ? sum % 9 : 9 );
	}
	return 0;
}
