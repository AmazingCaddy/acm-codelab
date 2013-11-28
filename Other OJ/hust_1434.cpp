/*
	author: AmazingCaddy
	time: 2011/4/10  12:50
	��һ��Ԫ�غܺõó�����b[1]+1���ɡ�
	b[i]��b[i+1]�Ĳ����b[i+1]��b[i]�����a[i+1]��������б���С��Ԫ�ز���������Ը���x,
	����a[i+1]��ǰ�����д��Ԫ�ز���������Ը���y, ��b[i]-b[i+1]=x-y.
	Ȼ���i����������n-i������,������x������С,n-i-x��������
	��ô�����������n������������һ����n-i-x+y�����ֱ�����
	��a[i] = n-(n-i-x+y)=i+x-y ������ɡ�
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
