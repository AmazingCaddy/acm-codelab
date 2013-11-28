/*
	author: AmazingCaddy
	time: 2011/4/7  16:33
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
const int maxn = 100004;

int pow_mod( int a, int b, int c )
{
	int ans = 1, d = a % c;
	while( b )
	{
		if( b & 1 ) ans = ans * d % c;
		d = d * d % c;
		b >>= 1;
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int cas;
	char ch;
	scanf( "%d", &cas );
	getchar( );
	while( cas-- )
	{
		int len = -1;
		int h = 0;
		while( ( ch = getchar( ) ) != '\n' )
		{
			len++;
			h = h * 10 + ( ch - '0' );
			h %= 11;
		}
		if( len == 0 )
		{
			//printf( "shit\n" );
			if( h == 1 ) printf( "1\n" );
			else if( h == 4 ) printf( "2\n" );
			else printf( "-1\n" );
		}
		else
		{
			int l = 1, r = maxn, m, len1;
			while( l <= r )
			{
				m = ( l + r ) / 2;
				len1 = m * log10( m * 1.0 );
				if( len1 == len ) break;
				else if( len1 > len ) r = m - 1;
				else l = m + 1;
			}
			len1 = pow_mod( m, m, 11 );
			if( len1 == h ) printf( "%d\n", m );
			else printf( "-1\n" );
		}
	}
	return 0;
}
