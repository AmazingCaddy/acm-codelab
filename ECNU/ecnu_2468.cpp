//  ����ÿ���������ı����Ƿ���ڣ�������ڼ����������ĸ�����
//  ͬʱ��¼��Щ�Ѿ�����ˣ�����ľͲ���Ҫ�ظ�����

#include <iostream>
#define MAXN 1000005
using namespace std;
bool appear[MAXN],vis[MAXN];
int result[MAXN],num[MAXN],count[MAXN];
int main( )
{
	int n,i,temp,max;
	while( scanf("%d",&n) != EOF )
	{
		max=0;
		memset( count, 0, sizeof(count) );
		memset( appear, false, sizeof(appear) );
		memset( vis, false, sizeof(vis) );
		memset( result, 0, sizeof(result) );
		for( i=1; i<=n; i++ )
		{
			scanf("%d",&num[i]);
			if( num[i] > max )
				max=num[i];
			appear[num[i]]=true;
			count[num[i]]++;
		}
		for( i=1; i<=n; i++ )
		{
			if( !vis[num[i]] )
			{
				if( count[num[i]] != 1 )
					result[num[i]]+=count[num[i]]-1;
				temp=2*num[i];
				while( temp <= max )
				{
					if( appear[temp] )
						result[temp]+=count[num[i]];
					temp+=num[i];
				}
				vis[num[i]]=true;
			}
		}
		for( i=1; i<=n; i++ )
			printf("%d\n",result[num[i]]);
	}
	return 0;
}