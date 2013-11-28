/*
	author : AmazingCaddy
	time : 2011-06-02 22:12:12 
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
#define lowbit(x) ((x)&(-(x)))

char s[ 8000 ][ 2500 ] = { "0", "1", "1", "1", "1" };

int main(int argc, char *argv[])
{
	int i, j, k, n, len;
	for( i = 5; i < 8000; i++ )
	{
		for( j = 0; s[ i - 1 ][ j ]; j++ )
  		{
    		if( !s[ i - 2 ][ j ] ) s[ i - 2 ][ j ] = '0';
			if( !s[ i - 3 ][ j ] ) s[ i - 3 ][ j ] = '0';
			if( !s[ i - 4 ][ j ] ) s[ i - 4 ][ j ] = '0';
			if( !s[ i ][ j ] ) s[ i ][ j ] = s[ i - 1 ][ j ] - '0' + s[ i - 2 ][ j ] - '0'
											+ s[ i - 3 ][ j ] - '0' + s[ i - 4 ][ j ];
			else s[ i ][ j ] += s[ i - 1 ][ j ] - '0' + s[ i - 2 ][ j ] - '0' 
							  + s[ i - 3 ][ j ] - '0' + s[ i - 4 ][ j ] - '0';
			if( s[ i ][ j ] >= 58 )
			{
				s[ i ][ j + 1 ] = ( s[ i ][ j ] - '0' ) / 10 + '0';
				s[ i ][ j ] = ( s[ i ][ j ] - '0' ) % 10 + '0';
			}
 		}
 	}
 	while( scanf( "%d", &n ) != EOF )
 	{
  		len = strlen( s[ n ] );
 	 	if( s[ n ][ len - 1 ] == '0' ) len--;
  		for( i = len - 1; i >= 0; i-- )
  		printf( "%c", s[ n ][ i ] );
  		printf( "\n" );
 	}
 	return 0;
}

