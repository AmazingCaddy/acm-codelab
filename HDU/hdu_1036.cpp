/*
    author: AmazingCaddy
    time: 16/05/2011 20:55:56 
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

const int maxn = 104;
const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos( -1.0 );

const int dx[ ] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[ ] = { 1, 0, -1, 0, -1, 1, 1, -1 };

char buf[ maxn ];

int main( int ac, char * av[ ] )
{
	int n, id, hh, mm, ss;
	double d;
	scanf( "%d%lf", &n, &d );	
	while( scanf( "%d", &id ) != EOF )
	{
		int flag = 0;
		double ans = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%s", buf );
			if( flag ) continue;
			if( buf[ 0 ] == '-' ) { flag = 1; continue; }
			hh = buf[ 0 ] - '0';
			mm = ( buf[ 2 ] - '0' ) * 10 + buf[ 3 ] - '0';
			ss = ( buf[ 5 ] - '0' ) * 10 + buf[ 6 ] - '0';
			double tt = hh * 60 + mm + ss / 60.0;
			ans += tt;
		}
		if( flag ) printf( "%3d: -\n", id );
		else 
		{
			int s = ( int )( ans / d * 60 + 0.5 );
			int m = s / 60;
			s %= 60;
			printf( "%3d: %d:%.2d min/km\n", id, m, s );
		}
	}
	return 0;
}
