/*
	author: AmazingCaddy
	time: 2011/4/16  12:52
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

const char * num[ ] = { "st", "nd", "rd",  };

int main(int argc, char *argv[])
{
	int cas, n;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		if( n < 10 )
		{
			if( n == 1 ) printf( "1st\n" );
			else if( n == 2 ) printf( "2nd\n" );
			else if( n == 3 ) printf( "3rd\n" );
			else printf( "%dth\n", n );
		}
		else
		{
			if( ( n / 10 ) % 10 != 1 )
			{
				if( n % 10 == 1 ) printf( "%dst\n", n );
				else if( n % 10 == 2 ) printf( "%dnd\n", n );
				else if( n % 10 ==3 ) printf( "%drd\n", n );
				else printf( "%dth\n", n );
			}
			else printf( "%dth\n", n );
		}
	}
	return 0;
}
