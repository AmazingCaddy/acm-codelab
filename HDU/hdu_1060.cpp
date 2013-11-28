/*
    author: AmazingCaddy
    time: 27/05/2011 20:47:59 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;

int main( int ac, char * av[ ] )
{
	int n, cas;
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d", &n );
		double tmp = n * log10( n * 1.0 );
		tmp = tmp - (ll)tmp;
		tmp = pow( 10.0, tmp );
		printf( "%d\n", (int)tmp );
	}
	return 0;
}
