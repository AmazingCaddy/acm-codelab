//��Ȼ��������,���ǻ�Ҫ����һ������used[]�洢ÿһ�������ŵ�ƥ�����.0Ϊδ��,1Ϊ����
//ÿ����һ��p,�ʹ�used[p]��ʼ�������  : for(j=p,j>=0,j--),
//�ҵ���һ��used[j]==0��j,��ô��ǰ����������ž����(p-j+1)����������ƥ��.
//�����ֵ���w������,�ٱ��used[j]=1����.


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