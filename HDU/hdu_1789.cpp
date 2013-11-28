//对于每个任务要么在截至日期前完成要么被扣分;所以考虑每个人物的完成情况即可;
//由于每天只能完成一个任务,所以优先考虑分值较大的任务,看看该任务能不能完成,
//只要能完成,即使提前完成,占了其他任务的完成日期也没关系,因为当前任务的分值最大嘛,
//而对于能完成的任务能拖多久就拖多久,以便腾出更多时间完成其他任务; 

#include<iostream>
#include<algorithm>
#define MAXN 1002
using namespace std;
struct node
{
	int deadline,sorce;
	bool operator<( const node &b )const
	{
		return sorce>b.sorce || sorce==b.sorce && deadline<b.deadline;
	}
};
node a[MAXN];
bool vis[MAXN];

int main( )
{
	int i,j,t,n,sum;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		for( i=1; i<=n; i++ )
			scanf("%d",&a[i].deadline);
		for( i=1; i<=n; i++ )
			scanf("%d",&a[i].sorce);
		sort( a+1, a+n+1 );
		memset( vis, false, sizeof(vis) );
		sum=0;
		for( i=1; i<=n; i++ )
		{
			for( j=a[i].deadline; j>0; j-- )
			{
				if( !vis[j] )
				{
					vis[j]=true;
					break;
				}
			}
			if( j==0 )sum+=a[i].sorce;
		}
		printf("%d\n",sum);
	}
	return 0;
}