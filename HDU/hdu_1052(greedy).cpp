/*
	author: AmazingCaddy
	time: 2011/5/18  23:44
	�����������
	�����ǵ��͵�һ��̰����Ŀ����̰��ʵ�ʣ���������󻯣���Ҫ�ɹ��ļ�����󻯣�
	������������̰�Ĳ��ԣ�
    1��ÿ��ʧ�ܵ���ƥ��Ҫ������ʧ�ܼ�ֵ���,���ذ����ɵ���ƥҪ����King���
	����ƥ����,����ʵ����ʧ�ܵļ�ֵ�������������ƥ��ȡ�����Ӯȡ���ʣ������
	�����ε�������king��ʱ��
    2��ÿ��ʤ������ƥ,Ҫ������ʤ����ֵ���,��ҪӮ��king�������õ���ƥ��
	����Ҳ�������ƥ��ȡ�����Ӯȡ���ʣ�
    3���ܾ�ƽ��
	��֮�� ��������������Ӯ��̹Ȼ����ͺñ������������ε���ñ������ٵ�Ǯ��
	��king��õ���ñ�����õĶ�������Ȼ�����ٵ�Ǯ����õĶ�����ǰ������ЩǮ
	���򣩣����������Լ۵���󻯣�
	���Կ��Ը�������:
    1.�������������Ӯ��Ӯ,�����king��õ���ȡ���������ƽ�ֵ������
    2.�������������king���������ƽʱ���������õ����������õ���ȣ�
	��Ӯ��Ӯ��������������������king��õ����!(������������õ�����
	king��õ����ƽ�����)
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
#include <queue>
using namespace std;

const int maxn = 1004;

int tian[ maxn ], king[ maxn ];

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) && n )
	{
		for( int i = 0; i < n; i++ )
			scanf( "%d", &tian[ i ] );
		for( int i = 0; i < n; i++ )
			scanf( "%d", &king[ i ] );
		sort( tian, tian + n );
		sort( king, king + n );
		int i = 0, s = 0, j = n - 1, e = n - 1;
		int ans = 0;
		while( i <= j )
		{
			if( tian[ i ] > king[ s ] ) ans++, i++, s++;
			else if( tian[ i ] == king[ s ] )
			{
				if( tian[ j ] > king[ e ] )
				{
					ans++;
					j--, e--;
				}
				else 
				{
					if( tian[ i ] < king[ e ] ) ans--;
					i++, e--;
				}
			}
			else ans--, i++, e--;
		}
		printf( "%d\n", ans * 200 );
	}
	return 0;
}
