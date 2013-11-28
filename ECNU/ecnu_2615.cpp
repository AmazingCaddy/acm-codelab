#include<iostream>
#include<cstdlib>
#define N 370
using namespace std;
struct node
{
	int s,t,w;
}data[305];
int compare( const void *a, const void *b )
{
	node *c=(node*)a,*d=(node*)b;
	return c->t-d->t;
}

int main()
{
	int T,n,i,max,j;
	int dp[N];
	scanf("%d",&T);
	while( T-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			scanf("%d%d%d",&data[i].s,&data[i].t,&data[i].w);
		qsort( data, n, sizeof(node), compare );
		memset( dp, 0, sizeof(dp) );
		for( i=0; i<n; i++ )
		{
			max=0;
			if( data[i].s==0 )
				dp[data[i].t]=data[i].w>dp[data[i].t]?data[i].w:dp[data[i].t];
			else 
			{
			    for( j=0; j<data[i].s; j++ )
					if( dp[j]+data[i].w>max )max=dp[j]+data[i].w;
				dp[data[i].t]=dp[data[i].t]>max?dp[data[i].t]:max;
			}
		}
		max=0;
		for( i=0; i<N; i++ )
			if( dp[i]>max )max=dp[i];
		printf("%d\n",max);
	}
	return 0;
}
