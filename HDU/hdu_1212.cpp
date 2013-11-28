#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 1003
using namespace std;
int a[MAXN];
char str[MAXN];
int main( int argc, char *argv[] )
{
	int n,i,len,sum;
	while( scanf("%s%d",str,&n) != EOF )
	{
		len = strlen( str );
		for( i = 0; i < len; i++ )
			a[i] = str[i] - '0';
		sum = 0;
		for( i = 0; i < len; i++ )
		{
			sum = sum * 10 + a[i];
			if( sum >= n )
				sum %= n;
		}
		printf("%d\n",sum%n);
	}
	return 0;
}
