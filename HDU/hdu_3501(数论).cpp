//下面我们求出小于N且与N互质的正整数之和, 设为S.
//不妨设这些数为a[1], a[2], ..., a[ phi(N) ], 其中phi(N)是N的欧拉函数值.
//对1 <= i <= phi(N), 由gcd(N, a[i]) = 1可知gcd(N, N - a[i]) = 1.
//这里可以采用反证: 设gcd(N, N - a[i]) = k > 1, 
//则k|N, k|(N - a[i]) -> k|a[i] -> k|gcd(N, a[i]), 而gcd(N, a[i]) = 1, 矛盾.
//这样, N - a[1], N - a[2], ..., N - a[ phi(N) ]也对应着原数列, 则有:
//S = a[1] + a[2] + ... + a[ phi(N) ]
//S = (N - a[1]) + (N - a[2]) + ... + (N - a[ phi[N] ])
//两式相加得: S = N * phi(N) / 2, 所求结果即为( N * (N - 1) / 2 - S) Mod 1000000007.

#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>

using namespace std;
typedef __int64 ll;
const int p = 1000000007;

int PHI( int n )
{
	int phi = n;
	for( int i = 2; i * i <= n; i++ )
	{
		if( n % i == 0 )
		{
			phi = phi / i * ( i - 1 );
			while( !( n % i ) ) n /= i;
		}
	}
	if( n > 1 ) phi = phi / n * ( n - 1 );
	return phi;
}

int main(int argc, char *argv[])
{
	int n;
	while( scanf("%d",&n) && n )
	{
		int ans = (ll)PHI( n ) * n / 2 % p;
		ans = ( (ll)n * ( n - 1 ) / 2 - ans ) % p;
		printf("%d\n",ans);
	}
	return 0;
}
