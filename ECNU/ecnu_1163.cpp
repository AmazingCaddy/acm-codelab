#include<iostream>
#define N 1000001
#define M 100001
using namespace std;
bool weight[N];
int w[M];
int main()
{
	int n,i,j,sum,max;
	while( scanf("%d",&n)!=EOF )
	{
		memset( weight, false, sizeof(weight) );
		weight[0]=true;
		sum=0;
		for( i=0; i<n; i++ )
		{
			scanf("%d",&w[i]);
			sum+=w[i];
		}
		max=0;
		for( i=0; i<n; i++ )
		{
			for( j=sum/2; j>=0; j-- )
			{
				if( weight[j-w[i]] )
				{
					weight[j]=true;
					if( j>max )max=j;
				}
			}
		}
		printf("%d\n",sum-2*max);
	}
	return 0;
}