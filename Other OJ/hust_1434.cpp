/*
	author: AmazingCaddy
	time: 2011/4/10  12:50
	第一个元素很好得出，即b[1]+1即可。
	b[i]和b[i+1]的差别是b[i+1]比b[i]多出了a[i+1]与后面所有比它小的元素产生的逆序对个数x,
	少了a[i+1]与前面所有大的元素产生的逆序对个数y, 即b[i]-b[i+1]=x-y.
	然后第i个数后面有n-i个数字,其中有x个比它小,n-i-x个比它大，
	那么这个数字在这n个数字里面有一共有n-i-x+y个数字比它大，
	即a[i] = n-(n-i-x+y)=i+x-y 输出即可。
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

typedef long long ll;

const int maxn = 100005;
ll b[ maxn ];
int mk[ maxn ];

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) != EOF )
	{
		for( int i = 1; i < n; i++ )
			scanf( "%lld", &b[ i ] );
		memset( mk, 0, sizeof( mk ) );
		ll ans = b[ 1 ] + 1;
		mk[ ans ] = 1;
		printf( "%lld ", ans );
		for( int i = 2; i < n; i++ )
		{
			ans = i + b[ i ] - b[ i - 1 ];
			mk[ ans ] = 1;
			printf( "%lld ", ans );
		}
		for( int i = 1; i <= n; i++ )
		{
			if( !mk[ i ] )
			{
				printf( "%lld\n", i );
				break;
			}
		}
	}
	return 0;
}
