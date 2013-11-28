/*
	author: AmazingCaddy
	time: 2011/3/29  19:36
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;
int p[ ] = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
ll n, maxsum, bestnum;

void make( ll num, ll k, ll sum, int limit )
//��ǰö�ٵ�������ö�ٵ��ĵ�K��������ӣ�������Լ�������������Ӹ�������
{
	ll temp;
	if( sum > maxsum )
	{
		maxsum = sum;
		bestnum = num;		//���Լ���������࣬�����Ž����Ϊ��ǰ��
	}
	if( sum == maxsum && bestnum > num )
		bestnum = num;		//���Լ��������ͬ�������Ž����Ϊ��С����

	if( k > 15 ) return;

	temp = num;
	for( int i = 1; i <= limit; i++ )	//��ʼö��ÿ�������ӵĸ���
	{
		if( temp * p[ k ] > n ) break;
		temp = temp * p[ k ];			//�۳˵���ǰ��
		make( temp, k + 1, sum * ( i + 1 ), i );	//������һ������
	}
}

int main(int argc, char *argv[])
{
	while( scanf( "%lld", &n ) != EOF )
	{
		maxsum = 0;
		bestnum = n;
		make( 1, 1, 1, 50 );
		printf( "%lld\n", bestnum );
	}
	return 0;
}
