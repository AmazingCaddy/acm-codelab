#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	int n, m, k, sum, cas;
	double ans;
	scanf("%d",&cas);
	for( int t = 1; t <= cas; t++ )
	{
		int tmp;
		scanf("%d%d%d",&n,&m,&k);
		sum = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf("%d",&tmp);
			sum += tmp;
		}
		ans = 1.0 * sum * m / n;
		printf("Case %d: %.5lf\n",t,ans);
	}
	return 0;
}
