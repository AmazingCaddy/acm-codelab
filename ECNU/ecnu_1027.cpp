//多重背包
#include<iostream>
#define MAXN 40005
using namespace std;
struct node
{
	int c,w;
};
node a[22];
bool dp[MAXN];
int th[105];
int b[5]={1,2,4,8,16};
int main( )
{
	int i,j,n,t,cnt,x,total,num;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			scanf("%d",&a[i].c);
		cnt=0;   total=0;
		for( i=0; i<n; i++ )
		{
			scanf("%d",&x);
			a[i].w=x;
			total+=a[i].c*a[i].w;
			for( j=0; j<5; j++ )
			{
				if( x-b[j]<0 )
				{
					th[cnt++]=x*a[i].c;
					break;
				}
				else th[cnt++]=b[j]*a[i].c,x-=b[j];
			}
		}
		memset( dp, false, sizeof(dp) );
		dp[0]=true;
		num=1;
		for( i=0; i<cnt; i++ )
			for( j=total; j>=th[i]; j-- )
				if( dp[j-th[i]] && !dp[j])
					dp[j]=true,num++;
		printf("%d\n",num);
	}
	return 0;
}