#include<iostream>
using namespace std;

__int64 gcd( __int64 a, __int64 b )
{
	return ( b ? gcd( b, a%b ) : a );
}

int main( )
{
	__int64 n,m,d,ans;
	int t;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%I64d%I64d",&n,&m);
		d=gcd( n, m );
		ans=n+m-d;
		printf("%I64d\n",ans);
	}
	return 0;
}