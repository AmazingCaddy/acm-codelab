/*
	author: AmazingCaddy
	time:	2011-07-08 13:55:55 
	f( x ) = 5 * x ^ 13 + 13 * x ^ 5 + k * a * x
	f( x + 1 )  = 5 * ( x + 1 ) ^ 13 + 13 * ( x + 1 ) ^ 5 + k * a * ( x + 1 )
				= 5 * ( C( 13, 0 ) * x ^ 13 + C( 13, 1 ) * x ^ 12 + ... + C( 13, 13 ) * x ^ 0 ) + 13 * ( C( 5, 0 ) * x ^ 5 + C( 5, 1 ) * x ^ 4 + ... + C( 5, 5 ) ) + k * a * x + k * a
				= f( x ) + 5 * ( C( 13, 1 ) * x ^ 12 + ... + C( 13, 12 ) * x ) + 13 * ( C( 5, 1 ) * x ^ 4 + ... + C( 5, 4 ) * x ) + 5 + 13 + k * a
				= f( x ) + 65 * N + 18 + k * a
	if 65 | f( x ) then 65 | f( x + 1 )
	65 | ( 18 + k * a )
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

int main(int argc, char *argv[])
{
	int k, i;
	while( scanf( "%d", &k ) != EOF )
	{
		for( i = 1; i < 66; ++i )
		{
			int sum = i * k;
			if( ( sum % 65 ) == 47 ) break;
        }
        if( i == 66 ) printf( "no\n" );
        else printf( "%d\n", i );
	}
	return 0;
}
