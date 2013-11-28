#include<iostream>
#define N 3405
#define M 12885
#define max(n,m) n>m?n:m
using namespace std;
int weight[M];
struct jewelry
{
	int w,d;
}wei[N];
 
int main()
{
	int i,j,n,m,max;
	while( scanf("%d%d",&n,&m)!=EOF )
	{
		memset( weight, 0, sizeof(weight) );
		for( i=0; i<n; i++ )
			scanf("%d%d",&wei[i].w,&wei[i].d);
		max=0;
		for( i=0; i<n; i++ )
		{
			for( j=m; j>=wei[i].w; j-- )
			{
				weight[j]=max( weight[j-wei[i].w]+wei[i].d, weight[j] );
				max=max( weight[j], max );
			}
		}
		printf("%d\n",max);
	}
	return 0;
}