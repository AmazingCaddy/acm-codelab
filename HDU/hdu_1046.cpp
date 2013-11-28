/*
    author: AmazingCaddy
    time: 
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

const int maxn = 10004;
const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[ ] = { 1, 0, -1, 0, -1, 1, 1, -1 };

int main( int ac, char * av[ ] )
{
	int n, m, cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ )
	{
		scanf( "%d%d", &n, &m );
		n--;
		m--;
		double ans = 2 * ( m + n ) + ( n - 1 ) * ( m - 1 );
		if( ( n % 2 == 0 ) && ( m % 2 == 0 ) )
		{
			//cout << "OK" << endl;
			ans = ans - 1 + sqrt( 2.0 );
		}
		printf( "Scenario #%d:\n%.2lf\n\n", t, ans ); 
	}
	return 0;
}
