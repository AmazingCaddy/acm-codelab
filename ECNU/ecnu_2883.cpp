/*
	author: AmazingCaddy
	time: 2011/3/27  12:03
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
	int L, C, N, si, pi;
	scanf( "%d %d %d", &L, &C, &N );
	for( int i = 0; i < C; i++ )
	{
		scanf( "%d %d", &si, &pi );
		printf( "%d\n", abs(pi - N)+ si);
	}
	return 0;
}
