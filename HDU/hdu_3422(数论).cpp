#include<iostream>
using namespace std;
typedef __int64 ll;
int main( )
{
	int n;
	ll sum, a, b, c;
	while( scanf("%d",&n) != EOF )
	{
		a = 2 * n + 1;
		b = (ll)2 * n * ( n + 1 );
		c = (ll)n * n + (ll)( n + 1 ) * ( n + 1 );
		sum = a + b + c - 3;
		printf("%I64d %I64d\n",sum, c);
	}
	return 0;
}