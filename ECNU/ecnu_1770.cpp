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

const int maxn = 10000007;
const unsigned int maxm = 46350;
bool mk[ maxn ];
int vis[ maxm ];
unsigned int p[ maxm ];
int plen;

void prime( )
{
	unsigned int i, j, k;
	plen = 0;
	memset( vis, 0, sizeof( vis ) );
	for( i = 2, k = 4; i < maxm; ++i, k += i + i - 1 )
	{
		if( !vis[ i ] )
		{
			p[ plen ++ ] = i;
			if( k < maxm ) for( j = k; j < maxm; j += i ) vis[ j ] = 1;
		}
	}
}

int main(int argc, char *argv[])
{
	prime( );
	unsigned int L, U, t;
	unsigned int maxl, maxr, minl, minr;
	while( scanf( "%u %u", &L, &U ) != EOF )
	{
		unsigned int i, j, k;
		if( L == 1 ) L++;
		memset( mk, false, sizeof(mk[0])*(U-L+1) );
		for( j = 0; j < plen && p[ j ] * p[ j ] <= U; j++ )
		{
			unsigned int be = ( L + p[j] - 1 ) / p[j];
			if( be == 1 ) be++;
			k = be * p[ j ];
			while( k <= U ) mk[ k - L ] = true, k += p[ j ];
		}
		unsigned int len = U - L;
		for( i = 0; i <= len; i++ )
			if( !mk[ i ] ) break;
		int tmp = i;
		if( tmp == len + 1 ) printf( "There are no adjacent primes.\n" );
		else 
		{
			maxl = minr = tmp;
			unsigned int Min = 3000000000, Max = 0;
			for( i = tmp + 1; i <= len; i++ )
			{
				if( !mk[ i ] )
				{
					if( i - tmp < Min )
					{
						minl = tmp;
						minr = i;
						Min = i - tmp;
					}
					if( i - tmp > Max )
					{
						maxl = tmp;
						maxr = i;
						Max = i - tmp;
					}
					tmp = i;
				}
			}
			if( Max == 0 ) printf( "There are no adjacent primes.\n" );
			else printf( "%u,%u are closest, %u,%u are most distant.\n", minl+L, minr+L, maxl+L, maxr+L );
		}
	}
	return 0;
}
