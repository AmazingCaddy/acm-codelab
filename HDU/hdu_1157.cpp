#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <complex>
#define MAXN 10003
using namespace std;

int a[MAXN];
int main( int argc, char *argv[] )
{
	int n, i;
	while( scanf("%d",&n) != EOF )
	{
		for( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		sort( a, a + n );
		printf("%d\n",a[n/2]);
	}
	return 0;
}
