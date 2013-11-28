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

const int maxn = 40004;
int vis[ maxn ];
void prime( )
{
	int i, j, k;
	memset( vis, 0, sizeof( vis ) );
	for( vis[ 0 ] = vis[ 1 ] = 1, i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
			if( k < maxn )
				for( j = k; j < maxn; j += i ) vis[ j ] = 1;
	}
}

int gcd( int a, int b )
{
	return b ? gcd( b, a % b ) : a;
}

bool check( int p, int q )
{
	int t;
	if( p == 0 && q == 0 )return false;
	if( p == 0 && q != 0 && q % 4 == 3 && !vis[ q ] ) return true;
	if( p != 0 && q == 0 && p % 4 == 3 && !vis[ p ] ) return true;
	if( p != 0 && q != 0 && !vis[ t = p * p + q * q ] && t % 4 != 3 ) return true;
	return false;
}

int main(int argc, char *argv[])
{
	int a, b, c, d;
	int cas;
	prime( );
	//if( check( 1, 0 ) ) cout << "OK" << "\n";
	//if( check( -1, 0 ) ) cout << "OK" << "\n";
	//if( check( 0, 1 ) ) cout << "OK" << "\n";
	//if( check( 0, -1 ) ) cout << "OK" << "\n";

	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%d %d %d %d", &a, &b, &c, &d );
		int cnt = 0;

		for( int i = a; i <= b; i++ )
		{
			for( int j = c; j <= d; j++ )
			{
				if( check( abs(i), abs(j) ) )
				{
					cnt++;
					//printf( "%d + %d i\n", i, j );
				}
			}
		}
		int fenmu = ( b - a + 1 ) * ( d - c + 1 );
		int d = 1, x, y;
		if( cnt != 0 ) 
		{
			d = gcd( fenmu, cnt );
			x=  cnt/d;
			y = fenmu/d;
		}
		else x = 0, y = 1;
		printf( "%d/%d\n",x,y);
	}
	return 0;
}
