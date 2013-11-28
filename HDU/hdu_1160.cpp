// 先对体重排个序
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1003;
struct node
{
	int w,s;
	int n;
	bool operator<( const node &b )
	{
		return w < b.w;
	}
};
node mice[maxn];
int dp[maxn];
int pre[maxn];

void print( int x )
{
	if( pre[x] == -1 ) printf("%d\n",x);
	else
	{
		print( pre[x] );
		printf("%d\n",x);
	}
}

int main( )
{
	int i = 1, j, len;
	while( scanf("%d%d",&mice[i].w,&mice[i].s) != EOF )
	{
		mice[i].n = i;
		i++;
	}
	len = i;
	sort( mice + 1, mice + len );
	for( i = 1; i < len; i++ )
		dp[i] = 1, pre[i] = -1;
	for( i = 2; i < len; i++ )
		for( j = 1; j < i; j++ )
			if( dp[j] + 1 > dp[i] && mice[j].w < mice[i].w && mice[j].s > mice[i].s )
				dp[i] = dp[j] + 1, pre[mice[i].n] = mice[j].n;
	int max = -1;
	for( i = 1; i < len; i++ )
		if( dp[i] > max )
			max = dp[i], j = i;
	printf("%d\n",max);
	print( mice[j].n );
	return 0;
}