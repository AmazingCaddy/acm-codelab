#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 10003;
char ch[maxn];
int a[maxn], b[maxn];

int main(int argc, char *argv[])
{
	int slen, len;
	for( int i = 0; i < 10; i++ ) b[i] = 1;
	for( int i = 10; i < 100; i++ ) b[i] = 2;
	for( int i = 100; i < 1000; i++ ) b[i] = 3;
	for( int i = 1000; i < 10000; i++ ) b[i] = 4;
	b[10000] = b[10001] = b[10002] = b[10003] = 5;
	while( scanf("%s",ch) != EOF )
	{
		slen = strlen( ch );
		len = 0;
		ch[slen++] = '#';
		if( ch[0] == 'L' ) a[len++] = 0;
		a[len] = 1;
		for( int i = 1; i < slen; i++ )
		{
			if( ch[i] != ch[i-1] )
				a[++len] = 1;
			else a[len]++;
		}
		a[len-1]++;
		//printf("len = %d\n",len);
		//for( int i = 0; i < len; i++ )
		//	printf("%d ",a[i]);
		//printf("\n");
		int sum = 0, s, t;
		for( int i = 0; i < len; i++ )
			sum += b[a[i]] + 3;
		sum -= 3;
		s = sum - 1, t = 0;
		for( int i = 0; i < len - 1; i++ )
		{
			for( int j = 0; j < s; j++ )
				printf(" ");
			printf("1\n");
			int tmp = b[a[i]] + 3;
			sum -= tmp;
			for( int j = 0; j < t; j++ )
				printf(" ");
			printf("%d + ",a[i]);
			for( int j = 0; j < sum; j++ )
				printf("-");
			printf("\n");
			t += tmp;
		}
		s = s + 1 - b[a[len-1]];
		for( int i = 0; i < s; i++ )
			printf(" ");
		printf("%d\n",a[len-1]);
	}
	return 0;
}
