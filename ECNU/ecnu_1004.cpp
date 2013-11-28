#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;
const int maxn = 50003;
int a[ maxn ], le[ maxn ], bet[ maxn ], ri[ maxn ];

int main(int argc, char *argv[])
{
	int n, m, cas;
	scanf("%d",&cas);
	while( cas-- )
	{
		scanf("%d",&n);
		for( int i = 0; i < n; i++ ) scanf("%d",&a[ i ]);
		scanf("%d",&m);
		memset( bet, 0, sizeof( bet ) );
		for( int i = 0; i < m; i++ ) bet[ 0 ] += a[ i ];
		for( int i = m; i < n; i++ ) bet[ i - m + 1 ] = bet[ i - m ] - a[ i - m ] + a[ i ];
		n -= m - 1;
		le[ 0 ] = bet[ 0 ];
		for( int i = 1; i < n; i++ ) le[ i ] = le[ i - 1 ] > bet[ i ] ? le[ i - 1 ] : bet[ i ];
		ri[ n - 1 ] = bet[ n - 1 ];
		for( int i = n - 2; i >= 0; i-- ) ri[ i ] = ri[ i + 1 ] > bet[ i ] ? ri[ i + 1 ] : bet[ i ];
		int ans = 0, tmp;
		for( int i = m; i < n - m; i++ )
			if( ans < ( tmp = le[ i - m ] + bet[ i ] + ri[ i + m ] ) )
				ans = tmp;
		printf("%d\n",ans);
	}
	return 0;
}
