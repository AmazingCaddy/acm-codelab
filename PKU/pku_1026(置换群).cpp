/*
	author: wwb
	time: 2011/2/25 19:28
	���⣺���㳤��n��һ������a[i]  Ȼ��k�������� �ٸ���һ���ַ���  
	      �ַ������Ȳ���n�ĺ��油�ո�
    ���������ַ���iλ�õķŵ�a[i]��   ��˲���k��
    ������ֱ��ģ��϶�TLE
	      ���ַ�����������T k=k%T  k���Ǻܴ� ��ʱ
          ��ÿ���ַ��������� b[i]  Ȼ�� k=k%b[i]
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
