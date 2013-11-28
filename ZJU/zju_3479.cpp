/*
	author: AmazingCaddy
	time: 2011/4/3  13:21
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
const int maxn = 205;
const char * sx[ ] = { "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Ram", "Monkey", "Rooster", "Dog", "Pig" };
int year[ maxn ];
void init( )
{
	for( int i = 1; i <= 12; i++ )
	{
		for( int j = 0; j * 12 + i < maxn; j++ )
		{
			year[ 12 * j + i ] = ( 28 - i ) % 12;
		}
	}
}

int main(int argc, char *argv[])
{
	int cas, y;
	scanf( "%d", &cas );
	init( );
	while( cas-- )
	{
		scanf( "%d", &y );
		printf( "%s\n", sx[ year[ y ] ] );
	}
	return 0;
}
