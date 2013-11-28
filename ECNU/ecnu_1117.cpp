#include<iostream>
#define M 1000
using namespace std;
int main()
{
	int t,m,i,j,sum,temp;
	int a[M],b[M];
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&m);
		for( i=0; i<m; i++ )
			scanf("%d",&a[i]);
		for( i=0; i<m; i++ )
			scanf("%d",&b[i]);
		sum=a[0]+b[0];temp=a[0];
		for( i=1; i<m; i++ )
		{
			while ( sum%a[i] != b[i] )
			{
				sum+=temp;
			}
			temp*=a[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}