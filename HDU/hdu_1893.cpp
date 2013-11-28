#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <complex>
using namespace std;
const int maxn = 1000;
const int p = 1000000007;
int s[maxn*1000+3];

int main( int argc, char *argv[] )
{
	int i, j, t;
	double x;
	for( i = 0; i < 1000; i++ )
	{
		s[i] = 1;
	}
	for( i = 1000; i <=1000000; i++ )
	{
		s[i] = s[i-1000];
		if( i >= 3140 )s[i] += s[i-3140];
		s[i] %= p;
	}
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%lf",&x);
		if( x < 0 )printf("0\n");
		else 
		{
			int n = x * 1000;
			printf("%d\n",s[n]);
		}
	}
	return 0;
}
