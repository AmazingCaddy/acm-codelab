//����ÿ������Ҫô�ڽ�������ǰ���Ҫô���۷�;���Կ���ÿ�����������������;
//����ÿ��ֻ�����һ������,�������ȿ��Ƿ�ֵ�ϴ������,�����������ܲ������,
//ֻҪ�����,��ʹ��ǰ���,ռ������������������Ҳû��ϵ,��Ϊ��ǰ����ķ�ֵ�����,
//����������ɵ��������϶�þ��϶��,�Ա��ڳ�����ʱ�������������; 

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