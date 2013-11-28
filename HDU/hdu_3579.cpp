#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef __int64 ll;
void ex_gcd( int a, int b, int &d, int &x, int &y )
{
	if( !b ) { d = a; x = 1; y = 0; }
	else
	{
		ex_gcd( b, a % b, d, y, x );
		y -= x * ( a / b );
	}
}

bool merge( int m1, int c1, int m2, int c2, int & m, int & c, int & d )
{
	int x, y;
	ex_gcd( m1, m2, d, x, y );
	c = c2 - c1;
	if( c % d ) return false;
	c /= d;
	m = (ll) m1 * m2 / d;
	c = ( (ll)c * x * m1 + c1 ) % m;
	c = ( c + m ) % m;
	return true;
}

const int maxn = 10;
int M[maxn], A[maxn];

int main( )
{
	int n, t, cas, i;
	scanf("%d",&cas);
	for( t = 1; t <= cas; t++ )
	{
		scanf("%d",&n);
		for( i = 0; i < n; i++ )
			scanf("%d",&M[i]);
		for( i = 0; i < n; i++ )
			scanf("%d",&A[i]);
		int flag = 1;
		int m, a, d;
		for( i = n - 1; i > 0 && flag; i-- )
		{
			if( !merge( M[i], A[i], M[i-1], A[i-1], m, a, d ) )
				flag = 0;
			M[i-1] = m, A[i-1] = a;
		}
		printf("Case %d: ",t);
		int ans;
		if( !flag ) ans = -1;
		else ans = ( A[0] ? A[0] : M[0] );
		printf("%d\n",ans);
	}
	return 0;
}
