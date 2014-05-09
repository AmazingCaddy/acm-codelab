//虽然不存括号,但是还要建立一个数组used[]存储每一个左括号的匹配情况.0为未配,1为已配
//每输入一个p,就从used[p]开始向左边搜  : for(j=p,j>=0,j--),
//找到第一个used[j]==0的j,那么当前输入的右括号就与第(p-j+1)个左括号相匹配.
//将这个值存进w数组里,再标记used[j]=1即可.


#include<iostream>
#include<string>
#define MAXN 100
using namespace std;
int main( )
{
	bool used[MAXN];
	int w[MAXN];
	int n,t,i,j,p;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		memset( used, false, sizeof(used) );
		for( i=0; i<n; i++ )
		{
			scanf("%d",&p);
			for( j=p; j>=1; j-- )
				if( !used[j] )
				{
					w[i]=p-j+1;
					used[j]=true;
					break;
				}
		}
		printf("%d",w[0]);
		for( i=1; i<n; i++ )
			printf(" %d",w[i]);
		printf("\n");
	}
	return 0;
}