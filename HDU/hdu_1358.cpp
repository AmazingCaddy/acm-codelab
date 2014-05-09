// KMP 失败连接值
// hdu 1358

#include<iostream>
#define MAXN 1000003
using namespace std;
char str[MAXN];
int flink[MAXN];

void fail_link( int n )
{
	int j,k;
	flink[0] = -1;
	j = 1;
	while( j < n )
	{
		k = flink[j-1];
		while( k != -1 && str[k] != str[j-1] )
			k = flink[k];
		flink[j] = k + 1;
		j++;
	}
}

int main( ) 
{
	int t=1,n,i,len,k;
	while( scanf("%d",&n) && n )
	{
		printf("Test case #%d\n",t++);
		scanf("%s",str);
		str[n] = '*';
		fail_link( n + 1 );
		for( i=2; i<=n; i++ )
		{
			len = i - flink[i];
			if( i % len == 0 && ( k = i / len ) > 1 )
				printf("%d %d\n",i,k);
		}
		printf("\n");
	}
	return 0;
}