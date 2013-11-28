#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef __int64 ll;
typedef pair<int, int> PII;
const int p = 1000000007;
priority_queue<PII, vector<PII>, greater<PII> > heap;

ll pow_mod( ll a, int b, int c )
{
	ll ans = 1, d = a % c;
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
	int n, m, x, y;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		while( !heap.empty( ) ) heap.pop( );
		for( int i = 0; i < m; i++ )
		{
			scanf("%d%d",&x,&y);
			heap.push( make_pair( x, y ) );
		}
		int c = n;
		while( !heap.empty( ) )
		{
			c--;
			PII a = heap.top( );
			heap.pop( );
			while( !heap.empty( ) )
			{
				PII tmp = heap.top( );
				if( a.first != tmp.first ) break;
				heap.pop( );
				tmp.first = a.second + 1;
				if( tmp. first > tmp.second ) continue;
				heap.push( tmp );
			}
		}
		int ans = pow_mod( 26, c, p );
		printf("%d\n",ans);
	}
	return 0;
}
