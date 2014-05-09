/*
	author: AmazingCaddy
	time: 2011/5/18  23:44
	田忌赛马问题
	此题是典型的一道贪心题目，其贪心实质：（几率最大化）想要成功的几率最大化，
	则必须采用如下贪心策略：
    1、每次失败的马匹，要体现其失败价值最大化,即必败无疑的马匹要跟其King最好
	的马匹比赛,才能实现其失败的价值！（即给后继马匹争取更大的赢取几率）（针对
	田忌最次的马弱于king马时）
    2、每次胜利的马匹,要体现其胜利价值最大化,即要赢了king里相对最好的马匹！
	（即也给后继马匹争取更大的赢取几率）
    3、拒绝平局
	总之： 就是死得其所，赢得坦然。这就好比买东西，田忌最次的马好比是最少的钱，
	而king最好的马好比是最好的东西；显然用最少的钱买最好的东西（前提是这些钱
	购买），才能体现性价的最大化！
	所以可以概括如下:
    1.田忌最弱的马能赢则赢,否则跟king最好的马比。（不包括平局的情况）
    2.田忌最弱的马与king最弱的马打平时，用田忌最好的马跟国王最好的马比，
	能赢则赢。否则用田忌最弱的马跟king最好的马比!(这里包含田忌最好的马与
	king最好的马打平的情况)
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
