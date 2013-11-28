/*
	author: AmazingCaddy
	time: 
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

int main(int argc, char *argv[])
{
	int x, y, z, cas;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d %d %d", &x, &y, &z );
		// 关于点(5,5,5)中心对称
		if( x < 5 ) x = 10 - x;
		if( y < 5 ) y = 10 - y;
		if( z < 5 ) z = 10 - z;
		if( ( x <= 10 && y <= 10 ) || ( x <= 10 && z <= 10 ) || ( y <= 10 && z <= 10 ) )
			printf( "4\n" );
		else if( x == 10 || y == 10 || z == 10 )
			printf( "5\n" );
		else printf( "6\n" );
	}
	return 0;
}
