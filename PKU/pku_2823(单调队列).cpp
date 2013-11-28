#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100006;
int Qmax[maxn], Qmin[maxn];
int win[maxn];
int MAX[maxn], MIN[maxn];

int main(int argc, char *argv[])
{
	//freopen("out.txt","w",stdout);
	int n, k;
	scanf("%d%d",&n,&k);
	for( int i = 1; i <= n; i++ )
		scanf("%d",&win[i]);
	if( k > n ) n = k;
	int hmax = 0, hmin = 0, tmax = 0, tmin = 0;
	//printf("hello\n");
	for( int i = 1; i <= n; i++ )
	{
		while( hmax < tmax && win[Qmax[tmax-1]] < win[i] ) tmax--;
		Qmax[tmax++] = i;
		if( i >= k )
		{
			while( i - Qmax[hmax] >= k ) hmax--;
			MAX[i] = win[Qmax[hmax]];
		}
	}
	for( int i = 1; i <= n; i++ )
	{
		while( hmin < tmin && win[Qmin[tmin-1]] > win[i] ) tmin--;
		Qmin[tmin++] = i;
		if( i >= k )
		{
			while( i - Qmin[hmin] >= k ) hmin--;
			MIN[i] = win[Qmin[hmin]];
		}
	}
	for( int i = k; i <= n; i++ )
	{
		printf("%d",MIN[i]);
		if( i != n )printf(" ");
	}
	printf("\n");
	for( int i = k; i <= n; i++ )
	{
		printf("%d",MAX[i]);
		if( i != n )printf(" ");
	}
	printf("\n");
	return 0;
}
/*
8 3
1 7 10 14 -1 2 3 4
*/
