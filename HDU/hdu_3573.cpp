#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	int a, b, c, cas;
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		scanf("%d%d%d",&a,&b,&c);
		b += c;
		int ans;
		if( a > b * 2 ) ans = ( a - b * 2 + 2 ) / 3 + b;
		else ans = ( b - ( a + 1 ) / 2 + 1 ) / 2 + ( a + 1 ) / 2;
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}
