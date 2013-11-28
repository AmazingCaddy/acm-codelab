#include <cstdio>
#include <iostream>
#include <cstring>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef __int64 ll;
const int maxn = 1000005;
int Q[ maxn ];
int mod[ maxn * 10 ];
//int max( int a, int b ) { return ( a > b ? a : b ); }
void solve( int n, ll A, ll B )
{
	ll tmp = 1, ans = 1, sz = A + 1;
	int head = 0, tail = 0;
	mod[ 0 ] = 1;
	for( int i = 1; i <= n; i++ )
	{
		mod[ i ] = mod[ i - 1 ] * A % B;
		while( head < tail && mod[ Q[ tail - 1] ] >= mod[ i ] ) tail--;
		Q[ tail++ ] = i;
		if( i <= sz )
		{
			ans = ans * mod[ Q[ head ] ] % B;
		}
		else
		{
			while( i - Q[ head ] >= sz ) head++;
			ans = ans * mod[ Q[ head ] ] % B;
		}
	}
	printf("%I64d\n",ans);
}

int main(int argc, char *argv[])
{
	int n;
	ll A, B;
	while( scanf("%d%I64d%I64d",&n,&A,&B) != EOF )
	{
		solve( n, A, B );
	}
	return 0;
}
