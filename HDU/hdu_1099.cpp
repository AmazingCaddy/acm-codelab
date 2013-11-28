/*
	author: AmazingCaddy
	time:	2011-07-08 16:30:23 
	题意：1~n编号的彩票，要买全，等概率条件下平均要买几张。
	已经买了m张时，买中剩下的概率为1-m/n，则要买的张数为1/(1-m/n)
	n=2，s=1+1/(1-1/2);n=3，s=1+1/(1-1/3)+1/(1-2/3)
	s=1+1/(1-1/n)+1/(1-2/n)+1/(1-3/n)+……+1/(1-(n-1)/n)=n/n+n/(n-1)+n/(n-2)+……+n/1=sum(n/i),i=1~n
	b/a+d/c=(bc+ad)/(ac)
	然后递推着通分，化简；输出。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;
#define lowbit(x) ((x)&(-(x)))

typedef __int64 ll;
const int maxn = 10004;
const int inf = 0x3fffffff;
const double eps = 1e-8;
const double pi = acos( -1.0 );

ll gcd( ll a, ll b ) { return ( b ? gcd( b, a % b ) : a ); }
ll lcm( ll a, ll b ) { return a / gcd( a, b ) * b; }

struct fenshu
{
	ll fenzi, fenmu;
	fenshu( ll _fenzi, ll _fenmu ) : fenzi( _fenzi ), fenmu( _fenmu )
	{
		if( fenzi )
		{
			ll d = gcd( fenzi, fenmu );
			fenzi /= d;
			fenmu /= d;
		}
		else fenmu = 1;
	}
	fenshu( ) { fenzi = 0; fenmu = 1; }
};

fenshu operator + ( const fenshu & a, const fenshu & b )
{
	ll fenmu = lcm( a.fenmu, b.fenmu );
	ll fenzi = fenmu / a.fenmu * a.fenzi + fenmu / b.fenmu * b.fenzi;
	ll d = gcd( fenmu, fenzi );
	return fenshu( fenzi / d, fenmu / d );
}

char buf[ 100 ];

int main(int argc, char *argv[])
{
	ll n;
	while( scanf( "%I64d", &n ) != EOF )
	{
		fenshu sum;
		for( int i = 1; i <= n; i++ )
		{
			sum = sum + fenshu( n, i );
		}
		ll zi = sum.fenzi, mu = sum.fenmu;
		if( zi % mu == 0 ) printf( "%I64d\n", zi / mu );
		else
		{
			ll a = zi / mu, b = zi % mu;
			sprintf( buf, "%I64d", a );
			int len = strlen( buf );
			for( int i = 0; i <= len; i++ ) printf( " " );
			printf( "%I64d\n", b );
			printf( "%s ", buf );
			sprintf( buf, "%I64d", mu );
			int len1 = strlen( buf );
			for( int i = 0; i < len1; i++ ) printf( "-" );
			printf( "\n" );
			for( int i = 0; i <= len; i++ ) printf( " " );
			printf( "%s\n", buf );
		}
	}
	return 0;
}

