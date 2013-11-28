////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-08-25 14:11:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3566
////Problem Title: 
////Run result: Accept
////Run time:2812MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 210;
int x[maxn], y[maxn], r[maxn];
int xx[maxn], yy[maxn], rx[maxn], ry[maxn];
int min( int a, int b ) { return ( a < b ? a : b ); }
int main(int argc, char *argv[])
{
	int n, g, cas;
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		scanf("%d%d",&n,&g);
		for( int i = 0; i < n; i++ )
		{
			scanf("%d%d%d",&x[i],&y[i],&r[i]);
			xx[i] = x[i], yy[i] = y[i];
		}
		sort( xx, xx + n );
		sort( yy, yy + n );
		for( int i = 0; i < n; i++ )
		{
			rx[i] = n - ( lower_bound( xx, xx + n, x[i] ) - xx );
			ry[i] = n - ( lower_bound( yy, yy + n, y[i] ) - yy );
		}
		int ans = 0;
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= n; j++ )
			{
				int a[] = { 0 , 0 }, r1[] = { 0, 0 }, r2[] = { 0, 0 };
				for( int k = 0; k < n; k++ )
				{
					if( rx[k] <= i && ry[k] <= j ) a[r[k]]++;
					else if( rx[k] <= i ) r1[r[k]]++;
					else if( ry[k] <= j ) r2[r[k]]++;
				}
				for( int k = 0; k <= a[0] + a[1]; k++ )
				{
					int s1 = g - k, s2 = g - ( a[0] + a[1] - k );
					if( s1 >= 0 && s2 >= 0 )
					{
						s1 = min( s1, r1[1] );
						s2 = min( s2, r2[1] );
						if( s1 + s2 + a[1] > ans )
							ans = s1 + s2 + a[1];
					}
				}
			}
		}
		printf("Case %d: %d\n",t, ans);
	}
	return 0;
}
