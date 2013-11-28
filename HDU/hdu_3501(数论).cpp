//�����������С��N����N���ʵ�������֮��, ��ΪS.
//��������Щ��Ϊa[1], a[2], ..., a[ phi(N) ], ����phi(N)��N��ŷ������ֵ.
//��1 <= i <= phi(N), ��gcd(N, a[i]) = 1��֪gcd(N, N - a[i]) = 1.
//������Բ��÷�֤: ��gcd(N, N - a[i]) = k > 1, 
//��k|N, k|(N - a[i]) -> k|a[i] -> k|gcd(N, a[i]), ��gcd(N, a[i]) = 1, ì��.
//����, N - a[1], N - a[2], ..., N - a[ phi(N) ]Ҳ��Ӧ��ԭ����, ����:
//S = a[1] + a[2] + ... + a[ phi(N) ]
//S = (N - a[1]) + (N - a[2]) + ... + (N - a[ phi[N] ])
//��ʽ��ӵ�: S = N * phi(N) / 2, ��������Ϊ( N * (N - 1) / 2 - S) Mod 1000000007.

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
