#include<iostream>
#include<algorithm>

using namespace std;
const int maxn = 1004;
const int inf = 2000000000;
int a[maxn];
int max( int a, int b ){ return a > b ? a : b ;}
int main( )
{
	int n, i, sum;
	while(scanf("%d",&n)!=EOF)
	{
		for( i = 0; i < n; i++  )
			scanf("%d",&a[i]);
		sort( a, a + n );
		for( sum = 0, i = 0; i < n; i++ )
			sum = max( ( n - i ) * a[i], sum );
		printf("%d\n",sum);
	}
	return 0;
}