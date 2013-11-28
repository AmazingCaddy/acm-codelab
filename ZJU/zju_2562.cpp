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
//当前枚举到的数；枚举到的第K大的质因子；该数的约数个数；质因子个数上限
{
	ll temp;
	if( sum > maxsum )
	{
		maxsum = sum;
		bestnum = num;		//如果约数个数更多，将最优解更新为当前数
	}
	if( sum == maxsum && bestnum > num )
		bestnum = num;		//如果约数个数相同，将最优解更新为较小的数

	if( k > 15 ) return;

	temp = num;
	for( int i = 1; i <= limit; i++ )	//开始枚举每个质因子的个数
	{
		if( temp * p[ k ] > n ) break;
		temp = temp * p[ k ];			//累乘到当前数
		make( temp, k + 1, sum * ( i + 1 ), i );	//继续下一步搜索
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
