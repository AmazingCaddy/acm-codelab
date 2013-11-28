/*
	author: wwb
	time: 2011/2/25 19:28
	题意：给你长度n的一组序列a[i]  然后k操作次数 再给你一组字符串  
	      字符串长度不足n的后面补空格
    操作：把字符在i位置的放到a[i]上   如此操作k次
    方法：直接模拟肯定TLE
	      求字符串整体周期T k=k%T  k还是很大 超时
          求每个字符串的周期 b[i]  然后 k=k%b[i]
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

typedef __int64 ll;

const int maxn = 205;
int a[ maxn ], b[ maxn ];
char str[ maxn ], ans[ maxn ];
int main(int argc, char *argv[])
{
	int n, k, pos;
	while( scanf( "%d", &n ) && n )
	{

		for( int i = 1; i <= n; i++ )
			scanf( "%d", &a[ i ] );
		for( int i = 1; i <= n; i++ )
		{
			pos = i;
			b[ i ] = 1;
			while( a[ pos ] != i )
			{
				pos = a[ pos ];
				b[ i ]++;
			}
		}
		while( scanf( "%d", &k ) && k )
		{
			getchar( );
			gets( str );
			int len = strlen( str );
			for( int i = len; i < n; i++ )
				str[ i ] = ' ';
			str[ n ] = '\0';
			for( int i = 0; i < n; i++ )
			{
				int tmp = k % b[ i + 1 ];
				pos = i + 1;
				while( tmp-- ) pos = a[ pos ];
				ans[ pos - 1 ] = str[ i ];
			}
			ans[ n ] = '\0';
			printf( "%s\n", ans );
		}
		printf( "\n" );
	}
	return 0;
}
