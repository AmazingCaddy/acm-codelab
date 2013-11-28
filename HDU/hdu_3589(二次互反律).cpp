#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef __int64 ll;
const int maxn = 100006;

int solve( int a, int n )
{
	if( n == 1 ) return 1;
	int b = a % n;
	if( b == 0 ) return 0;
	int cnt = 0;
	while( b && b % 2 == 0 )
	{
		b /= 2;
		cnt++;
	}
	if( cnt % 2 ) // ( 2 / n ) ^ cnt * ( b / n )
	{
		if( n % 8 == 3 || n % 8 == 5 ) // -1
		{
			if( n % 4 == 1 || b % 4 == 1 )
				return -1 * solve( n, b );
			return solve( n, b );
		}
		else  // 1
		{
			if( n % 4 == 1 || b % 4 == 1 )
				return solve( n, b );
			return -1 * solve( n, b );
		}
	}
	if( n % 4 == 1 || b % 4 == 1 )
		return solve( n, b );
	return -1 * solve( n, b );
}

int main( )
{
	int cas, a, n;
	while( scanf("%d%d",&a,&n) != EOF )
	{
		printf("%d\n",solve( a, n ) );
	}
	return 0;
}

// MU10_ECNU003[d5NbJ7]
